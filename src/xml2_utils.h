#ifndef __XML2_XML_UTILS__
#define __XML2_XML_UTILS__

#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>

// A wrapper around xmlChar* that frees memory if necessary
class Xml2Char {
  xmlChar* string_;
  bool free_;

public:
  Xml2Char(xmlChar* string): string_(string), free_(true) {}

  // Pointers into structs are const, so don't need to be freed
  Xml2Char(const xmlChar* string): string_((xmlChar*) string), free_(false) {}

  ~Xml2Char() {
    try {
      if (free_ && string_ != NULL)
        xmlFree(string_);
    } catch (...) {}
  }

  operator std::string() {
    if (string_ == NULL)
      return "";

    return std::string((char*) string_);
  }

  operator Rcpp::String() {
    if (string_ == NULL)
      return NA_STRING;

    return Rf_mkCharCE((char*) string_, CE_UTF8);
  };
};

#endif
