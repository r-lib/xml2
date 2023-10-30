#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

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
extern SEXP init_libxml2(void);
extern SEXP libxml2_version_(void);
extern SEXP node_append_child(SEXP, SEXP);
extern SEXP node_append_content(SEXP, SEXP);
extern SEXP node_append_sibling(SEXP, SEXP);
extern SEXP node_attr(SEXP, SEXP, SEXP, SEXP);
extern SEXP node_attrs(SEXP, SEXP);
extern SEXP node_cdata_new(SEXP, SEXP);
extern SEXP node_children(SEXP, SEXP);
extern SEXP node_comment_new(SEXP);
extern SEXP node_copy(SEXP);
extern SEXP node_has_children(SEXP, SEXP);
extern SEXP node_length(SEXP, SEXP);
extern SEXP node_name(SEXP, SEXP);
extern SEXP node_new(SEXP);
extern SEXP node_new_dtd(SEXP, SEXP, SEXP, SEXP);
extern SEXP node_new_ns(SEXP, SEXP);
extern SEXP node_new_text(SEXP, SEXP);
extern SEXP node_parent(SEXP);
extern SEXP node_parents(SEXP);
extern SEXP node_path(SEXP);
extern SEXP node_prepend_child(SEXP, SEXP);
extern SEXP node_prepend_sibling(SEXP, SEXP);
extern SEXP node_remove(SEXP, SEXP);
extern SEXP node_remove_attr(SEXP, SEXP, SEXP);
extern SEXP node_replace(SEXP, SEXP);
extern SEXP node_set_attr(SEXP, SEXP, SEXP, SEXP);
extern SEXP node_set_content(SEXP, SEXP);
extern SEXP node_set_name(SEXP, SEXP);
extern SEXP node_set_namespace_prefix(SEXP, SEXP, SEXP);
extern SEXP node_set_namespace_uri(SEXP, SEXP, SEXP);
extern SEXP node_siblings(SEXP, SEXP);
extern SEXP node_text(SEXP);
extern SEXP node_type(SEXP);
extern SEXP node_write_character(SEXP, SEXP, SEXP);
extern SEXP node_write_connection(SEXP, SEXP, SEXP, SEXP);
extern SEXP node_write_file(SEXP, SEXP, SEXP, SEXP);
extern SEXP nodes_duplicated(SEXP);
extern SEXP ns_lookup(SEXP, SEXP, SEXP);
extern SEXP ns_lookup_uri(SEXP, SEXP, SEXP);
extern SEXP read_connection_(SEXP, SEXP);
extern SEXP unique_ns(SEXP);
extern SEXP url_absolute_(SEXP, SEXP);
extern SEXP url_escape_(SEXP, SEXP);
extern SEXP url_parse_(SEXP);
extern SEXP url_relative_(SEXP, SEXP);
extern SEXP url_unescape_(SEXP);
extern SEXP xml_parse_options_(void);
extern SEXP xml_save_options_(void);
extern SEXP xpath_search(SEXP, SEXP, SEXP, SEXP, SEXP);

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
    {"node_cdata_new",            (DL_FUNC) &node_cdata_new,            2},
    {"node_children",             (DL_FUNC) &node_children,             2},
    {"node_comment_new",          (DL_FUNC) &node_comment_new,          1},
    {"node_copy",                 (DL_FUNC) &node_copy,                 1},
    {"node_has_children",         (DL_FUNC) &node_has_children,         2},
    {"node_length",               (DL_FUNC) &node_length,               2},
    {"node_name",                 (DL_FUNC) &node_name,                 2},
    {"node_new",                  (DL_FUNC) &node_new,                  1},
    {"node_new_dtd",              (DL_FUNC) &node_new_dtd,              4},
    {"node_new_ns",               (DL_FUNC) &node_new_ns,               2},
    {"node_new_text",             (DL_FUNC) &node_new_text,             2},
    {"node_parent",               (DL_FUNC) &node_parent,               1},
    {"node_parents",              (DL_FUNC) &node_parents,              1},
    {"node_path",                 (DL_FUNC) &node_path,                 1},
    {"node_prepend_child",        (DL_FUNC) &node_prepend_child,        2},
    {"node_prepend_sibling",      (DL_FUNC) &node_prepend_sibling,      2},
    {"node_remove",               (DL_FUNC) &node_remove,               2},
    {"node_remove_attr",          (DL_FUNC) &node_remove_attr,          3},
    {"node_replace",              (DL_FUNC) &node_replace,              2},
    {"node_set_attr",             (DL_FUNC) &node_set_attr,             4},
    {"node_set_content",          (DL_FUNC) &node_set_content,          2},
    {"node_set_name",             (DL_FUNC) &node_set_name,             2},
    {"node_set_namespace_prefix", (DL_FUNC) &node_set_namespace_prefix, 3},
    {"node_set_namespace_uri",    (DL_FUNC) &node_set_namespace_uri,    3},
    {"node_siblings",             (DL_FUNC) &node_siblings,             2},
    {"node_text",                 (DL_FUNC) &node_text,                 1},
    {"node_type",                 (DL_FUNC) &node_type,                 1},
    {"node_write_character",      (DL_FUNC) &node_write_character,      3},
    {"node_write_connection",     (DL_FUNC) &node_write_connection,     4},
    {"node_write_file",           (DL_FUNC) &node_write_file,           4},
    {"nodes_duplicated",          (DL_FUNC) &nodes_duplicated,          1},
    {"ns_lookup",                 (DL_FUNC) &ns_lookup,                 3},
    {"ns_lookup_uri",             (DL_FUNC) &ns_lookup_uri,             3},
    {"read_connection_",          (DL_FUNC) &read_connection_,          2},
    {"unique_ns",                 (DL_FUNC) &unique_ns,                 1},
    {"url_absolute_",             (DL_FUNC) &url_absolute_,             2},
    {"url_escape_",               (DL_FUNC) &url_escape_,               2},
    {"url_parse_",                (DL_FUNC) &url_parse_,                1},
    {"url_relative_",             (DL_FUNC) &url_relative_,             2},
    {"url_unescape_",             (DL_FUNC) &url_unescape_,             1},
    {"xml_parse_options_",        (DL_FUNC) &xml_parse_options_,        0},
    {"xml_save_options_",         (DL_FUNC) &xml_save_options_,         0},
    {"xpath_search",              (DL_FUNC) &xpath_search,              5},
    {NULL, NULL, 0}
};

void R_init_xml2(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
