#include <R_ext/Rdynload.h>
#include <stdio.h>
#include <libxml/xmlversion.h>

void R_init_xml2(DllInfo *info) {
  // Check that header and libs are compatible
  LIBXML_TEST_VERSION
}
