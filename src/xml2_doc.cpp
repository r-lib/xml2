#include <Rcpp.h>
using namespace Rcpp;

#include <libxml/parser.h>
#include <libxml/HTMLparser.h>
#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
Rcpp::IntegerVector xml_parse_options() {

#if defined(LIBXML_VERSION) && (LIBXML_VERSION >= 20700)
#define HAS_OLD10
#define HAS_NOBASEFIX
#define HAS_HUGE
#define HAS_OLDSAX
#endif

  /* * *
   * Author: Daniel Veillard <veillard@redhat.com>
   * Date:   Mon May 16 16:03:50 2011 +0800
   * https://github.com/GNOME/libxml2/commit/c62efc847c836d4c4f1aea08c68cd93bd342b9f4
   *
   * Add options to ignore the internal encoding
   */
#if defined(LIBXML_VERSION) && (LIBXML_VERSION >= 20800)
#define HAS_IGNORE_ENC
#endif

  /* * *
   * Author: Daniel Veillard <veillard@redhat.com>
   * Date:   Mon Aug 13 12:41:33 2012 +0800
   * https://github.com/GNOME/libxml2/commit/968a03a2e54f5bcf53089f5e3c8f790dbe0bf824
   *
   * Add support for big line numbers in error reporting
   */
#if defined(LIBXML_VERSION) && (LIBXML_VERSION >= 20900)
#define HAS_BIG_LINES
#endif

  const char * names[] = {
    "RECOVER",
    "NOENT",
    "DTDLOAD",
    "DTDATTR",
    "DTDVALID",
    "NOERROR",
    "NOWARNING",
    "PEDANTIC",
    "NOBLANKS",
    "SAX1",
    "XINCLUDE",
    "NONET",
    "NODICT",
    "NSCLEAN",
    "NOCDATA",
    "NOXINCNODE",
    "COMPACT",
#ifdef HAS_OLD10
    "OLD10",
#endif
#ifdef HAS_NOBASEFIX
    "NOBASEFIX",
#endif
#ifdef HAS_HUGE
    "HUGE",
#endif
#ifdef HAS_OLDSAX
    "OLDSAX",
#endif
#ifdef HAS_IGNORE_ENC
    "IGNORE_ENC",
#endif
#ifdef HAS_BIG_LINES
    "BIG_LINES",
#endif
  };

  const int values[] = {
    XML_PARSE_RECOVER,
    XML_PARSE_NOENT,
    XML_PARSE_DTDLOAD,
    XML_PARSE_DTDATTR,
    XML_PARSE_DTDVALID,
    XML_PARSE_NOERROR,
    XML_PARSE_NOWARNING,
    XML_PARSE_PEDANTIC,
    XML_PARSE_NOBLANKS,
    XML_PARSE_SAX1,
    XML_PARSE_XINCLUDE,
    XML_PARSE_NONET,
    XML_PARSE_NODICT,
    XML_PARSE_NSCLEAN,
    XML_PARSE_NOCDATA,
    XML_PARSE_NOXINCNODE,
    XML_PARSE_COMPACT,
#ifdef HAS_OLD10
    XML_PARSE_OLD10,
#endif
#ifdef HAS_NOBASEFIX
    XML_PARSE_NOBASEFIX,
#endif
#ifdef HAS_HUGE
    XML_PARSE_HUGE,
#endif
#ifdef HAS_OLDSAX
    XML_PARSE_OLDSAX,
#endif
#ifdef HAS_IGNORE_ENC
    XML_PARSE_IGNORE_ENC,
#endif
#ifdef HAS_BIG_LINES
    XML_PARSE_BIG_LINES,
#endif
  };

  const char * descriptions[] = {
    "recover on errors",
    "substitute entities",
    "load the external subset",
    "default DTD attributes",
    "validate with the DTD",
    "suppress error reports",
    "suppress warning reports",
    "pedantic error reporting",
    "remove blank nodes",
    "use the SAX1 interface internally",
    "Implement XInclude substitition",
    "Forbid network access",
    "Do not reuse the context dictionary",
    "remove redundant namespaces declarations",
    "merge CDATA as text nodes",
    "do not generate XINCLUDE START/END nodes",
    "compact small text nodes; no modification of the tree allowed afterwards (will possibly crash if you try to modify the tree)",
#ifdef HAS_OLD10
    "parse using XML-1.0 before update 5",
#endif
#ifdef HAS_NOBASEFIX
    "do not fixup XINCLUDE xml:base uris",
#endif
#ifdef HAS_HUGE
    "relax any hardcoded limit from the parser",
#endif
#ifdef HAS_OLDSAX
    "parse using SAX2 interface before 2.7.0",
#endif
#ifdef HAS_IGNORE_ENC
    "ignore internal document encoding hint",
#endif
#ifdef HAS_BIG_LINES
    "Store big lines numbers in text PSVI field",
#endif
  };

  size_t size = sizeof(values) / sizeof(values[0]);

  Rcpp::IntegerVector out_values = Rcpp::IntegerVector(size);
  Rcpp::CharacterVector out_names = Rcpp::CharacterVector(size);
  Rcpp::CharacterVector out_descriptions = Rcpp::CharacterVector(size);
  for (size_t i = 0; i < size; ++i) {
    out_values[i] = values[i];
    out_names[i] = names[i];
    out_descriptions[i] = descriptions[i];
  }
  out_values.attr("names") = out_names;
  out_values.attr("descriptions") = out_descriptions;

  return out_values;

#undef HAS_OLD10
#undef HAS_NOBASEFIX
#undef HAS_HUGE
#undef HAS_OLDSAX
#undef HAS_BIG_LINES
#undef HAS_IGNORE_ENC
}

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
XPtrNode doc_root(XPtrDoc x) {
  return XPtrNode(xmlDocGetRootElement(x.checked_get()));
}

// [[export]]
extern "C" SEXP doc_has_root(SEXP x_sxp) {
  XPtrDoc x(x_sxp);
  return Rf_ScalarLogical(xmlDocGetRootElement(x.get()) != NULL);
}

// [[Rcpp::export]]
CharacterVector doc_url(XPtrDoc x) {
  SEXP string = (x->URL == NULL) ? NA_STRING : Rf_mkCharCE((const char*) x->URL, CE_UTF8);
  return CharacterVector(string);
}

// [[Rcpp::export]]
XPtrDoc doc_new(std::string version, std::string encoding = "UTF-8") {
  XPtrDoc x = XPtrDoc(xmlNewDoc(asXmlChar(version)));
  xmlCharEncodingHandlerPtr p = xmlFindCharEncodingHandler(encoding.c_str());
  x->encoding = xmlStrdup(reinterpret_cast<const xmlChar *>(p->name));
  return x;
}

// [[Rcpp::export]]
XPtrNode doc_set_root(XPtrDoc doc, XPtrNode root) {
  return XPtrNode(xmlDocSetRootElement(doc, root));
}

// [[export]]
extern "C" SEXP doc_is_html(SEXP doc_sxp) {
  XPtrDoc doc(doc_sxp);
  return Rf_ScalarLogical(doc->properties & XML_DOC_HTML);
}
