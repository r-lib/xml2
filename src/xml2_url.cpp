#include <cpp11.hpp>

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/uri.h>
#include "xml2_utils.h"

const xmlChar* to_xml_chr(cpp11::strings x, const char* arg) {
  if (x.size() != 1) {
    cpp11::stop("%s must be a character vector of length 1", arg);
  }

  return (xmlChar*) cpp11::as_cpp<const char*>(x);
}

[[cpp11::register]]
cpp11::strings url_absolute_(cpp11::strings x_sxp, cpp11::strings base_sxp) {
  R_xlen_t n = x_sxp.size();
  cpp11::writable::strings out(n);

  const xmlChar* base_uri = to_xml_chr(base_sxp, "Base URL");

  for (R_xlen_t i = 0; i < n; ++i) {
    const xmlChar* uri = (xmlChar*) Rf_translateCharUTF8(x_sxp[i]);
    out[i] = Xml2String(xmlBuildURI(uri, base_uri)).asRString();
  }

  return out;
}

[[cpp11::register]]
cpp11::strings url_relative_(cpp11::strings x_sxp, cpp11::strings base_sxp) {
  R_xlen_t n = x_sxp.size();
  cpp11::writable::strings out(n);

  const xmlChar* base_uri = to_xml_chr(base_sxp, "Base URL");

  for (R_xlen_t i = 0; i < n; ++i) {
    const xmlChar* uri = (xmlChar*) Rf_translateCharUTF8(x_sxp[i]);
    out[i] = Xml2String(xmlBuildRelativeURI(uri, base_uri)).asRString();
  }

  return out;
}

[[cpp11::register]]
cpp11::data_frame url_parse_(cpp11::strings x_sxp) {
  R_xlen_t n = x_sxp.size();

  cpp11::writable::strings scheme(n);
  cpp11::writable::strings server(n);
  cpp11::writable::strings user(n);
  cpp11::writable::strings path(n);
  cpp11::writable::strings query(n);
  cpp11::writable::strings fragment(n);

  cpp11::writable::integers port(n);

  for (R_xlen_t i = 0; i < n; ++i) {
    const char* raw = Rf_translateCharUTF8(x_sxp[i]);
    xmlURI* uri = xmlParseURI(raw);
    if (uri == NULL) {
      continue;
    }

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

  using namespace cpp11::literals;

  cpp11::writable::data_frame out({
    "scheme"_nm = scheme,
    "server"_nm = server,
    "port"_nm = port,
    "user"_nm = user,
    "path"_nm = path,
    "query"_nm = query,
    "fragment"_nm = fragment,
  });

  return out;
}

[[cpp11::register]]
cpp11::strings url_escape_(cpp11::strings x_sxp, cpp11::strings reserved_sxp) {
  R_xlen_t n = x_sxp.size();
  cpp11::writable::strings out(n);

  const xmlChar* xReserved = to_xml_chr(reserved_sxp, "`reserved`");

  for (R_xlen_t i = 0; i < n; ++i) {
    const xmlChar* xx = (xmlChar*) Rf_translateCharUTF8(x_sxp[i]);
    out[i] = Xml2String(xmlURIEscapeStr(xx, xReserved)).asRString();
  }

  return out;
}

[[cpp11::register]]
cpp11::strings url_unescape_(cpp11::strings x_sxp) {
  R_xlen_t n = x_sxp.size();
  cpp11::writable::strings out(n);

  for (R_xlen_t i = 0; i < n; ++i) {
    const char* xx = Rf_translateCharUTF8(x_sxp[i]);

    char* unescaped = xmlURIUnescapeString(xx, 0, NULL);
    out[i] = (unescaped == NULL) ? cpp11::na<cpp11::r_string>() : cpp11::r_string(unescaped);
    xmlFree(unescaped);
  }

  return out;
}
