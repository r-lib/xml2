#' Write XML to disk.
#'
#' This writes out both XML and normalised HTML.
#'
#' @param x A document or node to write to disk. It's not possible to
#'   save a nodeset, because that would not create a valid XML file (there's
#'   no root node)
#' @param file Path to file to write.
#' @param ... Other arguments used by methods.
#' @export
#' @examples
#' h <- html("<p>Hi!</p>")
#'
#' tmp <- tempfile(fileext = ".xml")
#' write_xml(h, tmp)
#' read_xml(tmp)
write_xml <- function(x, file, ...) {
  UseMethod("write_xml")
}

#' @export
write_xml.xml_doc <- function(x, file, ...) {
  doc_write(x$doc, file)
}

#' @export
write_xml.xml_node <- function(x, file, ...) {
  node_write(x$node, x$doc, file)
}
