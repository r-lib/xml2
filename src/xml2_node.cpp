#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>

using namespace Rcpp;
#include "xml2_types.h"

// [[Rcpp::export]]
CharacterVector node_name(XPtrNode node) {
  return xmlCharToRChar(node->name);
}

// [[Rcpp::export]]
CharacterVector node_text(XPtrNode node) {
  return Xml2Char(xmlNodeGetContent(node.get())).string();
}

// [[Rcpp::export]]
CharacterVector node_attr(XPtrNode node, std::string name) {
  return Xml2Char(xmlGetProp(node.get(), (xmlChar*) name.c_str())).string();
}

// [[Rcpp::export]]
CharacterVector node_format(XPtrDoc doc, XPtrNode node,
                            bool format = true,
                            int indent = 0) {
  boost::shared_ptr<xmlBuffer> buffer(xmlBufferCreate(), xmlFree);
  xmlNodeDump(buffer.get(), doc.get(), node.get(), indent, format);

  return xmlCharToRChar(buffer->content);
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

// [[Rcpp::export]]
CharacterVector node_path(XPtrNode n) {
  return Xml2Char(xmlGetNodePath(n.get())).string();
}

