#include <Rcpp.h>
using namespace Rcpp;

#include <libxml/parser.h>
#include <libxml/HTMLparser.h>
#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
XPtrDoc doc_parse_file(std::string path,
                            std::string encoding = "",
                            bool as_html = false) {
  xmlDoc* pDoc;
  if (as_html) {
    pDoc = htmlReadFile(
      path.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | XML_PARSE_HUGE
    );
  } else {
    pDoc = xmlReadFile(
      path.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      0
    );
  }

  if (pDoc == NULL)
    Rcpp::stop("Failed to parse %s", path);

  return XPtrDoc(pDoc);
}

// [[Rcpp::export]]
XPtrDoc doc_parse_raw(RawVector x, std::string encoding,
                      std::string base_url = "",
                      bool as_html = false) {
  xmlDoc* pDoc;
  if (as_html) {
    pDoc = htmlReadMemory(
      (const char *) RAW(x),
      Rf_length(x),
      base_url == "" ? NULL : base_url.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      HTML_PARSE_RECOVER | HTML_PARSE_NOERROR
    );
  } else {
    pDoc = xmlReadMemory(
      (const char *) RAW(x),
      Rf_length(x),
      base_url == "" ? NULL : base_url.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      0
    );
  }

  if (pDoc == NULL)
    Rcpp::stop("Failed to parse text");

  return XPtrDoc(pDoc);
}

// [[Rcpp::export]]
CharacterVector doc_format(XPtrDoc x) {
  xmlChar *s;
  xmlDocDumpMemory(x.get(), &s, NULL);

  return Xml2String(s).asRString();
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
