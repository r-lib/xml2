#ifndef __XML2_XML_UTILS__
#define __XML2_XML_UTILS__

#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>
#include <map>

inline xmlChar* asXmlChar(std::string x) {
  return (xmlChar*) x.c_str();
}

inline xmlChar* asXmlChar(SEXP x, int n = 0) {
  return (xmlChar*) CHAR(STRING_ELT(x, n));
}

inline Rcpp::CharacterVector asCharacterVector(std::string x) {
  return Rcpp::CharacterVector(Rf_mkCharCE(x.c_str(), CE_UTF8));
}

// ----------------------------------------------------------------------------
// A wrapper around xmlChar* that frees memory if necessary
class Xml2String {
  xmlChar* string_;
  bool free_;

public:
  Xml2String(): string_(NULL), free_(false) {}

  Xml2String(xmlChar* string): string_(string), free_(true) {}

  // Pointers into structs are const, so don't need to be freed
  Xml2String(const xmlChar* string): string_((xmlChar*) string), free_(false) {}

  // Some strings are regular strings
  Xml2String(const char* string): string_((xmlChar*) string), free_(false) {}

  ~Xml2String() {
    try {
      if (free_ && string_ != NULL)
        xmlFree(string_);
    } catch (...) {}
  }

  std::string asStdString(std::string missing = "") {
    if (string_ == NULL)
      return missing;

    return std::string((char*) string_);
  }

  SEXP asRString(SEXP missing = NA_STRING) {
    if (string_ == NULL)
      return missing;

    return Rf_mkCharCE((char*) string_, CE_UTF8);
  };
};

// ----------------------------------------------------------------------------
// A wrapper around a pair of character vectors used to namespaces to prefixes

class NsMap {

  // We only store the index to avoid duplicating the data
  typedef std::multimap<std::string, std::string> prefix2url_t;

  prefix2url_t prefix2url;

  public:
  NsMap() {
  }

  // Initialise from an existing character vector
  NsMap(Rcpp::CharacterVector x) {
    Rcpp::CharacterVector names = Rcpp::as<Rcpp::CharacterVector>(x.attr("names"));
    for (R_len_t i = 0; i < x.size(); ++i) {
      add(std::string(names[i]), std::string(x[i]));
    }
  }

  bool hasPrefix(const std::string& prefix) {
    return prefix2url.find(prefix) != prefix2url.end();
  }

  std::string findUrl(const std::string& prefix) {
    prefix2url_t::const_iterator it = prefix2url.find(prefix);
    if (it != prefix2url.end()) {
      return it->second;
    }

    Rcpp::stop("Couldn't find url for prefix %s", prefix);
    return std::string();
  }

  std::string findPrefix(const std::string& url) {
    for (prefix2url_t::const_iterator it = prefix2url.begin(); it != prefix2url.end(); ++it) {
      if (it->second == url) {
        return it->first;
      }
    }

    Rcpp::stop("Couldn't find prefix for url %s", url);
    return std::string();
  }

  bool add(const xmlChar* prefix, const xmlChar* url) {
    return add(Xml2String(prefix).asStdString(), Xml2String(url).asStdString());
  }

  bool add(std::string prefix, std::string url) {
    prefix2url.insert(prefix2url_t::value_type(prefix, url));
    return true;
  }

  Rcpp::CharacterVector out() {
    return Rcpp::wrap(prefix2url);
  }
};
#endif
