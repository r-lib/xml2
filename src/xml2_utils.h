#ifndef __XML2_XML_UTILS__
#define __XML2_XML_UTILS__

#include <Rcpp.h>
#include <libxml/tree.h>

inline Rcpp::CharacterVector xmlCharToRChar(const xmlChar* x) {
  if (x == NULL)
    Rcpp::stop("Null string");

  Rcpp::CharacterVector out(1);
  out[0] = Rf_mkCharCE((char*) x, CE_UTF8);

  return out;
}

#endif
