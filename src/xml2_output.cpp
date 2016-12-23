#include <Rcpp.h>
using namespace Rcpp;

#define class class_name
#define private private_ptr
#include <R_ext/Connections.h>
#undef class
#undef private

#if R_CONNECTIONS_VERSION != 1
#error "Missing or unsupported connection API in R"
#endif

#if defined(R_VERSION) && R_VERSION >= R_Version(3, 3, 0)
Rconnection get_connection(SEXP con) {
  return R_GetConnection(con);
}
# else
extern "C" {
    extern Rconnection getConnection(int) ;
}
Rconnection get_connection(SEXP con) {
  if (!Rf_inherits(con, "connection")) stop("invalid connection");
  return getConnection(Rf_asInteger(con));
}
#endif

#include <libxml/tree.h>
#include <libxml/HTMLtree.h>
#include <libxml/xmlsave.h>

#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
CharacterVector doc_format_xml(XPtrDoc x, bool format = true) {
  xmlChar *s;
  int size;
  xmlDocDumpFormatMemory(x.checked_get(), &s, &size, format);

  return Xml2String(s).asRString();
}

// [[Rcpp::export]]
CharacterVector doc_format_html(XPtrDoc x, bool format = true) {
  xmlChar *s;
  int size;
  htmlDocDumpMemoryFormat(x.checked_get(), &s, &size, format);

  return Xml2String(s).asRString();
}

// [[Rcpp::export]]
Rcpp::IntegerVector xml_save_options() {
  Rcpp::IntegerVector out = Rcpp::IntegerVector::create(
      Rcpp::_["format"] = XML_SAVE_FORMAT,
      Rcpp::_["no_declaration"] = XML_SAVE_NO_DECL,
      Rcpp::_["no_empty_tags"] = XML_SAVE_NO_EMPTY,
      Rcpp::_["no_xhtml"] = XML_SAVE_NO_XHTML,
      Rcpp::_["require_xhtml"] = XML_SAVE_XHTML,
      Rcpp::_["as_xml"] = XML_SAVE_AS_XML,
      Rcpp::_["as_html"] = XML_SAVE_AS_HTML,
      Rcpp::_["format_whitespace"] = XML_SAVE_WSNONSIG);
  out.attr("descriptions") = Rcpp::CharacterVector::create(
      "Format output",
      "Drop the XML declaration",
      "Remove empty tags",
      "Disable XHTML1 rules",
      "Force XHTML1 rules",
      "Force XML output",
      "Force HTML output",
      "Format with non-significant whitespace");
  return out;
}

int xml_write_callback(Rconnection con, const char * buffer, int len) {
  size_t write_size;

  if ((write_size = R_WriteConnection(con, (void *) buffer, len)) != len) {
    stop("write failed, expected %l, got %l", len, write_size);
  }
  return write_size;
}

// [[Rcpp::export]]
void doc_write(XPtrDoc x, std::string path, std::string encoding = "UTF-8", int options = 1) {
  xmlSaveCtxtPtr savectx = xmlSaveToFilename(
      path.c_str(),
      encoding.c_str(),
      options);
  xmlSaveDoc(savectx, x.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    stop("Error closing file");
  }
}

// [[Rcpp::export]]
void doc_write_connection(XPtrDoc x, SEXP connection, std::string encoding = "UTF-8", int options = 1) {

  Rconnection con = get_connection(connection);

  xmlSaveCtxtPtr savectx = xmlSaveToIO(
      reinterpret_cast<xmlOutputWriteCallback>(xml_write_callback),
      NULL,
      con,
      encoding.c_str(),
      options);

  xmlSaveDoc(savectx, x.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    stop("Error closing connection");
  }
}

// [[Rcpp::export]]
void node_write(XPtrNode x, std::string path, std::string encoding = "UTF-8", int options = 1) {
  xmlSaveCtxtPtr savectx = xmlSaveToFilename(
      path.c_str(),
      encoding.c_str(),
      options);
  xmlSaveTree(savectx, x.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    stop("Error closing file");
  }
}

// [[Rcpp::export]]
void node_write_connection(XPtrNode x, SEXP connection, std::string encoding = "UTF-8", int options = 1) {

  Rconnection con = get_connection(connection);

  xmlSaveCtxtPtr savectx = xmlSaveToIO(
      (xmlOutputWriteCallback)xml_write_callback,
      NULL,
      con,
      encoding.c_str(),
      options);

  xmlSaveTree(savectx, x.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    stop("Error closing connection");
  }
}

// [[Rcpp::export]]
CharacterVector node_format_xml(XPtrDoc doc, XPtrNode node,
                                bool format = true,
                                int indent = 0) {
  boost::shared_ptr<xmlBuffer> buffer(xmlBufferCreate(), xmlFree);
  xmlNodeDump(buffer.get(), doc.checked_get(), node.checked_get(), indent, format);

  return Xml2String(buffer->content).asRString();
}
// [[Rcpp::export]]
CharacterVector node_format_html(XPtrDoc doc, XPtrNode node,
                                 bool format = true) {
  boost::shared_ptr<xmlBuffer> buffer(xmlBufferCreate(), xmlBufferFree);
  xmlOutputBuffer *outputBuffer = xmlOutputBufferCreateBuffer( buffer.get(), NULL );

  htmlNodeDumpFormatOutput(
    outputBuffer,
    doc.checked_get(),
    node.checked_get(),
    NULL,
    format ? 1 : 0
  );

  return Xml2String(buffer->content).asRString();
}
