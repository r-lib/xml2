#' Extract children.
#'
#' @param x A document, node or nodeset.
#' @param ... Additional arguments passed down to methods. (Not currently used).
#' @return A nodeset
#' @export
#' @examples
#' x <- xml_parse("<foo> <bar><boo /></bar> 123 <baz/> </foo>")
#' (kids <- xml_children(x))
#' (grand_kids <- xml_children(kids))
xml_children <- function(x, ...) {
  UseMethod("xml_children")
}

#' @export
xml_children.xml_node <- function(x, ...) {
  xml_nodeset(node_children(x$node), x$doc)
}
#' @export
xml_children.xml_nodeset <- function(x, ...) {
  unlist(lapply(x, xml_children), recursive = FALSE)
}
#' @export
xml_children.xml_doc <- function(x, ...) {
  xml_children(xml_root(x))
}
