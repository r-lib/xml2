#ifndef __XML2_XML2_TYPES__
#define __XML2_XML2_TYPES__

#include "xml2_utils.h"
#include <libxml/tree.h>
#include <Rcpp.h>

inline void finaliseNode(xmlNodePtr node) {

  // Only unlinked nodes not part of a tree will have a NULL parent, so we free
  // them here, root nodes have their parent set to the document. Otherwise the
  // nodes will be free'd when their document is free'd.
  if (node->parent == NULL) {
    //xmlFreeNode(node);
    //node = NULL;
  }
  // do nothing
}

inline void finaliseNs(xmlNsPtr ns) {
}

typedef Rcpp::XPtr<xmlDoc,Rcpp::PreserveStorage,xmlFreeDoc> XPtrDoc;
typedef Rcpp::XPtr<xmlNode,Rcpp::PreserveStorage,finaliseNode> XPtrNode;
typedef Rcpp::XPtr<xmlNs,Rcpp::PreserveStorage,finaliseNs> XPtrNs;

#endif
