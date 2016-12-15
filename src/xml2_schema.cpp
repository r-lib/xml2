#include <Rcpp.h>
using namespace Rcpp;

#include <libxml/xmlschemas.h>
#include "xml2_types.h"

void handleSchemaError(void* userData, xmlError* error) {
  Rcpp::CharacterVector * vec = (Rcpp::CharacterVector *) userData;
  std::string message = std::string(error->message);
  message.resize(message.size() - 1);
  vec->push_back(message);
}

// [[Rcpp::export]]
Rcpp::LogicalVector doc_validate(XPtrDoc doc, XPtrDoc schema) {
  xmlLineNumbersDefault(1);
  Rcpp::CharacterVector vec;
  xmlSchemaParserCtxtPtr cptr = xmlSchemaNewDocParserCtxt(schema.checked_get());
  xmlSchemaSetParserStructuredErrors(cptr, handleSchemaError, &vec);
  xmlSchemaPtr sptr = xmlSchemaParse(cptr);
  xmlSchemaValidCtxtPtr vptr = xmlSchemaNewValidCtxt(sptr);
  xmlSchemaSetValidStructuredErrors(vptr, handleSchemaError, &vec);
  Rcpp::LogicalVector out;
  out.push_back(xmlSchemaValidateDoc(vptr, doc.checked_get()));
  out.attr("errors") = vec;
  return out;
}
