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
bool node_attr_exists(XPtrNode node, std::string name) {
  return xmlHasProp(node.get(), (xmlChar*) name.c_str()) != NULL;
}

// [[Rcpp::export]]
CharacterVector node_attrs(XPtrNode node) {

  int n = 0;
  for(xmlAttr* cur = node->properties; cur != NULL; cur = cur->next)
    n++;

  CharacterVector names(n), values(n), namespaces(n);

  bool hasNs = false;
  int i = 0;
  for(xmlAttr* cur = node->properties; cur != NULL; cur = cur->next) {
    names[i] = asCHARSXP(cur->name);
    values[i] = asCHARSXP(xmlGetProp(node.get(), cur->name));

    xmlNs* ns = cur->ns;
    if (ns != NULL)
      hasNs = true;
    namespaces[i] = asCHARSXP(ns == NULL ? NULL : ns->href);
    ++i;
  }

  values.attr("names") = wrap<CharacterVector>(names);
  if (hasNs)
    values.attr("ns") = wrap<CharacterVector>(namespaces);

  return values;
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
XPtrNode node_parent(XPtrNode n) {
  return XPtrNode(n->parent);
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

// [[Rcpp::export]]
LogicalVector nodes_duplicated(ListOf<XPtrNode> nodes) {
  std::set<xmlNode*> seen;

  int n = nodes.size();
  LogicalVector out(n);

  for (int i = 0; i < n; ++i) {
    XPtrNode node = nodes[i];
    out[i] = !seen.insert(node.get()).second;
  }

  return out;
}

// [[Rcpp::export]]
int node_type(XPtrNode node) {
  return node->type;
}
