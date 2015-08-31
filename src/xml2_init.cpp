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
    Rcpp::warning("%s [%i]", message, error->code);
  } else {
    Rcpp::stop("%s [%i]", message, error->code);
  }
}

extern "C" {

  void R_init_xml2(DllInfo *info) {
    // Check that header and libs are compatible
    LIBXML_TEST_VERSION

    xmlInitParser();
    xmlSetStructuredErrorFunc(NULL, handleError);
  }

  void R_unload_xml2(DllInfo *info) {
    xmlCleanupParser();
  }

}

// [[Rcpp::export]]
std::string libxml2_version(){
  return LIBXML_DOTTED_VERSION;
}
