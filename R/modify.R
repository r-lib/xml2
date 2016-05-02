#' Replace a node with another node
#'
#' @param x a document, node or nodeset.
#' @param copy whether to copy the \code{value} before replacing. If this is \code{FALSE}
#'   then the node will be moved from it's current location.
#' @param value node or nodeset to replace with.
#' @export
xml_replace <- function(x, value, copy = TRUE) {
  UseMethod("xml_replace")
}

#' @export
xml_replace.xml_node <- function(x, value, copy = TRUE) {
  x$node <- node_replace(x$node, value$node, copy)
  x
}

#' @export
xml_replace.xml_nodeset <- function(x, value, copy = TRUE) {

  # Need to wrap this in a list if a bare xml_node so it is recycled properly
  if (inherits(value, "xml_node")) {
    value <- list(value)
  }

  Map(xml_replace, x, value, copy)
}

#' Append a sibling onto another node
#'
#' @param x a document, node or nodeset.
#' @param copy whether to copy the \code{value} before replacing. If this is \code{FALSE}
#'   then the node will be moved from it's current location.
#' @param value node or nodeset to replace with.
#' @param where whether to add \code{value} before or after \code{x}.
#' @return the added element
#' @export
xml_add_sibling <- function(x, value, where = c("after", "before"), copy = TRUE) {
  UseMethod("xml_add_sibling")
}

#' @export
xml_add_sibling.xml_node <- function(x, value, where = c("after", "before"), copy = TRUE) {
  where <- match.arg(where)

  x$node <- switch(where,
    before = node_prepend_sibling(x$node, value$node, copy),
    after = node_append_sibling(x$node, value$node, copy))

  x
}

#' @export
xml_add_sibling.xml_nodeset <- function(x, value, where = c("after", "before"), copy = TRUE) {
  where <- match.arg(where)

  # Need to wrap this in a list if a bare xml_node so it is recycled properly
  if (inherits(value, "xml_node")) {
    value <- list(value)
  }

  Map(xml_add_sibling, rev(x), rev(value), where, copy)
}

#' Add a child node
#'
#' @param x a document, node or nodeset.
#' @param value node or nodeset.
#' @param copy whether to copy the \code{value} before replacing. If this is \code{FALSE}
#'   then the node will be moved from it's current location.
#' @return the added element
#' @export
xml_add_child <- function(x, value, copy = TRUE) {
  UseMethod("xml_add_child")
}

#' @export
xml_add_child.xml_node <- function(x, value, copy = TRUE) {
  node_add_child(x$node, value$node, copy)

  x
}

#' @export
xml_add_child.xml_nodeset <- function(x, value, copy = TRUE) {

  # Need to wrap this in a list if a bare xml_node so it is recycled properly
  if (inherits(value, "xml_node")) {
    value <- list(value)
  }

  Map(xml_add_child, x, value, copy)
}

#' @export
xml_remove_node <- function(x) {
   UseMethod("xml_remove_node")
}

#' @export
xml_remove_node.xml_node <- function(x) {
  node_remove(x$node)
}

## Questions
# - Assignment methods for xml_missing objects? Error, warning or identity
