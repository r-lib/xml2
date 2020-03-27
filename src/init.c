#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP doc_has_root(SEXP);
extern SEXP doc_is_html(SEXP);
extern SEXP doc_namespaces(SEXP);
extern SEXP doc_new(SEXP, SEXP);
extern SEXP doc_parse_file(SEXP, SEXP, SEXP, SEXP);
extern SEXP doc_parse_raw(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP doc_root(SEXP);
extern SEXP doc_set_root(SEXP, SEXP);
extern SEXP doc_url(SEXP);
extern SEXP doc_validate(SEXP, SEXP);
extern SEXP doc_write_character(SEXP, SEXP, SEXP);
extern SEXP doc_write_connection(SEXP, SEXP, SEXP, SEXP);
extern SEXP doc_write_file(SEXP, SEXP, SEXP, SEXP);
extern SEXP init_libxml2();
extern SEXP libxml2_version_();
extern SEXP node_append_child(SEXP, SEXP);
extern SEXP node_append_content(SEXP, SEXP);
extern SEXP node_append_sibling(SEXP, SEXP);
extern SEXP node_attr(SEXP, SEXP, SEXP, SEXP);
extern SEXP node_attrs(SEXP, SEXP);
extern SEXP _xml2_node_cdata_new(SEXP, SEXP);
extern SEXP _xml2_node_children(SEXP, SEXP);
extern SEXP _xml2_node_comment_new(SEXP);
extern SEXP _xml2_node_copy(SEXP);
extern SEXP _xml2_node_has_children(SEXP, SEXP);
extern SEXP _xml2_node_length(SEXP, SEXP);
extern SEXP _xml2_node_name(SEXP, SEXP);
extern SEXP _xml2_node_new(SEXP);
extern SEXP _xml2_node_new_dtd(SEXP, SEXP, SEXP, SEXP);
extern SEXP _xml2_node_new_ns(SEXP, SEXP);
extern SEXP _xml2_node_new_text(SEXP, SEXP);
extern SEXP _xml2_node_null();
extern SEXP _xml2_node_parent(SEXP);
extern SEXP _xml2_node_parents(SEXP);
extern SEXP _xml2_node_path(SEXP);
extern SEXP _xml2_node_prepend_child(SEXP, SEXP);
extern SEXP _xml2_node_prepend_sibling(SEXP, SEXP);
extern SEXP _xml2_node_remove(SEXP, SEXP);
extern SEXP _xml2_node_remove_attr(SEXP, SEXP, SEXP);
extern SEXP _xml2_node_replace(SEXP, SEXP);
extern SEXP _xml2_node_set_attr(SEXP, SEXP, SEXP, SEXP);
extern SEXP _xml2_node_set_content(SEXP, SEXP);
extern SEXP _xml2_node_set_name(SEXP, SEXP);
extern SEXP _xml2_node_set_namespace_prefix(SEXP, SEXP, SEXP);
extern SEXP _xml2_node_set_namespace_uri(SEXP, SEXP, SEXP);
extern SEXP _xml2_node_siblings(SEXP, SEXP);
extern SEXP _xml2_node_text(SEXP);
extern SEXP _xml2_node_type(SEXP);
extern SEXP _xml2_node_write_character(SEXP, SEXP, SEXP);
extern SEXP _xml2_node_write_connection(SEXP, SEXP, SEXP, SEXP);
extern SEXP _xml2_node_write_file(SEXP, SEXP, SEXP, SEXP);
extern SEXP _xml2_nodes_duplicated(SEXP);
extern SEXP _xml2_ns_lookup(SEXP, SEXP, SEXP);
extern SEXP _xml2_ns_lookup_uri(SEXP, SEXP, SEXP);
extern SEXP _xml2_read_connection_(SEXP, SEXP);
extern SEXP _xml2_unique_ns(SEXP);
extern SEXP _xml2_url_absolute(SEXP, SEXP);
extern SEXP _xml2_url_escape(SEXP, SEXP);
extern SEXP _xml2_url_parse(SEXP);
extern SEXP _xml2_url_relative(SEXP, SEXP);
extern SEXP _xml2_url_unescape(SEXP);
extern SEXP _xml2_xml_parse_options();
extern SEXP _xml2_xml_save_options();
extern SEXP _xml2_xpath_search(SEXP, SEXP, SEXP, SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"doc_has_root",              (DL_FUNC) &doc_has_root,              1},
    {"doc_is_html",               (DL_FUNC) &doc_is_html,               1},
    {"doc_namespaces",            (DL_FUNC) &doc_namespaces,            1},
    {"doc_new",                   (DL_FUNC) &doc_new,                   2},
    {"doc_parse_file",            (DL_FUNC) &doc_parse_file,            4},
    {"doc_parse_raw",             (DL_FUNC) &doc_parse_raw,             5},
    {"doc_root",                  (DL_FUNC) &doc_root,                  1},
    {"doc_set_root",              (DL_FUNC) &doc_set_root,              2},
    {"doc_url",                   (DL_FUNC) &doc_url,                   1},
    {"doc_validate",              (DL_FUNC) &doc_validate,              2},
    {"doc_write_character",       (DL_FUNC) &doc_write_character,       3},
    {"doc_write_connection",      (DL_FUNC) &doc_write_connection,      4},
    {"doc_write_file",            (DL_FUNC) &doc_write_file,            4},
    {"init_libxml2",              (DL_FUNC) &init_libxml2,              0},
    {"libxml2_version_",          (DL_FUNC) &libxml2_version_,          0},
    {"node_append_child",         (DL_FUNC) &node_append_child,         2},
    {"node_append_content",       (DL_FUNC) &node_append_content,       2},
    {"node_append_sibling",       (DL_FUNC) &node_append_sibling,       2},
    {"node_attr",                 (DL_FUNC) &node_attr,                 4},
    {"node_attrs",                (DL_FUNC) &node_attrs,                2},
    {"_xml2_node_cdata_new",            (DL_FUNC) &_xml2_node_cdata_new,            2},
    {"_xml2_node_children",             (DL_FUNC) &_xml2_node_children,             2},
    {"_xml2_node_comment_new",          (DL_FUNC) &_xml2_node_comment_new,          1},
    {"_xml2_node_copy",                 (DL_FUNC) &_xml2_node_copy,                 1},
    {"_xml2_node_has_children",         (DL_FUNC) &_xml2_node_has_children,         2},
    {"_xml2_node_length",               (DL_FUNC) &_xml2_node_length,               2},
    {"_xml2_node_name",                 (DL_FUNC) &_xml2_node_name,                 2},
    {"_xml2_node_new",                  (DL_FUNC) &_xml2_node_new,                  1},
    {"_xml2_node_new_dtd",              (DL_FUNC) &_xml2_node_new_dtd,              4},
    {"_xml2_node_new_ns",               (DL_FUNC) &_xml2_node_new_ns,               2},
    {"_xml2_node_new_text",             (DL_FUNC) &_xml2_node_new_text,             2},
    {"_xml2_node_null",                 (DL_FUNC) &_xml2_node_null,                 0},
    {"_xml2_node_parent",               (DL_FUNC) &_xml2_node_parent,               1},
    {"_xml2_node_parents",              (DL_FUNC) &_xml2_node_parents,              1},
    {"_xml2_node_path",                 (DL_FUNC) &_xml2_node_path,                 1},
    {"_xml2_node_prepend_child",        (DL_FUNC) &_xml2_node_prepend_child,        2},
    {"_xml2_node_prepend_sibling",      (DL_FUNC) &_xml2_node_prepend_sibling,      2},
    {"_xml2_node_remove",               (DL_FUNC) &_xml2_node_remove,               2},
    {"_xml2_node_remove_attr",          (DL_FUNC) &_xml2_node_remove_attr,          3},
    {"_xml2_node_replace",              (DL_FUNC) &_xml2_node_replace,              2},
    {"_xml2_node_set_attr",             (DL_FUNC) &_xml2_node_set_attr,             4},
    {"_xml2_node_set_content",          (DL_FUNC) &_xml2_node_set_content,          2},
    {"_xml2_node_set_name",             (DL_FUNC) &_xml2_node_set_name,             2},
    {"_xml2_node_set_namespace_prefix", (DL_FUNC) &_xml2_node_set_namespace_prefix, 3},
    {"_xml2_node_set_namespace_uri",    (DL_FUNC) &_xml2_node_set_namespace_uri,    3},
    {"_xml2_node_siblings",             (DL_FUNC) &_xml2_node_siblings,             2},
    {"_xml2_node_text",                 (DL_FUNC) &_xml2_node_text,                 1},
    {"_xml2_node_type",                 (DL_FUNC) &_xml2_node_type,                 1},
    {"_xml2_node_write_character",      (DL_FUNC) &_xml2_node_write_character,      3},
    {"_xml2_node_write_connection",     (DL_FUNC) &_xml2_node_write_connection,     4},
    {"_xml2_node_write_file",           (DL_FUNC) &_xml2_node_write_file,           4},
    {"_xml2_nodes_duplicated",          (DL_FUNC) &_xml2_nodes_duplicated,          1},
    {"_xml2_ns_lookup",                 (DL_FUNC) &_xml2_ns_lookup,                 3},
    {"_xml2_ns_lookup_uri",             (DL_FUNC) &_xml2_ns_lookup_uri,             3},
    {"_xml2_read_connection_",          (DL_FUNC) &_xml2_read_connection_,          2},
    {"_xml2_unique_ns",                 (DL_FUNC) &_xml2_unique_ns,                 1},
    {"_xml2_url_absolute",              (DL_FUNC) &_xml2_url_absolute,              2},
    {"_xml2_url_escape",                (DL_FUNC) &_xml2_url_escape,                2},
    {"_xml2_url_parse",                 (DL_FUNC) &_xml2_url_parse,                 1},
    {"_xml2_url_relative",              (DL_FUNC) &_xml2_url_relative,              2},
    {"_xml2_url_unescape",              (DL_FUNC) &_xml2_url_unescape,              1},
    {"_xml2_xml_parse_options",         (DL_FUNC) &_xml2_xml_parse_options,         0},
    {"_xml2_xml_save_options",          (DL_FUNC) &_xml2_xml_save_options,          0},
    {"_xml2_xpath_search",              (DL_FUNC) &_xml2_xpath_search,              5},
    {NULL, NULL, 0}
};

void R_init_xml2(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
