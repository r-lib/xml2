#include <Rcpp.h>
using namespace Rcpp;
#include "XmlDoc.h"
#include "XmlNode.h"

// [[Rcpp::export]]
XPtr<XmlNode> xml_doc_root(XPtr<Xml2DocumentPtr> x) {
  xmlDoc* doc = x.get()->get();
  xmlNode* root = xmlDocGetRootElement(doc);

  return XPtr<XmlNode>(new XmlNode(*x, root));
}

// [[Rcpp::export]]
CharacterVector xml_name(XPtr<XmlNode> node) {
  return node->name();
}

