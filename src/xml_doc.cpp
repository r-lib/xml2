#include <Rcpp.h>
using namespace Rcpp;
#include "XmlDoc.h"

// [[Rcpp::export]]
XPtr<Xml2DocumentPtr> parse_xml_file(std::string path,
                                     std::string encoding = "",
                                     int options = 0) {
  xmlDoc* pDoc = xmlReadFile(
    path.c_str(),
    encoding == "" ? NULL : encoding.c_str(),
    options
  );
  if (pDoc == NULL)
    Rcpp::stop("Failed to parse %s", path);

  Xml2DocumentPtr* pDoc2_ = new Xml2DocumentPtr(pDoc, xmlFreeDoc);
  return XPtr<Xml2DocumentPtr>(pDoc2_, true);
}

// [[Rcpp::export]]
XPtr<Xml2DocumentPtr> parse_xml_string(CharacterVector x, std::string encoding,
                                       std::string base_url = "",
                                       int options = 0) {

  SEXP x1 = x[0];

  xmlDoc* pDoc = xmlReadMemory(
    CHAR(x1),
    Rf_length(x1),
    base_url == "" ? NULL : base_url.c_str(),
    encoding == "" ? NULL : encoding.c_str(),
    options
  );
  if (pDoc == NULL)
    Rcpp::stop("Failed to parse text");

  Xml2DocumentPtr* pDoc2_ = new Xml2DocumentPtr(pDoc, xmlFreeDoc);
  return XPtr<Xml2DocumentPtr>(pDoc2_, true);
}

// [[Rcpp::export]]
CharacterVector xml_doc_format(XPtr<Xml2DocumentPtr> x) {
  xmlChar *s;
  xmlDocDumpMemory(x.get()->get(), &s, NULL);

  Rcpp::CharacterVector out = xmlCharToRChar(s);
  xmlFree(s);

  return out;
}
