#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>
#include <boost/algorithm/string/trim.hpp>

using namespace Rcpp;
#include "xml2_types.h"
#include "xml2_utils.h"

template<typename T> // for xmlAttr and xmlNode
std::string nodeName(T* node, CharacterVector nsMap) {
  std::string name = Xml2String(node->name).asStdString();
  if (nsMap.size() == 0)
    return name;

  xmlNs* ns = node->ns;
  if (ns == NULL)
    return name;

  std::string prefix = NsMap(nsMap).findPrefix(Xml2String(ns->href).asStdString());
  return prefix + ":" + name;
}

// [[Rcpp::export]]
CharacterVector node_name(XPtrNode node, CharacterVector nsMap) {
  return asCharacterVector(nodeName(node.get(), nsMap));
}

// [[Rcpp::export]]
CharacterVector node_text(XPtrNode node, bool trim) {
  std::string text = Xml2String(xmlNodeGetContent(node.get())).asStdString();

  if (trim)
    boost::algorithm::trim(text);

  return asCharacterVector(text.c_str());
}

// [[Rcpp::export]]
SEXP node_attr(XPtrNode node, std::string name, CharacterVector missing,
                 CharacterVector nsMap) {
  if (missing.size() != 1)
    Rcpp::stop("`missing` should be length 1");
  SEXP missingVal = missing[0];

  xmlChar* string;
  if (nsMap.size() == 0) {
    string = xmlGetProp(node.get(), asXmlChar(name));
  } else {
    size_t colon = name.find(":");
    if (colon == std::string::npos) {
      // Has namespace spec, but attribute not qualified, so look for attribute
      // without namespace
      string = xmlGetNoNsProp(node.get(), asXmlChar(name));
    } else {
      // Split name into prefix & attr, then look up full url
      std::string
      prefix = name.substr(0, colon),
        attr = name.substr(colon + 1, name.size() - 1);

      std::string url = NsMap(nsMap).findUrl(prefix);

      string = xmlGetNsProp(node.get(), asXmlChar(attr), asXmlChar(url));
    }
  }

  return CharacterVector(Xml2String(string).asRString(missingVal));
}

// [[Rcpp::export]]
CharacterVector node_attrs(XPtrNode node, CharacterVector nsMap) {

  int n = 0;
  for(xmlAttr* cur = node->properties; cur != NULL; cur = cur->next)
    n++;

  CharacterVector names(n), values(n);

  int i = 0;
  for(xmlAttr* cur = node->properties; cur != NULL; cur = cur->next) {
    names[i] = nodeName(cur, nsMap);

    xmlNs* ns = cur->ns;
    if (ns == NULL) {
      if (nsMap.size() > 0) {
        values[i] = Xml2String(xmlGetNoNsProp(node.get(), cur->name)).asRString();
      } else {
        values[i] = Xml2String(xmlGetProp(node.get(), cur->name)).asRString();
      }
    } else {
      values[i] = Xml2String(xmlGetNsProp(node.get(), cur->name, ns->href)).asRString();
    }

    ++i;
  }

  values.attr("names") = wrap<CharacterVector>(names);
  return values;
}

// [[Rcpp::export]]
std::string node_format(XPtrDoc doc, XPtrNode node,
                        bool format = true,
                        int indent = 0) {
  boost::shared_ptr<xmlBuffer> buffer(xmlBufferCreate(), xmlFree);
  xmlNodeDump(buffer.get(), doc.get(), node.get(), indent, format);

  return Xml2String(buffer->content).asStdString();
}

List asList(std::vector<xmlNode*> nodes) {
  List out(nodes.size());
  for (size_t i = 0; i < nodes.size(); ++i)
    out[i] = XPtrNode(nodes[i]);

  return out;
}

// [[Rcpp::export]]
Rcpp::List node_children(XPtrNode node, bool onlyNode = true) {
  std::vector<xmlNode*> out;

  for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (onlyNode && cur->type != XML_ELEMENT_NODE)
      continue;
    out.push_back(cur);
  }

  return asList(out);
}

// [[Rcpp::export]]
int node_length(XPtrNode node, bool onlyNode = true) {
  int i = 0;
  for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (onlyNode && cur->type != XML_ELEMENT_NODE)
      continue;
    ++i;
  }

  return i;
}


// [[Rcpp::export]]
Rcpp::List node_parents(XPtrNode node) {
  std::vector<xmlNode*> out;

  for(xmlNode* cur = node->parent; cur != NULL; cur = cur->parent) {
    if (cur->type != XML_ELEMENT_NODE)
      continue;
    out.push_back(cur);
  }

  return asList(out);
}

// [[Rcpp::export]]
Rcpp::List node_siblings(XPtrNode node, bool onlyNode = true) {
  std::vector<xmlNode*> out;

  xmlNode* parent = node->parent;
  if (parent == NULL)
    return List();

  for(xmlNode* cur = parent->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (cur == node)
      continue;
    if (onlyNode && cur->type != XML_ELEMENT_NODE)
      continue;

    out.push_back(cur);
  }

  return asList(out);
}


// [[Rcpp::export]]
XPtrNode node_parent(XPtrNode n) {
  if (n->parent == NULL)
    Rcpp::stop("Parent does not exist");
  return XPtrNode(n->parent);
}

// [[Rcpp::export]]
void node_write(XPtrNode n, XPtrDoc d, std::string path) {
  FILE* f = fopen(path.c_str(), "wb");
  xmlElemDump(f, d.get(), n.get());
  fclose(f);
}

// [[Rcpp::export]]
std::string node_path(XPtrNode n) {
  return Xml2String(xmlGetNodePath(n.get())).asStdString();
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
