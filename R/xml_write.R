#' Write XML or HTML to disk.
#'
#' This writes out both XML and normalised HTML. The default behavior will
#' output the same format which was read. If you want to force output pass
#' \code{option = "as_xml"} or \code{option = "as_html"} respectively.
#'
#' @param x A document or node to write to disk. It's not possible to
#'   save nodesets containing more than one node.
#' @param file Path to file or connection to write to.
#' @param encoding The character encoding to use in the document. The default
#' encoding is \sQuote{UTF-8}. Available encodings are specified at
#' \url{http://xmlsoft.org/html/libxml-encoding.html#xmlCharEncoding}.
#' @param options default: \sQuote{format}. Zero or more of
#' \Sexpr[results=rd]{xml2:::describe_options(xml2:::xml_save_options())}
#' @param ... additional arguments passed to methods.
#' @export
#' @examples
#' h <- read_html("<p>Hi!</p>")
#'
#' tmp <- tempfile(fileext = ".xml")
#' write_xml(h, tmp, options = "format")
#' readLines(tmp)
#'
#' # write formatted HTML output
#' write_html(h, tmp, options = "format")
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
write_xml.xml_document <- function(x, file, ..., options = "format", encoding = "UTF-8") {
  options  <- parse_options(options, xml_save_options())
  file <- path_to_connection(file, check = "dir")

  if (inherits(file, "connection")) {
    if (!isOpen(file)) {
      open(file, "wb")
      on.exit(close(file))
    }
    doc_write_connection(x$doc, file, options = options, encoding = encoding)
  } else {
    if (!(is.character(file) && length(file) == 1 && nzchar(file))) {
      stop("`file` must be a non-zero character of length 1", call. = FALSE)
    }
    doc_write(x$doc, file, options = options, encoding = encoding)
  }
}

#' @export
write_xml.xml_nodeset <- function(x, file, ..., options = "format", encoding = "UTF-8") {
  if (length(x) != 1) {
    stop("Can only save length 1 node sets", call. = FALSE)
  }

  options  <- parse_options(options, xml_save_options())
  file <- path_to_connection(file, check = "dir")

  if (inherits(file, "connection")) {
    if (!isOpen(file)) {
      open(file, "wb")
      on.exit(close(file))
    }
    node_write_connection(x[[1]]$node, file, options = options, encoding = encoding)
  } else {
    if (!(is.character(file) && length(file) == 1 && nzchar(file))) {
      stop("`file` must be a non-zero character of length 1", call. = FALSE)
    }
    node_write(x[[1]]$node, file, options = options, encoding = encoding)
  }
}

#' @export
write_xml.xml_node <- function(x, file, format = TRUE, ..., options = "format", encoding = "UTF-8") {
  options  <- parse_options(options, xml_save_options())

  file <- path_to_connection(file, check = "dir")
  if (inherits(file, "connection")) {
    if (!isOpen(file)) {
      open(file, "wb")
      on.exit(close(file))
    }
    node_write_connection(x$node, file, options = options, encoding = encoding)
  } else {
    if (!(is.character(file) && length(file) == 1 && nzchar(file))) {
      stop("`file` must be a non-zero character of length 1", call. = FALSE)
    }
    node_write(x$node, file, options = options, encoding = encoding)
  }
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
write_html.xml_document <- write_xml.xml_document

#' @export
write_html.xml_nodeset <- write_xml.xml_nodeset

#' @export
write_html.xml_node <- write_xml.xml_node
