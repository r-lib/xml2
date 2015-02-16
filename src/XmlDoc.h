#ifndef __XML2_XMLDOC__
#define __XML2_XMLDOC__

#include <Rcpp.h>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <libxml/parser.h>

// convenience typedef for shared_ptr to PqConnection
class XmlDoc;
typedef boost::shared_ptr<XmlDoc> XmlDocPtr;

class XmlDoc : boost::noncopyable {
  xmlDoc* pDoc_;

public:

  XmlDoc(std::string filename, std::string encoding, int options = 0) {
    pDoc_ = xmlReadFile(filename.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      options
    );
    if (pDoc_ == NULL)
      Rcpp::stop("Failed to parse %s", filename);
  }

  XmlDoc(const char* text, int size, std::string base_url, std::string encoding,
         int options = 0) {

    pDoc_ = xmlReadMemory(text, size,
      base_url == "" ? NULL : base_url.c_str(),
      encoding == "" ? NULL : encoding.c_str(),
      options
    );
    if (pDoc_ == NULL)
      Rcpp::stop("Failed to parse text");
  }

  ~XmlDoc() {
    try {
      xmlFreeDoc(pDoc_);
    } catch (...) {}
  }

  Rcpp::CharacterVector format() {
    xmlChar *s;
    xmlDocDumpMemory(pDoc_, &s, NULL);

    if (s == NULL)
      Rcpp::stop("Failed to format xml as string");

    Rcpp::CharacterVector out(1);
    out[0] = Rf_mkCharCE((char*) s, CE_UTF8);
    xmlFree(s);

    return out;
  }

};

#endif
