#' Modify a tree by inserting, replacing or removing nodes
#'
#' \code{xml_add_sibling()} and \code{xml_add_child()} are used to insert a node
#' as a sibling or a child. \code{xml_add_parent()} adds a new parent in
#' between the input node and the current parent. \code{xml_replace()}
#' replaces an existing node with a new node. \code{xml_remove()} removes a
#' node from the tree.
#'
#' @details Care needs to be taken when using \code{xml_remove()},
#' @param .x a document, node or nodeset.
#' @param .copy whether to copy the \code{.value} before replacing. If this is \code{FALSE}
#'   then the node will be moved from it's current location.
#' @param .where whether to add \code{.value} before or after \code{.x}.
#' @param ... If named attributes or namespaces to set on the node, if unnamed
#' text to assign to the node.
#' @param .value node or nodeset to insert.
#' @param free When removing the node also free the memory used for that node.
#' Note if you use this option you cannot use any existing objects pointing to
#' the node or its children, it is likely to crash R or return garbage.
#' @export
xml_replace <- function(.x, .value, ..., .copy = TRUE) {
  UseMethod("xml_replace")
}

#' @export
xml_replace.xml_node <- function(.x, .value, ..., .copy = TRUE) {

  node <- create_node(.value, .x, ...)

  .x$node <- node_replace(.x$node, node$node, .copy)
  node
}

#' @export
xml_replace.xml_nodeset <- function(.x, .value, ..., .copy = TRUE) {

  if (length(.x) == 0) {
    return(.x)
  }

  # Need to wrap this in a list if a bare xml_node so it is recycled properly
  if (inherits(.value, "xml_node")) {
    .value <- list(.value)
  }

  Map(xml_replace, .x, .value, ..., .copy = .copy)
}

#' @export
xml_replace.xml_missing <- function(.x, .value, ..., .copy = TRUE) {
  .x
}

#' @rdname xml_replace
#' @export
xml_add_sibling <- function(.x, .value, ..., .where = c("after", "before"), .copy = TRUE) {
  UseMethod("xml_add_sibling")
}

#' @export
xml_add_sibling.xml_node <- function(.x, .value, ..., .where = c("after", "before"), .copy = inherits(.value, "xml_node")) {
  .where <- match.arg(.where)

  node <- create_node(.value, .x, ...)

  .x$node <- switch(.where,
    before = node_prepend_sibling(.x$node, node$node, .copy),
    after = node_append_sibling(.x$node, node$node, .copy))

  invisible(.x)
}

#' @export
xml_add_sibling.xml_nodeset <- function(.x, .value, ..., .where = c("after", "before"), .copy = TRUE) {
  if (length(.x) == 0) {
    return(.x)
  }

  .where <- match.arg(.where)

  # Need to wrap this in a list if a bare xml_node so it is recycled properly
  if (inherits(.value, "xml_node")) {
    .value <- list(.value)
  }

  invisible(Map(xml_add_sibling, rev(.x), rev(.value), ..., .where = .where, .copy = .copy))
}

#' @export
xml_add_sibling.xml_missing <- function(.x, .value, ..., .where = c("after", "before"), .copy = TRUE) {
  .x
}

# Helper function used in the xml_add* methods
create_node <- function(.value, parent, ...) {
  if (inherits(.value, "xml_node")) {
    return(.value)
  }

  if (inherits(.value, "xml_cdata")) {
    return(xml_node(node_cdata_new(parent$doc, .value), doc = parent$doc))
  }

  if (inherits(.value, "xml_comment")) {
    return(xml_node(node_comment_new(.value), doc = parent$doc))
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

  invisible(node)
}

#' @export
xml_add_child.xml_document <- function(.x, .value, ..., .copy = inherits(.value, "xml_node")) {
  if (inherits(.x, "xml_node")) {
    NextMethod("xml_add_child")
  } else {
    node <- create_node(.value, .x, ...)
    if (!doc_has_root(.x$doc)) {
      doc_set_root(.x$doc, node$node)
    }
    node_add_child(doc_root(.x$doc), node$node, .copy)
    invisible(xml_document(.x$doc))
  }
}

#' @export
xml_add_child.xml_nodeset <- function(.x, .value, ..., .copy = TRUE) {
  if (length(.x) == 0) {
    return(.x)
  }

  # Need to wrap this in a list if a bare xml_node so it is recycled properly
  if (inherits(.value, "xml_node")) {
    .value <- list(.value)
  }

  res <- Map(xml_add_child, .x, .value, ..., .copy = .copy)
  invisible(make_nodeset(res, res[[1]]$doc))
}

#' @export
xml_add_child.xml_missing <- function(.x, .value, ..., .copy = TRUE) {
  .x
}

#' @rdname xml_replace
#' @export
xml_add_parent <- function(.x, .value, ...) {
  UseMethod("xml_add_parent")
}

#' @export
xml_add_parent.xml_node <- function(.x, .value, ...) {
  new_parent <- xml_replace(.x, .value = .value, ..., .copy = FALSE)
  node <- xml_add_child(new_parent, .value = .x, .copy = FALSE)

  invisible(node)
}

#' @export
xml_add_parent.xml_nodeset <- function(.x, .value, ...) {
  if (length(.x) == 0) {
    return(.x)
  }

  # Need to wrap this in a list if a bare xml_node so it is recycled properly
  if (inherits(.value, "xml_node")) {
    .value <- list(.value)
  }

  res <- Map(xml_add_parent, .x, .value, ...)
  invisible(make_nodeset(res, res[[1]]$doc))
}

#' @export
xml_add_parent.xml_missing <- function(.x, .value, ..., .copy = TRUE) {
  invisible(.x)
}

#' @rdname xml_replace
#' @export
xml_remove <- function(.x, free = FALSE) {
   UseMethod("xml_remove")
}

#' @export
xml_remove.xml_node <- function(.x, free = FALSE) {
  node_remove(.x$node, free = free)
}

#' @export
xml_remove.xml_nodeset <- function(.x, free = FALSE) {
  if (length(.x) == 0) {
    return(.x)
  }

  Map(xml_remove, rev(.x), free = free)
}

#' @export
xml_remove.xml_missing <- function(.x, free = FALSE) {
  .x
}

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
#' @param version The version number of the document.
#' @return A \code{xml_document} object.
#' @export
xml_new_document <- function(version = "1.0") {
  doc <- doc_new(version)
  structure(list(doc = doc), class = "xml_document")
}

#' Strip the default namespaces from a document
#'
#' @inheritParams xml_name
#' @examples
#' x <- read_xml(
#'  "<foo xmlns = 'http://foo.com'>
#'    <baz/>
#'    <bar xmlns = 'http://bar.com'>
#'      <baz/>
#'    </bar>
#'   </foo>")
#' # Need to specify the default namespaces to find the baz nodes
#' xml_find_all(x, "//d1:baz")
#' xml_find_all(x, "//d2:baz")
#'
#' # After stripping the default namespaces you can find both baz nodes directly
#' xml_ns_strip(x)
#' xml_find_all(x, "//baz")
#' @export
xml_ns_strip <- function(x) {

  # //namespace::*[name()=''] finds all the namespace definition nodes with no
  # prefix (default namespaces).
  # What we actually want is the element node the definitions are contained in
  # so return the parent (/parent::*)
  namespace_element_nodes <- xml_find_all(x, "//namespace::*[name()='']/parent::*")
  xml_attr(namespace_element_nodes, "xmlns") <- NULL
  invisible(x)
}
