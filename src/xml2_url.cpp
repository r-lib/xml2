#include <Rcpp.h>
using namespace Rcpp;

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

//' @export
//' @rdname url_absolute
// [[Rcpp::export]]
CharacterVector url_relative(CharacterVector x, CharacterVector base) {
  int n = x.size();
  CharacterVector out(n);

  if (base.size() > 1)
    Rcpp::stop("Base URL must be length 1");
  const xmlChar* base_uri = (xmlChar*) Rf_translateCharUTF8(base[0]);

  for (int i = 0; i < n; ++i) {
    const xmlChar* uri = (xmlChar*) Rf_translateCharUTF8(x[i]);
    out[i] = Xml2String(xmlBuildRelativeURI(uri, base_uri)).asRString();
  }

  return out;
}

//' Parse a url into its component pieces.
//'
//' @param x A character vector of urls.
//' @return A dataframe with one row for each element of \code{x} and
//'   columns: scheme, server, port, user, path, query, fragment.
//' @export
//' @examples
//' url_parse("http://had.co.nz/")
//' url_parse("http://had.co.nz:1234/")
//' url_parse("http://had.co.nz:1234/?a=1&b=2")
//' url_parse("http://had.co.nz:1234/?a=1&b=2#def")
// [[Rcpp::export]]
List url_parse(CharacterVector x) {
  int n = x.size();
  CharacterVector scheme(n), server(n), user(n), path(n), query(n), fragment(n);
  IntegerVector port(n);

  for (int i = 0; i < n; ++i) {
    const char* raw = Rf_translateCharUTF8(x[i]);
    xmlURI* uri = xmlParseURI(raw);
    if (uri == NULL)
      continue;

    scheme[i] = uri->scheme == NULL ? "" : uri->scheme;
    server[i] = uri->server == NULL ? "" : uri->server;
    port[i] = uri->port == 0 ? NA_INTEGER : uri->port;
    user[i] = uri->user == NULL ? "" : uri->user;
    path[i] = uri->path  == NULL ? "" : uri->path;
    fragment[i] = uri->fragment == NULL ? "" : uri->fragment;

    /* * *
     * Thu Apr 26 10:36:26 CEST 2007 Daniel Veillard
     * svn path=/trunk/; revision=3607
     * https://github.com/GNOME/libxml2/commit/a1413b84f7163d57c6251d5f4251186368efd859
     */
    #if defined(LIBXML_VERSION) && (LIBXML_VERSION >= 20629)
    query[i] = uri->query_raw  == NULL ? "" : uri->query_raw;
    #else
    query[i] = uri->query  == NULL ? "" : uri->query;
    #endif

    xmlFreeURI(uri);
  }

  List out = List::create(
    _["scheme"] = scheme,
    _["server"] = server,
    _["port"] = port,
    _["user"] = user,
    _["path"] = path,
    _["query"] = query,
    _["fragment"] = fragment
  );
  out.attr("class") = "data.frame";
  out.attr("row.names") = IntegerVector::create(NA_INTEGER, -n);

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

//' @export
//' @rdname url_escape
// [[Rcpp::export]]
CharacterVector url_unescape(CharacterVector x) {
  int n = x.size();
  CharacterVector out(n);

  std::string buffer;

  for (int i = 0; i < n; ++i) {
    const char* xx = Rf_translateCharUTF8(x[i]);

    char* unescaped = xmlURIUnescapeString(xx, 0, NULL);
    out[i] = (unescaped == NULL) ? NA_STRING : Rf_mkCharCE(unescaped, CE_UTF8);
    xmlFree(unescaped);
  }

  return out;
}
