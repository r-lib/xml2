#include <Rcpp.h>
#include <libxml/tree.h>

using namespace Rcpp;
#include "xml2_types.h"
#include "xml2_utils.h"

class NsMap {
  CharacterVector prefix_, url_;
  int n_, capacity_;

public:
  NsMap(int capacity = 10): n_(0), capacity_(capacity) {
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

  bool has_url(String url) {
    for (int i = 0; i < n_; ++i) {
      String cur_url(url_[i]);
      if (cur_url == url)
        return true;
    }

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

  bool add(const xmlChar* prefix, const xmlChar* url) {
    // SEXP rUrl = Rf_mkCharCE(url.c_str(), CE_UTF8);

    return add(asCHARSXP(prefix), asCHARSXP(url));
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

void cache_namespace(xmlNode* node, NsMap* nsMap) {
  // Iterate over namespace definitions
  for(xmlNs* cur = node->nsDef; cur != NULL; cur = cur->next) {
    nsMap->add(cur->prefix, cur->href);
  }

  // Iterate over children, calling this function recursively
  for(xmlNode* cur = node->children; cur != NULL; cur = cur->next) {
    cache_namespace(cur, nsMap);
  }
}

// [[Rcpp::export]]
CharacterVector doc_namespaces(XPtrDoc doc) {
  NsMap nsMap;

  xmlNode* root = xmlDocGetRootElement(doc.get());
  cache_namespace(root, &nsMap);

  return nsMap.out();
}
