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
  //for(xmlNode* cur = node->children; cur != NULL; cur = cur->next)
  for(xmlNode* cur = node->children; cur != NULL && cur->type != XML_ENTITY_DECL; cur = cur->next)
    cache_namespace(cur, nsMap);
}

// [[Rcpp::export]]
CharacterVector doc_namespaces(XPtrDoc doc) {
  NsMap nsMap;

  xmlNode* root = xmlDocGetRootElement(doc.checked_get());
  cache_namespace(root, &nsMap);

  return nsMap.out();
}

// [[Rcpp::export]]
XPtrNs ns_lookup_uri(XPtrDoc doc, XPtrNode node, std::string uri) {
  xmlNsPtr ns = xmlSearchNsByHref(doc.checked_get(), node.checked_get(), asXmlChar(uri));
  if (ns == NULL) {
    stop("No namespace with URI `%s` found", uri);
  }
  return XPtrNs(ns);
}

// [[Rcpp::export]]
XPtrNs ns_lookup(XPtrDoc doc, XPtrNode node, std::string prefix) {
  xmlNsPtr ns = NULL;
  if (prefix.length() == 0) {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), NULL);
  } else {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), asXmlChar(prefix));
    if (ns == NULL) {
      stop("No namespace with prefix `%s` found", prefix);
    }
  }
  return XPtrNs(ns);
}
