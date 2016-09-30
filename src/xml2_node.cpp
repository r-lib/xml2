#include <Rcpp.h>
#include <libxml/tree.h>
#include <boost/shared_ptr.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <fstream>
#include <sstream>

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
  return asCharacterVector(nodeName(node.checked_get(), nsMap));
}

// [[Rcpp::export]]
void node_set_name(XPtrNode node, std::string value) {
  return xmlNodeSetName(node, asXmlChar(value));
}

// [[Rcpp::export]]
CharacterVector node_text(XPtrNode node, bool trim) {
  std::string text = Xml2String(xmlNodeGetContent(node.checked_get())).asStdString();

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

  if (name == "xmlns") {
    return CharacterVector(Xml2String(xmlNsDefinition(node, NULL)).asRString(missingVal));
  }
  if (hasPrefix("xmlns:", name)) {
    std::string prefix = name.substr(6);
    return CharacterVector(Xml2String(xmlNsDefinition(node, asXmlChar(prefix))).asRString(missingVal));
  }
  xmlChar* string;
  if (nsMap.size() == 0) {
    string = xmlGetProp(node.checked_get(), asXmlChar(name));
  } else {
    size_t colon = name.find(":");
    if (colon == std::string::npos) {
      // Has namespace spec, but attribute not qualified, so look for attribute
      // without namespace
      string = xmlGetNoNsProp(node.checked_get(), asXmlChar(name));
    } else {
      // Split name into prefix & attr, then look up full url
      std::string
        prefix = name.substr(0, colon),
               attr = name.substr(colon + 1, name.size() - 1);

      std::string url = NsMap(nsMap).findUrl(prefix);

      string = xmlGetNsProp(node.checked_get(), asXmlChar(attr), asXmlChar(url));
    }
  }

  return CharacterVector(Xml2String(string).asRString(missingVal));
}

// [[Rcpp::export]]
CharacterVector node_attrs(XPtrNode node_, CharacterVector nsMap) {

  int n = 0;
  xmlNodePtr node = node_.checked_get();

  if (node->type == XML_ELEMENT_NODE) {
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
          values[i] = Xml2String(xmlGetNoNsProp(node, cur->name)).asRString();
        } else {
          values[i] = Xml2String(xmlGetProp(node, cur->name)).asRString();
        }
      } else {
        values[i] = Xml2String(xmlGetNsProp(node, cur->name, ns->href)).asRString();
      }
    }

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

  return CharacterVector();
}


// Fix the tree by removing the namespace pointers to the given tree
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
    if (ns->prefix != NULL && // default namespaces will not exist on attributes
        node->type == XML_ELEMENT_NODE) {
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

// Fix the tree by adding the namespace pointers to the given tree
void xmlAddNamespace(xmlNodePtr tree, xmlNsPtr ns) {

  // Only needed for default namespaces
  if (ns->prefix != NULL) {
    return;
  }

  // From https://github.com/GNOME/libxml2/blob/v2.9.2/tree.c#L6440
  //
  xmlNodePtr node = tree;
  /*
   * Browse the full subtree, deep first
   */
  while(node != NULL) {
    if (node->ns == NULL) {
      node->ns = ns;
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
void node_set_attr(XPtrNode node_, std::string name, std::string value, CharacterVector nsMap) {

  bool remove = value.length() == 0;
  const xmlNodePtr node = node_.checked_get();

  if (name == "xmlns") {
    if (remove) removeNs(node, NULL);
    else xmlAddNamespace(node, xmlNewNs(node, asXmlChar(value), NULL));
    return;
  }
  if (hasPrefix("xmlns:", name)) {
    std::string prefix = name.substr(6);
    if (remove) removeNs(node, asXmlChar(prefix));
    else xmlAddNamespace(node, xmlNewNs(node, asXmlChar(value), asXmlChar(prefix)));
    return;
  }

  if (nsMap.size() == 0) {
      if (remove) xmlUnsetProp(node, asXmlChar(name));
      else xmlSetProp(node, asXmlChar(name), asXmlChar(value));
  } else {
    size_t colon = name.find(":");
    if (colon == std::string::npos) {
      // Has namespace spec, but attribute not qualified, so just use that name
      if (remove) xmlUnsetNsProp(node, NULL, asXmlChar(name));
      else xmlSetProp(node, asXmlChar(name), asXmlChar(value));
    } else {
      // Split name into prefix & attr, then look up full url
      std::string
      prefix = name.substr(0, colon),
        attr = name.substr(colon + 1, name.size() - 1);

      std::string url = NsMap(nsMap).findUrl(prefix);

      xmlNsPtr ns = xmlSearchNsByHref(node_->doc, node, asXmlChar(url));

      if (remove) xmlUnsetNsProp(node, ns, asXmlChar(attr));
      else xmlSetNsProp(node, ns, asXmlChar(attr), asXmlChar(value));
    }
  }

  return;
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
std::string node_path(XPtrNode n) {
  return Xml2String(xmlGetNodePath(n.checked_get())).asStdString();
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
      result = !seen.insert(node.checked_get()).second;
    } else if (RObject(nodes[i]).inherits("xml_missing")){
      result = false;
    } else {
      XPtrNode node = nodes[i];
      result = !seen.insert(node.checked_get()).second;
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
  return xmlNodeSetContentLen(node.checked_get(), asXmlChar(content), content.size());
}

// [[Rcpp::export]]
void node_append_content(XPtrNode node, std::string content) {
  return xmlNodeAddContentLen(node.checked_get(), asXmlChar(content), content.size());
}

// [[Rcpp::export]]
XPtrNode node_add_child(XPtrNode parent, XPtrNode cur, bool copy) {
  xmlNodePtr node = NULL;
  if (copy) {
    node = xmlCopyNode(cur.checked_get(), 1);
  } else {
    node = cur.checked_get();
  }
  return XPtrNode(xmlAddChild(parent.checked_get(), node));
}

// Previous sibling
// [[Rcpp::export]]
XPtrNode node_prepend_sibling(XPtrNode cur, XPtrNode elem, bool copy) {
  xmlNodePtr node = NULL;
  if (copy) {
    node = xmlCopyNode(elem.checked_get(), 1);
  } else {
    node = elem.checked_get();
  }
  return XPtrNode(xmlAddPrevSibling(cur.checked_get(), node));
}

// Append sibling
// [[Rcpp::export]]
XPtrNode node_append_sibling(XPtrNode cur, XPtrNode elem, bool copy) {
  xmlNodePtr node = NULL;
  if (copy) {
    node = xmlCopyNode(elem.checked_get(), 1);
  } else {
    node = elem.checked_get();
  }
  return XPtrNode(xmlAddNextSibling(cur.checked_get(), node));
}

// Replace node
// [[Rcpp::export]]
XPtrNode node_replace(XPtrNode old, XPtrNode cur, bool copy) {
  xmlNodePtr node = NULL;
  if (copy) {
    node = xmlCopyNode(cur.checked_get(), 1);
  } else {
    node = cur.checked_get();
  }
  return XPtrNode(xmlReplaceNode(old.checked_get(), node));
}

// [[Rcpp::export]]
void node_remove(XPtrNode cur, bool free) {
  xmlUnlinkNode(cur.checked_get());
  if (free) {
    xmlFreeNode(cur.checked_get());
  }
  return;
}

// [[Rcpp::export]]
XPtrNode node_new(std::string name) {
  return XPtrNode(xmlNewNode(NULL, asXmlChar(name)));
}

// [[Rcpp::export]]
XPtrNode node_new_ns(std::string name, XPtrNs ns) {
  return XPtrNode(xmlNewNode(ns.checked_get(), asXmlChar(name)));
}

// [[Rcpp::export]]
XPtrNode node_null() {
  return XPtrNode(xmlNodePtr(NULL));
}

// [[Rcpp::export]]
void node_set_namespace_uri(XPtrDoc doc, XPtrNode node, std::string uri) {
  xmlNsPtr ns = xmlSearchNsByHref(doc.checked_get(), node.checked_get(), asXmlChar(uri));

  xmlSetNs(node.checked_get(), ns);
}

// [[Rcpp::export]]
void node_set_namespace_prefix(XPtrDoc doc, XPtrNode node, std::string prefix) {
  xmlNsPtr ns = NULL;
  if (prefix.length() == 0) {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), NULL);
  } else {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), asXmlChar(prefix));
  }

  xmlSetNs(node.checked_get(), ns);
}
