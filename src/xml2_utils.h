#ifndef __XML2_XML_UTILS__
#define __XML2_XML_UTILS__

#include <cpp11.hpp>

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/tree.h>
#include <map>
#include <string>

inline const xmlChar* asXmlChar(std::string const& x) {
  return (const xmlChar*) x.c_str();
}

inline const xmlChar* asXmlChar(cpp11::strings x) {
  return (const xmlChar*) cpp11::as_cpp<const char*>(x);
}

#define BEGIN_CPP try {

#define END_CPP                                                                \
  }                                                                            \
  catch (std::exception & e) {                                                 \
    Rf_error("C++ exception: %s", e.what());                                   \
  }


// If we are using C++11 disallow moves
#if __cplusplus >= 201103L
void asXmlChar(std::string&&) = delete;
#endif

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

  cpp11::r_string asRString(cpp11::r_string missing = NA_STRING) {
    if (string_ == NULL)
      return missing;

    return cpp11::r_string((char*) string_);
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

  // Initialise from an existing STRSXP
  NsMap(cpp11::strings x) {
    cpp11::strings names = x.names();
    for (R_len_t i = 0; i < x.size(); ++i) {
      add(cpp11::r_string(names[i]), cpp11::r_string(x[i]));
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

    Rf_error("Couldn't find url for prefix %s", prefix.c_str());
    return std::string();
  }

  std::string findPrefix(const std::string& url) {
    for (prefix2url_t::const_iterator it = prefix2url.begin(); it != prefix2url.end(); ++it) {
      if (it->second == url) {
        return it->first;
      }
    }

    Rf_error("Couldn't find prefix for url %s", url.c_str());
    return std::string();
  }

  bool add(const xmlChar* prefix, const xmlChar* url) {
    return add(Xml2String(prefix).asStdString(), Xml2String(url).asStdString());
  }

  bool add(std::string prefix, std::string url) {
    prefix2url.insert(prefix2url_t::value_type(prefix, url));
    return true;
  }

  cpp11::sexp out() {
    int n = prefix2url.size();
    cpp11::writable::strings out(n);
    cpp11::writable::strings names(n);

    size_t i = 0;
    for (prefix2url_t::const_iterator it = prefix2url.begin(); it != prefix2url.end(); ++it) {
      out[i] = it->second.c_str();
      names[i] = it->first.c_str();
      ++i;
    }

    out.names() = names;

    return out;
  }
};
#endif
