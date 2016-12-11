#include <Rcpp.h>
using namespace Rcpp;

#include <libxslt/xsltInternals.h>
#include <libxslt/transform.h>
#include "xml2_types.h"

// [[Rcpp::export]]
XPtrDoc doc_xslt_apply(XPtrDoc doc, XPtrDoc xslt) {
  xmlDocPtr docPtr = doc.checked_get();
  xsltStylesheetPtr	xsltPtr = xsltParseStylesheetDoc(xslt.checked_get());
  xmlDocPtr res = xsltApplyStylesheet(xsltPtr, docPtr, NULL);
  return XPtrDoc(res);
}
