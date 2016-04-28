## Questions
# 1. Assignment methods for xml_missing objects? Error, warning or identity

#' @export
`xml_attr<-` <- function(x, ...) UseMethod("xml_attr<-")

#' @export
`xml_attr<-.xml_node` <- function(x, attr, ns = character(), value) {
  if (is.null(value)) {
    node_remove_attr(x$node, name = attr, nsMap = ns)
  } else {
    node_set_attr(x$node, name = attr, nsMap = ns, value)
  }
  x
}

#' @export
`xml_attr<-.xml_nodeset` <- function(x, attr, ns = character(), value) {
  lapply(x, `xml_attr<-`, attr = attr, ns = ns, value = value)
  x
}

#' @export
`xml_attrs<-` <- function(x, ...) UseMethod("xml_attrs<-")

#' @export
`xml_attrs<-.xml_node` <- function(x, ns = character(), value) {
  if (!is_named_or_null(value)) {
    stop("`value` must be a named character vector or `NULL`", call. = FALSE)
  }

  attrs <- names(value)

  current_attrs <- names(xml_attrs(x, ns = ns))

  existing <- intersect(current_attrs, attrs)
  new <- setdiff(attrs, current_attrs)
  removed <- setdiff(current_attrs, attrs)

  Map(function(attr, val) {
      xml_attr(x, attr, ns) <- val
  }, attr = c(existing, new), value[c(existing, new)])


  Map(function(attr) {
    xml_attr(x, attr, ns) <- NULL
  }, attr = removed)

  x
}

#' @export
`xml_attrs<-.xml_nodeset` <- function(x, ns = character(), value) {
  if (!is.list(value)) {
     value <- list(value)
  }
  if (!all(vapply(value, is_named_or_null, logical(1)))) {
    stop("`value` must be a list of named character vectors")
  }

  for (i in seq_along(x)) {

    # recycle value if necessary
    xml_attrs(x[[i]], ns) <- value[[((i - 1) %% length(value)) + 1]]
  }

  x
}

#' Replace a node with another node
#'
#' @param x a document, node or nodeset.
#' @param copy whether to copy the \code{value} before replacing. If this is \code{FALSE}
#'   then the node will be moved from it's current location.
#' @param value node or nodeset to replace with.
#' @export
`xml_replace<-` <- function(x, copy = TRUE, value) UseMethod("xml_replace<-")

#' @export
`xml_replace<-.xml_node` <- function(x, copy = TRUE, value) {
  x$node <- node_replace(x$node, value$node, copy)
  x
}

#' @export
`xml_replace<-.xml_nodeset` <- function(x, copy = TRUE, value) {
  Map(`xml_replace<-`, x, copy, value)
}

#' Append a sibling onto another node
#'
#' @param x a document, node or nodeset.
#' @param copy whether to copy the \code{value} before replacing. If this is \code{FALSE}
#'   then the node will be moved from it's current location.
#' @param value node or nodeset to replace with.
#' @return the added element
#' @export
xml_add_sibling <- function(x, value, where = c("after", "before"), copy = TRUE) UseMethod("xml_add_sibling")

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

  Map(`xml_add_sibling<-`, x, value, where, copy)
}

#' Add a child node
#'
#' @param x a document, node or nodeset.
#' @param value node or nodeset.
#' @param copy whether to copy the \code{value} before replacing. If this is \code{FALSE}
#'   then the node will be moved from it's current location.
#' @return the added element
#' @export
xml_add_child <- function(x, value, copy = TRUE) UseMethod("xml_add_child")

#' @export
xml_add_child <- function(x, value, copy = TRUE) {
  node_add_child(x$node, value$node, copy)

  x
}

#' @export
xml_add_child.xml_nodeset <- function(x, value, copy = TRUE) {
  Map(`xml_add_child<-`, x, value, where, copy)
}
