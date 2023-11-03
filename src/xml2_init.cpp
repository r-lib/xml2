#include <cpp11.hpp>

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

#define BEGIN_CPP try {

#define END_CPP                                                                \
  }                                                                            \
  catch (std::exception & e) {                                                 \
    Rf_error("C++ exception: %s", e.what());                                   \
  }

void handleStructuredError(void* userData, xmlError* error) {

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

[[cpp11::register]]
cpp11::sexp init_libxml2() {
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

[[cpp11::register]]
cpp11::strings libxml2_version_(){
  return cpp11::writable::strings(cpp11::r_string(LIBXML_DOTTED_VERSION));
}
