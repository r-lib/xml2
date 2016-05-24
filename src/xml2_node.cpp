#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <fstream>
#include <sstream>

using namespace Rcpp;
#include "xml2_types.h"
#include "xml2_utils.h"

#define LIBXML_DEBUG_ENABLED
#include <libxml/debugXML.h>

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
void node_set_name(XPtrNode node, std::string value) {
  return xmlNodeSetName(node, asXmlChar(value));
}

// [[Rcpp::export]]
CharacterVector node_text(XPtrNode node, bool trim) {
  std::string text = Xml2String(xmlNodeGetContent(node.get())).asStdString();

  if (trim)
    boost::algorithm::trim(text);

  return asCharacterVector(text.c_str());
}

bool hasPrefix(std::string lhs, std::string rhs) {
  if (lhs.length() > rhs.length()) {
    return false;
  }

  return std::equal(
      lhs.begin(),
      lhs.end(),
      rhs.begin());
}

const xmlChar* xmlNsDefinition(xmlNodePtr node, xmlChar* lookup) {
  xmlNsPtr next = node->nsDef;

  while(next != NULL) {
    // default namespace
    if (xmlStrEqual(next->prefix, lookup)) {
      return next->href;
    }
    next = next->next;
  }

  return NULL;
}

// [[Rcpp::export]]
SEXP node_attr(XPtrNode node, std::string name, CharacterVector missing,
                 CharacterVector nsMap) {
  if (missing.size() != 1)
    Rcpp::stop("`missing` should be length 1");
  SEXP missingVal = missing[0];

  const xmlChar* string;
  if (name == "xmlns") {
    string = xmlNsDefinition(node, NULL);
  } else if (hasPrefix("xmlns:", name)) {
    string = xmlNsDefinition(node,
        asXmlChar(name.substr(6)));
  } else {
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
  }

  return CharacterVector(Xml2String(string).asRString(missingVal));
}

// [[Rcpp::export]]
CharacterVector node_attrs(XPtrNode node, CharacterVector nsMap) {

  int n = 0;
  // attributes
  for(xmlAttr* cur = node->properties; cur != NULL; cur = cur->next)
    n++;

  // namespace definitions
  for(xmlNsPtr cur = node->nsDef; cur != NULL; cur = cur->next)
    n++;

  CharacterVector names(n), values(n);

  int i = 0;
  for(xmlAttr* cur = node->properties; cur != NULL; cur = cur->next, ++i) {
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
  }

  // Namespace definitions as well
  for(xmlNsPtr cur = node->nsDef; cur != NULL; cur = cur->next, ++i) {
    if (cur->prefix == NULL) {
      names[i] = "xmlns";
    } else {
      names[i] = "xmlns:" + Xml2String(cur->prefix).asStdString();
    }
    values[i] = Xml2String(cur->href).asRString();
  }

  values.attr("names") = wrap<CharacterVector>(names);
  return values;
}


// Fix the tree by removing the namespace pointers to the given namespace
void xmlRemoveNamespace(xmlNodePtr tree, xmlNsPtr ns) {

  // From https://github.com/GNOME/libxml2/blob/v2.9.2/tree.c#L6440
  //
  xmlNodePtr node = tree;
  /*
   * Browse the full subtree, deep first
   */
  while(node != NULL) {
    if (node->ns != NULL && node->ns == ns) {
      node->ns = NULL;
    }

    // Check for namespaces on the attributes
    if (node->type == XML_ELEMENT_NODE) {
      xmlAttrPtr attr = node->properties;
      while (attr != NULL) {
        if (attr->ns != NULL && attr->ns == ns) {
          attr->ns = NULL;
        }
        attr = attr->next;
      }
    }

    if ((node->children != NULL) && (node->type != XML_ENTITY_REF_NODE)) {
      /* deep first */
      node = node->children;
    } else if ((node != tree) && (node->next != NULL)) {
      /* then siblings */
      node = node->next;
    } else if (node != tree) {
      /* go up to parents->next if needed */
      while (node != tree) {
        if (node->parent != NULL)
          node = node->parent;
        if ((node != tree) && (node->next != NULL)) {
          node = node->next;
          break;
        }
        if (node->parent == NULL) {
          node = NULL;
          break;
        }
      }
      /* exit condition */
      if (node == tree)
        node = NULL;
    } else
      break;
  }
  return;
}

void removeNs(xmlNodePtr node, xmlChar* prefix) {
  if (node == NULL) {
    return;
  }

  if (node->nsDef == NULL) {
    return;
  }

  xmlNsPtr prev = node->nsDef;
  if (xmlStrEqual(prev->prefix, prefix)) {
    node->nsDef = prev->next;
    xmlRemoveNamespace(node, prev);
    xmlFreeNs(prev);
    return;
  }

  while(prev->next != NULL) {
    xmlNsPtr cur = prev->next;
    if (xmlStrEqual(cur->prefix, prefix)) {
      prev->next = cur->next;
      xmlRemoveNamespace(node, cur);
      xmlFreeNs(cur);
      return;
    }
    prev = prev->next;
  }
  return;
}

// [[Rcpp::export]]
void node_set_attr(XPtrNode node, std::string name, std::string value, CharacterVector nsMap) {

  bool remove = value.length() == 0;

  if (name == "xmlns") {
    if (remove) removeNs(node.get(), NULL);
    else xmlNewNs(node.get(), asXmlChar(value), NULL);
    return;
  }
  if (hasPrefix("xmlns:", name)) {
    xmlChar* prefix = asXmlChar(name.substr(6));
    if (remove) removeNs(node.get(), prefix);
    else xmlNewNs(node.get(), asXmlChar(value), prefix);
    return;
  }

  if (nsMap.size() == 0) {
      if (remove) xmlUnsetProp(node.get(), asXmlChar(name));
      else xmlSetProp(node.get(), asXmlChar(name), asXmlChar(value));
  } else {
    size_t colon = name.find(":");
    if (colon == std::string::npos) {
      // Has namespace spec, but attribute not qualified, so just use that name
      if (remove) xmlUnsetNsProp(node.get(), NULL, asXmlChar(name));
      else xmlSetProp(node.get(), asXmlChar(name), asXmlChar(value));
    } else {
      // Split name into prefix & attr, then look up full url
      std::string
      prefix = name.substr(0, colon),
        attr = name.substr(colon + 1, name.size() - 1);

      xmlNodePtr node_ = node.get();
      std::string url = NsMap(nsMap).findUrl(prefix);

      xmlNsPtr ns = xmlSearchNsByHref(node_->doc, node_, asXmlChar(url));

      if (remove) xmlUnsetNsProp(node_, ns, asXmlChar(attr));
      else xmlSetNsProp(node_, ns, asXmlChar(attr), asXmlChar(value));
    }
  }

  return;
}

// [[Rcpp::export]]
CharacterVector node_format(XPtrDoc doc, XPtrNode node,
                        bool format = true,
                        int indent = 0) {
  boost::shared_ptr<xmlBuffer> buffer(xmlBufferCreate(), xmlFree);
  xmlNodeDump(buffer.get(), doc.get(), node.get(), indent, format);

  return Xml2String(buffer->content).asRString();
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
LogicalVector nodes_duplicated(List nodes) {

  std::set<xmlNode*> seen;

  int n = nodes.size();
  LogicalVector out(n);

  for (int i = 0; i < n; ++i) {
    bool result;
    if (RObject(nodes[i]).inherits("xml_node")) {
      XPtrNode node = as<XPtrNode>(List(nodes[i])["node"]);
      result = !seen.insert(node.get()).second;
    } else if (RObject(nodes[i]).inherits("xml_missing")){
      result = false;
    } else {
      XPtrNode node = nodes[i];
      result = !seen.insert(node.get()).second;
    }
    out[i] = result;
  }

  return out;
}

// [[Rcpp::export]]
int node_type(XPtrNode node) {
  return node->type;
}

// [[Rcpp::export]]
void node_set_content(XPtrNode node, std::string content) {
  return xmlNodeSetContentLen(node.get(), asXmlChar(content), content.size());
}

// [[Rcpp::export]]
void node_append_content(XPtrNode node, std::string content) {
  return xmlNodeAddContentLen(node.get(), asXmlChar(content), content.size());
}

// [[Rcpp::export]]
XPtrNode node_add_child(XPtrNode parent, XPtrNode cur, bool copy) {
  xmlNodePtr node = NULL;
  if (copy) {
    node = xmlCopyNode(cur.get(), 1);
  } else {
    node = cur.get();
  }
  return XPtrNode(xmlAddChild(parent.get(), node));
}

// Previous sibling
// [[Rcpp::export]]
XPtrNode node_prepend_sibling(XPtrNode cur, XPtrNode elem, bool copy) {
  xmlNodePtr node = NULL;
  if (copy) {
    node = xmlCopyNode(elem.get(), 1);
  } else {
    node = elem.get();
  }
  return XPtrNode(xmlAddPrevSibling(cur.get(), node));
}

// Append sibling
// [[Rcpp::export]]
XPtrNode node_append_sibling(XPtrNode cur, XPtrNode elem, bool copy) {
  xmlNodePtr node = NULL;
  if (copy) {
    node = xmlCopyNode(elem.get(), 1);
  } else {
    node = elem.get();
  }
  return XPtrNode(xmlAddNextSibling(cur.get(), node));
}

// Replace node
// [[Rcpp::export]]
XPtrNode node_replace(XPtrNode old, XPtrNode cur, bool copy) {
  xmlNodePtr node = NULL;
  if (copy) {
    node = xmlCopyNode(cur.get(), 1);
  } else {
    node = cur.get();
  }
  return XPtrNode(xmlReplaceNode(old.get(), node));
}

// [[Rcpp::export]]
void node_remove(XPtrNode cur, bool free) {
  xmlUnlinkNode(cur.get());
  if (free) {
    xmlFreeNode(cur.get());
  }
  return;
}

// [[Rcpp::export]]
XPtrNode node_new(std::string name) {
  return XPtrNode(xmlNewNode(NULL, asXmlChar(name)));
}

// [[Rcpp::export]]
XPtrNode node_new_ns(std::string name, XPtrNs ns) {
  return XPtrNode(xmlNewNode(ns.get(), asXmlChar(name)));
}

// [[Rcpp::export]]
XPtrNode node_null() {
  return XPtrNode(xmlNodePtr(NULL));
}

// [[Rcpp::export]]
void node_set_namespace_uri(XPtrDoc doc, XPtrNode node, std::string uri) {
  xmlNsPtr ns = xmlSearchNsByHref(doc.get(), node.get(), asXmlChar(uri));

  xmlSetNs(node.get(), ns);
}

// [[Rcpp::export]]
void node_set_namespace_prefix(XPtrDoc doc, XPtrNode node, std::string prefix) {
  xmlNsPtr ns = NULL;
  if (prefix.length() == 0) {
    ns = xmlSearchNs(doc.get(), node.get(), NULL);
  } else {
    ns = xmlSearchNs(doc.get(), node.get(), asXmlChar(prefix));
  }

  xmlSetNs(node.get(), ns);
}

// [[Rcpp::export]]
void str_xml_node(XPtrNode node_) {
  xmlNodePtr node = node_.get();
  xmlDebugDumpNode(NULL, node, 0);
}
