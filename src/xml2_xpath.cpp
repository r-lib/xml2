#include <Rcpp.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <libxml/tree.h>
#include "xml2_types.h"
using namespace Rcpp;

class XmlSeeker {
  xmlXPathContext* context_;
  xmlXPathObject* result_;
  xmlNodeSet* nodes_; // Component of result, so doesn't need to be cleaned up

public:

  XmlSeeker(xmlDoc* doc, xmlNode* node) : result_(NULL) {
    context_ = xmlXPathNewContext(doc);
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

  void search(std::string xpath) {
    result_ = xmlXPathEval((xmlChar*) xpath.c_str(), context_);
    if (result_ == NULL)
      return;

    if (result_->type != XPATH_NODESET)
      Rcpp::stop("Currently only nodeset results are supported");

    nodes_ = result_->nodesetval;
  }

  int n_matches() {
    if (result_ == NULL || nodes_ == NULL)
      return 0;

    return nodes_->nodeNr;
  }

  List matches() {
    int n = n_matches();
    List out(n);

    for (int i = 0; i < n; i++) {
      out[i] = XPtrNode(nodes_->nodeTab[i]);
    }
    return out;
  }

  XPtrNode firstMatch() {
    int n = n_matches();
    if (n == 0)
      Rcpp::stop("No matches");

    if (n > 1)
      Rcpp::warning("%i matches: using first", n);

    return XPtrNode(nodes_->nodeTab[0]);
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
Rcpp::List node_find_all(XPtrNode node, XPtrDoc doc, std::string xpath, CharacterVector nsMap) {
  XmlSeeker seeker(doc.get(), node.get());
  seeker.registerNamespace(nsMap);
  seeker.search(xpath);

  if (seeker.n_matches() == 0)
    return List();

  return seeker.matches();
}

// [[Rcpp::export]]
XPtrNode node_find_one(XPtrNode node, XPtrDoc doc, std::string xpath, CharacterVector nsMap) {
  XmlSeeker seeker(doc.get(), node.get());
  seeker.registerNamespace(nsMap);
  seeker.search(xpath);

  return seeker.firstMatch();
}
