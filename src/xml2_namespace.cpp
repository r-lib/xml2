#include <Rcpp.h>
#include <libxml/tree.h>

using namespace Rcpp;
#include "xml2_types.h"
#include "xml2_utils.h"

class NsMap {
  CharacterVector prefix_, url_;
  int n_, capacity_;

public:
  NsMap(int capacity = 10): capacity_(capacity), n_(0) {
    url_ = CharacterVector(capacity_);
    prefix_ = CharacterVector(capacity_);
  }

  // Initialise from an existing character vector
  NsMap(CharacterVector x) {
    url_ = x;
    prefix_ = as<CharacterVector>(x.attr("names"));
    n_ = x.size();
    capacity_ = x.size();
  }

  bool has_url(std::string url) {
    SEXP rUrl = Rf_mkCharCE(url.c_str(), CE_UTF8);
    for (int i = 0; i < n_; ++i)
      if (url_[i] == rUrl)
        return true;

    return false;
  }

  bool add(String prefix, String url) {
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

  CharacterVector out() {
    resize(n_);

    url_.attr("names") = prefix_;
    return url_;
  }
};

// [[Rcpp::export]]
CharacterVector unique_ns(CharacterVector ns) {
  CharacterVector prefix = as<CharacterVector>(ns.attr("names"));

  NsMap nsMap(1);
  for (int i = 0; i < prefix.size(); ++i)
    nsMap.add(prefix[i], ns[i]);

  return nsMap.out();
}
