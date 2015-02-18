#' Retrieve an attribute.
#'
#' Use \code{xml_attr} to retrieve attribute values. If the attribute doesn't
#' exist, it will be return as an \code{NA}. Use \code{xml_attr_exists} to
#' test if an attribute is present.
#'
#' @inheritParams xml_name
#' @param attr Name of attribute to extract.
#' @return For \code{xml_attr}, a character vector. If an attribute is not
#'  presented, its value will be missing. For \code{xml_attr_exists},
#'  a logical vector.
#' @export
#' @examples
#' x <- xml("<root id='1'><child id ='a' /><child id='b' d='b'/></root>")
#' xml_attr(x, "id")
#'
#' xml_attr(xml_children(x), "id")
#' xml_attr_exists(xml_children(x), "id")
#'
#' # Missing attributes give missing values
#' xml_attr(xml_children(x), "d")
#' xml_attr_exists(xml_children(x), "d")
xml_attr <- function(x, attr, ...) {
  UseMethod("xml_attr")
}

#' @export
xml_attr.xml_node <- function(x, attr, ...) {
  node_attr(x$node, attr)
}

#' @export
xml_attr.xml_doc <- function(x, attr, ...) {
  node_attr(doc_root(x$doc), attr)
}

#' @export
xml_attr.xml_nodeset <- function(x, attr, ...) {
  vapply(x, xml_attr, attr = attr, ..., FUN.VALUE = character(1))
}


#' @export
#' @rdname xml_attr
xml_attr_exists <- function(x, attr, ...) {
  UseMethod("xml_attr_exists")
}

#' @export
xml_attr_exists.xml_node <- function(x, attr, ...) {
  node_attr_exists(x$node, attr)
}

#' @export
xml_attr_exists.xml_doc <- function(x, attr, ...) {
  node_attr_exists(doc_root(x$doc), attr)
}

#' @export
xml_attr_exists.xml_nodeset <- function(x, attr, ...) {
  vapply(x, xml_attr_exists, attr = attr, ..., FUN.VALUE = logical(1))
}
