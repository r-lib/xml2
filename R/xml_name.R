#' The (tag) name of an xml element.
#'
#' @param x A document, node, or node set.
#' @export
#' @examples
#' x <- xml_parse("<bar>123</bar>")
#' xml_name(x)
xml_name <- function(x) {
  UseMethod("xml_name")
}
#' @export
xml_name.xml_node <- function(x) node_name(x$node)
#' @export
xml_name.xml_doc <- function(x) node_name(xml_root(x)$node)
