xml_node <- function(node, doc) {
  structure(list(
    node = node,
    doc = doc
  ), class = "xml_node")
}

#' @export
print.xml_node <- function(x, ...) {
  cat(node_format(x$doc, x$node), "\n", sep = "")
}

#' Extract the root node from a document
#'
#' @param x An xml_doc
#' @export
xml_root <- function(x) {
  xml_node(doc_root(x$doc), x$doc)
}

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
