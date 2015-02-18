#' The (tag) name of an xml element.
#'
#' @param x A document, node, or node set.
#' @param ... Additional arguments passed down to methods. (Not currently used).
#' @return A character vector.
#' @export
#' @examples
#' x <- xml("<bar>123</bar>")
#' xml_name(x)
#'
#' y <- xml("<bar><baz>1</baz>abc<foo /></bar>")
#' z <- xml_children(y)
#' xml_name(xml_children(y))
xml_name <- function(x, ...) {
  UseMethod("xml_name")
}

#' @export
xml_name.xml_nodeset <- function(x, ...) {
  vapply(x$nodes, node_name, FUN.VALUE = character(1))
}
