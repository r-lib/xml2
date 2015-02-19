#' Retrieve an attribute.
#'
#' Use \code{xml_attrs} to retrieve all attributes values as a character vector.
#' Use \code{xml_attr} to retrieve the value of single attribute. If the
#' attribute doesn't exist, it will be returned as an \code{NA}.
#' Use \code{xml_attr_exists} to test if an attribute is present.
#'
#' @inheritParams xml_name
#' @param attr Name of attribute to extract.
#' @return For \code{xml_attr}, a character vector. If an attribute is not
#'  presented, its value will be missing. For \code{xml_attr_exists},
#'  a logical vector. For \code{xml_attr} a list of named character vectors.
#'  If any attrbutes have an associated namespace, the vector will have
#'  a \code{ns} attribute.
#' @export
#' @examples
#' x <- xml("<root id='1'><child id ='a' /><child id='b' d='b'/></root>")
#' xml_attr(x, "id")
#' xml_attrs(x)
#'
#' xml_attr(xml_children(x), "id")
#' xml_attr_exists(xml_children(x), "id")
#' xml_attrs(xml_children(x))
#'
#' # Missing attributes give missing values
#' xml_attr(xml_children(x), "d")
#' xml_attr_exists(xml_children(x), "d")
xml_attr <- function(x, attr, ...) {
  UseMethod("xml_attr")
}

#' @export
xml_attr.xml_nodeset <- function(x, attr, ...) {
  vapply(x$nodes, node_attr, name = attr, FUN.VALUE = character(1))
}


#' @export
#' @rdname xml_attr
xml_attr_exists <- function(x, attr, ...) {
  UseMethod("xml_attr_exists")
}

#' @export
xml_attr_exists.xml_nodeset <- function(x, attr, ...) {
  vapply(x$nodes, node_attr_exists, name = attr, FUN.VALUE = logical(1))
}

#' @export
#' @rdname xml_attr
xml_attrs <- function(x, ns = character()) {
  lapply(x$nodes, node_attrs, ns = ns)
}
