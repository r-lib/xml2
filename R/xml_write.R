#' Write XML or HTML to disk.
#'
#' This writes out both XML and normalised HTML.
#'
#' @param x A document or node to write to disk. It's not possible to
#'   save nodesets containing more than one node.
#' @param file Path to file to write.
#' @param ... additional arguments passed to methods.
#' @param format if \code{TRUE}, the formatting spaces/lines are added to the
#' output, if \code{FALSE} output is left as is.
#' @export
#' @examples
#' h <- read_html("<p>Hi!</p>")
#'
#' tmp <- tempfile(fileext = ".xml")
#' write_xml(h, tmp)
#' readLines(tmp)
#'
#' # write formatted HTML output
#' write_html(h, tmp, format = TRUE)
#' readLines(tmp)
write_xml <- function(x, file, ...) {
  UseMethod("write_xml")
}

#' @export
write_xml.xml_missing <- function(x, file, ...) {
  stop("Missing data cannot be written", call. = FALSE)
}

#' @rdname write_xml
#' @export
write_xml.xml_document <- function(x, file, format = TRUE, ...) {
  doc_write_xml(x$doc, file, format)
}

#' @export
write_xml.xml_nodeset <- function(x, file, ...) {
  if (length(x$nodeset) != 1) {
    stop("Can only save length 1 node sets", call. = FALSE)
  }

  node_write_xml(x[[1]]$node, x$doc, file, ...)
}

#' @export
write_xml.xml_node <- function(x, file, format = TRUE, ...) {
  node_write_xml(x$node, x$doc, file)
}


#' @export
#' @rdname write_xml
write_html <- function(x, file, ...) {
  UseMethod("write_html")
}

#' @export
write_html.xml_missing <- function(x, file, ...) {
  stop("Missing data cannot be written", call. = FALSE)
}

#' @rdname write_xml
#' @export
write_html.xml_document <- function(x, file, format = TRUE, ...) {
  doc_write_html(x$doc, file, format)
}

#' @export
write_html.xml_nodeset <- function(x, file, ...) {
  if (length(x$nodeset) != 1) {
    stop("Can only save length 1 node sets", call. = FALSE)
  }

  node_write_html(x[[1]]$node, x$doc, file, ...)
}

#' @export
write_html.xml_node <- function(x, file, format = TRUE, ...) {
  node_write_html(x$node, x$doc, file)
}
