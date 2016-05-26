#ifndef __XML2_XML_UTILS__
#define __XML2_XML_UTILS__

#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>

inline xmlChar* asXmlChar(std::string x) {
  return (xmlChar*) x.c_str();
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
  typedef boost::unordered_map<std::string, std::string> url2prefix_t;

  url2prefix_t url2prefix;
  std::vector<std::string> order;

  public:
  NsMap() {
  }

  // Initialise from an existing character vector
  NsMap(Rcpp::CharacterVector x) {
    Rcpp::CharacterVector names = Rcpp::as<Rcpp::CharacterVector>(x.attr("names"));
    for (std::vector<std::string>::size_type i = 0; i < x.size(); ++i) {
      add(std::string(names[i]), std::string(x[i]));
    }
  }

  bool hasUrl(std::string url) {
    return url2prefix.find(url) != url2prefix.end();
  }

  std::string findPrefix(std::string url) {
    url2prefix_t::const_iterator it = url2prefix.find(url);
    if (it != url2prefix.end()) {
      return it->second;
    }

    Rcpp::stop("Couldn't find prefix for url %s", url);
    return std::string();
  }

  std::string findUrl(std::string prefix) {
    for (url2prefix_t::const_iterator it = url2prefix.begin(); it != url2prefix.end(); ++it) {
      if (it->second == prefix) {
        return it->first;
      }
    }

    Rcpp::stop("Couldn't find url for prefix %s", prefix);
    return std::string();
  }

  bool add(const xmlChar* prefix, const xmlChar* url) {
    return add(Xml2String(prefix).asStdString(), Xml2String(url).asStdString());
  }

  bool add(std::string prefix, std::string url) {
    if (hasUrl(url))
      return false;

    // Add the value to the vector and store the order.
    order.push_back(url);
    url2prefix.insert(url2prefix_t::value_type(url, prefix));
    return true;
  }

  Rcpp::CharacterVector out() {
    Rcpp::CharacterVector out = Rcpp::wrap(order);
    std::vector<std::string> name;
    name.reserve(order.size());

    for(std::vector<std::string>::const_iterator it = order.begin();it != order.end(); ++it) {
      name.push_back(url2prefix.at(*it));
    }
    out.attr("names") = Rcpp::wrap(name);
    return out;
  }
};
#endif
