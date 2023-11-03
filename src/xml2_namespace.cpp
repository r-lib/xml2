#include <cpp11.hpp>

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/tree.h>

#include "xml2_types.h"
#include "xml2_utils.h"

[[cpp11::register]]
cpp11::sexp unique_ns(SEXP ns) {
  BEGIN_CPP
  return NsMap(ns).out();
  END_CPP
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

[[cpp11::register]]
cpp11::sexp doc_namespaces(doc_pointer doc_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);

  NsMap nsMap;

  xmlNode* root = xmlDocGetRootElement(doc.checked_get());
  cache_namespace(root, &nsMap);

  return nsMap.out();
  END_CPP
}

[[cpp11::register]]
cpp11::sexp ns_lookup_uri(doc_pointer doc_sxp, node_pointer node_sxp, cpp11::strings uri_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  XPtrNode node(node_sxp);

  xmlNsPtr ns = xmlSearchNsByHref(doc.checked_get(), node.checked_get(), asXmlChar(uri_sxp));
  if (ns == NULL) {
    Rf_error("No namespace with URI `%s` found", cpp11::as_cpp<const char*>(uri_sxp));
  }
  XPtrNs out(ns);
  return SEXP(out);
  END_CPP
}

[[cpp11::register]]
cpp11::sexp ns_lookup(doc_pointer doc_sxp, node_pointer node_sxp, cpp11::strings prefix_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  XPtrNode node(node_sxp);

  xmlNsPtr ns = NULL;
  if (prefix_sxp[0].size() == 0) {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), NULL);
  } else {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), asXmlChar(prefix_sxp));
    if (ns == NULL) {
      Rf_error("No namespace with prefix `%s` found", cpp11::as_cpp<const char*>(prefix_sxp));
    }
  }

  XPtrNs out(ns);
  return SEXP(out);
  END_CPP
}
