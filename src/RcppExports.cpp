// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/xml2_types.h"
#include <Rcpp.h>

using namespace Rcpp;

// read_connection_
RawVector read_connection_(RObject con, int chunk_size);
RcppExport SEXP _xml2_read_connection_(SEXP conSEXP, SEXP chunk_sizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< RObject >::type con(conSEXP);
    Rcpp::traits::input_parameter< int >::type chunk_size(chunk_sizeSEXP);
    rcpp_result_gen = Rcpp::wrap(read_connection_(con, chunk_size));
    return rcpp_result_gen;
END_RCPP
}
// xml_parse_options
Rcpp::IntegerVector xml_parse_options();
RcppExport SEXP _xml2_xml_parse_options() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(xml_parse_options());
    return rcpp_result_gen;
END_RCPP
}
// unique_ns
CharacterVector unique_ns(CharacterVector ns);
RcppExport SEXP _xml2_unique_ns(SEXP nsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type ns(nsSEXP);
    rcpp_result_gen = Rcpp::wrap(unique_ns(ns));
    return rcpp_result_gen;
END_RCPP
}
// ns_lookup_uri
XPtrNs ns_lookup_uri(XPtrDoc doc, XPtrNode node, std::string uri);
RcppExport SEXP _xml2_ns_lookup_uri(SEXP docSEXP, SEXP nodeSEXP, SEXP uriSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrDoc >::type doc(docSEXP);
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< std::string >::type uri(uriSEXP);
    rcpp_result_gen = Rcpp::wrap(ns_lookup_uri(doc, node, uri));
    return rcpp_result_gen;
END_RCPP
}
// ns_lookup
XPtrNs ns_lookup(XPtrDoc doc, XPtrNode node, std::string prefix);
RcppExport SEXP _xml2_ns_lookup(SEXP docSEXP, SEXP nodeSEXP, SEXP prefixSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrDoc >::type doc(docSEXP);
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< std::string >::type prefix(prefixSEXP);
    rcpp_result_gen = Rcpp::wrap(ns_lookup(doc, node, prefix));
    return rcpp_result_gen;
END_RCPP
}
// node_name
CharacterVector node_name(XPtrNode node, CharacterVector nsMap);
RcppExport SEXP _xml2_node_name(SEXP nodeSEXP, SEXP nsMapSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type nsMap(nsMapSEXP);
    rcpp_result_gen = Rcpp::wrap(node_name(node, nsMap));
    return rcpp_result_gen;
END_RCPP
}
// node_set_name
void node_set_name(XPtrNode node, std::string value);
RcppExport SEXP _xml2_node_set_name(SEXP nodeSEXP, SEXP valueSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< std::string >::type value(valueSEXP);
    node_set_name(node, value);
    return R_NilValue;
END_RCPP
}
// node_text
CharacterVector node_text(XPtrNode node);
RcppExport SEXP _xml2_node_text(SEXP nodeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    rcpp_result_gen = Rcpp::wrap(node_text(node));
    return rcpp_result_gen;
END_RCPP
}
// node_set_attr
void node_set_attr(XPtrNode node_, std::string name, SEXP value, CharacterVector nsMap);
RcppExport SEXP _xml2_node_set_attr(SEXP node_SEXP, SEXP nameSEXP, SEXP valueSEXP, SEXP nsMapSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node_(node_SEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< SEXP >::type value(valueSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type nsMap(nsMapSEXP);
    node_set_attr(node_, name, value, nsMap);
    return R_NilValue;
END_RCPP
}
// node_remove_attr
void node_remove_attr(XPtrNode node_, std::string name, CharacterVector nsMap);
RcppExport SEXP _xml2_node_remove_attr(SEXP node_SEXP, SEXP nameSEXP, SEXP nsMapSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node_(node_SEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type nsMap(nsMapSEXP);
    node_remove_attr(node_, name, nsMap);
    return R_NilValue;
END_RCPP
}
// node_length
int node_length(XPtrNode node, bool onlyNode);
RcppExport SEXP _xml2_node_length(SEXP nodeSEXP, SEXP onlyNodeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< bool >::type onlyNode(onlyNodeSEXP);
    rcpp_result_gen = Rcpp::wrap(node_length(node, onlyNode));
    return rcpp_result_gen;
END_RCPP
}
// node_has_children
bool node_has_children(XPtrNode node, bool onlyNode);
RcppExport SEXP _xml2_node_has_children(SEXP nodeSEXP, SEXP onlyNodeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< bool >::type onlyNode(onlyNodeSEXP);
    rcpp_result_gen = Rcpp::wrap(node_has_children(node, onlyNode));
    return rcpp_result_gen;
END_RCPP
}
// node_parents
Rcpp::List node_parents(XPtrNode node);
RcppExport SEXP _xml2_node_parents(SEXP nodeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    rcpp_result_gen = Rcpp::wrap(node_parents(node));
    return rcpp_result_gen;
END_RCPP
}
// node_siblings
Rcpp::List node_siblings(XPtrNode node, bool onlyNode);
RcppExport SEXP _xml2_node_siblings(SEXP nodeSEXP, SEXP onlyNodeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< bool >::type onlyNode(onlyNodeSEXP);
    rcpp_result_gen = Rcpp::wrap(node_siblings(node, onlyNode));
    return rcpp_result_gen;
END_RCPP
}
// node_parent
XPtrNode node_parent(XPtrNode n);
RcppExport SEXP _xml2_node_parent(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(node_parent(n));
    return rcpp_result_gen;
END_RCPP
}
// node_path
std::string node_path(XPtrNode n);
RcppExport SEXP _xml2_node_path(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(node_path(n));
    return rcpp_result_gen;
END_RCPP
}
// nodes_duplicated
LogicalVector nodes_duplicated(List nodes);
RcppExport SEXP _xml2_nodes_duplicated(SEXP nodesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type nodes(nodesSEXP);
    rcpp_result_gen = Rcpp::wrap(nodes_duplicated(nodes));
    return rcpp_result_gen;
END_RCPP
}
// node_type
int node_type(XPtrNode node);
RcppExport SEXP _xml2_node_type(SEXP nodeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    rcpp_result_gen = Rcpp::wrap(node_type(node));
    return rcpp_result_gen;
END_RCPP
}
// node_set_content
void node_set_content(XPtrNode node, std::string content);
RcppExport SEXP _xml2_node_set_content(SEXP nodeSEXP, SEXP contentSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< std::string >::type content(contentSEXP);
    node_set_content(node, content);
    return R_NilValue;
END_RCPP
}
// node_new_text
void node_new_text(XPtrNode node, std::string content);
RcppExport SEXP _xml2_node_new_text(SEXP nodeSEXP, SEXP contentSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< std::string >::type content(contentSEXP);
    node_new_text(node, content);
    return R_NilValue;
END_RCPP
}
// node_prepend_child
XPtrNode node_prepend_child(XPtrNode parent, XPtrNode cur);
RcppExport SEXP _xml2_node_prepend_child(SEXP parentSEXP, SEXP curSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type parent(parentSEXP);
    Rcpp::traits::input_parameter< XPtrNode >::type cur(curSEXP);
    rcpp_result_gen = Rcpp::wrap(node_prepend_child(parent, cur));
    return rcpp_result_gen;
END_RCPP
}
// node_prepend_sibling
XPtrNode node_prepend_sibling(XPtrNode cur, XPtrNode elem);
RcppExport SEXP _xml2_node_prepend_sibling(SEXP curSEXP, SEXP elemSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type cur(curSEXP);
    Rcpp::traits::input_parameter< XPtrNode >::type elem(elemSEXP);
    rcpp_result_gen = Rcpp::wrap(node_prepend_sibling(cur, elem));
    return rcpp_result_gen;
END_RCPP
}
// node_replace
XPtrNode node_replace(XPtrNode old, XPtrNode cur);
RcppExport SEXP _xml2_node_replace(SEXP oldSEXP, SEXP curSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type old(oldSEXP);
    Rcpp::traits::input_parameter< XPtrNode >::type cur(curSEXP);
    rcpp_result_gen = Rcpp::wrap(node_replace(old, cur));
    return rcpp_result_gen;
END_RCPP
}
// node_remove
void node_remove(XPtrNode cur, bool free);
RcppExport SEXP _xml2_node_remove(SEXP curSEXP, SEXP freeSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type cur(curSEXP);
    Rcpp::traits::input_parameter< bool >::type free(freeSEXP);
    node_remove(cur, free);
    return R_NilValue;
END_RCPP
}
// node_new
XPtrNode node_new(std::string name);
RcppExport SEXP _xml2_node_new(SEXP nameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    rcpp_result_gen = Rcpp::wrap(node_new(name));
    return rcpp_result_gen;
END_RCPP
}
// node_new_ns
XPtrNode node_new_ns(std::string name, XPtrNs ns);
RcppExport SEXP _xml2_node_new_ns(SEXP nameSEXP, SEXP nsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< XPtrNs >::type ns(nsSEXP);
    rcpp_result_gen = Rcpp::wrap(node_new_ns(name, ns));
    return rcpp_result_gen;
END_RCPP
}
// node_null
XPtrNode node_null();
RcppExport SEXP _xml2_node_null() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(node_null());
    return rcpp_result_gen;
END_RCPP
}
// node_set_namespace_uri
void node_set_namespace_uri(XPtrDoc doc, XPtrNode node, std::string uri);
RcppExport SEXP _xml2_node_set_namespace_uri(SEXP docSEXP, SEXP nodeSEXP, SEXP uriSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrDoc >::type doc(docSEXP);
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< std::string >::type uri(uriSEXP);
    node_set_namespace_uri(doc, node, uri);
    return R_NilValue;
END_RCPP
}
// node_set_namespace_prefix
void node_set_namespace_prefix(XPtrDoc doc, XPtrNode node, std::string prefix);
RcppExport SEXP _xml2_node_set_namespace_prefix(SEXP docSEXP, SEXP nodeSEXP, SEXP prefixSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrDoc >::type doc(docSEXP);
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< std::string >::type prefix(prefixSEXP);
    node_set_namespace_prefix(doc, node, prefix);
    return R_NilValue;
END_RCPP
}
// node_new_dtd
void node_new_dtd(XPtrDoc doc, std::string name, std::string eid, std::string sid);
RcppExport SEXP _xml2_node_new_dtd(SEXP docSEXP, SEXP nameSEXP, SEXP eidSEXP, SEXP sidSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrDoc >::type doc(docSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< std::string >::type eid(eidSEXP);
    Rcpp::traits::input_parameter< std::string >::type sid(sidSEXP);
    node_new_dtd(doc, name, eid, sid);
    return R_NilValue;
END_RCPP
}
// xml_save_options
Rcpp::IntegerVector xml_save_options();
RcppExport SEXP _xml2_xml_save_options() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(xml_save_options());
    return rcpp_result_gen;
END_RCPP
}
// node_write_file
void node_write_file(XPtrNode x, std::string path, std::string encoding, int options);
RcppExport SEXP _xml2_node_write_file(SEXP xSEXP, SEXP pathSEXP, SEXP encodingSEXP, SEXP optionsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type x(xSEXP);
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    Rcpp::traits::input_parameter< int >::type options(optionsSEXP);
    node_write_file(x, path, encoding, options);
    return R_NilValue;
END_RCPP
}
// node_write_connection
void node_write_connection(XPtrNode x, SEXP connection, std::string encoding, int options);
RcppExport SEXP _xml2_node_write_connection(SEXP xSEXP, SEXP connectionSEXP, SEXP encodingSEXP, SEXP optionsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type x(xSEXP);
    Rcpp::traits::input_parameter< SEXP >::type connection(connectionSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    Rcpp::traits::input_parameter< int >::type options(optionsSEXP);
    node_write_connection(x, connection, encoding, options);
    return R_NilValue;
END_RCPP
}
// node_write_character
CharacterVector node_write_character(XPtrNode x, std::string encoding, int options);
RcppExport SEXP _xml2_node_write_character(SEXP xSEXP, SEXP encodingSEXP, SEXP optionsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type x(xSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    Rcpp::traits::input_parameter< int >::type options(optionsSEXP);
    rcpp_result_gen = Rcpp::wrap(node_write_character(x, encoding, options));
    return rcpp_result_gen;
END_RCPP
}
// url_absolute
CharacterVector url_absolute(CharacterVector x, CharacterVector base);
RcppExport SEXP _xml2_url_absolute(SEXP xSEXP, SEXP baseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type base(baseSEXP);
    rcpp_result_gen = Rcpp::wrap(url_absolute(x, base));
    return rcpp_result_gen;
END_RCPP
}
// url_relative
CharacterVector url_relative(CharacterVector x, CharacterVector base);
RcppExport SEXP _xml2_url_relative(SEXP xSEXP, SEXP baseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type base(baseSEXP);
    rcpp_result_gen = Rcpp::wrap(url_relative(x, base));
    return rcpp_result_gen;
END_RCPP
}
// url_parse
List url_parse(CharacterVector x);
RcppExport SEXP _xml2_url_parse(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(url_parse(x));
    return rcpp_result_gen;
END_RCPP
}
// url_escape
CharacterVector url_escape(CharacterVector x, CharacterVector reserved);
RcppExport SEXP _xml2_url_escape(SEXP xSEXP, SEXP reservedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type reserved(reservedSEXP);
    rcpp_result_gen = Rcpp::wrap(url_escape(x, reserved));
    return rcpp_result_gen;
END_RCPP
}
// url_unescape
CharacterVector url_unescape(CharacterVector x);
RcppExport SEXP _xml2_url_unescape(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(url_unescape(x));
    return rcpp_result_gen;
END_RCPP
}
// xpath_search
RObject xpath_search(XPtrNode node, XPtrDoc doc, std::string xpath, CharacterVector nsMap, double num_results);
RcppExport SEXP _xml2_xpath_search(SEXP nodeSEXP, SEXP docSEXP, SEXP xpathSEXP, SEXP nsMapSEXP, SEXP num_resultsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtrNode >::type node(nodeSEXP);
    Rcpp::traits::input_parameter< XPtrDoc >::type doc(docSEXP);
    Rcpp::traits::input_parameter< std::string >::type xpath(xpathSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type nsMap(nsMapSEXP);
    Rcpp::traits::input_parameter< double >::type num_results(num_resultsSEXP);
    rcpp_result_gen = Rcpp::wrap(xpath_search(node, doc, xpath, nsMap, num_results));
    return rcpp_result_gen;
END_RCPP
}
