#include <Rcpp.h>
#include <libxml/tree.h>

using namespace Rcpp;
#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
CharacterVector unique_ns(CharacterVector ns) {
  CharacterVector prefix = as<CharacterVector>(ns.attr("names"));

  NsMap nsMap(1);
  for (int i = 0; i < prefix.size(); ++i)
    nsMap.add(prefix[i], ns[i]);

  return nsMap.out();
}

void cache_namespace(xmlNode* node, NsMap* nsMap) {
  // Iterate over namespace definitions
  for(xmlNs* cur = node->nsDef; cur != NULL; cur = cur->next) {
    nsMap->add(Xml2Char(cur->prefix), Xml2Char(cur->href));
  }

  // Iterate over children, calling this function recursively
  for(xmlNode* cur = node->children; cur != NULL; cur = cur->next) {
    cache_namespace(cur, nsMap);
  }
}

// [[Rcpp::export]]
CharacterVector doc_namespaces(XPtrDoc doc) {
  NsMap nsMap;

  xmlNode* root = xmlDocGetRootElement(doc.get());
  cache_namespace(root, &nsMap);

  return nsMap.out();
}
