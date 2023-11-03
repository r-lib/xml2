#include <cpp11.hpp>

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/tree.h>
#include <libxml/HTMLtree.h>
#include <libxml/xmlsave.h>

#include "connection.h"
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
#define HAS_SAVE_HTML
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

typedef struct {
  const char* name;
  const char* description;
  int value;
} xml_save_def;

[[cpp11::register]]
cpp11::writable::integers xml_save_options_() {

  static const xml_save_def entries[] = {
    {"format", "Format output", XML_SAVE_FORMAT},
    {"no_declaration", "Drop the XML declaration", XML_SAVE_NO_DECL},
    {"no_empty_tags", "Remove empty tags", XML_SAVE_NO_EMPTY},
#ifdef HAS_SAVE_HTML
    {"no_xhtml", "Disable XHTML1 rules", XML_SAVE_NO_XHTML},
    {"require_xhtml", "Force XHTML rules", XML_SAVE_XHTML},
    {"as_xml", "Force XML output", XML_SAVE_AS_XML},
    {"as_html", "Force HTML output", XML_SAVE_AS_HTML},
#endif
#ifdef HAS_SAVE_WSNONSIG
    {"format_whitespace", "Format with non-significant whitespace", XML_SAVE_WSNONSIG},
#endif
    {NULL, NULL, 0}
  };

  // First figure out size, seems like there would be a way for the compiler to
  // do this, but I don't know it.
  R_xlen_t n = 0;
  while(entries[n].name != NULL) {
    ++n;
  }

  cpp11::writable::strings names(n);
  cpp11::writable::strings descriptions(n);
  cpp11::writable::integers values(n);

  for (R_xlen_t i = 0; i < n; ++i) {
    names[i] = entries[i].name;
    descriptions[i] = entries[i].description;
    values[i] = entries[i].value;
  }

  values.names() = names;
  values.attr("descriptions") = descriptions;

  return values;
}

int xml_write_callback(SEXP con, const char * buffer, int len) {
  size_t write_size;

  if ((write_size = R_WriteConnection(con, (void *) buffer, len)) != static_cast<size_t>(len)) {
    cpp11::stop("write failed, expected %l, got %l", len, write_size);
  }
  return write_size;
}

[[cpp11::register]]
cpp11::sexp doc_write_file(cpp11::sexp doc_sxp, cpp11::strings path_sxp, cpp11::strings encoding_sxp, cpp11::integers options_sxp) {
  XPtrDoc doc(doc_sxp);
  const char* path = cpp11::as_cpp<const char*>(path_sxp);
  const char* encoding = cpp11::as_cpp<const char*>(encoding_sxp);
  int options = cpp11::as_cpp<int>(options_sxp);

  xmlSaveCtxtPtr savectx = xmlSaveToFilename(
      path,
      encoding,
      options);
  xmlSaveDoc(savectx, doc.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    cpp11::stop("Error closing file");
  }

  return R_NilValue;
}

[[cpp11::register]]
cpp11::sexp doc_write_connection(cpp11::sexp doc_sxp, cpp11::sexp connection, cpp11::strings encoding_sxp, cpp11::integers options_sxp) {
  XPtrDoc doc(doc_sxp);
  const char* encoding = cpp11::as_cpp<const char*>(encoding_sxp);
  int options = cpp11::as_cpp<int>(options_sxp);

  xmlSaveCtxtPtr savectx = xmlSaveToIO(
      reinterpret_cast<xmlOutputWriteCallback>(xml_write_callback),
      NULL,
      connection,
      encoding,
      options);

  xmlSaveDoc(savectx, doc.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    cpp11::stop("Error closing connection");
  }

  return R_NilValue;
}

[[cpp11::register]]
cpp11::writable::strings doc_write_character(cpp11::sexp doc_sxp, cpp11::strings encoding_sxp, cpp11::integers options_sxp) {
  XPtrDoc doc(doc_sxp);
  const char* encoding = cpp11::as_cpp<const char*>(encoding_sxp);
  int options = options_sxp[0];

  xmlBufferPtr buffer = xmlBufferCreate();

  xmlSaveCtxtPtr savectx = xmlSaveToBuffer(
      buffer,
      encoding,
      options);

  xmlSaveDoc(savectx, doc.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    xmlFree(buffer);
    cpp11::stop("Error writing to buffer");
  }
  cpp11::writable::strings out(Xml2String(buffer->content).asRString());

  xmlFree(buffer);

  return out;
}

[[cpp11::register]]
cpp11::sexp node_write_file(cpp11::sexp node_sxp, cpp11::strings path_sxp, cpp11::strings encoding_sxp, cpp11::integers options_sxp) {
  XPtrNode node(node_sxp);
  const char* path = cpp11::as_cpp<const char*>(path_sxp);
  const char* encoding = cpp11::as_cpp<const char*>(encoding_sxp);
  int options = cpp11::as_cpp<int>(options_sxp);

  xmlSaveCtxtPtr savectx = xmlSaveToFilename(
      path,
      encoding,
      options);
  xmlSaveTree(savectx, node.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    cpp11::stop("Error closing file");
  }

  return R_NilValue;
}

[[cpp11::register]]
cpp11::sexp node_write_connection(cpp11::sexp node_sxp, cpp11::sexp connection, cpp11::strings encoding_sxp, cpp11::integers options_sxp) {
  XPtrNode node(node_sxp);
  const char* encoding = cpp11::as_cpp<const char*>(encoding_sxp);
  int options = cpp11::as_cpp<int>(options_sxp);

  xmlSaveCtxtPtr savectx = xmlSaveToIO(
      (xmlOutputWriteCallback)xml_write_callback,
      NULL,
      connection,
      encoding,
      options);

  xmlSaveTree(savectx, node.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    cpp11::stop("Error closing connection");
  }

  return R_NilValue;
}

[[cpp11::register]]
cpp11::writable::strings node_write_character(cpp11::sexp node_sxp, cpp11::strings encoding_sxp, cpp11::integers options_sxp) {
  XPtrNode node(node_sxp);
  const char* encoding = cpp11::as_cpp<const char*>(encoding_sxp);
  int options = cpp11::as_cpp<int>(options_sxp);

  xmlBufferPtr buffer = xmlBufferCreate();

  xmlSaveCtxtPtr savectx = xmlSaveToBuffer(
      buffer,
      encoding,
      options);

  xmlSaveTree(savectx, node.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    xmlFree(buffer);
    cpp11::stop("Error writing to buffer");
  }
  cpp11::writable::strings out(Xml2String(buffer->content).asRString());
  xmlFree(buffer);

  return out;
}
