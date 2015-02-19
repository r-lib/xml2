#' The (tag) name of an xml element.
#'
#' @param x A document, node, or node set.
#' @param ns Optionally, a named vector giving prefix-url pairs, as produced
#'   by \code{\link{xml_ns}}. If provided, all names will be explicitly
#'   qualified with the ns prefix, i.e. if the element \code{bar} is defined
#'   in namespace \code{foo}, it will be called \code{foo:bar}. (And
#'   similarly for atttributes). Default namespaces must be given an explicit
#'   name.
#' @return A character vector.
#' @export
#' @examples
#' x <- xml("<bar>123</bar>")
#' xml_name(x)
#'
#' y <- xml("<bar><baz>1</baz>abc<foo /></bar>")
#' z <- xml_children(y)
#' xml_name(xml_children(y))
xml_name <- function(x, ns = character()) {
  UseMethod("xml_name")
}

#' @export
xml_name.xml_nodeset <- function(x, ns = character()) {
  vapply(x$nodes, node_name, ns = ns, FUN.VALUE = character(1))
}
