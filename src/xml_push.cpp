#include <Rcpp.h>
using namespace Rcpp;

#include <libxml/parser.h>
#include "xml2_types.h"

// [[Rcpp::export]]
XPtrParser new_push_parser(std::string filename) {
  xmlParserCtxt* parser = xmlCreatePushParserCtxt(NULL, NULL, NULL, 0,
    filename.c_str());

  if (parser == NULL)
    Rcpp::stop("Failed to initialise parser");

  return XPtrParser(parser);
}

// [[Rcpp::export]]
bool feed_push_parser_text(XPtrParser parser, const char* text, int size) {
  int res = xmlParseChunk(parser.get(), text, size, 0);
  if (res)
    Rcpp::stop("XML Parsing Error: %d", res);
  return true;
}

// [[Rcpp::export]]
bool feed_push_parser_raw(XPtrParser parser, SEXP data) {
  size_t size = Rf_length(data);
  int res = xmlParseChunk(parser.get(), (const char*) RAW(data), size, 0);
  if (res)
    Rcpp::stop("XML Parsing Error: %d", res);
  return true;
}

// [[Rcpp::export]]
bool close_push_parser(XPtrParser parser) {
  int res = xmlParseChunk(parser.get(), NULL, 0, 1);
  if (res)
    Rcpp::stop("XML Parsing Error: %d", res);
  return true;
}

// [[Rcpp::export]]
XPtrDoc get_push_parser_doc(XPtrParser parser) {
  if (!parser->wellFormed)
    Rcpp::warning("XML is not well-formed.");
  return XPtrDoc(parser->myDoc);
}
