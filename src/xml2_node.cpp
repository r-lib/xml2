#include <Rcpp.h>
using namespace Rcpp;
#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
CharacterVector node_name(XPtr<xmlNode> node) {
  return xmlCharToRChar(node->name);
}

// [[Rcpp::export]]
CharacterVector node_format(XPtr<xmlDoc> doc, XPtr<xmlNode> node,
                            bool format = true,
                            int indent = 0) {
  xmlBufferPtr buffer = xmlBufferCreate();
  int size = xmlNodeDump(buffer, doc.get(), node.get(), indent, format);

  CharacterVector out = xmlCharToRChar(buffer->content);
  xmlFree(buffer);

  return out;
}
