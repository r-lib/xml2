#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/uri.h>
#include "xml2_utils.h"

// [[export]]
extern "C" SEXP url_absolute_(SEXP x_sxp, SEXP base_sxp) {
  R_xlen_t n = Rf_xlength(x_sxp);
  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  if (Rf_xlength(base_sxp) > 1) {
    Rf_error("Base URL must be length 1");
  }

  const xmlChar* base_uri = (xmlChar*) Rf_translateCharUTF8(STRING_ELT(base_sxp, 0));

  for (int i = 0; i < n; ++i) {
    const xmlChar* uri = (xmlChar*) Rf_translateCharUTF8(STRING_ELT(x_sxp, i));
    SET_STRING_ELT(out, i, Xml2String(xmlBuildURI(uri, base_uri)).asRString());
  }

  UNPROTECT(1);
  return out;
}

// [[export]]
extern "C" SEXP url_relative_(SEXP x_sxp, SEXP base_sxp) {
  R_xlen_t n = Rf_xlength(x_sxp);
  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  if (Rf_xlength(base_sxp) > 1) {
    Rf_error("Base URL must be length 1");
  }

  const xmlChar* base_uri = (xmlChar*) Rf_translateCharUTF8(STRING_ELT(base_sxp, 0));

  for (int i = 0; i < n; ++i) {
    const xmlChar* uri = (xmlChar*) Rf_translateCharUTF8(STRING_ELT(x_sxp, i));
    SET_STRING_ELT(out, i, Xml2String(xmlBuildRelativeURI(uri, base_uri)).asRString());
  }

  UNPROTECT(1);
  return out;
}

// [[export]]
extern "C" SEXP url_parse_(SEXP x_sxp) {
  R_xlen_t n = Rf_xlength(x_sxp);

  SEXP scheme = PROTECT(Rf_allocVector(STRSXP, n));
  SEXP server = PROTECT(Rf_allocVector(STRSXP, n));
  SEXP user = PROTECT(Rf_allocVector(STRSXP, n));
  SEXP path = PROTECT(Rf_allocVector(STRSXP, n));
  SEXP query = PROTECT(Rf_allocVector(STRSXP, n));
  SEXP fragment = PROTECT(Rf_allocVector(STRSXP, n));

  SEXP port = PROTECT(Rf_allocVector(INTSXP, n));

  for (int i = 0; i < n; ++i) {
    const char* raw = Rf_translateCharUTF8(STRING_ELT(x_sxp, i));
    xmlURI* uri = xmlParseURI(raw);
    if (uri == NULL) {
      continue;
    }

    SET_STRING_ELT(scheme, i, Rf_mkChar(uri->scheme == NULL ? "" : uri->scheme));
    SET_STRING_ELT(server, i, Rf_mkChar(uri->server == NULL ? "" : uri->server));
    INTEGER(port)[i] = uri->port == 0 ? NA_INTEGER : uri->port;
    SET_STRING_ELT(user, i, Rf_mkChar(uri->user == NULL ? "" : uri->user));
    SET_STRING_ELT(path, i, Rf_mkChar(uri->path  == NULL ? "" : uri->path));
    SET_STRING_ELT(fragment, i, Rf_mkChar(uri->fragment == NULL ? "" : uri->fragment));

    /* * *
     * Thu Apr 26 10:36:26 CEST 2007 Daniel Veillard
     * svn path=/trunk/; revision=3607
     * https://github.com/GNOME/libxml2/commit/a1413b84f7163d57c6251d5f4251186368efd859
     */
    #if defined(LIBXML_VERSION) && (LIBXML_VERSION >= 20629)
    SET_STRING_ELT(query, i, Rf_mkChar(uri->query_raw  == NULL ? "" : uri->query_raw));
    #else
    SET_STRING_ELT(query, i, Rf_mkChar(uri->query  == NULL ? "" : uri->query));
    #endif

    xmlFreeURI(uri);
  }

  SEXP out = PROTECT(Rf_allocVector(VECSXP, 7));
  SET_VECTOR_ELT(out, 0, scheme);
  SET_VECTOR_ELT(out, 1, server);
  SET_VECTOR_ELT(out, 2, port);
  SET_VECTOR_ELT(out, 3, user);
  SET_VECTOR_ELT(out, 4, path);
  SET_VECTOR_ELT(out, 5, query);
  SET_VECTOR_ELT(out, 6, fragment);

  SEXP names = PROTECT(Rf_allocVector(STRSXP, 7));

  SET_STRING_ELT(names, 0, Rf_mkChar("scheme"));
  SET_STRING_ELT(names, 1, Rf_mkChar("server"));
  SET_STRING_ELT(names, 2, Rf_mkChar("port"));
  SET_STRING_ELT(names, 3, Rf_mkChar("user"));
  SET_STRING_ELT(names, 4, Rf_mkChar("path"));
  SET_STRING_ELT(names, 5, Rf_mkChar("query"));
  SET_STRING_ELT(names, 6, Rf_mkChar("fragment"));

  Rf_setAttrib(out, R_ClassSymbol, Rf_mkString("data.frame"));
  Rf_setAttrib(out, R_NamesSymbol, names);

  SEXP row_names = PROTECT(Rf_allocVector(INTSXP, 2));
  INTEGER(row_names)[0] = NA_INTEGER;
  INTEGER(row_names)[1] = -n;
  Rf_setAttrib(out, R_RowNamesSymbol, row_names);

  UNPROTECT(10);

  return out;
}

// [[export]]
extern "C" SEXP url_escape_(SEXP x_sxp, SEXP reserved_sxp) {
  R_xlen_t n = Rf_xlength(x_sxp);
  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  if (Rf_xlength(reserved_sxp) != 1) {
    Rf_error("`reserved` must be character vector of length 1");
  }

  xmlChar* xReserved = (xmlChar*) Rf_translateCharUTF8(STRING_ELT(reserved_sxp, 0));

  for (int i = 0; i < n; ++i) {
    const xmlChar* xx = (xmlChar*) Rf_translateCharUTF8(STRING_ELT(x_sxp, i));
    SET_STRING_ELT(out, i, Xml2String(xmlURIEscapeStr(xx, xReserved)).asRString());
  }

  UNPROTECT(1);
  return out;
}

// [[export]]
extern "C" SEXP url_unescape_(SEXP x_sxp) {
  R_xlen_t n = Rf_xlength(x_sxp);
  SEXP out = PROTECT(Rf_allocVector(STRSXP, n));

  for (int i = 0; i < n; ++i) {
    const char* xx = Rf_translateCharUTF8(STRING_ELT(x_sxp, i));

    char* unescaped = xmlURIUnescapeString(xx, 0, NULL);
    SET_STRING_ELT(out, i, (unescaped == NULL) ? NA_STRING : Rf_mkCharCE(unescaped, CE_UTF8));
    xmlFree(unescaped);
  }

  UNPROTECT(1);
  return out;
}
