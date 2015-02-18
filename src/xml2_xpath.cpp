#include <Rcpp.h>
#include <libxml/xpath.h>
#include <libxml/tree.h>
#include "xml2_types.h"
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::List node_search(XPtrNode node, XPtrDoc doc, std::string xpath) {
  xmlXPathContextPtr context = xmlXPathNewContext(doc.get());
  xmlXPathObjectPtr result = xmlXPathNodeEval(
    node.get(),
    (xmlChar*) xpath.c_str(),
    context
  );
  xmlXPathFreeContext(context);

  if (result->type != XPATH_NODESET) {
    xmlXPathFreeObject(result);
    Rcpp::stop("Currently only nodeset results are supported");
  }

  // Return an empty list if there are no matches
  xmlNodeSetPtr nodes = result->nodesetval;
  if (xmlXPathNodeSetIsEmpty(nodes)) {
    xmlXPathFreeObject(result);
    return Rcpp::List::create();
  }

  int n = nodes->nodeNr;
  List out(n);
  for (int i = 0; i < nodes->nodeNr; i++) {
    out[i] = XPtrNode(nodes->nodeTab[i]);
  }
  xmlXPathFreeObject(result);


  return out;
}
