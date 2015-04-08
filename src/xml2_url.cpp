#include <Rcpp.h>
using namespace Rcpp;

#include <libxml/uri.h>
#include "xml2_utils.h"

//' Convert between relative and absolute urls.
//'
//' @param x A character vector of urls relative to that base
//' @param base A string giving a base url.
//' @return A character vector of urls
//' @export
//' @examples
//' url_absolute(c(".", "..", "/", "/x"), "http://hadley.nz/a/b/c/d")
//'
//' url_relative("http://hadley.nz/a/c", "http://hadley.nz")
//' url_relative("http://hadley.nz/a/c", "http://hadley.nz/")
//' url_relative("http://hadley.nz/a/c", "http://hadley.nz/a/b")
//' url_relative("http://hadley.nz/a/c", "http://hadley.nz/a/b/")
// [[Rcpp::export]]
CharacterVector url_absolute(CharacterVector x, CharacterVector base) {
  int n = x.size();
  CharacterVector out(n);

  if (base.size() > 1)
    Rcpp::stop("Base URL must be length 1");
  const xmlChar* base_uri = (xmlChar*) Rf_translateCharUTF8(base[0]);

  for (int i = 0; i < n; ++i) {
    const xmlChar* uri = (xmlChar*) Rf_translateCharUTF8(x[i]);
    out[i] = Xml2String(xmlBuildURI(uri, base_uri));
  }

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
    out[i] = Xml2String(xmlBuildRelativeURI(uri, base_uri));
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
    query[i] = uri->query_raw  == NULL ? "" : uri->query_raw;
    fragment[i] = uri->fragment == NULL ? "" : uri->fragment;

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

