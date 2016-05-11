#' Modify a tree by inserting, replacing or removing nodes
#'
#' \code{xml_add_sbling()} and \code{xml_add_child()} are used to insert a node
#' as a sibling or a child. \code{xml_replace()} replaces an existing node with
#' a new node. \code{xml_remove()} removes a node from the tree, but does not
#' free it's memory.
#'
#' @param .x a document, node or nodeset.
#' @param .copy whether to copy the \code{.value} before replacing. If this is \code{FALSE}
#'   then the node will be moved from it's current location.
#' @param .where whether to add \code{.value} before or after \code{.x}.
#' @param ... If named attributes or namespaces to set on the node, if unnamed
#' text to assign to the node.
#' @param .value node or nodeset to insert.
#' @export
xml_replace <- function(.x, .value, ..., .copy = TRUE) {
  UseMethod("xml_replace")
}

#' @export
xml_replace.xml_node <- function(.x, .value, ..., .copy = TRUE) {

  node <- create_node(.value, .x, ...)

  .x$node <- node_replace(.x$node, node$node, .copy)
  .x
}

#' @export
xml_replace.xml_nodeset <- function(.x, .value, ..., .copy = TRUE) {

  # Need to wrap this in a list if a bare xml_node so it is recycled properly
  if (inherits(.value, "xml_node")) {
    .value <- list(.value)
  }

  Map(xml_replace, .x, .value, ..., .copy = .copy)
}

#' @rdname xml_replace
#' @export
xml_add_sibling <- function(.x, .value, ..., .where = c("after", "before"), .copy = TRUE) {
  UseMethod("xml_add_sibling")
}

#' @export
xml_add_sibling.xml_node <- function(.x, .value, ..., .where = c("after", "before"), .copy = TRUE) {
  .where <- match.arg(.where)

  node <- create_node(.value, .x, ...)

  .x$node <- switch(.where,
    before = node_prepend_sibling(.x$node, node$node, .copy),
    after = node_append_sibling(.x$node, node$node, .copy))

  .x
}

#' @export
xml_add_sibling.xml_nodeset <- function(.x, .value, ..., .where = c("after", "before"), .copy = TRUE) {
  .where <- match.arg(.where)

  # Need to wrap this in a list if a bare xml_node so it is recycled properly
  if (inherits(.value, "xml_node")) {
    .value <- list(.value)
  }

  Map(xml_add_sibling, rev(.x), rev(.value), ..., .where = .where, .copy = .copy)
}

# Helper function used in the xml_add* methods
create_node <- function(.value, parent, ...) {
  if (inherits(.value, "xml_node")) {
    return(.value)
  }

  if (!is.character(.value)) {
    stop("`.value` must be a character", call. = FALSE)
  }

  parts <- strsplit(.value, ":")[[1]]
  if (length(parts) == 2) {
    namespace <- ns_lookup(parent$doc, parent$node, parts[[1]])
    node <- structure(list(node = node_new_ns(parts[[2]], namespace), doc = parent$doc), class = "xml_node")
  } else {
    node <- structure(list(node = node_new(.value), doc = parent$doc), class = "xml_node")
  }

  args <- list(...)
  named <- has_names(args)
  xml_attrs(node) <- args[named]
  xml_text(node) <- paste(args[!named], collapse = "")

  node
}

#' @rdname xml_replace
#' @export
xml_add_child <- function(.x, .value, ..., .copy = TRUE) {
  UseMethod("xml_add_child")
}

#' @export
xml_add_child.xml_node <- function(.x, .value, ..., .copy = inherits(.value, "xml_node")) {

  node <- create_node(.value, .x, ...)
  node_add_child(.x$node, node$node, .copy)

  node
}

#' @export
xml_add_child.xml_document <- function(.x, .value, ...) {
  if (is.null(.x$node)) {
    node <- create_node(.value, .x, ...)
    doc_set_root(.x$doc, node$node)

    xml_document(.x$doc)
  } else {
    NextMethod("xml_add_child")
  }
}

#' @export
xml_add_child.xml_nodeset <- function(.x, .value, ..., .copy = TRUE) {

  # Need to wrap this in a list if a bare xml_node so it is recycled properly
  if (inherits(.value, "xml_node")) {
    .value <- list(.value)
  }

  Map(xml_add_child, .x, .value, ..., .copy = .copy)
}

#' @rdname xml_replace
#' @export
xml_remove_node <- function(.x) {
   UseMethod("xml_remove_node")
}

#' @export
xml_remove_node.xml_node <- function(.x) {
  node_remove(.x$node)
}

#' @export
xml_remove_node.xml_nodeset <- function(.x) {
  Map(xml_remove_node, rev(.x))
}

## Questions
# - Assignment methods for xml_missing objects? Error, warning or identity

#' Set the node's namespace
#'
#' The namespace to be set must be already defined in one of the node's
#' ancestors.
#' @param .x a node
#' @param prefix The namespace prefix to use
#' @param uri The namespace URI to use
#' @return the node (invisibly)
#' @export
xml_set_namespace <- function(.x, prefix = "", uri = "") {
  stopifnot(inherits(.x, "xml_node"))

  if (nzchar(uri)) {
    node_set_namespace_uri(.x$doc, .x$node, uri)
  } else {
    node_set_namespace_prefix(.x$doc, .x$node, prefix)
  }
  invisible(.x)
}

#' Create a new document
#'
#' @param node The root node of the document.
#' @param version The version number of the document.
#' @return A \code{xml_document} object.
#' @export
xml_new_document <- function(node, version = "1.0") {
  doc <- doc_new(version)
  structure(list(doc = doc), class = "xml_document")
}
