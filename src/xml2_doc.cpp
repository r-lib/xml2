#include <Rcpp.h>
using namespace Rcpp;

#include <libxml/parser.h>
#include <libxml/HTMLparser.h>
#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
XPtrDoc doc_parse_file(std::string path,
                            std::string encoding = "",
                            bool as_html = false,
                            int options = 0) {
  xmlDoc* pDoc;
  if (as_html) {
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
XPtrDoc doc_parse_raw(RawVector x, std::string encoding,
                      std::string base_url = "",
                      bool as_html = false,
                      int options = 0) {
  xmlDoc* pDoc;
  if (as_html) {
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
CharacterVector doc_format(XPtrDoc x) {
  xmlChar *s;
  xmlDocDumpMemory(x.checked_get(), &s, NULL);

  return Xml2String(s).asRString();
}

// [[Rcpp::export]]
void doc_write(XPtrDoc x, std::string path, bool format) {
  FILE* f = fopen(R_ExpandFileName(path.c_str()), "wb");

  int res = xmlDocFormatDump(f, x.checked_get(), format ? 1 : 0);
  fclose(f);

  if (res == -1) {
    Rcpp::stop("Failed to write to %s", path);
  }
}

// [[Rcpp::export]]
XPtrNode doc_root(XPtrDoc x) {
  return XPtrNode(xmlDocGetRootElement(x.checked_get()));
}

// [[Rcpp::export]]
bool doc_has_root(XPtrDoc x) {
  return xmlDocGetRootElement(x.get()) != NULL;
}

// [[Rcpp::export]]
CharacterVector doc_url(XPtrDoc x) {
  SEXP string = (x->URL == NULL) ? NA_STRING : Rf_mkCharCE((const char*) x->URL, CE_UTF8);
  return CharacterVector(string);
}

// [[Rcpp::export]]
XPtrDoc doc_new(std::string version) {
  return XPtrDoc(xmlNewDoc(asXmlChar(version)));
}

// [[Rcpp::export]]
XPtrNode doc_set_root(XPtrDoc doc, XPtrNode root) {
  return XPtrNode(xmlDocSetRootElement(doc, root));
}
