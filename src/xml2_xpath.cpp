#include <Rcpp.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <libxml/tree.h>
#include "xml2_types.h"
using namespace Rcpp;

class XmlSeeker {
  xmlXPathContext* context_;
  xmlXPathObject* result_;
  std::string xpath_;
  XPtrDoc doc_;

public:

  XmlSeeker(XPtrDoc doc, xmlNode* node) : result_(NULL), doc_(doc) {
    context_ = xmlXPathNewContext(doc.get());
    // Set context to current node
    context_->node = node;
  }

  void registerNamespace(CharacterVector nsMap) {
    if (nsMap.size() == 0)
      return;

    CharacterVector prefix = as<CharacterVector>(nsMap.attr("names"));

    for (int i = 0; i < nsMap.size(); ++i) {
      xmlChar* prefixI = (xmlChar*) CHAR(STRING_ELT(prefix, i));
      xmlChar* urlI = (xmlChar*) CHAR(STRING_ELT(nsMap, i));

      if (xmlXPathRegisterNs(context_, prefixI, urlI) != 0)
        stop("Failed to register namespace (%s <-> %s)", prefixI, urlI);
    }
  }

  RObject search(std::string xpath, int num_results) {
    xpath_ = xpath;
    result_ = xmlXPathEval((xmlChar*) xpath.c_str(), context_);
    if (result_ == NULL) {
      List ret = List();
      ret.attr("class") = "xml_missing";
      return ret;
    }

    switch (result_->type) {
      case XPATH_NODESET:
        {
          xmlNodeSet* nodes = result_->nodesetval;
          if (nodes == NULL || nodes->nodeNr == 0) {
            List ret = List();
            ret.attr("class") = "xml_missing";
            return ret;
          }
          int n = std::min(result_->nodesetval->nodeNr, num_results);
          List out(n);
          for (int i = 0; i < n; i++) {
            List ret;
            ret["node"] = XPtrNode(nodes->nodeTab[i]);
            ret["doc"] = doc_;
            ret.attr("class") = "xml_node";
            out[i] = ret;
          }
          return out;
        }
      case XPATH_NUMBER: { return NumericVector::create(result_->floatval); }
      case XPATH_BOOLEAN: { return LogicalVector::create(result_->boolval); }
      case XPATH_STRING: { return CharacterVector::create(Rf_mkCharCE((char *) result_->stringval, CE_UTF8)); }
      default:
        stop("XPath result type: %d not supported", result_->type);
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

// [[Rcpp::export]]
RObject xpath_search(XPtrNode node, XPtrDoc doc, std::string xpath, CharacterVector nsMap, double num_results) {

  if (num_results == R_PosInf) {
    num_results = INT_MAX;
  }
  XmlSeeker seeker(doc, node.get());
  seeker.registerNamespace(nsMap);
  return seeker.search(xpath, num_results);
}
