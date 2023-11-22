#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/parser.h>
#include <libxml/xmlschemas.h>
#include <vector>
#include <string>

#include "xml2_types.h"
#include "xml2_utils.h"

/* * *
 * Author: Nick Wellnhofer <wellnhofer@aevum.de>
 * Date:   Thu, 21 Sep 2023 23:52:52 +0200
 * https://github.com/GNOME/libxml2/commit/45470611b047db78106dcb2fdbd4164163c15ab7
 *
 * error: Make xmlGetLastError return a const error
 */
#if defined(LIBXML_VERSION) && (LIBXML_VERSION >= 21200)
void handleSchemaError(void* userData, const xmlError* error) {
#else
void handleSchemaError(void* userData, xmlError* error) {
#endif
  std::vector<std::string> * vec = (std::vector<std::string> *) userData;
  std::string message = std::string(error->message);
  message.resize(message.size() - 1);
  vec->push_back(message);
}

// [[export]]
extern "C" SEXP doc_validate(SEXP doc_sxp, SEXP schema_sxp) {

  XPtrDoc doc(doc_sxp);
  XPtrDoc schema(schema_sxp);

  xmlLineNumbersDefault(1);

  BEGIN_CPP

  std::vector<std::string> vec;

  xmlSchemaParserCtxtPtr cptr = xmlSchemaNewDocParserCtxt(schema.checked_get());

  xmlSchemaSetParserStructuredErrors(cptr, handleSchemaError, &vec);

  xmlSchemaPtr sptr = xmlSchemaParse(cptr);

  xmlSchemaValidCtxtPtr vptr = xmlSchemaNewValidCtxt(sptr);

  xmlSchemaSetValidStructuredErrors(vptr, handleSchemaError, &vec);

  SEXP out = PROTECT(Rf_allocVector(LGLSXP, 1));

  LOGICAL(out)[0] = xmlSchemaValidateDoc(vptr, doc.checked_get()) == 0;

  xmlSchemaFreeParserCtxt(cptr);
  xmlSchemaFreeValidCtxt(vptr);
  xmlSchemaFree(sptr);

  SEXP errors = PROTECT(Rf_allocVector(STRSXP, vec.size()));
  for (size_t i = 0; i < vec.size(); ++i) {
    SET_STRING_ELT(errors, i, Rf_mkCharLenCE(vec[i].c_str(), vec[i].size(), CE_UTF8));
  }
  Rf_setAttrib(out, Rf_install("errors"), errors);


  UNPROTECT(2);
  return out;

  END_CPP
}
