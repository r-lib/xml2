#' Serializing XML objects to connections.
#'
#' @inheritParams base::serialize
#' @param ... Additional arguments passed to \code{\link{read_xml}}.
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
  serialize(structure(as.character(object, ...), class = "xml_document"), connection)
}

#' @export
xml_serialize.xml_document <- function(object, connection, ...) {
  x <- as_xml_document(object, "root")
  serialize(structure(as.character(x, ...), class = "xml_node"), connection)
}

#' @export
xml_serialize.xml_nodeset <- function(object, connection, ...) {
  x <- as_xml_document(object, "root")
  serialize(structure(as.character(x, ...), class = "xml_nodeset"), connection)
}

#' @rdname xml_serialize
#' @export
xml_unserialize <- function(connection, ...) {
  object <- unserialize(connection)
  if (inherits(object, "xml_nodeset")) {
    x <- read_xml(unclass(object), ...)
    return(xml_find_all(x, "/*/node()"))
  }
  if (inherits(object, "xml_document")) {
    read_xml(unclass(object), ...)
  }
  if (inherits(object, "xml_node")) {
    read_xml(unclass(object), ...)
  }
}
