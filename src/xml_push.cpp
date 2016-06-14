#include <Rcpp.h>
using namespace Rcpp;

#include "xml2_types.h"
#include <libxml/parser.h>
#include <libxml/HTMLparser.h>

typedef Rcpp::XPtr<xmlParserCtxt,Rcpp::PreserveStorage,xmlFreeParserCtxt> XPtrXmlParser;
typedef Rcpp::XPtr<htmlParserCtxt,Rcpp::PreserveStorage,htmlFreeParserCtxt> XPtrHtmlParser;

// The push parser seems to give different results to parsing as one big
// chunk, so it's not currently used.

// xml_push_parse <- function(con, uri = "", n = 16384, verbose = FALSE) {
//   p <- xml_push_parser_create(uri);
//   if (verbose)
//     cat("Parsing...")
//
//   while (length(buf <- readBin(con, raw(), n))){
//     xml_push_parser_feed(p, buf)
//     if (verbose)
//       cat(".")
//   }
//
//   xml_push_parser_complete(p)
//   xml_document(xml_push_parser_doc(p))
// }
//
// html_push_parse <- function(con, uri = "", n = 16384, verbose = FALSE) {
//   p <- html_push_parser_create(uri);
//   if (verbose)
//     cat("Parsing...")
//
//   while (length(buf <- readBin(con, raw(), n))){
//     html_push_parser_feed(p, buf)
//     if (verbose)
//       cat(".")
//   }
//
//   html_push_parser_complete(p)
//   xml_document(html_push_parser_doc(p))
// }



// XML -------------------------------------------------------------------------

XPtrXmlParser xml_push_parser_create(std::string uri) {
  xmlParserCtxt* parser = xmlCreatePushParserCtxt(NULL, NULL, NULL, 0,
    uri.c_str());

  if (parser == NULL)
    Rcpp::stop("Failed to initialise parser");

  return XPtrXmlParser(parser);
}

bool xml_push_parser_feed(XPtrXmlParser parser, SEXP data) {
  size_t size = Rf_length(data);
  int res = xmlParseChunk(parser.checked_get(), (const char*) RAW(data), size, 0);
  if (res)
    Rcpp::stop("XML Parsing Error: %d", res);
  return true;
}

bool xml_push_parser_complete(XPtrXmlParser parser) {
  int res = xmlParseChunk(parser.checked_get(), NULL, 0, 1);
  if (res)
    Rcpp::stop("XML Parsing Error: %d", res);
  return true;
}

XPtrDoc xml_push_parser_doc(XPtrXmlParser parser) {
  if (!parser->wellFormed)
    Rcpp::warning("XML is not well-formed.");
  return XPtrDoc(parser->myDoc);
}

// HTML ------------------------------------------------------------------------

XPtrHtmlParser html_push_parser_create(std::string uri) {
  xmlParserCtxt* parser = htmlCreatePushParserCtxt(NULL, NULL, NULL, 0,
    uri.c_str(), XML_CHAR_ENCODING_NONE);

  if (parser == NULL)
    Rcpp::stop("Failed to initialise parser");

  return XPtrHtmlParser(parser);
}

bool html_push_parser_feed(XPtrHtmlParser parser, SEXP data) {
  htmlParseChunk(parser.checked_get(), (const char*) RAW(data), Rf_length(data), 0);
  return true;
}

bool html_push_parser_complete(XPtrHtmlParser parser) {
  htmlParseChunk(parser.checked_get(), NULL, 0, 1);
  return true;
}

XPtrDoc html_push_parser_doc(XPtrHtmlParser parser) {
  if (!parser->wellFormed)
    Rcpp::warning("HTML is not well-formed.");
  return XPtrDoc(parser->myDoc);
}
