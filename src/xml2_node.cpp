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
  xmlNodeDump(buffer, doc.get(), node.get(), indent, format);

  CharacterVector out = xmlCharToRChar(buffer->content);
  xmlFree(buffer);

  return out;
}

// [[Rcpp::export]]
Rcpp::List node_children(XPtrNode node) {

  int n = 0;
  for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next)
    n++;

  Rcpp::List out(n);
  int i = 0;
  for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next) {
    out[i] = XPtrNode(cur);
    i++;
  }

  return out;
}
