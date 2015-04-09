#include <Rcpp.h>
using namespace Rcpp;

#include <libxml/parser.h>
#include <libxml/HTMLparser.h>
#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
XPtrDoc doc_parse_file(std::string path,
                            std::string encoding = "",
                            int options = 0,
                            bool html = false) {
  xmlDoc* pDoc;
  if (html) {
    pDoc = htmlReadFile(
      path.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      options
    );
  } else {
    pDoc = xmlReadFile(
      path.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      options
    );
  }

  if (pDoc == NULL)
    Rcpp::stop("Failed to parse %s", path);

  return XPtrDoc(pDoc);
}

// [[Rcpp::export]]
XPtrDoc doc_parse_string(CharacterVector x, std::string encoding,
                              std::string base_url = "",
                              int options = 0,
                              bool html = false) {
  SEXP x1 = x[0];

  xmlDoc* pDoc;
  if (html) {
    pDoc = htmlReadMemory(
      CHAR(x1),
      Rf_length(x1),
      base_url == "" ? NULL : base_url.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      options
    );
  } else {
   pDoc = xmlReadMemory(
      CHAR(x1),
      Rf_length(x1),
      base_url == "" ? NULL : base_url.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      options
    );
  }

  if (pDoc == NULL)
    Rcpp::stop("Failed to parse text");

  return XPtrDoc(pDoc);
}

// [[Rcpp::export]]
XPtrDoc doc_parse_raw(RawVector x, std::string encoding,
                      std::string base_url = "",
                      int options = 0,
                      bool html = false) {
  xmlDoc* pDoc;
  if (html) {
    pDoc = htmlReadMemory(
      (const char *) RAW(x),
      Rf_length(x),
      base_url == "" ? NULL : base_url.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      options
    );
  } else {
    pDoc = xmlReadMemory(
      (const char *) RAW(x),
      Rf_length(x),
      base_url == "" ? NULL : base_url.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      options
    );
  }


  if (pDoc == NULL)
    Rcpp::stop("Failed to parse text");

  return XPtrDoc(pDoc);
}

// [[Rcpp::export]]
std::string doc_format(XPtrDoc x) {
  xmlChar *s;
  xmlDocDumpMemory(x.get(), &s, NULL);

  return Xml2String(s).asStdString();
}

// [[Rcpp::export]]
void doc_write(XPtrDoc x, std::string path) {
  FILE* f = fopen(path.c_str(), "wb");

  int res = xmlDocDump(f, x.get());
  fclose(f);

  if (res == -1) {
    Rcpp::stop("Failed to write to %s", path);
  }
}

// [[Rcpp::export]]
XPtrNode doc_root(XPtrDoc x) {
  return XPtrNode(xmlDocGetRootElement(x.get()));
}

// [[Rcpp::export]]
CharacterVector doc_url(XPtrDoc x) {
  SEXP string = (x->URL == NULL) ? NA_STRING : Rf_mkCharCE((const char*) x->URL, CE_UTF8);
  return CharacterVector(string);
}
