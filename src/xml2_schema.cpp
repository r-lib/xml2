#include <Rcpp.h>
using namespace Rcpp;

#include <libxml/xmlschemas.h>
#include "xml2_types.h"

void handleSchemaError(void* userData, xmlError* error) {
  std::string message = std::string(error->message);
  message.resize(message.size() - 1); // trim off trailing newline

  if (error->level <= 2) {
    Rcpp::warning("%s [%i]", message, error->code);
  } else {
    Rcpp::stop("%s [%i]", message, error->code);
  }
}

// [[Rcpp::export]]
bool doc_validate(XPtrDoc doc, XPtrDoc schema) {
  xmlLineNumbersDefault(1);
  xmlSchemaParserCtxtPtr cptr = xmlSchemaNewDocParserCtxt(schema.checked_get());
  xmlSchemaSetParserStructuredErrors(cptr, handleSchemaError, NULL);
  xmlSchemaPtr sptr = xmlSchemaParse(cptr);
  xmlSchemaValidCtxtPtr vptr = xmlSchemaNewValidCtxt(sptr);
  xmlSchemaSetValidStructuredErrors(vptr, handleSchemaError, NULL);
  int out = xmlSchemaValidateDoc(vptr, doc.checked_get());
  return out == 0;
}
