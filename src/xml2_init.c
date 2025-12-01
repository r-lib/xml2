#include <Rinternals.h>
#include <libxml/xmlversion.h>
#include <libxml/xmlerror.h>
#include <libxml/parser.h>
#include <string.h>

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

  int len = strlen(error->message);
  if(len > 2){
    error->message[len-1] = '\0';
  }

  //Workarounds for xml bugs in R.app https://github.com/r-lib/xml2/issues/458
  //Another solution is to use a static libxml2
#ifdef __APPLE__
  xmlParserCtxt *ctxt = error->ctxt;
  static unsigned char icns[5] = { 'i', 'c', 'n', 's', '\0' };
  static unsigned char mm[3] = { 'M', 'M', '\0' };
  if(error->code == XML_ERR_DOCUMENT_EMPTY && ctxt->input && ctxt->input->base){
    if(!xmlStrcmp(ctxt->input->base, icns) || !xmlStrcmp(ctxt->input->base, mm)){
      return;
    }
  }
#endif

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

#if LIBXML_VERSION >= 21500

static xmlExternalEntityLoader defaultLoader = NULL;

xmlParserInput *download_file_callback(const char *url){
  SEXP arg = PROTECT(Rf_mkString(url));
  SEXP expr = PROTECT(Rf_install("download_file_callback"));
  SEXP call = PROTECT(Rf_lang2(expr, arg));
  SEXP env = R_FindNamespace(Rf_mkString("xml2"));
  int err = 1;
  SEXP out = PROTECT(R_tryEvalSilent(call, env, &err));
  if(err) return NULL;
  xmlParserInputFlags flags = XML_INPUT_BUF_STATIC | XML_INPUT_USE_SYS_CATALOG;
  xmlParserInput *buf = xmlNewInputFromMemory(url, RAW(out), Rf_length(out), flags);
  //xmlParserInputBuffer *buf = xmlParserInputBufferCreateMem((char*) RAW(out), Rf_length(out), XML_CHAR_ENCODING_UTF8);
  UNPROTECT(4);
  return buf;
}

static xmlParserInputPtr myExternalEntityLoader(const char *URL, const char *ID, xmlParserCtxtPtr ctxt){
  if (URL && (strncmp(URL, "http://", 7) == 0 || strncmp(URL, "https://", 8) == 0)) {
    //REprintf("Fetching external resource %s\n", URL);
    xmlParserInput *buf = download_file_callback(URL);
    if(buf) return buf;
  }
  // Fallback to default behavior
  if (defaultLoader)
    return defaultLoader(URL, ID, ctxt);
  return NULL;
}

#endif


void init_libxml2_library(void) {
  // Check that header and libs are compatible
  LIBXML_TEST_VERSION

  xmlInitParser();
  xmlSetStructuredErrorFunc(NULL, handleStructuredError);
  xmlSetGenericErrorFunc(NULL, handleGenericError);

  // Set custom download callback
#if LIBXML_VERSION >= 21500
  defaultLoader = xmlGetExternalEntityLoader();
  xmlSetExternalEntityLoader(myExternalEntityLoader);
#endif
}
