#include <Rcpp.h>
using namespace Rcpp;
#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
XPtr<xmlDoc> parse_xml_file(std::string path,
                            std::string encoding = "",
                            int options = 0) {
  xmlDoc* pDoc = xmlReadFile(
    path.c_str(),
    encoding == "" ? NULL : encoding.c_str(),
    options
  );
  if (pDoc == NULL)
    Rcpp::stop("Failed to parse %s", path);

  return XPtr<xmlDoc>(pDoc, &xmlFreeDoc);
}

// [[Rcpp::export]]
XPtr<xmlDoc> parse_xml_string(CharacterVector x, std::string encoding,
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

  return XPtr<xmlDoc>(pDoc, &xmlFreeDoc);
}

// [[Rcpp::export]]
CharacterVector xml_doc_format(XPtr<xmlDoc> x) {
  xmlChar *s;
  xmlDocDumpMemory(x.get(), &s, NULL);

  Rcpp::CharacterVector out = xmlCharToRChar(s);
  xmlFree(s);

  return out;
}
