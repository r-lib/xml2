#ifndef __XML2_XML_UTILS__
#define __XML2_XML_UTILS__

#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>

inline SEXP asCHARSXP(const xmlChar* x) {
  if (x == NULL)
    return NA_STRING;

  return Rf_mkCharCE((char*) x, CE_UTF8);
}

inline Rcpp::CharacterVector xmlCharToRChar(const xmlChar* x) {
  return Rcpp::CharacterVector::create(asCHARSXP(x));
}

// A wrapper around xmlChar* that always frees memory
class Xml2Char {
  xmlChar* string_;

public:
  Xml2Char(xmlChar* string): string_(string) {}

  ~Xml2Char() {
    try {
      if (string_ != NULL)
        xmlFree(string_);
    } catch (...) {}
  }

  Rcpp::CharacterVector string() {
    return xmlCharToRChar(string_);
  }
};

#endif
