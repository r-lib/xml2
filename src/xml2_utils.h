#ifndef __XML2_XML_UTILS__
#define __XML2_XML_UTILS__

#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>

// ----------------------------------------------------------------------------
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

// ----------------------------------------------------------------------------
// A wrapper around a pair of character vectors used to namespaces to prefixes

class NsMap {
  Rcpp::CharacterVector prefix_, url_;
  int n_, capacity_;

public:
  NsMap(int capacity = 10): n_(0), capacity_(capacity) {
    url_ = Rcpp::CharacterVector(capacity_);
    prefix_ = Rcpp::CharacterVector(capacity_);
  }

  // Initialise from an existing character vector
  NsMap(Rcpp::CharacterVector x) {
    url_ = x;
    prefix_ = Rcpp::as<Rcpp::CharacterVector>(x.attr("names"));
    n_ = x.size();
    capacity_ = x.size();
  }

  bool has_url(Rcpp::String url) {
    for (int i = 0; i < n_; ++i) {
      Rcpp::String cur_url(url_[i]);
      if (cur_url == url)
        return true;
    }

    return false;
  }

  Rcpp::String find_prefix(Rcpp::String url) {
    for (int i = 0; i < n_; ++i) {
      Rcpp::String cur_url = url_[i];
      if (cur_url == url)
        return prefix_[i];
    }

    Rcpp::stop("Could not find ns url %s", url.get_cstring());
    return "";
  }

  Rcpp::String find_url(Rcpp::String prefix) {
    for (int i = 0; i < n_; ++i) {
      Rcpp::String cur_prefix(url_[i]);
      if (cur_prefix == prefix)
        return url_[i];
    }

    Rcpp::stop("Could not find ns prefix %s", prefix.get_cstring());
    return "";
  }


  bool add(Rcpp::String prefix, Rcpp::String url) {
    if (has_url(url))
      return false;

    if (n_ >= capacity_) {
      resize(capacity_ * 2);
    }

    prefix_[n_] = prefix;
    url_[n_] = url;
    n_++;

    return true;
  }

  void resize(int n) {
    prefix_ = Rf_lengthgets(prefix_, n);
    url_ = Rf_lengthgets(url_, n);
    capacity_ = n;
  }

  Rcpp::CharacterVector out() {
    resize(n_);

    url_.attr("names") = prefix_;
    return url_;
  }
};


#endif
