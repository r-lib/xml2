#' Navigate around the family tree.
#'
#' @inheritParams xml_name
#' @return A node or nodeset (possibly empty).
#' @export
#' @examples
#' x <- xml("<foo> <bar><boo /></bar> 123 <baz/> </foo>")
#' (kids <- xml_children(x))
#' (grand_kids <- xml_children(kids))
#'
#' xml_parent(kids)
xml_children <- function(x, ...) {
  UseMethod("xml_children")
}

#' @export
xml_children.xml_nodeset <- function(x, ...) {
  nodeset_apply(x, node_children)
}

#' @export
#' @rdname xml_children
xml_parent <- function(x, ...) {
  UseMethod("xml_parent")
}

#' @export
xml_parent.xml_nodeset <- function(x, ...) {
  nodeset_apply(x, node_parent)
}
