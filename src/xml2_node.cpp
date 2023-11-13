#include <cpp11.hpp>

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <libxml/tree.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>

#include "xml2_types.h"
#include "xml2_utils.h"

template<typename T> // for xmlAttr and xmlNode
std::string nodeName(T* node, cpp11::strings nsMap) {
  std::string name = Xml2String(node->name).asStdString();
  if (Rf_xlength(nsMap) == 0) {
    return name;
  }

  xmlNs* ns = node->ns;
  if (ns == NULL)
    return name;

  std::string prefix = NsMap(nsMap).findPrefix(Xml2String(ns->href).asStdString());
  return prefix + ":" + name;
}

cpp11::r_string node_name_impl(cpp11::list x, cpp11::strings nsMap) {
  NodeType type = getNodeType(x);

  cpp11::r_string out;

  switch(type) {
  case NodeType::missing:
    out = NA_STRING;
    break;
  case NodeType::node: {
    XPtrNode node(x[0]);

    out = nodeName(node.checked_get(), nsMap);
    break;
  }
  default: stop_unexpected_node_type();
  }

  return out;
}

[[cpp11::register]]
cpp11::strings node_name(cpp11::list x, cpp11::strings nsMap) {
  NodeType type = getNodeType(x);

  switch(type)
  {
  case NodeType::missing:
  case NodeType::node:
    // TODO can this be done nicer?
    return cpp11::writable::strings(node_name_impl(x, nsMap));
    break;
  case NodeType::nodeset: {
    R_xlen_t n = x.size();

    cpp11::writable::strings out(n);
    for (int i = 0; i < n; ++i) {
      out[i] = node_name_impl(x[i], nsMap);
    }

    return out;
  };
  default: stop_unexpected_node_type();
  }
}

[[cpp11::register]]
SEXP node_set_name(node_pointer node_sxp, cpp11::strings value) {
  XPtrNode node(node_sxp);

  xmlNodeSetName(node, asXmlChar(value));

  return R_NilValue;
}

cpp11::r_string node_text_impl(cpp11::list x) {
  NodeType type = getNodeType(x);

  cpp11::r_string out;

  switch(type) {
  case NodeType::missing:
    out = NA_STRING;
    break;
  case NodeType::node: {
    XPtrNode node(x[0]);

    out = Xml2String(xmlNodeGetContent(node.checked_get())).asRString();
    break;
  }
  default: stop_unexpected_node_type();
  }

  return out;
}

[[cpp11::register]]
cpp11::strings node_text(cpp11::list x) {
  NodeType type = getNodeType(x);

  switch(type)
  {
  case NodeType::missing:
  case NodeType::node:
    // TODO can this be done nicer?
    return cpp11::writable::strings(node_text_impl(x));
    break;
  case NodeType::nodeset: {
    R_xlen_t n = x.size();

    cpp11::writable::strings out(n);
    for (int i = 0; i < n; ++i) {
      out[i] = node_text_impl(x[i]);
    }

    return out;
  };
  default: stop_unexpected_node_type();
  }
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

const xmlChar* xmlNsDefinition(xmlNodePtr node, const xmlChar* lookup) {
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


cpp11::r_string node_attr_impl(cpp11::list x,
                               const std::string& name,
                               cpp11::r_string missingVal,
                               cpp11::strings nsMap_sxp) {
  NodeType type = getNodeType(x);

  switch(type) {
  case NodeType::missing:
    return NA_STRING;
    break;
  case NodeType::node: {
    XPtrNode node(x[0]);
    if (name == "xmlns") {
      return Xml2String(xmlNsDefinition(node, NULL)).asRString(missingVal);
    }

    if (hasPrefix("xmlns:", name)) {
      std::string prefix = name.substr(6);
      return Xml2String(xmlNsDefinition(node, asXmlChar(prefix))).asRString(missingVal);
    }

    xmlChar* string;
    if (Rf_xlength(nsMap_sxp) == 0) {
      string = xmlGetProp(node.checked_get(), asXmlChar(name));
    } else {
      size_t colon = name.find(':');
      if (colon == std::string::npos) {
        // Has namespace spec, but attribute not qualified, so look for attribute
        // without namespace
        string = xmlGetNoNsProp(node.checked_get(), asXmlChar(name));
      } else {
        // Split name into prefix & attr, then look up full url
        std::string
        prefix = name.substr(0, colon),
          attr = name.substr(colon + 1, name.size() - 1);

        std::string url = NsMap(nsMap_sxp).findUrl(prefix);

        string = xmlGetNsProp(node.checked_get(), asXmlChar(attr), asXmlChar(url));
      }
    }

    return Xml2String(string).asRString(missingVal);
    break;
  }
  default: stop_unexpected_node_type();
  }
}

[[cpp11::register]]
cpp11::strings node_attr(
    cpp11::list x,
    cpp11::strings name_sxp,
    cpp11::strings missing_sxp,
    cpp11::strings nsMap_sxp) {
  NodeType type = getNodeType(x);

  std::string name(cpp11::as_cpp<const char*>(name_sxp));

  if (missing_sxp.size() != 1) {
    cpp11::stop("`missing` should be length 1");
  }

  cpp11::r_string missingVal = missing_sxp[0];

  switch(type)
  {
  case NodeType::missing:
  case NodeType::node:
    return cpp11::writable::strings(node_attr_impl(x, name, missingVal, nsMap_sxp));
    break;
  case NodeType::nodeset: {
    R_xlen_t n = x.size();

    cpp11::writable::strings out(n);

    for (int i = 0; i < n; ++i) {
      out[i] = node_attr_impl(x[i], name, missingVal, nsMap_sxp);
    }

    return out;
  };
  default: stop_unexpected_node_type();
  }
}

cpp11::strings node_attrs_impl(cpp11::list x, cpp11::strings nsMap_sxp) {
  NodeType type = getNodeType(x);

  switch(type) {
  case NodeType::missing:
    return cpp11::writable::strings({NA_STRING});
    break;
  case NodeType::node: {
    XPtrNode node_(x[0]);

    int n = 0;
    xmlNodePtr node = node_.checked_get();

    if (node->type == XML_ELEMENT_NODE) {
      // attributes
      for(xmlAttr* cur = node->properties; cur != NULL; cur = cur->next)
        n++;

      // namespace definitions
      for(xmlNsPtr cur = node->nsDef; cur != NULL; cur = cur->next)
        n++;

      cpp11::writable::strings names(n);
      cpp11::writable::strings values(n);

      int i = 0;
      for(xmlAttr* cur = node->properties; cur != NULL; cur = cur->next, ++i) {
        std::string name = nodeName(cur, nsMap_sxp);
        names[i] = name;

        xmlNs* ns = cur->ns;
        if (ns == NULL) {
          if (nsMap_sxp.size() > 0) {
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
          std::string name = std::string("xmlns:") + Xml2String(cur->prefix).asStdString();
          names[i] = name;
        }
        values[i] = Xml2String(cur->href).asRString();
      }

      values.names() = names;

      return values;
    }

    return cpp11::strings();
    break;
  }
  default: stop_unexpected_node_type();
  }
}

[[cpp11::register]]
cpp11::sexp node_attrs(cpp11::list x, cpp11::strings nsMap_sxp) {
  NodeType type = getNodeType(x);

  switch(type)
  {
  case NodeType::missing:
  case NodeType::node:
    return node_attrs_impl(x, nsMap_sxp);
    break;
  case NodeType::nodeset: {
    R_xlen_t n = x.size();

    cpp11::writable::list out(n);

    for (int i = 0; i < n; ++i) {
      out[i] = node_attrs_impl(x[i], nsMap_sxp);
    }

    return out;
  };
  default: stop_unexpected_node_type();
  }
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

void removeNs(xmlNodePtr node, const xmlChar* prefix) {
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

[[cpp11::register]]
cpp11::sexp node_set_attr(
    node_pointer node_sxp,
    cpp11::strings name_sxp,
    cpp11::strings value,
    cpp11::strings nsMap) {
  XPtrNode node_(node_sxp);
  std::string name(cpp11::as_cpp<const char*>(name_sxp));

  const xmlNodePtr node = node_.checked_get();

  if (name == "xmlns") {
    xmlAddNamespace(node, xmlNewNs(node, asXmlChar(value), NULL));
    return R_NilValue;
  }
  if (hasPrefix("xmlns:", name)) {
    std::string prefix = name.substr(6);
    removeNs(node, asXmlChar(prefix));
    xmlAddNamespace(node, xmlNewNs(node, asXmlChar(value), asXmlChar(prefix)));
    return R_NilValue;
  }

  if (nsMap.empty()) {
      xmlSetProp(node, asXmlChar(name), asXmlChar(value));
  } else {
    size_t colon = name.find(':');
    if (colon == std::string::npos) {
      // Has namespace spec, but attribute not qualified, so just use that name
      xmlSetProp(node, asXmlChar(name), asXmlChar(value));
    } else {
      // Split name into prefix & attr, then look up full url
      std::string
      prefix = name.substr(0, colon),
        attr = name.substr(colon + 1, name.size() - 1);

      std::string url = NsMap(nsMap).findUrl(prefix);

      xmlNsPtr ns = xmlSearchNsByHref(node_->doc, node, asXmlChar(url));

      xmlSetNsProp(node, ns, asXmlChar(attr), asXmlChar(value));
    }
  }

  return R_NilValue;
}

[[cpp11::register]]
cpp11::sexp node_remove_attr(
    node_pointer node_sxp,
    cpp11::strings name_sxp,
    cpp11::strings nsMap) {
  XPtrNode node_(node_sxp);
  std::string name(cpp11::as_cpp<const char*>(name_sxp));

  const xmlNodePtr node = node_.checked_get();

  if (name == "xmlns") {
    removeNs(node, NULL);
    return R_NilValue;
  }
  if (hasPrefix("xmlns:", name)) {
    std::string prefix = name.substr(6);
    removeNs(node, asXmlChar(prefix));
    return R_NilValue;
  }

  if (nsMap.empty()) {
      xmlUnsetProp(node, asXmlChar(name));
  } else {
    size_t colon = name.find(':');
    if (colon == std::string::npos) {
      // Has namespace spec, but attribute not qualified, so just use that name
      xmlUnsetNsProp(node, NULL, asXmlChar(name));
    } else {
      // Split name into prefix & attr, then look up full url
      std::string
      prefix = name.substr(0, colon),
        attr = name.substr(colon + 1, name.size() - 1);

      std::string url = NsMap(nsMap).findUrl(prefix);

      xmlNsPtr ns = xmlSearchNsByHref(node_->doc, node, asXmlChar(url));

      xmlUnsetNsProp(node, ns, asXmlChar(attr));
    }
  }

  return R_NilValue;
}

cpp11::list asList(std::vector<xmlNode*> nodes) {
  R_xlen_t n = nodes.size();
  cpp11::writable::list out(n);
  for (R_xlen_t i = 0; i < n; ++i) {
    XPtrNode node(nodes[i]);
    out[i] = SEXP(node);
  }

  return out;
}

[[cpp11::register]]
cpp11::list node_children(node_pointer node_sxp, cpp11::logicals only_node_sxp) {
  XPtrNode node(node_sxp);
  bool only_node = cpp11::as_cpp<bool>(only_node_sxp);

  std::vector<xmlNode*> out;

  for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (only_node && cur->type != XML_ELEMENT_NODE) {
      continue;
    }

    out.push_back(cur);
  }

  return asList(out);
}

int node_length_impl(cpp11::list x, bool only_node) {
  NodeType type = getNodeType(x);

  int out;

  switch(type) {
  case NodeType::missing:
    out = 0;
    break;
  case NodeType::node: {
    XPtrNode node(x[0]);

    out = 0;
    for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next) {
      if (only_node && cur->type != XML_ELEMENT_NODE) {
        continue;
      }
      ++out;
    }
    break;
  }
  default: stop_unexpected_node_type();
  }

  return out;
}

[[cpp11::register]]
cpp11::integers node_length(cpp11::list x, cpp11::logicals only_node_sxp) {
  NodeType type = getNodeType(x);

  bool only_node = cpp11::as_cpp<bool>(only_node_sxp);

  switch(type)
  {
  case NodeType::missing:
  case NodeType::node:
    return cpp11::integers({node_length_impl(x, only_node)});
    break;
  case NodeType::nodeset: {
    R_xlen_t n = x.size();

    if (n == 0) {
      return cpp11::writable::integers({0});
    }

    cpp11::writable::integers out(n);

    for (int i = 0; i < n; ++i) {
      out[i] = node_length_impl(x[i], only_node);
    }

    return out;
  };
  default: stop_unexpected_node_type();
  }
}

[[cpp11::register]]
cpp11::logicals node_has_children(node_pointer node_sxp, cpp11::logicals only_node_sxp) {
  XPtrNode node(node_sxp);
  bool only_node = cpp11::as_cpp<bool>(only_node_sxp);

  for(xmlNode* cur = node->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (only_node && cur->type != XML_ELEMENT_NODE) {
      continue;
    }
    return cpp11::logicals({true});
  }
  return cpp11::logicals({false});
}

[[cpp11::register]]
cpp11::list node_parents(node_pointer node_sxp) {
  XPtrNode node(node_sxp);

  std::vector<xmlNode*> out;

  for(xmlNode* cur = node->parent; cur != NULL; cur = cur->parent) {
    if (cur->type != XML_ELEMENT_NODE)
      continue;
    out.push_back(cur);
  }

  return asList(out);
}

[[cpp11::register]]
cpp11::list node_siblings(node_pointer node_sxp, cpp11::logicals only_node_sxp) {
  XPtrNode node(node_sxp);
  bool only_node = cpp11::as_cpp<bool>(only_node_sxp);

  std::vector<xmlNode*> out;

  xmlNode* parent = node->parent;
  if (parent == NULL)
    return cpp11::list(0);

  for(xmlNode* cur = parent->xmlChildrenNode; cur != NULL; cur = cur->next) {
    if (cur == node) {
      continue;
    }
    if (only_node && cur->type != XML_ELEMENT_NODE) {
      continue;
    }

    out.push_back(cur);
  }

  return asList(out);
}


[[cpp11::register]]
node_pointer node_parent(node_pointer node_sxp) {
  XPtrNode node(node_sxp);

  if (node->parent == NULL) {
    cpp11::stop("Parent does not exist");
  }
  XPtrNode out(node->parent);
  return SEXP(out);
}

cpp11::r_string node_path_impl(cpp11::list x) {
  NodeType type = getNodeType(x);

  switch(type) {
  case NodeType::missing:
    return NA_STRING;
    break;
  case NodeType::node: {
    XPtrNode node(x[0]);

    return Xml2String(xmlGetNodePath(node.checked_get())).asRString();
    break;
  }
  default: stop_unexpected_node_type();
  }
}

[[cpp11::register]]
cpp11::strings node_path(cpp11::list x) {
  NodeType type = getNodeType(x);

  switch(type)
  {
  case NodeType::missing:
  case NodeType::node:
    return cpp11::writable::strings(node_path_impl(x));
    break;
  case NodeType::nodeset: {
    R_xlen_t n = x.size();

    cpp11::writable::strings out(n);

    for (int i = 0; i < n; ++i) {
      out[i] = node_path_impl(x[i]);
    }

    return out;
  };
  default: stop_unexpected_node_type();
  }
}

[[cpp11::register]]
cpp11::logicals nodes_duplicated(cpp11::list nodes) {
  std::set<xmlNode*> seen;

  R_xlen_t n = nodes.size();

  cpp11::writable::logicals out(n);

  for (int i = 0; i < n; ++i) {
    bool result;
    cpp11::list cur = nodes[i];
    if (Rf_inherits(cur, "xml_node")) {
      XPtrNode node(cur[0]);
      result = !seen.insert(node.checked_get()).second;
    } else if (Rf_inherits(cur, "xml_missing")) {
      result = false;
    } else {
      XPtrNode node(cur);
      result = !seen.insert(node.checked_get()).second;
    }
    out[i] = result;
  }

  return out;
}

int node_type_impl(cpp11::list x) {
  NodeType type = getNodeType(x);

  int out;

  switch(type) {
  case NodeType::missing:
    out = NA_INTEGER;
    break;
  case NodeType::node: {
    XPtrNode node(x[0]);

    out = node->type;
    break;
  }
  default: stop_unexpected_node_type();
  }

  return out;
}

[[cpp11::register]]
cpp11::integers node_type(cpp11::list x) {
  NodeType type = getNodeType(x);

  switch(type)
  {
  case NodeType::missing:
  case NodeType::node:
    return cpp11::writable::integers({node_type_impl(x)});
    break;
  case NodeType::nodeset: {
    R_xlen_t n = x.size();

    cpp11::writable::integers out(n);

    for (int i = 0; i < n; ++i) {
      out[i] = node_type_impl(x[i]);
    }

    return out;
  };
  default: stop_unexpected_node_type();
  }
}

[[cpp11::register]]
node_pointer node_copy(node_pointer node_sxp) {
  XPtrNode node(node_sxp);

  XPtrNode copy(xmlCopyNode(node.checked_get(), 1));

  return SEXP(copy);
}

[[cpp11::register]]
cpp11::sexp node_set_content(node_pointer node_sxp, cpp11::strings content) {
  XPtrNode node(node_sxp);

  xmlNodeSetContentLen(node.checked_get(), asXmlChar(content), content[0].size());

  return R_NilValue;
}

[[cpp11::register]]
cpp11::sexp node_append_content(node_pointer node_sxp, cpp11::strings content) {
  XPtrNode node(node_sxp);

  xmlNodeAddContentLen(node.checked_get(), asXmlChar(content), content[0].size());

  return R_NilValue;
}

[[cpp11::register]]
cpp11::sexp node_new_text(node_pointer node_sxp, cpp11::strings content) {
  XPtrNode node(node_sxp);

  xmlAddChild(node.checked_get(), xmlNewTextLen(asXmlChar(content), content[0].size()));

  return R_NilValue;
}

[[cpp11::register]]
node_pointer node_append_child(node_pointer parent_sxp, node_pointer cur_sxp) {
  XPtrNode parent(parent_sxp);
  XPtrNode cur(cur_sxp);
  XPtrNode out(xmlAddChild(parent.checked_get(), cur.checked_get()));
  return SEXP(out);
}

[[cpp11::register]]
node_pointer node_prepend_child(node_pointer parent_sxp, node_pointer cur_sxp) {
  XPtrNode parent(parent_sxp);
  XPtrNode cur(cur_sxp);

  XPtrNode out(xmlAddPrevSibling(parent.checked_get()->children, cur.checked_get()));

  return SEXP(out);
}

// Previous sibling
[[cpp11::register]]
node_pointer node_prepend_sibling(node_pointer cur_sxp, node_pointer elem_sxp) {
  XPtrNode cur(cur_sxp);
  XPtrNode elem(elem_sxp);

  XPtrNode out(xmlAddPrevSibling(cur.checked_get(), elem.checked_get()));

  return SEXP(out);
}

// Append sibling
[[cpp11::register]]
node_pointer node_append_sibling(node_pointer cur_sxp, node_pointer elem_sxp) {
  XPtrNode cur(cur_sxp);
  XPtrNode elem(elem_sxp);
  XPtrNode out(xmlAddNextSibling(cur.checked_get(), elem.checked_get()));

  return SEXP(out);
}

// Replace node
[[cpp11::register]]
node_pointer node_replace(node_pointer old_sxp, node_pointer cur_sxp) {
  XPtrNode old(old_sxp);
  XPtrNode cur(cur_sxp);
  XPtrNode out(xmlReplaceNode(old.checked_get(), cur.checked_get()));

  return SEXP(out);
}

[[cpp11::register]]
cpp11::sexp node_remove(node_pointer node_sxp, cpp11::logicals free_sxp) {
  XPtrNode node(node_sxp);
  bool free = cpp11::as_cpp<bool>(free_sxp);

  xmlUnlinkNode(node.checked_get());
  if (free) {
    xmlFreeNode(node.checked_get());
  }

  return R_NilValue;
}

[[cpp11::register]]
cpp11::sexp node_new(cpp11::strings name) {
  XPtrNode node(xmlNewNode(NULL, asXmlChar(name)));
  return SEXP(node);
}


[[cpp11::register]]
cpp11::sexp node_cdata_new(cpp11::sexp doc_sxp, cpp11::strings content_sxp) {
  XPtrDoc doc(doc_sxp);
  XPtrNode node(xmlNewCDataBlock(doc.checked_get(), asXmlChar(content_sxp), content_sxp[0].size()));
  return SEXP(node);
}

[[cpp11::register]]
node_pointer node_comment_new(cpp11::strings content) {
  XPtrNode node(xmlNewComment(asXmlChar(content)));
  return SEXP(node);
}

[[cpp11::register]]
node_pointer node_new_ns(cpp11::strings name, cpp11::external_pointer<xmlNs> ns_sxp) {
  XPtrNs ns(ns_sxp);
  XPtrNode node(xmlNewNode(ns.checked_get(), asXmlChar(name)));
  return SEXP(node);
}

[[cpp11::register]]
cpp11::sexp node_set_namespace_uri(doc_pointer doc_sxp, node_pointer node_sxp, cpp11::strings uri) {
  XPtrDoc doc(doc_sxp);
  XPtrNode node(node_sxp);

  xmlNsPtr ns = xmlSearchNsByHref(doc.checked_get(), node.checked_get(), asXmlChar(uri));

  xmlSetNs(node.checked_get(), ns);

  return R_NilValue;
}

[[cpp11::register]]
cpp11::sexp node_set_namespace_prefix(doc_pointer doc_sxp, node_pointer node_sxp, cpp11::strings prefix_sxp) {
  XPtrDoc doc(doc_sxp);
  XPtrNode node(node_sxp);

  xmlNsPtr ns = NULL;
  if (prefix_sxp[0].size() == 0) {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), NULL);
  } else {
    ns = xmlSearchNs(doc.checked_get(), node.checked_get(), asXmlChar(prefix_sxp));
  }

  xmlSetNs(node.checked_get(), ns);

  return R_NilValue;
}

[[cpp11::register]]
cpp11::sexp node_new_dtd(doc_pointer doc_sxp, cpp11::strings name_sxp, cpp11::strings eid_sxp, cpp11::strings sid_sxp) {
  XPtrDoc doc(doc_sxp);
  std::string name(cpp11::as_cpp<const char*>(name_sxp));
  std::string eid(cpp11::as_cpp<const char*>(eid_sxp));
  std::string sid(cpp11::as_cpp<const char*>(sid_sxp));

  xmlDtdPtr dtd = xmlNewDtd(doc, name == "" ? NULL : asXmlChar(name), eid == "" ? NULL : asXmlChar(eid), sid == "" ? NULL : asXmlChar(sid));
  xmlAddChild(reinterpret_cast<xmlNodePtr>(doc.checked_get()), reinterpret_cast<xmlNodePtr>(dtd));

  return R_NilValue;
}
