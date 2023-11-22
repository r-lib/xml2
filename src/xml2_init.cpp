#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <R_ext/Rdynload.h>
#include <stdio.h>
#include <libxml/xmlversion.h>
#include <libxml/xmlerror.h>
#include <libxml/parser.h>
#include <string>
#include "xml2_utils.h"

/* * *
 * Author: Nick Wellnhofer <wellnhofer@aevum.de>
 * Date:   Thu, 21 Sep 2023 23:52:52 +0200
 * https://github.com/GNOME/libxml2/commit/45470611b047db78106dcb2fdbd4164163c15ab7
 *
 * error: Make xmlGetLastError return a const error
 */
#if defined(LIBXML_VERSION) && (LIBXML_VERSION >= 21200)
void handleStructuredError(void* userData, const xmlError* error) {
#else
void handleStructuredError(void* userData, xmlError* error) {
#endif

  BEGIN_CPP
  std::string message = std::string(error->message);
  message.resize(message.size() - 1); // trim off trailing newline

  if (error->level <= 2) {
    Rf_warning("%s [%i]", message.c_str(), (int) error->code);
  } else {
    Rf_error("%s [%i]", message.c_str(), (int) error->code);
  }
  END_CPP

}

void handleGenericError(void *ctx, const char *fmt, ...)
{
  char buffer[BUFSIZ];
  va_list arg;

  if (fmt == NULL) fmt = "(null)";

  va_start(arg, fmt);
  vsnprintf(buffer, BUFSIZ, fmt, arg);
  Rf_error(buffer);
}

// [[export]]
extern "C" SEXP init_libxml2() {
  // Check that header and libs are compatible
  LIBXML_TEST_VERSION

  xmlInitParser();
  xmlSetStructuredErrorFunc(NULL, handleStructuredError);
  xmlSetGenericErrorFunc(NULL, handleGenericError);

  return R_NilValue;
}

extern "C" {
  void R_unload_xml2(DllInfo *info) {
    xmlCleanupParser();
  }

}

// [[export]]
extern "C" SEXP libxml2_version_(){
  return Rf_mkString(LIBXML_DOTTED_VERSION);
}
