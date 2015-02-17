#include <Rcpp.h>
using namespace Rcpp;
#include "xml2_types.h"
#include "xml2_utils.h"

// [[Rcpp::export]]
List xml_doc_root(XPtr<xmlDoc> x) {
  xmlNode* root = xmlDocGetRootElement(x.get());

  return List::create(
    _["doc"] = x,
    _["node"] = XPtr<xmlNode>(root)
  );
}

// [[Rcpp::export]]
CharacterVector xml_name(XPtr<xmlNode> node) {
  return xmlCharToRChar(node->name);
}

