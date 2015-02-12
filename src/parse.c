#include <stdio.h>
#include <Rinternals.h>
#include <string.h>
#include <libxml/tree.h>
#include <libxml/parser.h>

void fin_doc(SEXP ptr){
  if(!R_ExternalPtrAddr(ptr)) return;
  xmlFreeDoc(R_ExternalPtrAddr(ptr));
  R_ClearExternalPtr(ptr);
}

SEXP R_xml_parse(SEXP x){
  const char *str = translateCharUTF8(asChar(x));
  xmlDocPtr doc = xmlParseMemory(str, strlen(str));
  SEXP ptr = PROTECT(R_MakeExternalPtr(doc, R_NilValue, R_NilValue));
  R_RegisterCFinalizerEx(ptr, fin_doc, 1);
  setAttrib(ptr, R_ClassSymbol, mkString("xmlDocPtr"));
  UNPROTECT(1);
  return ptr;  
}

SEXP R_doc_to_string(SEXP ptr){
  if(!R_ExternalPtrAddr(ptr))
    error("ptr is null");  
  xmlChar *s;
  xmlDocDumpMemory(R_ExternalPtrAddr(ptr), &s, NULL);
  return mkString((const char *) s);
}
