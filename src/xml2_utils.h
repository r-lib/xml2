#ifndef __XML2_XML_UTILS__
#define __XML2_XML_UTILS__

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/tree.h>
#include <map>
#include <string>

enum NodeType {
  missing = 1,
  node = 2,
  nodeset = 3,
};


inline int inherits3(SEXP x, const char *name) {
  SEXP expr = PROTECT(Rf_lang3(Rf_install("inherits"), x, Rf_mkString(name)));
  SEXP result = PROTECT(Rf_eval(expr, R_GlobalEnv));

  int out = LOGICAL(result)[0];
  UNPROTECT(2);
  return out;
}

inline const NodeType getNodeType(SEXP x) {

  // for fhircrackr
  if (IS_S4_OBJECT(x)) {
    if (inherits3(x, "xml_node")) {
      return(NodeType::node);
    } else if (inherits3(x, "xml_nodeset")) {
      return(NodeType::nodeset);
    } else if (inherits3(x, "xml_missing")) {
      return(NodeType::missing);
    } else {
      Rf_error("Unexpected node type");
    }
  }

  if (Rf_inherits(x, "xml_node")) {
    return(NodeType::node);
  } else if (Rf_inherits(x, "xml_nodeset")) {
    return(NodeType::nodeset);
  } else if (Rf_inherits(x, "xml_missing")) {
    return(NodeType::missing);
  } else {
    Rf_error("Unexpected node type");
  }
}

inline const xmlChar* asXmlChar(std::string const& x) {
  return (const xmlChar*) x.c_str();
}

inline const xmlChar* asXmlChar(SEXP x, int n = 0) {
  return (const xmlChar*) CHAR(STRING_ELT(x, n));
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

  // Initialise from an existing STRSXP
  NsMap(SEXP x) {
    SEXP names = Rf_getAttrib(x, R_NamesSymbol);
    for (R_len_t i = 0; i < Rf_xlength(x); ++i) {
      add(std::string(CHAR(STRING_ELT(names, i))), std::string(CHAR(STRING_ELT(x, i))));
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

  SEXP out() {
    SEXP out = PROTECT(Rf_allocVector(STRSXP, prefix2url.size()));
    SEXP names = PROTECT(Rf_allocVector(STRSXP, prefix2url.size()));

    size_t i = 0;
    for (prefix2url_t::const_iterator it = prefix2url.begin(); it != prefix2url.end(); ++it) {
      SET_STRING_ELT(out, i, Rf_mkChar(it->second.c_str()));
      SET_STRING_ELT(names, i, Rf_mkChar(it->first.c_str()));
      ++i;
    }

    Rf_setAttrib(out, R_NamesSymbol, names);

    UNPROTECT(2);
    return out;
  }
};
#endif
