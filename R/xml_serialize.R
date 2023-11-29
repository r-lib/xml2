#' Serializing XML objects to connections.
#'
#' @inheritParams base::serialize
#' @param ... Additional arguments passed to [read_xml()].
#' @inherit base::serialize return
#' @examples
#' library(xml2)
#' x <- read_xml("<a>
#'   <b><c>123</c></b>
#'   <b><c>456</c></b>
#' </a>")
#'
#' b <- xml_find_all(x, "//b")
#' out <- xml_serialize(b, NULL)
#' xml_unserialize(out)
#' @export
xml_serialize <- function(object, connection, ...) UseMethod("xml_serialize")

#' @export
xml_serialize.xml_document <- function(object, connection, ...) {
  if (is.character(connection)) {
    connection <- file(connection, "w", raw = TRUE)
    on.exit(close(connection))
  }
  serialize(structure(as.character(object, ...), doc_type = doc_type(object), class = "xml_serialized_document"), connection)
}

#' @export
xml_serialize.xml_node <- function(object, connection, ...) {
  if (is.character(connection)) {
    connection <- file(connection, "w", raw = TRUE)
    on.exit(close(connection))
  }
  x <- as_xml_document(object)
  serialize(structure(as.character(x, ...), class = "xml_serialized_node"), connection)
}

#' @export
xml_serialize.xml_nodeset <- function(object, connection, ...) {
  if (is.character(connection)) {
    connection <- file(connection, "w", raw = TRUE)
    on.exit(close(connection))
  }
  x <- as_xml_document(object, "root")
  serialize(structure(as.character(x, ...), class = "xml_serialized_nodeset"), connection)
}

#' @rdname xml_serialize
#' @export
xml_unserialize <- function(connection, ...) {
  if (is.character(connection)) {
    connection <- file(connection, "r", raw = TRUE)
    on.exit(close(connection))
  }
  object <- unserialize(connection)
  if (inherits(object, "xml_serialized_nodeset")) {
    x <- read_xml(unclass(object), ...)

    # Select only the direct children of the root
    res <- xml_find_all(x, "/*/node()")
  } else if (inherits(object, "xml_serialized_node")) {
    x <- read_xml(unclass(object), ...)

    # Select only the root
    res <- xml_find_first(x, "/node()")
  } else if (inherits(object, "xml_serialized_document")) {
    read_xml_int <- function(object, as_html = FALSE, ...) {
      if (missing(as_html)) {
        as_html <- identical(attr(object, "doc_type", exact = TRUE), "html")
      }
      read_xml(unclass(object), as_html = as_html, ...)
    }
    res <- read_xml_int(unclass(object), ...)
  } else {
    abort("Not a serialized xml2 object")
  }
  res
}
