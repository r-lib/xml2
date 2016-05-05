#' Modify a tree by inserting, replacing or removing nodes
#'
#' \code{xml_add_sbling()} and \code{xml_add_child()} are used to insert a node
#' as a sibling or a child. \code{xml_replace()} replaces an existing node with
#' a new node. \code{xml_remove()} removes a node from the tree, but does not
#' free it's memory.
#'
#' @param x a document, node or nodeset.
#' @param copy whether to copy the \code{value} before replacing. If this is \code{FALSE}
#'   then the node will be moved from it's current location.
#' @param where whether to add \code{value} before or after \code{x}.
#' @param value node or nodeset to insert.
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

#' @rdname xml_replace
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

#' @rdname xml_replace
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

#' @rdname xml_replace
#' @export
xml_remove_node <- function(x) {
   UseMethod("xml_remove_node")
}

#' @export
xml_remove_node.xml_node <- function(x) {
  node_remove(x$node)
}

#' @export
xml_remove_node.xml_nodeset <- function(x) {
  Map(xml_remove_node, rev(x))
}

## Questions
# - Assignment methods for xml_missing objects? Error, warning or identity

# xml_new_node("nodename", child1, child2, attr1 = "foo", attr3 = "bar")

#' Create a new node
#' @param .name name of the node.
#' @param ... Either named attributes or child nodes to add to the new node.
#' @return A \code{xml_node} object.
xml_new_node <- function(.name, ..., .ns = character()) {

  args <- list(...)

  named <- has_names(args)
  children <- args[!named]
  if (length(children) > 0 && !all(vapply(children, inherits, logical(1), "xml_node"))) {
    stop("All unnamed arguments must be `xml_node`s", call. = FALSE)
  }

  node <- structure(list(node = node_new(.name), doc = node_null()), class = "xml_node")

  attrs <- args[named]
  xml_attrs(node) <- attrs

  lapply(children, xml_add_child, x = node)

  node
}

#' Create a new document
#' @param node The root node of the document.
#' @param version The version number of the document.
xml_new_document <- function(node, version = "1.0") {
  doc <- doc_new(version)
  doc_set_root(doc, node$node)
  xml_document(doc)
}

# Namespaces
# - xmlNewNode() needs a xmlNsPtr to assign a namespace
# - These need the node to already be inserted into the document
  # - xmlSearchNsByHref() searches _parents_ of a node for a namespace (by URI).
  # - xmlSearchNs() searches _parents_ of a node for a namespace (by prefix).
# xml_ns() collects _all_ namespaces from a document together
  # - What happens if we try to use a namespace that is not a parent?
# xml_name() returns prefix:name if given ns, should we do allow assigning a prefix in the same fashion, e.g. xml_name(x, ns) <- "prefix:node"

#<?xml version = "1.0" encoding="UTF-8"?>
#<sld xmlns="http://www.o.net/sld" 
     #xmlns:ogc="http://www.o.net/ogc" 
     #xmlns:se="http://www.o.net/se"
     #version="1.1.0" >
#<layer>
#<se:Name>My Layer</se:Name>
#</layer>
#</sld>
