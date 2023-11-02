#include <cpp11.hpp>

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

  void registerNamespace(cpp11::strings nsMap) {
    R_xlen_t n = nsMap.size();
    if (n == 0) {
      return;
    }

    cpp11::strings prefix = nsMap.names();

    for (int i = 0; i < n; ++i) {
      xmlChar* prefixI = (xmlChar*) CHAR(prefix[i]);
      xmlChar* urlI = (xmlChar*) CHAR(nsMap[i]);

      if (xmlXPathRegisterNs(context_, prefixI, urlI) != 0)
        cpp11::stop("Failed to register namespace (%s <-> %s)", prefixI, urlI);
    }
  }

  cpp11::sexp search(const char* xpath, int num_results) {
    result_ = xmlXPathEval((const xmlChar*)xpath, context_);
    if (result_ == NULL) {
      SEXP ret = PROTECT(Rf_allocVector(VECSXP, 0));
      Rf_setAttrib(ret, R_ClassSymbol, Rf_mkString("xml_missing"));
      UNPROTECT(1);
      // TODO creating an empty list doesn't work; fails test-xml_find.R:40:3
      // cpp11::writable::list ret;
      // ret.attr("class") = "xml_missing";
      return ret;
    }

    switch (result_->type) {
      case XPATH_NODESET:
        {
          xmlNodeSet* nodes = result_->nodesetval;
          if (nodes == NULL || nodes->nodeNr == 0) {
            // TODO
            SEXP ret = PROTECT(Rf_allocVector(VECSXP, 0));
            Rf_setAttrib(ret, R_ClassSymbol, Rf_mkString("xml_missing"));
            UNPROTECT(1);
            return ret;
          }
          int n = std::min(result_->nodesetval->nodeNr, num_results);

          cpp11::writable::list out(n);

          cpp11::strings names({"node", "doc"});

          for (int i = 0; i < n; i++) {
            cpp11::writable::list ret({
              XPtrNode(nodes->nodeTab[i]),
              doc_
            });

            ret.names() = names;
            ret.attr("class") = "xml_node";

            out[i] = ret;
          }

          return out;
        }
      case XPATH_NUMBER: { return cpp11::doubles({result_->floatval}); }
      case XPATH_BOOLEAN: { return cpp11::logicals({result_->boolval}); }
      case XPATH_STRING: { return cpp11::as_sexp((const char*) result_->stringval); }
      default:
        cpp11::stop("XPath result type: %d not supported", result_->type);
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

[[cpp11::register]]
cpp11::sexp xpath_search(cpp11::sexp node_sxp, cpp11::sexp doc_sxp, cpp11::sexp xpath_sxp, cpp11::strings nsMap_sxp, cpp11::doubles num_results_sxp) {
  XPtrNode node(node_sxp);
  XPtrDoc doc(doc_sxp);
  if (TYPEOF(xpath_sxp) != STRSXP) {
    cpp11::stop("XPath must be a string, received %s", Rf_type2char(TYPEOF(xpath_sxp)));
  }
  const char* xpath = cpp11::as_cpp<const char*>(xpath_sxp);

  double num_results = num_results_sxp[0];

  if (num_results == R_PosInf) {
    num_results = INT_MAX;
  }
  XmlSeeker seeker(doc, node.checked_get());
  seeker.registerNamespace(nsMap_sxp);
  return seeker.search(xpath, num_results);
}
