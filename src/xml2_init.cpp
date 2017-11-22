#include <Rcpp.h>
#include <R_ext/Rdynload.h>
#include <stdio.h>
#include <libxml/xmlversion.h>
#include <libxml/xmlerror.h>
#include <libxml/parser.h>

void handleError(void* userData, xmlError* error) {
  std::string message = std::string(error->message);
  message.resize(message.size() - 1); // trim off trailing newline

  if (error->level <= 2) {
    Rf_warning("%s [%i]", message.c_str(), error->code);
  } else {
    Rcpp::stop("%s [%i]", message, error->code);
  }
}

// [[Rcpp::export]]
void init_libxml2() {
  // Check that header and libs are compatible
  LIBXML_TEST_VERSION

  xmlInitParser();
  xmlSetStructuredErrorFunc(NULL, handleError);
}

extern "C" {
  void R_unload_xml2(DllInfo *info) {
    xmlCleanupParser();
  }

}

// [[Rcpp::export]]
std::string libxml2_version(){
  return LIBXML_DOTTED_VERSION;
}
