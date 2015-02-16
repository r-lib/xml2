#include <Rcpp.h>
using namespace Rcpp;
#include "XmlDoc.h"

// [[Rcpp::export]]
XPtr<XmlDocPtr> parse_xml_file(std::string path, std::string encoding = "",
                                     int options = 0) {
  XmlDocPtr* pConn = new XmlDocPtr(
    new XmlDoc(path, encoding, options)
  );
  return XPtr<XmlDocPtr>(pConn, true);
}

// [[Rcpp::export]]
XPtr<XmlDocPtr> parse_xml_string(CharacterVector x, std::string encoding,
                                 std::string base_url = "", int options = 0) {
  SEXP x1 = x[0];

  XmlDocPtr* pConn = new XmlDocPtr(
    new XmlDoc(CHAR(x1), Rf_length(x1), base_url, encoding, options)
  );
  return XPtr<XmlDocPtr>(pConn, true);
}

// [[Rcpp::export]]
CharacterVector xml_doc_format(XPtr<XmlDocPtr> x) {
  return (*x)->format();
}
