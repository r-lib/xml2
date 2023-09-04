#include <cpp11.hpp>

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/xmlschemas.h>
#include <vector>
#include <string>

#include "xml2_types.h"
#include "xml2_utils.h"

void handleSchemaError(void* userData, xmlError* error) {
  std::vector<std::string> * vec = (std::vector<std::string> *) userData;
  std::string message = std::string(error->message);
  message.resize(message.size() - 1);
  vec->push_back(message);
}

[[cpp11::register]]
cpp11::logicals doc_validate(cpp11::sexp doc_sxp, cpp11::sexp schema_sxp) {

  XPtrDoc doc(doc_sxp);
  XPtrDoc schema(schema_sxp);

  xmlLineNumbersDefault(1);

  std::vector<std::string> vec;

  xmlSchemaParserCtxtPtr cptr = xmlSchemaNewDocParserCtxt(schema.checked_get());

  xmlSchemaSetParserStructuredErrors(cptr, handleSchemaError, &vec);

  xmlSchemaPtr sptr = xmlSchemaParse(cptr);

  xmlSchemaValidCtxtPtr vptr = xmlSchemaNewValidCtxt(sptr);

  xmlSchemaSetValidStructuredErrors(vptr, handleSchemaError, &vec);

  bool valid = (xmlSchemaValidateDoc(vptr, doc.checked_get()) == 0);
  cpp11::writable::logicals out{valid};

  xmlSchemaFreeParserCtxt(cptr);
  xmlSchemaFreeValidCtxt(vptr);
  xmlSchemaFree(sptr);

  out.attr("errors") = vec;

  return out;
}
