#include <Rcpp.h>
#include <libxml/tree.h>

using namespace Rcpp;
#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
CharacterVector unique_ns(CharacterVector ns) {
  return NsMap(ns).out();
}

void cache_namespace(xmlNode* node, NsMap* nsMap) {
  // Iterate over namespace definitions
  for(xmlNs* cur = node->nsDef; cur != NULL; cur = cur->next) {
    nsMap->add(cur->prefix, cur->href);
  }


  // Iterate over children, calling this function recursively
  for(xmlNode* cur = node->children; cur != NULL; cur = cur->next)
    cache_namespace(cur, nsMap);
}

// [[Rcpp::export]]
CharacterVector doc_namespaces(XPtrDoc doc) {
  NsMap nsMap;

  xmlNode* root = xmlDocGetRootElement(doc.get());
  cache_namespace(root, &nsMap);

  return nsMap.out();
}
