#ifndef __XML2_XML2_TYPES__
#define __XML2_XML2_TYPES__

#include "xml2_utils.h"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/HTMLparser.h>
#include <Rcpp.h>

inline void finaliseNode(xmlNode* node) {
  // do nothing
}

typedef Rcpp::XPtr<xmlDoc,Rcpp::PreserveStorage,xmlFreeDoc> XPtrDoc;
typedef Rcpp::XPtr<xmlNode,Rcpp::PreserveStorage,finaliseNode> XPtrNode;
typedef Rcpp::XPtr<xmlParserCtxt,Rcpp::PreserveStorage,xmlFreeParserCtxt> XPtrXmlParser;
typedef Rcpp::XPtr<htmlParserCtxt,Rcpp::PreserveStorage,htmlFreeParserCtxt> XPtrHtmlParser;

#endif
