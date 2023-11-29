#' Determine the type of a node.
#'
#' @inheritParams xml_name
#' @export
#' @examples
#' x <- read_xml("<foo> a <b /> <![CDATA[ blah]]></foo>")
#' xml_type(x)
#' xml_type(xml_contents(x))
xml_type <- function(x) {
  types <- .Call(node_type, x)
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
