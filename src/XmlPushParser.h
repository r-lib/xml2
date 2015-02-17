#ifndef __XML2_PUSHPARSER__
#define __XML2_PUSHPARSER__

#include <Rcpp.h>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <libxml/parser.h>
#include "XmlDoc.h"

// convenience typedef for shared_ptr to PqConnection
class XmlPushParser;
typedef boost::shared_ptr<XmlPushParser> XmlPushParserPtr;

class XmlPushParser : boost::noncopyable {
  xmlParserCtxtPtr ctxt;

public:
  //constructor
  XmlPushParser(std::string filename) {
    ctxt = xmlCreatePushParserCtxt(NULL, NULL, NULL, 0, filename.c_str());

    if (ctxt == NULL)
      Rcpp::stop("Failed to parse %s", filename);
  }

  ~XmlPushParser() {
    try {
      xmlFreeParserCtxt(ctxt);
    } catch (...) {}
  }

  //Feed character vectors
  bool feed(const char* text, size_t size){
    int res = xmlParseChunk(ctxt, text, size, 0);
    if(res)
      Rcpp::stop("XML Parsing Error: %d", res);
    return true;
  }

  //Feed raw vectors
  bool feed(SEXP data){
    size_t size = Rf_length(data);
    const char *buf = (const char *) RAW(data);
    int res = xmlParseChunk(ctxt, buf, size, 0);
    if(res)
      Rcpp::stop("XML Parsing Error: %d", res);
    return true;
  }

  bool done(){
    int res = xmlParseChunk(ctxt, NULL, 0, 1);
    if(res)
      Rcpp::stop("XML Parsing Error: %d", res);
    return true;
  }

  xmlDoc* doc() {
    if(!ctxt->wellFormed)
      Rcpp::warning("XML is not well-formed.");
    return ctxt->myDoc;
  }

};

#endif
