#' @useDynLib xml2
#' @importFrom Rcpp sourceCpp
NULL

# document ---------------------------------------------------------------------

xml_doc <- function(doc) {
  structure(list(doc = doc), class = "xml_doc")
}

#' @export
print.xml_doc <- function(x, ...){
  cat(doc_format(x$doc), "\n")
}

# node -------------------------------------------------------------------------

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

# nodeset -----------------------------------------------------------------

xml_nodeset <- function(nodes, doc) {
  structure(
    lapply(nodes, xml_node, doc = doc),
    class = "xml_nodeset"
  )
}

#' @export
print.xml_nodeset <- function(x, ...) {
  if (length(x) == 0) {
    cat("<Empty nodeset>\n")
    return()
  }

  NextMethod()
}
