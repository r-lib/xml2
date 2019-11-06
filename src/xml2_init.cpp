#include <Rcpp.h>
#include <R_ext/Rdynload.h>
#include <stdio.h>
#include <libxml/xmlversion.h>
#include <libxml/xmlerror.h>
#include <libxml/parser.h>

void handleStructuredError(void* userData, xmlError* error) {
  std::string message = std::string(error->message);
  message.resize(message.size() - 1); // trim off trailing newline

  if (error->level <= 2) {
    Rf_warning("%s [%i]", message.c_str(), error->code);
  } else {
    Rcpp::stop("%s [%i]", message, error->code);
  }
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

// [[Rcpp::export]]
void init_libxml2() {
  // Check that header and libs are compatible
  LIBXML_TEST_VERSION

  xmlInitParser();
  xmlSetStructuredErrorFunc(NULL, handleStructuredError);
  xmlSetGenericErrorFunc(NULL, handleGenericError);
}

extern "C" {
  void R_unload_xml2(DllInfo *info) {
    xmlCleanupParser();
  }

}

// [[Rcpp::export]]
std::string libxml2_version_(){
  return LIBXML_DOTTED_VERSION;
}
