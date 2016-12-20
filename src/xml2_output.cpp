#include <Rcpp.h>
using namespace Rcpp;

#define class class_name
#define private private_ptr
#include <R_ext/Connections.h>
#undef class
#undef private

#include <libxml/tree.h>
#include <libxml/HTMLtree.h>

#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
void doc_write_xml(XPtrDoc x, std::string path, bool format) {
  int res = xmlSaveFormatFile(
    R_ExpandFileName(path.c_str()),
    x.checked_get(),
    format ? 1 : 0
  );
  if (res == -1)
    Rcpp::stop("Failed to write to %s", path);
}
// [[Rcpp::export]]
void doc_write_html(XPtrDoc x, std::string path, bool format) {
  int res = htmlSaveFileFormat(
    R_ExpandFileName(path.c_str()),
    x.checked_get(),
    "UTF-8",
    format ? 1 : 0
  );
  if (res == -1)
    Rcpp::stop("Failed to write to %s", path);
}


// [[Rcpp::export]]
void node_write_xml(XPtrNode n, XPtrDoc d, std::string path) {
  FILE* f = fopen(path.c_str(), "wb");
  xmlElemDump(f, d.checked_get(), n.checked_get());
  fclose(f);
}
// [[Rcpp::export]]
void node_write_html(XPtrNode n, XPtrDoc d, std::string path) {
  FILE* f = fopen(path.c_str(), "wb");
  htmlNodeDumpFile(f, d.checked_get(), n.checked_get());
  fclose(f);
}


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
void doc_write_xml_connection(XPtrDoc x, SEXP connection, bool format = true) {
  xmlChar *s;
  int size;
  size_t write_size;
  xmlDocDumpFormatMemory(x.checked_get(), &s, &size, format);

  Rconnection con = R_GetConnection(connection);
  Rcout << con->description << ':' << con->isopen << ':' << con->canwrite << std::endl;
  Rcout << "trying to write " << size << " bytes" << std::endl;
  if ((write_size = R_WriteConnection(con, s, size)) != size) {
    stop("write failed, expected %l, got %l", size, write_size);
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
