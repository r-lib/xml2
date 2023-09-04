#include <cpp11.hpp>

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/parser.h>
#include <libxml/HTMLparser.h>
#include "xml2_types.h"
#include "xml2_utils.h"
#include <cstring>
#include <vector>

[[cpp11::register]]
cpp11::sexp  xml_parse_options_() {

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

  std::vector<std::string> names = {
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

  std::vector<int> values = {
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

  std::vector<std::string> descriptions = {
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

  cpp11::writable::integers out_values(values);

  out_values.names() = names;
  out_values.attr("descriptions") = descriptions;

  return out_values;

#undef HAS_OLD10
#undef HAS_NOBASEFIX
#undef HAS_HUGE
#undef HAS_OLDSAX
#undef HAS_BIG_LINES
#undef HAS_IGNORE_ENC
}

[[cpp11::register]]
cpp11::sexp doc_parse_file(
    cpp11::strings path_sxp,
    cpp11::strings encoding_sxp,
    cpp11::logicals as_html_sxp,
    cpp11::integers options_sxp) {
  const char* path = cpp11::as_cpp<const char*>(path_sxp);
  const char* encoding = cpp11::as_cpp<const char*>(encoding_sxp);
  bool as_html = cpp11::as_cpp<bool>(as_html_sxp);
  int options = cpp11::as_cpp<int>(options_sxp);
  xmlDoc* pDoc;
  if (as_html) {
    pDoc = htmlReadFile(
      path,
      encoding[0] == '\0' ? NULL : encoding,
      options
    );
  } else {
    pDoc = xmlReadFile(
      path,
      encoding[0] == '\0' ? NULL : encoding,
      options
    );
  }

  if (pDoc == NULL) {
    cpp11::stop("Failed to parse %s", path);
  }

  return SEXP(XPtrDoc(pDoc));
}

[[cpp11::register]]
cpp11::sexp doc_parse_raw(
    cpp11::raws x,
    cpp11::strings encoding_sxp,
    cpp11::strings base_url_sxp,
    cpp11::logicals as_html_sxp,
    cpp11::integers options_sxp) {
  std::string encoding = cpp11::as_cpp<const char*>(encoding_sxp);
  std::string base_url = cpp11::as_cpp<const char*>(base_url_sxp);
  bool as_html = cpp11::as_cpp<bool>(as_html_sxp);
  int options = cpp11::as_cpp<int>(options_sxp);

  xmlDoc* pDoc;
  if (as_html) {
    pDoc = htmlReadMemory(
      (const char *) RAW(x),
      x.size(),
      base_url == "" ? NULL : base_url.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      options
    );
  } else {
    pDoc = xmlReadMemory(
      (const char *) RAW(x),
      x.size(),
      base_url == "" ? NULL : base_url.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      options
    );
  }

  if (pDoc == NULL) {
    cpp11::stop("Failed to parse text");
  }

  return SEXP(XPtrDoc(pDoc));
}

[[cpp11::register]]
cpp11::sexp doc_root(cpp11::sexp x) {
  XPtrDoc doc(x);
  XPtrNode node(xmlDocGetRootElement(doc.checked_get()));
  return SEXP(node);
}

[[cpp11::register]]
cpp11::logicals doc_has_root(cpp11::sexp x_sxp) {
  XPtrDoc x(x_sxp);
  return cpp11::logicals({xmlDocGetRootElement(x.get()) != NULL});
}

[[cpp11::register]]
cpp11::strings doc_url(cpp11::sexp doc_sxp) {
  XPtrDoc doc(doc_sxp);
  if (doc->URL == NULL) {
    return cpp11::writable::strings({NA_STRING});
  }

  return cpp11::as_sexp((const char*) doc->URL);
}

[[cpp11::register]]
cpp11::sexp doc_new(cpp11::sexp version_sxp, cpp11::strings encoding_sxp) {
  const char* encoding = cpp11::as_cpp<const char*>(encoding_sxp);

  XPtrDoc x(xmlNewDoc(asXmlChar(version_sxp)));
  xmlCharEncodingHandlerPtr p = xmlFindCharEncodingHandler(encoding);
  x->encoding = xmlStrdup(reinterpret_cast<const xmlChar *>(p->name));
  return SEXP(x);
}

[[cpp11::register]]
cpp11::sexp doc_set_root(cpp11::sexp doc_sxp, cpp11::sexp root_sxp) {
  XPtrDoc doc(doc_sxp);
  XPtrNode root(root_sxp);
  XPtrNode out(xmlDocSetRootElement(doc, root));
  return SEXP(out);
}

[[cpp11::register]]
cpp11::sexp doc_is_html(cpp11::sexp doc_sxp) {
  XPtrDoc doc(doc_sxp);
  return cpp11::logicals({doc->properties & XML_DOC_HTML});
}
