#include <Rcpp.h>
#include <libxml/xpath.h>
#include <libxml/tree.h>
#include "xml2_types.h"
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::List node_find(XPtrNode node, XPtrDoc doc, std::string xpath) {
  boost::shared_ptr<xmlXPathContext> context(
      xmlXPathNewContext(doc.get()),
      xmlXPathFreeContext
  );

  // Set context to current node
  context->node = node.get();

  boost::shared_ptr<xmlXPathObject> result(
    xmlXPathEval((xmlChar*) xpath.c_str(), context.get()),
    xmlXPathFreeObject
  );

  if (result->type != XPATH_NODESET) {
    Rcpp::stop("Currently only nodeset results are supported");
  }

  // Return an empty list if there are no matches
  xmlNodeSetPtr nodes = result->nodesetval;
  if (xmlXPathNodeSetIsEmpty(nodes)) {
    return Rcpp::List::create();
  }

  int n = nodes->nodeNr;
  List out(n);
  for (int i = 0; i < nodes->nodeNr; i++) {
    out[i] = XPtrNode(nodes->nodeTab[i]);
  }

  return out;
}
