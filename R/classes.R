#' @useDynLib xml2
#' @importFrom Rcpp sourceCpp
NULL

# document ---------------------------------------------------------------------

xml_document <- function(doc) {
  structure(
    list(
      doc = doc,
      nodes = list(doc_root(doc))
    ),
    class = c("xml_document", "xml_nodeset")
  )
}

#' @export
print.xml_document <- function(x, ...) {
  cat("<xml_document>\n")
}

# node -------------------------------------------------------------------------

xml_nodeset <- function(nodes, doc) {
  structure(
    list(
      doc = doc,
      nodes = nodes
    ),
    class = "xml_nodeset"
  )
}

#' @export
print.xml_nodeset <- function(x, ...) {
  cat("<xml_nodeset [", length(x$nodes), "]>\n", sep = "")
}

nodeset_apply <- function(x, fun, ...) {
  out <- lapply(x$nodes, fun, ...)
  out <- unlist(out, recursive = FALSE)
  out <- out[!nodes_duplicated(out)]
  xml_nodeset(out, x$doc)
}
