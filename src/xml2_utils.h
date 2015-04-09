#ifndef __XML2_XML_UTILS__
#define __XML2_XML_UTILS__

#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>

inline xmlChar* asXmlChar(std::string x) {
  return (xmlChar*) x.c_str();
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
  std::vector<std::string> prefix_, url_;

public:
  NsMap() {
  }

  // Initialise from an existing character vector
  NsMap(Rcpp::CharacterVector x) {
    Rcpp::CharacterVector names =  Rcpp::as<Rcpp::CharacterVector>(x.attr("names"));
    for (int i = 0; i < x.size(); ++i) {
      add(std::string(names[i]), std::string(x[i]));
    }
  }

  bool hasUrl(std::string url) {
    for (int i = 0; i < url_.size(); ++i) {
      if (url_[i] == url)
        return true;
    }
    return false;
  }

  std::string findPrefix(std::string url) {
    for (int i = 0; i < url_.size(); ++i) {
      if (url_[i] == url)
        return prefix_[i];
    }

    Rcpp::stop("Couldn't find prefix for url %s", url);
    return "";
  }

  std::string findUrl(std::string prefix) {
    for (int i = 0; i < prefix_.size(); ++i) {
      if (prefix_[i] == prefix)
        return url_[i];
    }

    Rcpp::stop("Couldn't find url for prefix %s", prefix);
    return "";
  }

  bool add(const xmlChar* prefix, const xmlChar* url) {
    return add(Xml2String(prefix).asStdString(), Xml2String(url).asStdString());
  }

  bool add(std::string prefix, std::string url) {
    if (hasUrl(url))
      return false;

    prefix_.push_back(prefix);
    url_.push_back(url);

    return true;
  }

  Rcpp::CharacterVector out() {
    Rcpp::CharacterVector out = Rcpp::wrap(url_);
    out.attr("names") = Rcpp::wrap(prefix_);
    return out;
  }
};

#endif
