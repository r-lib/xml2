#' Write XML or HTML to disk.
#'
#' This writes out both XML and normalised HTML. The default behavior will
#' output the same format which was read. If you want to force output pass
#' `option = "as_xml"` or `option = "as_html"` respectively.
#'
#' @param x A document or node to write to disk. It's not possible to
#'   save nodesets containing more than one node.
#' @param file Path to file or connection to write to.
#' @param encoding The character encoding to use in the document. The default
#' encoding is \sQuote{UTF-8}. Available encodings are specified at
#' <http://xmlsoft.org/html/libxml-encoding.html#xmlCharEncoding>.
#' @param options default: \sQuote{format}. Zero or more of
#' \Sexpr[results=rd, stage=build]{xml2:::describe_options(xml2:::xml_save_options())}
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
  abort("Missing data cannot be written")
}

#' @rdname write_xml
#' @export
write_xml.xml_document <- function(x, file, ..., options = "format", encoding = "UTF-8") {
  options <- parse_options(options, xml_save_options())
  file <- path_to_connection(file, check = "dir")

  if (inherits(file, "connection")) {
    if (!isOpen(file)) {
      open(file, "wb")
      on.exit(close(file))
    }
    .Call(doc_write_connection, x$doc, file, encoding, options)
  } else {
    check_string(file)
    .Call(doc_write_file, x$doc, file, encoding, options)
  }

  invisible()
}

#' @export
write_xml.xml_nodeset <- function(x, file, ..., options = "format", encoding = "UTF-8") {
  if (length(x) != 1) {
    abort("Can only save length 1 node sets")
  }

  options <- parse_options(options, xml_save_options())
  file <- path_to_connection(file, check = "dir")

  if (inherits(file, "connection")) {
    if (!isOpen(file)) {
      open(file, "wb")
      on.exit(close(file))
    }
    .Call(node_write_connection, x[[1]]$node, file, encoding, options)
  } else {
    check_string(file)
    .Call(node_write_file, x[[1]]$node, file, encoding, options)
  }

  invisible()
}

#' @export
write_xml.xml_node <- function(x, file, ..., options = "format", encoding = "UTF-8") {
  options <- parse_options(options, xml_save_options())

  file <- path_to_connection(file, check = "dir")
  if (inherits(file, "connection")) {
    if (!isOpen(file)) {
      open(file, "wb")
      on.exit(close(file))
    }
    .Call(node_write_connection, x$node, file, encoding, options)
  } else {
    check_string(file)
    .Call(node_write_file, x$node, file, encoding, options)
  }

  invisible()
}


#' @export
#' @rdname write_xml
write_html <- function(x, file, ...) {
  UseMethod("write_html")
}

#' @export
write_html.xml_missing <- function(x, file, ...) {
  abort("Missing data cannot be written")
}

#' @rdname write_xml
#' @export
write_html.xml_document <- write_xml.xml_document

#' @export
write_html.xml_nodeset <- write_xml.xml_nodeset

#' @export
write_html.xml_node <- write_xml.xml_node
