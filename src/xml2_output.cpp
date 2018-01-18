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

  /* * *
   *
   * Author: Daniel Veillard <veillard@src.gnome.org>
   * Date:   Thu Sep 25 14:31:40 2008 +0000
   * https://github.com/GNOME/libxml2/commit/856d92818bda07549a532d6fb16f323a94e0c39a
   *
   * include/libxml/xmlsave.h xmlsave.c: new options to serialize
   * as XML/HTML/XHTML and restore old entry point behaviours
   * Daniel
   */
#if defined(LIBXML_VERSION) && (LIBXML_VERSION >= 20704)
#define HAS_SAVE_AS_HTML
#endif


  /* * *
   *
   * Author: Adam Spragg <adam@spra.gg>
   * Date:   Wed Nov 3 15:33:40 2010 +0100
   * https://github.com/GNOME/libxml2/commit/d2e62311cd15651e68f921167c7fcf05b19378f9
   *
   * Add xmlSaveOption XML_SAVE_WSNONSIG
   */
#if defined(LIBXML_VERSION) && (LIBXML_VERSION >= 20708)
#define HAS_SAVE_WSNONSIG
#endif

// [[Rcpp::export]]
Rcpp::IntegerVector xml_save_options() {
  Rcpp::IntegerVector out = Rcpp::IntegerVector::create(
      Rcpp::_["format"] = XML_SAVE_FORMAT,
      Rcpp::_["no_declaration"] = XML_SAVE_NO_DECL,
      Rcpp::_["no_empty_tags"] = XML_SAVE_NO_EMPTY,
      Rcpp::_["no_xhtml"] = XML_SAVE_NO_XHTML,
      Rcpp::_["require_xhtml"] = XML_SAVE_XHTML,
      Rcpp::_["as_xml"] = XML_SAVE_AS_XML,
#ifdef HAS_SAVE_AS_HTML
      Rcpp::_["as_html"] = XML_SAVE_AS_HTML
#endif
#ifdef HAS_SAVE_WSNONSIG
      , Rcpp::_["format_whitespace"] = XML_SAVE_WSNONSIG
#endif
      );
  out.attr("descriptions") = Rcpp::CharacterVector::create(
      "Format output",
      "Drop the XML declaration",
      "Remove empty tags",
      "Disable XHTML1 rules",
      "Force XHTML1 rules",
      "Force XML output",
#ifdef HAS_SAVE_AS_HTML
      "Force HTML output"
#endif
#ifdef HAS_SAVE_WSNONSIG
      , "Format with non-significant whitespace"
#endif
      );
  return out;
}

int xml_write_callback(Rconnection con, const char * buffer, int len) {
  size_t write_size;

  if ((write_size = R_WriteConnection(con, (void *) buffer, len)) != static_cast<size_t>(len)) {
    stop("write failed, expected %l, got %l", len, write_size);
  }
  return write_size;
}

// [[Rcpp::export]]
void doc_write_file(XPtrDoc x, std::string path, std::string encoding = "UTF-8", int options = 1) {
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
CharacterVector doc_write_character(XPtrDoc x, std::string encoding = "UTF-8", int options = 1) {
  xmlBufferPtr buffer = xmlBufferCreate();

  xmlSaveCtxtPtr savectx = xmlSaveToBuffer(
      buffer,
      encoding.c_str(),
      options);

  xmlSaveDoc(savectx, x.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    xmlFree(buffer);
    stop("Error writing to buffer");
  }
  CharacterVector out(Xml2String(buffer->content).asRString());
  xmlFree(buffer);
  return out;
}

// [[Rcpp::export]]
void node_write_file(XPtrNode x, std::string path, std::string encoding = "UTF-8", int options = 1) {
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
CharacterVector node_write_character(XPtrNode x, std::string encoding = "UTF-8", int options = 1) {
  xmlBufferPtr buffer = xmlBufferCreate();

  xmlSaveCtxtPtr savectx = xmlSaveToBuffer(
      buffer,
      encoding.c_str(),
      options);

  xmlSaveTree(savectx, x.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    xmlFree(buffer);
    stop("Error writing to buffer");
  }
  CharacterVector out(Xml2String(buffer->content).asRString());
  xmlFree(buffer);
  return out;
}
