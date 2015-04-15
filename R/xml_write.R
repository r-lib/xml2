#' Write XML to disk.
#'
#' This writes out both XML and normalised HTML.
#'
#' @param x A document or node to write to disk. It's not possible to
#'   save nodesets containing more than one node.
#' @param file Path to file to write.
#' @export
#' @examples
#' h <- read_html("<p>Hi!</p>")
#'
#' tmp <- tempfile(fileext = ".xml")
#' write_xml(h, tmp)
#' read_xml(tmp)
write_xml <- function(x, file) {
  UseMethod("write_xml")
}

#' @export
write_xml.xml_document <- function(x, file) {
  doc_write(x$doc, file)
}

#' @export
write_xml.xml_nodeset <- function(x, file, ...) {
  if (length(x$nodeset) != 1) {
    stop("Can only save length 1 node sets")
  }

  node_write(x[[1]]$node, x$doc, file)
}

#' @export
write_xml.xml_node <- function(x, file, ...) {
  node_write(x$node, x$doc, file)
}
