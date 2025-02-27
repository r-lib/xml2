#include <Rinternals.h>
#include <libxml/xmlversion.h>
#include <libxml/xmlerror.h>
#include <libxml/parser.h>

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

  //std::string message = std::string(error->message);
  //message.resize(message.size() - 1); // trim off trailing newline
  if (error->level <= 2) {
    Rf_warning("%s [%i]", error->message, (int) error->code);
  } else {
    Rf_error("%s [%i]", error->message, (int) error->code);
  }
}

void handleGenericError(void *ctx, const char *fmt, ...){
  char buffer[BUFSIZ];
  va_list arg;

  if (fmt == NULL) fmt = "(null)";

  va_start(arg, fmt);
  vsnprintf(buffer, BUFSIZ, fmt, arg);
  Rf_error("%s", buffer);
}

void init_libxml2_library() {
  // Check that header and libs are compatible
  LIBXML_TEST_VERSION

  xmlInitParser();
  xmlSetStructuredErrorFunc(NULL, handleStructuredError);
  xmlSetGenericErrorFunc(NULL, handleGenericError);
}

