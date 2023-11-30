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

// [[export]]
extern "C" SEXP xml_save_options_() {

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

  SEXP names = PROTECT(Rf_allocVector(STRSXP, n));
  SEXP descriptions = PROTECT(Rf_allocVector(STRSXP, n));
  SEXP values = PROTECT(Rf_allocVector(INTSXP, n));


  for (R_xlen_t i = 0;i < n; ++i) {
    SET_STRING_ELT(names, i, Rf_mkChar(entries[i].name));
    SET_STRING_ELT(descriptions, i, Rf_mkChar(entries[i].description));
    INTEGER(values)[i] = entries[i].value;
  }

  Rf_setAttrib(values, R_NamesSymbol, names);
  Rf_setAttrib(values, Rf_install("descriptions"), descriptions);

  UNPROTECT(3);

  return values;
}

int xml_write_callback(SEXP con, const char * buffer, int len) {
  size_t write_size;

  if ((write_size = R_WriteConnection(con, (void *) buffer, len)) != static_cast<size_t>(len)) {
    Rf_error("write failed, expected %i, got %zu", len, write_size);
  }
  return write_size;
}

// [[export]]
extern "C" SEXP doc_write_file(SEXP doc_sxp, SEXP path_sxp, SEXP encoding_sxp, SEXP options_sxp) {

  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  const char* path = CHAR(STRING_ELT(path_sxp, 0));
  const char* encoding = CHAR(STRING_ELT(encoding_sxp, 0));
  int options = INTEGER(options_sxp)[0];

  xmlSaveCtxtPtr savectx = xmlSaveToFilename(
      path,
      encoding,
      options);
  xmlSaveDoc(savectx, doc.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    Rf_error("Error closing file");
  }

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP doc_write_connection(SEXP doc_sxp, SEXP connection, SEXP encoding_sxp, SEXP options_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  const char* encoding = CHAR(STRING_ELT(encoding_sxp, 0));
  int options = INTEGER(options_sxp)[0];

  SEXP con = R_GetConnection(connection);

  xmlSaveCtxtPtr savectx = xmlSaveToIO(
      reinterpret_cast<xmlOutputWriteCallback>(xml_write_callback),
      NULL,
      con,
      encoding,
      options);

  xmlSaveDoc(savectx, doc.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    Rf_error("Error closing connection");
  }

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP doc_write_character(SEXP doc_sxp, SEXP encoding_sxp, SEXP options_sxp) {
  BEGIN_CPP
  XPtrDoc doc(doc_sxp);
  const char* encoding = CHAR(STRING_ELT(encoding_sxp, 0));
  int options = INTEGER(options_sxp)[0];

  xmlBufferPtr buffer = xmlBufferCreate();

  xmlSaveCtxtPtr savectx = xmlSaveToBuffer(
      buffer,
      encoding,
      options);

  xmlSaveDoc(savectx, doc.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    xmlFree(buffer);
    Rf_error("Error writing to buffer");
  }
  SEXP out = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_STRING_ELT(out, 0, Xml2String(buffer->content).asRString());

  xmlFree(buffer);

  UNPROTECT(1);

  return out;
  END_CPP
}

// [[export]]
extern "C" SEXP node_write_file(SEXP node_sxp, SEXP path_sxp, SEXP encoding_sxp, SEXP options_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);
  const char* path = CHAR(STRING_ELT(path_sxp, 0));
  const char* encoding = CHAR(STRING_ELT(encoding_sxp, 0));
  int options = INTEGER(options_sxp)[0];

  xmlSaveCtxtPtr savectx = xmlSaveToFilename(
      path,
      encoding,
      options);
  xmlSaveTree(savectx, node.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    Rf_error("Error closing file");
  }

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP node_write_connection(SEXP node_sxp, SEXP connection, SEXP encoding_sxp, SEXP options_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);
  SEXP con = R_GetConnection(connection);
  const char* encoding = CHAR(STRING_ELT(encoding_sxp, 0));
  int options = INTEGER(options_sxp)[0];

  xmlSaveCtxtPtr savectx = xmlSaveToIO(
      (xmlOutputWriteCallback)xml_write_callback,
      NULL,
      con,
      encoding,
      options);

  xmlSaveTree(savectx, node.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    Rf_error("Error closing connection");
  }

  return R_NilValue;
  END_CPP
}

// [[export]]
extern "C" SEXP node_write_character(SEXP node_sxp, SEXP encoding_sxp, SEXP options_sxp) {
  BEGIN_CPP
  XPtrNode node(node_sxp);
  const char* encoding = CHAR(STRING_ELT(encoding_sxp, 0));
  int options = INTEGER(options_sxp)[0];

  xmlBufferPtr buffer = xmlBufferCreate();

  xmlSaveCtxtPtr savectx = xmlSaveToBuffer(
      buffer,
      encoding,
      options);

  xmlSaveTree(savectx, node.checked_get());
  if (xmlSaveClose(savectx) == -1) {
    xmlFree(buffer);
    Rf_error("Error writing to buffer");
  }
  SEXP out = PROTECT(Rf_ScalarString(Xml2String(buffer->content).asRString()));
  xmlFree(buffer);

  UNPROTECT(1);
  return out;
  END_CPP
}
