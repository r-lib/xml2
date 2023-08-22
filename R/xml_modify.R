#' Modify a tree by inserting, replacing or removing nodes
#'
#' `xml_add_sibling()` and `xml_add_child()` are used to insert a node
#' as a sibling or a child. `xml_add_parent()` adds a new parent in
#' between the input node and the current parent. `xml_replace()`
#' replaces an existing node with a new node. `xml_remove()` removes a
#' node from the tree.
#'
#' @details Care needs to be taken when using `xml_remove()`,
#' @param .x a document, node or nodeset.
#' @param .copy whether to copy the `.value` before replacing. If this is `FALSE`
#'   then the node will be moved from it's current location.
#' @param .where to add the new node, for `xml_add_child` the position
#' after which to add, use `0` for the first child. For
#' `xml_add_sibling` either \sQuote{"before"} or \sQuote{"after"}
#' indicating if the new node should be before or after `.x`.
#' @param ... If named attributes or namespaces to set on the node, if unnamed
#' text to assign to the node.
#' @param .value node to insert.
#' @param free When removing the node also free the memory used for that node.
#' Note if you use this option you cannot use any existing objects pointing to
#' the node or its children, it is likely to crash R or return garbage.
#' @export
xml_replace <- function(.x, .value, ..., .copy = TRUE) {
  UseMethod("xml_replace")
}

#' @export
xml_replace.xml_node <- function(.x, .value, ..., .copy = TRUE) {
  node <- create_node(.value, .parent = .x, .copy = .copy, ...)

  .x$node <- .Call(node_replace, .x$node, node$node)
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

  node <- create_node(.value, .parent = .x, .copy = .copy, ...)

  .x$node <- switch(.where,
    before = .Call(node_prepend_sibling, .x$node, node$node),
    after = .Call(node_append_sibling, .x$node, node$node)
  )

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
create_node <- function(.value, ..., .parent, .copy) {
  if (inherits(.value, "xml_node")) {
    if (isTRUE(.copy)) {
      .value$node <- .Call(node_copy, .value$node)
    }
    return(.value)
  }

  if (inherits(.value, "xml_cdata")) {
    return(xml_node(.Call(node_cdata_new, .parent$doc, .value), doc = .parent$doc))
  }

  if (inherits(.value, "xml_comment")) {
    return(xml_node(.Call(node_comment_new, .value), doc = .parent$doc))
  }

  if (inherits(.value, "xml_dtd")) {
    .Call(node_new_dtd, .parent$doc, .value$name, .value$external_id, .value$system_id)
    return()
  }

  check_character(.value)

  parts <- strsplit(.value, ":")[[1]]
  if (length(parts) == 2 && !is.null(.parent$node)) {
    namespace <- .Call(ns_lookup, .parent$doc, .parent$node, parts[[1]])
    node <- list(node = .Call(node_new_ns, parts[[2]], namespace), doc = .parent$doc)
  } else {
    node <- list(node = .Call(node_new, .value), doc = .parent$doc)
  }
  class(node) <- "xml_node"

  args <- list(...)
  named <- has_names(args)
  xml_attrs(node) <- args[named]
  xml_text(node) <- paste(args[!named], collapse = "")

  node
}

#' @rdname xml_replace
#' @export
xml_add_child <- function(.x, .value, ..., .where = length(xml_children(.x)), .copy = TRUE) {
  UseMethod("xml_add_child")
}

#' @export
xml_add_child.xml_node <- function(.x, .value, ..., .where = length(xml_children(.x)), .copy = inherits(.value, "xml_node")) {
  node <- create_node(.value, .parent = .x, .copy = .copy, ...)

  if (.where == 0L) {
    if (.Call(node_has_children, .x$node, TRUE)) {
      .Call(node_prepend_child, .x$node, node$node)
    } else {
      .Call(node_append_child, .x$node, node$node)
    }
  } else {
    num_children <- length(xml_children(.x))
    if (.where >= num_children) {
      .Call(node_append_child, .x$node, node$node)
    } else {
      .Call(node_append_sibling, xml_child(.x, search = .where)$node, node$node)
    }
  }

  invisible(node)
}

#' @export
xml_add_child.xml_document <- function(.x, .value, ..., .where = length(xml_children(.x)), .copy = inherits(.value, "xml_node")) {
  if (inherits(.x, "xml_node")) {
    NextMethod("xml_add_child")
  } else {
    node <- create_node(.value, .parent = .x, .copy = .copy, ...)
    if (!is.null(node)) {
      if (!.Call(doc_has_root, .x$doc)) {
        .Call(doc_set_root, .x$doc, node$node)
      }
      .Call(node_append_child, .Call(doc_root, .x$doc), node$node)
    }
    invisible(xml_document(.x$doc))
  }
}

#' @export
xml_add_child.xml_nodeset <- function(.x, .value, ..., .where = length(xml_children(.x)), .copy = TRUE) {
  if (length(.x) == 0) {
    return(.x)
  }

  # Need to wrap this in a list if a bare xml_node so it is recycled properly
  if (inherits(.value, "xml_node")) {
    .value <- list(.value)
  }

  res <- Map(xml_add_child, .x, .value, ..., .where = .where, .copy = .copy)
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
  .Call(node_remove, .x$node, free)

  invisible(.x)
}

#' @export
xml_remove.xml_nodeset <- function(.x, free = FALSE) {
  if (length(.x) == 0) {
    return(invisible(.x))
  }

  invisible(Map(xml_remove, rev(.x), free = free))
}

#' @export
xml_remove.xml_missing <- function(.x, free = FALSE) {
  invisible(.x)
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
    .Call(node_set_namespace_uri, .x$doc, .x$node, uri)
  } else {
    .Call(node_set_namespace_prefix, .x$doc, .x$node, prefix)
  }
  invisible(.x)
}

#' Create a new document, possibly with a root node
#'
#' `xml_new_document` creates only a new document without a root node. In
#' most cases you should instead use `xml_new_root`, which creates a new
#' document and assigns the root node in one step.
#' @param version The version number of the document.
#' @param encoding The character encoding to use in the document. The default
#' encoding is \sQuote{UTF-8}. Available encodings are specified at
#' <http://xmlsoft.org/html/libxml-encoding.html#xmlCharEncoding>.
#' @return A `xml_document` object.
#' @export
# TODO: jimhester 2016-12-16 Deprecate this in the future?
xml_new_document <- function(version = "1.0", encoding = "UTF-8") {
  doc <- .Call(doc_new, version, encoding)
  out <- list(doc = doc)
  class(out) <- "xml_document"
  out
}

#' @param .version The version number of the document, passed to `xml_new_document(version)`.
#' @param .encoding The encoding of the document, passed to `xml_new_document(encoding)`.
#' @inheritParams xml_add_child
#' @rdname xml_new_document
#' @export
xml_new_root <- function(.value, ..., .copy = inherits(.value, "xml_node"), .version = "1.0", .encoding = "UTF-8") {
  xml_add_child(xml_new_document(version = .version, encoding = .encoding), .value = .value, ... = ..., .copy = .copy)
}

#' Strip the default namespaces from a document
#'
#' @inheritParams xml_name
#' @examples
#' x <- read_xml(
#'   "<foo xmlns = 'http://foo.com'>
#'    <baz/>
#'    <bar xmlns = 'http://bar.com'>
#'      <baz/>
#'    </bar>
#'   </foo>"
#' )
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
