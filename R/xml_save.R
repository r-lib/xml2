#' Save xml nodes to a character vector.
#'
#' @param x A document, node, or node set.
#' @return A character vector.
#' @export
#' @examples
#' x <- xml("<bar><baz>1</baz>abc<foo /></bar>")
#' xml_save(x)
#'
#' y <- xml("<bar><baz>1</baz>abc<baz><foo>2</foo></baz></bar>")
#' ns <- xml_find(y, "//baz")
#' xml_save(ns)
xml_save <- function(x) {
  UseMethod("xml_save")
}

#' @export
xml_save.xml_nodeset <- function(x) {
  vapply(x$nodes, node_format, doc = x$doc, FUN.VALUE = character(1))
}

#' @export
xml_save.xml_document <- function(x) {
  doc_format(x$doc)
}
