#' The (tag) name of an xml element.
#'
#' @param x A document, node, or node set.
#' @return A character vector.
#' @export
#' @examples
#' x <- xml_parse("<bar>123</bar>")
#' xml_name(x)
#'
#' y <- xml_parse("<bar><baz>1</baz>abc<foo /></bar>")
#' z <- xml_children(y)
#' xml_name(xml_children(y))
xml_name <- function(x, ...) {
  UseMethod("xml_name")
}

#' @export
xml_name.xml_node <- function(x, ...) {
  node_name(x$node)
}

#' @export
xml_name.xml_doc <- function(x, ...) {
  node_name(xml_root(x)$node)
}

#' @export
xml_name.xml_nodeset <- function(x, ...) {
  vapply(x, xml_name, character(1))
}
