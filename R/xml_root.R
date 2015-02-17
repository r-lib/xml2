#' Extract the root node from a document
#'
#' @param x An xml_doc
#' @export
xml_root <- function(x) {
  xml_node(doc_root(x$doc), x$doc)
}

