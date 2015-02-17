#' Extract the root node.
#'
#' @param x A document, a node or a nodeset.
#' @param ... Additional arguments passed down to methods. (Not currently used).
#' @return If \code{x} is a document, returns the root node. If \code{x}
#'   is a node or nodeset, returns the input unchanged.
#' @export
#' @examples
#' x <- xml_parse("<foo> <bar> 1 </bar> </foo>")
#' xml_root(x)
#' xml_root(x)
xml_root <- function(x, ...) {
  UseMethod("xml_root")
}

#' @export
xml_root.xml_doc <- function(x, ...) {
  xml_node(doc_root(x$doc), x$doc)
}

#' @export
xml_root.xml_node <- function(x, ...) {
  x
}

#' @export
xml_root.xml_nodeset <- function(x, ...) {
  x
}
