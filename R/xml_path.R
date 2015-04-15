#' Retrieve the xpath to a node
#'
#' This is useful when you want to figure out where nodes matching an
#' xpath expression live in a document.
#'
#' @inheritParams xml_name
#' @return A character vector.
#' @export
#' @examples
#' x <- read_xml("<foo><bar><baz /></bar><baz /></foo>")
#' xml_path(xml_find_all(x, ".//baz"))
xml_path <- function(x) {
  UseMethod("xml_path")
}

#' @export
xml_path.xml_node <- function(x) {
  node_path(x$node)
}

#' @export
xml_path.xml_nodeset <- function(x) {
  vapply(x, xml_path, FUN.VALUE = character(1))
}
