#include <Rcpp.h>
using namespace Rcpp;
#include "XmlDoc.h"
#include "XmlNode.h"

// [[Rcpp::export]]
XPtr<XmlNode> xml_doc_root(XPtr<XmlDocPtr> x) {
  return XPtr<XmlNode>(new XmlNode(*x, (*x)->root()), true);
}

// [[Rcpp::export]]
CharacterVector xml_name(XPtr<XmlNode> node) {
  return node->name();
}

