#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/tree.h>

#include "xml2_types.h"
#include "xml2_utils.h"

// [[export]]
extern "C" SEXP unique_ns(SEXP ns) {
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

// [[export]]
extern "C" SEXP doc_namespaces(SEXP doc_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);

  NsMap nsMap;

  xmlNode* root = xmlDocGetRootElement(doc.checked_get());
  cache_namespace(root, &nsMap);

  return nsMap.out();
  END_CPP
}

// [[export]]
extern "C" SEXP ns_lookup_uri(SEXP doc_sxp, SEXP node_sxp, SEXP uri_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  XPtrNode node(node_sxp);

  xmlNsPtr ns = xmlSearchNsByHref(doc.checked_get(), node.checked_get(), asXmlChar(uri_sxp));
  if (ns == NULL) {
    Rf_error("No namespace with URI `%s` found", CHAR(STRING_ELT(uri_sxp, 0)));
  }
  XPtrNs out(ns);
  return SEXP(out);
  END_CPP
}

// [[export]]
extern "C" SEXP ns_lookup(SEXP doc_sxp, SEXP node_sxp, SEXP prefix_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  XPtrNode node(node_sxp);

  xmlNsPtr ns = NULL;
  if (Rf_xlength(STRING_ELT(prefix_sxp, 0)) == 0) {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), NULL);
  } else {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), asXmlChar(prefix_sxp));
    if (ns == NULL) {
      Rf_error("No namespace with prefix `%s` found", CHAR(STRING_ELT(prefix_sxp, 0)));
    }
  }

  XPtrNs out(ns);
  return SEXP(out);
  END_CPP
}
