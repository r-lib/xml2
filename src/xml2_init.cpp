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
 * Date:   Tue, 24 Oct 2023 15:02:36 +0200
 * https://github.com/GNOME/libxml2/commit/61034116d0a3c8b295c6137956adc3ae55720711
 *
 * error: Make more xmlError structs constant
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
  Rf_error("%s", buffer);
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
