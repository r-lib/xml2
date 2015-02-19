#include <Rcpp.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <libxml/tree.h>
#include "xml2_types.h"
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::List node_find(XPtrNode node, XPtrDoc doc, std::string xpath, CharacterVector nsMap) {
  boost::shared_ptr<xmlXPathContext> context(
      xmlXPathNewContext(doc.get()),
      xmlXPathFreeContext
  );

  // Set context to current node
  context->node = node.get();

  // Register namespacese
  if (nsMap.size() > 0) {
    CharacterVector prefix = as<CharacterVector>(nsMap.attr("names"));

    for (int i = 0; i < nsMap.size(); ++i) {
      xmlChar* prefixI = (xmlChar*) CHAR(STRING_ELT(prefix, i));
      xmlChar* urlI = (xmlChar*) CHAR(STRING_ELT(nsMap, i));

      if (xmlXPathRegisterNs(context.get(), prefixI, urlI) != 0)
        stop("Failed to register namespace (%s <-> %s)", prefixI, urlI);
    }
  }

  boost::shared_ptr<xmlXPathObject> result(
    xmlXPathEval((xmlChar*) xpath.c_str(), context.get()),
    xmlXPathFreeObject
  );
  if (result.get() == NULL)
    Rcpp::stop("Xpath failed to execute");

  if (result->type != XPATH_NODESET)
    Rcpp::stop("Currently only nodeset results are supported");

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
