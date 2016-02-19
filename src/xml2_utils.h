#ifndef __XML2_XML_UTILS__
#define __XML2_XML_UTILS__

#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>
#include <boost/typeof/typeof.hpp>
#include <map>

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

  // We only store a pointer to the strings in url2prefix to avoid an extra duplication.
  typedef std::multimap<std::string, std::string> prefix2url_t;
  typedef std::map<std::string, const std::string*> url2prefix_t;

  prefix2url_t prefix2url;
  url2prefix_t url2prefix;

  public:
  NsMap() {
  }

  // Initialise from an existing character vector
  NsMap(Rcpp::CharacterVector x) {
    BOOST_AUTO(names, Rcpp::as<Rcpp::CharacterVector>(x.attr("names")));
    for (int i = 0; i < x.size(); ++i) {
      add(std::string(names[i]), std::string(x[i]));
    }
  }

  bool hasUrl(std::string url) {
    return url2prefix.find(url) != url2prefix.end();
  }

  std::string findPrefix(std::string url) {
    BOOST_AUTO(it, url2prefix.find(url));
    if (it != url2prefix.end()) {
      return *it->second;
    }

    Rcpp::stop("Couldn't find prefix for url %s", url);
    return "";
  }

  std::string findUrl(std::string prefix) {
    BOOST_AUTO(it, prefix2url.find(prefix));
    if (it != prefix2url.end()) {
      return it->second;
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

    // The return value of multimap.insert is an iterator of the inserted
    // element. We store the address of the key string as the value in
    // url2prefix to avoid duplicating the data.
    BOOST_AUTO(p, prefix2url.insert(prefix2url_t::value_type(prefix, url)));
    url2prefix.insert(url2prefix_t::value_type(url, &(p->first)));

    return true;
  }

  Rcpp::CharacterVector out() {
    return Rcpp::wrap(prefix2url);
  }
};

#endif
