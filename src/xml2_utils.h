#ifndef __XML2_XML_UTILS__
#define __XML2_XML_UTILS__

#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>

inline Rcpp::CharacterVector xmlCharToRChar(const xmlChar* x) {
  if (x == NULL)
    return Rcpp::CharacterVector::create(NA_STRING);

  Rcpp::CharacterVector out(1);
  out[0] = Rf_mkCharCE((char*) x, CE_UTF8);

  return out;
}

// A wrapper around xmlChar* that always frees memory
class Xml2Char {
  boost::shared_ptr<xmlChar> string_;

public:
  Xml2Char(xmlChar* string): string_(string, xmlFree) {}

  Rcpp::CharacterVector string() {
    return xmlCharToRChar(string_.get());
  }
};

#endif
