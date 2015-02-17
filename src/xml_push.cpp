#include <Rcpp.h>
using namespace Rcpp;
#include "XmlPushParser.h"
#include "XmlDoc.h"

// [[Rcpp::export]]
XPtr<XmlPushParserPtr> new_push_parser(std::string filename) {
  XmlPushParserPtr* ctxt = new XmlPushParserPtr(
    new XmlPushParser(filename)
  );
  return XPtr<XmlPushParserPtr>(ctxt, true);
}

// [[Rcpp::export]]
bool feed_push_parser_text(XPtr<XmlPushParserPtr> x, const char* text, int size) {
  return (*x)->feed(text, size);
}

// [[Rcpp::export]]
bool feed_push_parser_raw(XPtr<XmlPushParserPtr> x, SEXP data) {
  return (*x)->feed(data);
}

// [[Rcpp::export]]
bool close_push_parser(XPtr<XmlPushParserPtr> x) {
  return (*x)->done();
}

// [[Rcpp::export]]
XPtr<XmlDocPtr> get_push_parser_doc(XPtr<XmlPushParserPtr> x) {
  XmlDocPtr* pConn = new XmlDocPtr(
    new XmlDoc((*x)->doc())
  );
  return XPtr<XmlDocPtr>(pConn, true);
}
