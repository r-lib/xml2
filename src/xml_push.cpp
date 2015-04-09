#include <Rcpp.h>
using namespace Rcpp;

#include <libxml/parser.h>
#include "xml2_types.h"

// XML -------------------------------------------------------------------------

// [[Rcpp::export]]
XPtrXmlParser xml_push_parser_create(std::string uri) {
  xmlParserCtxt* parser = xmlCreatePushParserCtxt(NULL, NULL, NULL, 0,
    uri.c_str());

  if (parser == NULL)
    Rcpp::stop("Failed to initialise parser");

  return XPtrXmlParser(parser);
}

// [[Rcpp::export]]
bool xml_push_parser_feed(XPtrXmlParser parser, SEXP data) {
  size_t size = Rf_length(data);
  int res = xmlParseChunk(parser.get(), (const char*) RAW(data), size, 0);
  if (res)
    Rcpp::stop("XML Parsing Error: %d", res);
  return true;
}

// [[Rcpp::export]]
bool xml_push_parser_complete(XPtrXmlParser parser) {
  int res = xmlParseChunk(parser.get(), NULL, 0, 1);
  if (res)
    Rcpp::stop("XML Parsing Error: %d", res);
  return true;
}

// [[Rcpp::export]]
XPtrDoc xml_push_parser_doc(XPtrXmlParser parser) {
  if (!parser->wellFormed)
    Rcpp::warning("XML is not well-formed.");
  return XPtrDoc(parser->myDoc);
}

// HTML ------------------------------------------------------------------------

// [[Rcpp::export]]
XPtrHtmlParser html_push_parser_create(std::string uri) {
  xmlParserCtxt* parser = htmlCreatePushParserCtxt(NULL, NULL, NULL, 0,
    uri.c_str(), XML_CHAR_ENCODING_NONE);

  if (parser == NULL)
    Rcpp::stop("Failed to initialise parser");

  return XPtrHtmlParser(parser);
}

// [[Rcpp::export]]
bool html_push_parser_feed(XPtrHtmlParser parser, SEXP data) {
  htmlParseChunk(parser.get(), (const char*) RAW(data), Rf_length(data), 0);
  return true;
}

// [[Rcpp::export]]
bool html_push_parser_complete(XPtrHtmlParser parser) {
  htmlParseChunk(parser.get(), NULL, 0, 1);
  return true;
}

// [[Rcpp::export]]
XPtrDoc html_push_parser_doc(XPtrHtmlParser parser) {
  if (!parser->wellFormed)
    Rcpp::warning("HTML is not well-formed.");
  return XPtrDoc(parser->myDoc);
}
