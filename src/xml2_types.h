#ifndef __XML2_XML2_TYPES__
#define __XML2_XML2_TYPES__

#include <RcppCommon.h>
#include <libxml/parser.h>
#include "XmlPushParser.h"

inline void finaliseNode(xmlNode* node) {
  // do nothing
}

typedef Rcpp::XPtr<xmlDoc,Rcpp::PreserveStorage,xmlFreeDoc> XPtrDoc;
typedef Rcpp::XPtr<xmlNode,Rcpp::PreserveStorage,finaliseNode> XPtrNode;

#endif
