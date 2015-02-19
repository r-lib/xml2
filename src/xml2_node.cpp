#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>

using namespace Rcpp;
#include "xml2_types.h"

std::string findPrefix(xmlNs* ns, CharacterVector nsMap) {
  String url = Xml2Char(ns->href);

  int pos = -1;
  for (int i = 0; i < nsMap.length(); ++i) {
    String urli = nsMap[i];
    if (urli == url) {
      pos = i;
      continue;
    }
  }
  if (pos == -1)
    stop("Couldn't find prefix for url %s", (char *) ns->href);

  return std::string(as<CharacterVector>(nsMap.attr("names"))[pos]);
}
std::string findUrl(std::string prefix, CharacterVector nsMap) {
  CharacterVector prefixes = as<CharacterVector>(nsMap.attr("names"));

  for (int i = 0; i < nsMap.length(); ++i) {
    if (prefix == std::string(prefixes[i]))
      return std::string(nsMap[i]);
  }
  stop("Couldn't find prefix for prefix %s", prefix);
  return "";
}

template<typename T> // for xmlAttr and xmlNode
std::string nodeName(T* node, CharacterVector nsMap) {
  std::string name = Xml2Char(node->name);
  if (nsMap.size() == 0)
    return name;

  xmlNs* ns = node->ns;
  if (ns == NULL)
    return name;

  return findPrefix(ns, nsMap) + ":" + name;
}

// [[Rcpp::export]]
std::string node_name(XPtrNode node, CharacterVector nsMap) {
  return nodeName(node.get(), nsMap);
}

// [[Rcpp::export]]
std::string node_text(XPtrNode node) {
  return Xml2Char(xmlNodeGetContent(node.get()));
}

// [[Rcpp::export]]
std::string node_attr(XPtrNode node, std::string name, CharacterVector nsMap) {
  if (nsMap.size() == 0)
    return Xml2Char(xmlGetProp(node.get(), (xmlChar*) name.c_str()));

  size_t colon = name.find(":");
  if (colon == std::string::npos) {
    // Has namespace spec, but attribute not qualified, so look for attribute
    // without namespace
    return Xml2Char(xmlGetNoNsProp(node.get(), (xmlChar*) name.c_str()));
  } else {
    // Split name into prefix & attr, then look up full url
    std::string
      prefix = name.substr(0, colon),
      attr = name.substr(colon + 1, name.size() - 1);

    std::string url = findUrl(prefix, nsMap);

    return Xml2Char(xmlGetNsProp(node.get(), (xmlChar*) attr.c_str(), (xmlChar*) url.c_str()));
  }
}

// [[Rcpp::export]]
bool node_attr_exists(XPtrNode node, std::string name) {
  return xmlHasProp(node.get(), (xmlChar*) name.c_str()) != NULL;
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
        values[i] = Xml2Char(xmlGetNoNsProp(node.get(), cur->name));
      } else {
        values[i] = Xml2Char(xmlGetProp(node.get(), cur->name));
      }
    } else {
      values[i] = Xml2Char(xmlGetNsProp(node.get(), cur->name, ns->href));
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

  return Xml2Char(buffer->content);
}


// [[Rcpp::export]]
int node_count_children(XPtrNode node) {

  int n = 0;
  for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (cur->type != XML_ELEMENT_NODE)
      continue;
    n++;
  }

  return n;
}

// [[Rcpp::export]]
Rcpp::List node_children(XPtrNode node) {
  Rcpp::List out(node_count_children(node));
  int i = 0;
  for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (cur->type != XML_ELEMENT_NODE)
      continue;
    out[i] = XPtrNode(cur);
    i++;
  }

  return out;
}

// [[Rcpp::export]]
Rcpp::List node_contents(XPtrNode node) {

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
std::string node_path(XPtrNode n) {
  return Xml2Char(xmlGetNodePath(n.get()));
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
