#include <Rcpp.h>
#include <libxml/tree.h>

using namespace Rcpp;
#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
CharacterVector node_name(XPtrNode node) {
  return xmlCharToRChar(node->name);
}

// [[Rcpp::export]]
CharacterVector node_text(XPtrNode node) {
  xmlChar* s = xmlNodeGetContent(node.get());
  CharacterVector out = xmlCharToRChar(s);
  if (s != NULL)
    xmlFree(s);

  return out;
}

// [[Rcpp::export]]
CharacterVector node_attr(XPtrNode node, std::string name) {
  xmlChar* s = xmlGetProp(node.get(), (xmlChar*) name.c_str());

  CharacterVector out = xmlCharToRChar(s);
  if (s != NULL)
    xmlFree(s);

  return out;
}

// [[Rcpp::export]]
CharacterVector node_format(XPtrDoc doc, XPtrNode node,
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

// [[Rcpp::export]]
void node_write(XPtrNode n, XPtrDoc d, std::string path) {
  FILE* f = fopen(path.c_str(), "wb");
  xmlElemDump(f, d.get(), n.get());
  fclose(f);
}
