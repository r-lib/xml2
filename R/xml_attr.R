#' Retrieve an attribute.
#'
#' @inheritParams xml_name
#' @param attr Name of attribute to extract.
#' @return A character vector. If an attribute is not presented, its
#'  value will be missing.
#' @export
#' @examples
#' x <- xml("<root id='1'><child id ='a' /><child id='b' d='b'/></root>")
#' xml_attr(x, "id")
#' xml_attr(xml_children(x), "id")
#' xml_attr(xml_children(x), "d")
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
