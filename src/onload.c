#include <stdio.h>
#include <Rinternals.h>
#include <libxml/tree.h>
#include <libxml/parser.h>

// load required macro, see docs
SEXP R_xml_init(){
  LIBXML_TEST_VERSION
  return R_NilValue;
}
