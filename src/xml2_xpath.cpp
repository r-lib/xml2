#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <libxml/tree.h>
#include "xml2_types.h"
#include <algorithm>

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

  void registerNamespace(SEXP nsMap) {
    R_xlen_t n = Rf_xlength(nsMap);
    if (n == 0) {
      return;
    }

    SEXP prefix = Rf_getAttrib(nsMap, R_NamesSymbol);

    for (int i = 0; i < n; ++i) {
      xmlChar* prefixI = (xmlChar*) CHAR(STRING_ELT(prefix, i));
      xmlChar* urlI = (xmlChar*) CHAR(STRING_ELT(nsMap, i));

      if (xmlXPathRegisterNs(context_, prefixI, urlI) != 0)
        Rf_error("Failed to register namespace (%s <-> %s)", prefixI, urlI);
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
