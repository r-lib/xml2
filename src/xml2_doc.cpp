#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/parser.h>
#include <libxml/HTMLparser.h>
#include "xml2_types.h"
#include "xml2_utils.h"
#include <cstring>

// [[export]]
extern "C" SEXP  xml_parse_options_() {

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

  SEXP out_values = PROTECT(Rf_allocVector(INTSXP, size));
  SEXP out_names = PROTECT(Rf_allocVector(STRSXP, size));
  SEXP out_descriptions = PROTECT(Rf_allocVector(STRSXP, size));

  for (size_t i = 0; i < size; ++i) {
    INTEGER(out_values)[i] = values[i];
    SET_STRING_ELT(out_names, i, Rf_mkChar(names[i]));
    SET_STRING_ELT(out_descriptions, i, Rf_mkChar(descriptions[i]));
  }

  Rf_setAttrib(out_values, R_NamesSymbol, out_names);
  Rf_setAttrib(out_values, Rf_install("descriptions"), out_descriptions);

  UNPROTECT(3);

  return out_values;

#undef HAS_OLD10
#undef HAS_NOBASEFIX
#undef HAS_HUGE
#undef HAS_OLDSAX
#undef HAS_BIG_LINES
#undef HAS_IGNORE_ENC
}

// [[export]]
extern "C" SEXP doc_parse_file(
    SEXP path_sxp,
    SEXP encoding_sxp,
    SEXP as_html_sxp,
    SEXP options_sxp) {

  const char* path = CHAR(STRING_ELT(path_sxp, 0));
  const char* encoding = CHAR(STRING_ELT(encoding_sxp, 0));
  bool as_html = LOGICAL(as_html_sxp)[0];
  int options = INTEGER(options_sxp)[0];
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
    Rf_error("Failed to parse %s", path);
  }

  return SEXP(XPtrDoc(pDoc));
}

// [[export]]
extern "C" SEXP doc_parse_raw(
    SEXP x,
    SEXP encoding_sxp,
    SEXP base_url_sxp,
    SEXP as_html_sxp,
    SEXP options_sxp) {

  BEGIN_CPP
  std::string encoding(CHAR(STRING_ELT(encoding_sxp, 0)));
  std::string base_url(CHAR(STRING_ELT(base_url_sxp, 0)));
  bool as_html = LOGICAL(as_html_sxp)[0];
  int options = INTEGER(options_sxp)[0];

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

  if (pDoc == NULL) {
    Rf_error("Failed to parse text");
  }

  return SEXP(XPtrDoc(pDoc));

  END_CPP
}

// [[export]]
extern "C" SEXP doc_root(SEXP x) {
  BEGIN_CPP
  XPtrDoc doc(x);
  XPtrNode node(xmlDocGetRootElement(doc.checked_get()));
  return SEXP(node);
  END_CPP
}

// [[export]]
extern "C" SEXP doc_has_root(SEXP x_sxp) {
  BEGIN_CPP
  XPtrDoc x(x_sxp);
  return Rf_ScalarLogical(xmlDocGetRootElement(x.get()) != NULL);
  END_CPP
}

// [[export]]
extern "C" SEXP  doc_url(SEXP doc_sxp) {
  BEGIN_CPP

  XPtrDoc doc(doc_sxp);
  if (doc->URL == NULL) {
    return Rf_ScalarString(NA_STRING);
  }

  SEXP out = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_STRING_ELT(out, 0, Rf_mkCharCE((const char*) doc->URL, CE_UTF8));
  UNPROTECT(1);

  return out;
  END_CPP
}

// [[export]]
extern "C" SEXP  doc_new(SEXP version_sxp, SEXP encoding_sxp) {

  const char* encoding = CHAR(STRING_ELT(encoding_sxp, 0));

  BEGIN_CPP
  XPtrDoc x(xmlNewDoc(asXmlChar(version_sxp)));
  xmlCharEncodingHandlerPtr p = xmlFindCharEncodingHandler(encoding);
  x->encoding = xmlStrdup(reinterpret_cast<const xmlChar *>(p->name));
  return SEXP(x);
  END_CPP
}

// [[export]]
extern "C" SEXP doc_set_root(SEXP doc_sxp, SEXP root_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  XPtrNode root(root_sxp);
  XPtrNode out(xmlDocSetRootElement(doc, root));
  return SEXP(out);
  END_CPP
}

// [[export]]
extern "C" SEXP doc_is_html(SEXP doc_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  return Rf_ScalarLogical(doc->properties & XML_DOC_HTML);
  END_CPP
}
