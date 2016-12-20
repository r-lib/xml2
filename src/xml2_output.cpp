#include <Rcpp.h>
using namespace Rcpp;

#define class class_name
#define private private_ptr
#include <R_ext/Connections.h>
#undef class
#undef private

#include <libxml/tree.h>
#include <libxml/HTMLtree.h>
#include <libxml/xmlsave.h>

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

struct write_ctxt {
  Rconnection con;
  bool should_close;
};

int xml_write_callback(write_ctxt * context, const char * buffer, int len) {
  size_t write_size;

  if ((write_size = R_WriteConnection(context->con, (void *) buffer, len)) != len) {
    stop("write failed, expected %l, got %l", len, write_size);
  }
  return write_size;
}

int xml_close_callback(write_ctxt * context) {
  if (context->should_close) {
    context->con->close(context->con);
  }
  return 0;
}

// [[Rcpp::export]]
void doc_write_xml_connection(XPtrDoc x, SEXP connection, bool format = true) {
  write_ctxt ctxt;
  ctxt.should_close = false;

  ctxt.con = R_GetConnection(connection);
  if (!ctxt.con->isopen) {
    ctxt.con->open(ctxt.con);
    ctxt.should_close = true;
  }

  xmlSaveCtxtPtr savectx;
  savectx = xmlSaveToIO(
      (xmlOutputWriteCallback)xml_write_callback,
      (xmlOutputCloseCallback) xml_close_callback,
      &ctxt,
      NULL,
      0);

  xmlSaveDoc(savectx, x.checked_get());
  xmlSaveClose(savectx);
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
