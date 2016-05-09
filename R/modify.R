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
xml_add_child <- function(x, value, ..., copy = TRUE) {
  UseMethod("xml_add_child")
}

#' @export
xml_add_child.xml_node <- function(x, value, ..., .copy = inherits(value, "xml_node")) {

  args <- list(...)

  named <- has_names(args)
  children <- args[!named]
  if (length(children) > 0 && !all(vapply(children, inherits, logical(1), "xml_node"))) {
    stop("All unnamed arguments must be `xml_node`s", call. = FALSE)
  }

  if (inherits(value, "xml_node")) {
    node <- value
  } else if (is.character(value)) {
    parts <- strsplit(value, ":")[[1]]
    if (length(parts) == 2) {
      # Should we fail if namespace is not found?
      namespace <- ns_lookup(x$doc, x$node, parts[[1]])
      node <- structure(list(node = node_new_ns(parts[[2]], namespace), doc = x$doc), class = "xml_node")
    } else {
      node <- structure(list(node = node_new(value), doc = x$doc), class = "xml_node")
    }
  }
  node_add_child(x$node, node$node, .copy)

  xml_attrs(node) <- args[named]

  x #return self or child?
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

#' Create a new namespace and assign it to a node
#'
#' @param x a node
#' @param namespaces A named character vector of prefixes and URIs for the
#' namespaces. If one element is unnamed it is used as the default namespace.
#' @return the node (invisibly)
#' @export
#' @examples
#' d <- xml_new_document(xml_new_node("sld", version = "1.1.0", xml_new_node("layer", xml_new_node("Name"))))
#' sld <- xml_find_one(d, "//sld")
#' name <- xml_find_one(d, "//Name")
#' xml_new_namespace(sld, c("http://www.o.net/sld", ogc = "http://www.o.net/ogc", se = "http://www.o.net/se"))
#' xml_set_namespace(name, "se")
xml_new_namespace <- function(x, ...) {
  stopifnot(inherits(x, "xml_node"))

  namespaces <- list(...)

  named <- has_names(namespaces)

  if (sum(!named) > 1) {
    stop("`namespaces` can only contain one unnamed namespace", call. = FALSE)
  }
  names(namespaces)[!named] <- ""

  Map(node_new_namespace, list(x$node), namespaces, names(namespaces))

  invisible(x)
}

#' Set the node's namespace
#'
#' The namespace to be set must be defined in one of the node's ancestors.
#' @param a node
#' @param prefix The namespace prefix to use
#' @param uri The namespace URI to use
#' @return the node (invisibly)
#' @export
xml_set_namespace <- function(x, prefix = "", uri = "") {
  stopifnot(inherits(x, "xml_node"))

  if (nzchar(uri)) {
    node_set_namespace_uri(x$doc, x$node, uri)
  } else {
    node_set_namespace_prefix(x$doc, x$node, prefix)
  }
  invisible(x)
}

#' Create a new node
#'
#' @param .name name of the node.
#' @param ... Either named attributes or child nodes to add to the new node.
#' @return A \code{xml_node} object.
#' @export
xml_new_node <- function(.name, ...) {

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
#'
#' @param node The root node of the document.
#' @param version The version number of the document.
#' @return A \code{xml_document} object.
#' @export
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

# 1. Create a new namespace(s) at the current node
# 2. Assign the node to an existing namespace (assume all namespaces are at the root node?)
