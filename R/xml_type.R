#' Determine the type of a node.
#'
#' @inheritParams xml_name
#' @export
#' @examples
#' x <- xml("<foo> a <b /> <![CDATA[ blah]]></foo>")
#' xml_type(x)
#' xml_type(xml_contents(x))
xml_type <- function(x) {
  UseMethod("xml_type")
}

#' @export
xml_type.xml_nodeset <- function(x) {
  types <- vapply(x$nodes, node_type, integer(1))
  xmlElementType[types]
}

xmlElementType <- c(
  "element",
  "attribute",
  "text",
  "cdata",
  "entity_ref",
  "entity",
  "pi",
  "comment",
  "document",
  "document_type",
  "document_frag",
  "notation",
  "html_document",
  "dtd",
  "element_decl",
  "attribute_decl",
  "entity_decl",
  "namespace_decl",
  "xinclude_start",
  "xinclude_end",
  "docb_document"
)
