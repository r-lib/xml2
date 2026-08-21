#include <Rinternals.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <libxml/tree.h>
#include "xml2_types.h"
#include <algorithm>
#include <cmath>

class XmlSeeker {
  xmlXPathContext* context_;
  xmlXPathObject* result_;
  XPtrDoc doc_;

public:

  XmlSeeker(XPtrDoc doc, xmlNode* node) : result_(NULL), doc_(doc) {
    context_ = xmlXPathNewContext(doc.checked_get());
    // Set context to current node
    context_->node = node;
  }

  static bool registerNamespace(xmlXPathContext* context, SEXP nsMap) {
    R_xlen_t n = Rf_xlength(nsMap);
    if (n == 0) {
      return true;
    }

    SEXP prefix = Rf_getAttrib(nsMap, R_NamesSymbol);

    for (int i = 0; i < n; ++i) {
      xmlChar* prefixI = (xmlChar*) CHAR(STRING_ELT(prefix, i));
      xmlChar* urlI = (xmlChar*) CHAR(STRING_ELT(nsMap, i));

      if (xmlXPathRegisterNs(context, prefixI, urlI) != 0)
        return false;
    }
    return true;
  }

  void registerNamespace(SEXP nsMap) {
    if (!registerNamespace(context_, nsMap)) {
      Rf_error("Failed to register namespace");
    }
  }

  SEXP search(const char* xpath, int num_results) {
    result_ = xmlXPathEval((const xmlChar*)xpath, context_);
    if (result_ == NULL) {
      SEXP ret = PROTECT(Rf_allocVector(VECSXP, 0));
      Rf_setAttrib(ret, R_ClassSymbol, Rf_mkString("xml_missing"));
      UNPROTECT(1);
      return ret;
    }

    switch (result_->type) {
      case XPATH_NODESET:
        {
          xmlNodeSet* nodes = result_->nodesetval;
          if (nodes == NULL || nodes->nodeNr == 0) {
            SEXP ret = PROTECT(Rf_allocVector(VECSXP, 0));
            Rf_setAttrib(ret, R_ClassSymbol, Rf_mkString("xml_missing"));
            UNPROTECT(1);
            return ret;
          }
          int n = std::min(result_->nodesetval->nodeNr, num_results);

          SEXP out = PROTECT(Rf_allocVector(VECSXP, n));

          SEXP names = PROTECT(Rf_allocVector(STRSXP, 2));
          SET_STRING_ELT(names, 0, Rf_mkChar("node"));
          SET_STRING_ELT(names, 1, Rf_mkChar("doc"));

          for (int i = 0; i < n; i++) {
            SEXP ret = PROTECT(Rf_allocVector(VECSXP, 2));

            SET_VECTOR_ELT(ret, 0, XPtrNode(nodes->nodeTab[i]));
            SET_VECTOR_ELT(ret, 1, doc_);

            Rf_setAttrib(ret, R_NamesSymbol, names);
            Rf_setAttrib(ret, R_ClassSymbol, Rf_mkString("xml_node"));

            SET_VECTOR_ELT(out, i, ret);

            UNPROTECT(1);
          }

          UNPROTECT(2);
          return out;
        }
      case XPATH_NUMBER: { return Rf_ScalarReal(result_->floatval); }
      case XPATH_BOOLEAN: { return Rf_ScalarLogical(result_->boolval); }
      case XPATH_STRING: { return Rf_ScalarString(Rf_mkCharCE((char *) result_->stringval, CE_UTF8)); }
      default:
        Rf_error("XPath result type: %d not supported", result_->type);
    }

    return R_NilValue;
  }

  ~XmlSeeker() {
    try {
      xmlXPathFreeContext(context_);
      if (result_ != NULL)
        xmlXPathFreeObject(result_);
    } catch (...) {}
  }

};

// [[export]]
extern "C" SEXP xpath_search(SEXP node_sxp, SEXP doc_sxp, SEXP xpath_sxp, SEXP nsMap_sxp, SEXP num_results_sxp) {

  XPtrNode node(node_sxp);
  XPtrDoc doc(doc_sxp);
  if (TYPEOF(xpath_sxp) != STRSXP) {
    Rf_error("XPath must be a string, received %s", Rf_type2char(TYPEOF(xpath_sxp)));
  }
  const char* xpath = CHAR(STRING_ELT(xpath_sxp, 0));

  double num_results = REAL(num_results_sxp)[0];

  if (num_results == R_PosInf) {
    num_results = INT_MAX;
  }
  XmlSeeker seeker(doc, node.checked_get());
  seeker.registerNamespace(nsMap_sxp);
  return seeker.search(xpath, num_results);
}

// [[export]]
extern "C" SEXP xpath_search_atomic(SEXP nodeset_sxp, SEXP xpath_sxp, SEXP nsMap_sxp, SEXP type_sxp) {
  if (TYPEOF(xpath_sxp) != STRSXP || Rf_xlength(xpath_sxp) == 0) {
    Rf_error("XPath must be a string");
  }
  const char* xpath = CHAR(STRING_ELT(xpath_sxp, 0));
  int target_type = INTEGER(type_sxp)[0];

  xmlXPathCompExprPtr comp = xmlXPathCompile((const xmlChar*)xpath);
  if (comp == NULL) {
    Rf_error("Invalid XPath: %s", xpath);
  }

  int n = Rf_xlength(nodeset_sxp);
  SEXP out = R_NilValue;
  switch (target_type) {
    case 1: out = PROTECT(Rf_allocVector(STRSXP, n)); break;
    case 2: out = PROTECT(Rf_allocVector(LGLSXP, n)); break;
    case 3: out = PROTECT(Rf_allocVector(REALSXP, n)); break;
    case 4: out = PROTECT(Rf_allocVector(INTSXP, n)); break;
    default:
      xmlXPathFreeCompExpr(comp);
      Rf_error("Unknown target type %d", target_type);
  }

  xmlDocPtr current_doc = NULL;
  xmlXPathContextPtr context = NULL;

  for (int i = 0; i < n; ++i) {
    SEXP x_i = VECTOR_ELT(nodeset_sxp, i);
    if (TYPEOF(x_i) != VECSXP || Rf_xlength(x_i) < 2) {
      if (context != NULL) xmlXPathFreeContext(context);
      xmlXPathFreeCompExpr(comp);
      UNPROTECT(1);
      Rf_error("nodeset element %d is not a valid xml_node", i + 1);
    }
    SEXP node_sxp = VECTOR_ELT(x_i, 0);
    SEXP doc_sxp = VECTOR_ELT(x_i, 1);

    if (TYPEOF(node_sxp) != EXTPTRSXP || TYPEOF(doc_sxp) != EXTPTRSXP) {
      if (context != NULL) xmlXPathFreeContext(context);
      xmlXPathFreeCompExpr(comp);
      UNPROTECT(1);
      Rf_error("nodeset element %d has invalid external pointer", i + 1);
    }

    xmlNodePtr node = (xmlNodePtr) R_ExternalPtrAddr(node_sxp);
    xmlDocPtr doc = (xmlDocPtr) R_ExternalPtrAddr(doc_sxp);
    if (node == NULL || doc == NULL) {
      if (context != NULL) xmlXPathFreeContext(context);
      xmlXPathFreeCompExpr(comp);
      UNPROTECT(1);
      Rf_error("external pointer is not valid");
    }

    if (doc != current_doc || context == NULL) {
      if (context != NULL) {
        xmlXPathFreeContext(context);
      }
      current_doc = doc;
      context = xmlXPathNewContext(current_doc);
      if (context == NULL) {
        xmlXPathFreeCompExpr(comp);
        UNPROTECT(1);
        Rf_error("Failed to create XPath context");
      }
      if (!XmlSeeker::registerNamespace(context, nsMap_sxp)) {
        xmlXPathFreeContext(context);
        xmlXPathFreeCompExpr(comp);
        UNPROTECT(1);
        Rf_error("Failed to register namespace");
      }
    }
    context->node = node;

    xmlXPathObjectPtr res = xmlXPathCompiledEval(comp, context);
    if (res == NULL) {
      if (context != NULL) xmlXPathFreeContext(context);
      xmlXPathFreeCompExpr(comp);
      UNPROTECT(1);
      Rf_error("Evaluation of XPath `%s` failed on node %d", xpath, i + 1);
    }

    switch (target_type) {
      case 1: // CHR
        if (res->type == XPATH_STRING) {
          SET_STRING_ELT(out, i, Rf_mkCharCE((char*)res->stringval, CE_UTF8));
        } else {
          int type = res->type;
          xmlXPathFreeObject(res);
          if (context != NULL) xmlXPathFreeContext(context);
          xmlXPathFreeCompExpr(comp);
          UNPROTECT(1);
          Rf_error("Result of XPath `%s` is not a string (type: %d)", xpath, type);
        }
        break;
      case 2: // LGL
        if (res->type == XPATH_BOOLEAN) {
          LOGICAL(out)[i] = res->boolval ? 1 : 0;
        } else {
          int type = res->type;
          xmlXPathFreeObject(res);
          if (context != NULL) xmlXPathFreeContext(context);
          xmlXPathFreeCompExpr(comp);
          UNPROTECT(1);
          Rf_error("Result of XPath `%s` is not a logical (type: %d)", xpath, type);
        }
        break;
      case 3: // NUM
        if (res->type == XPATH_NUMBER) {
          REAL(out)[i] = res->floatval;
        } else {
          int type = res->type;
          xmlXPathFreeObject(res);
          if (context != NULL) xmlXPathFreeContext(context);
          xmlXPathFreeCompExpr(comp);
          UNPROTECT(1);
          Rf_error("Result of XPath `%s` is not a number (type: %d)", xpath, type);
        }
        break;
      case 4: // INT
        if (res->type == XPATH_NUMBER) {
          double val = res->floatval;
          if (std::isnan(val) || val == std::floor(val)) {
            INTEGER(out)[i] = (int)val;
          } else {
            xmlXPathFreeObject(res);
            if (context != NULL) xmlXPathFreeContext(context);
            xmlXPathFreeCompExpr(comp);
            UNPROTECT(1);
            Rf_error("Result of XPath `%s` is not an integer", xpath);
          }
        } else {
          int type = res->type;
          xmlXPathFreeObject(res);
          if (context != NULL) xmlXPathFreeContext(context);
          xmlXPathFreeCompExpr(comp);
          UNPROTECT(1);
          Rf_error("Result of XPath `%s` is not a whole number (type: %d)", xpath, type);
        }
        break;
    }
    xmlXPathFreeObject(res);
  }

  if (context != NULL) {
    xmlXPathFreeContext(context);
  }
  xmlXPathFreeCompExpr(comp);
  UNPROTECT(1); // out

  return out;
}
