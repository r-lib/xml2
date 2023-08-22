#' Coerce a R list to xml nodes.
#'
#' This turns an R list into the equivalent XML document. Not all R lists will
#' produce valid XML, in particular there can only be one root node and all
#' child nodes need to be named (or empty) lists. R attributes become XML
#' attributes and R names become XML node names.
#'
#' @inheritParams as_list
#' @include as_list.R xml_parse.R
#' @export
#' @examples
# empty lists generate empty nodes
#' as_xml_document(list(x = list()))
#'
#' # Nesting multiple nodes
#' as_xml_document(list(foo = list(bar = list(baz = list()))))
#'
#' # attributes are stored as R attributes
#' as_xml_document(list(foo = structure(list(), id = "a")))
#' as_xml_document(list(foo = list(
#'   bar = structure(list(), id = "a"),
#'   bar = structure(list(), id = "b")
#' )))
as_xml_document <- function(x, ...) {
  UseMethod("as_xml_document")
}

#' @export
as_xml_document.character <- read_xml.character

#' @export
as_xml_document.raw <- read_xml.raw

#' @export
as_xml_document.connection <- read_xml.connection

#' @export
as_xml_document.response <- read_xml.response

#' @export
as_xml_document.list <- function(x, ...) {
  if (length(x) > 1) {
    abort("Root nodes must be of length 1")
  }


  add_node <- function(x, parent, tag = NULL) {
    if (is.atomic(x)) {
      return(.Call(node_new_text, parent$node, as.character(x)))
    }
    if (!is.null(tag)) {
      parent <- xml_add_child(parent, tag)
      attr <- r_attrs_to_xml(attributes(x))
      for (i in seq_along(attr)) {
        xml_set_attr(parent, names(attr)[[i]], attr[[i]])
      }
    }
    for (i in seq_along(x)) {
      add_node(x[[i]], parent, names(x)[[i]])
    }
  }

  doc <- xml_new_document()
  add_node(x, doc)
  xml_root(doc)
}

#' @export
as_xml_document.xml_node <- function(x, ...) {
  xml_new_root(.value = x, ..., .copy = TRUE)
}

#' @export
as_xml_document.xml_nodeset <- function(x, root, ...) {
  doc <- xml_new_root(.value = root, ..., .copy = TRUE)
  for (i in seq_along(x)) {
    xml_add_child(doc, x[[i]], .copy = TRUE)
  }
  doc
}

#' @export
as_xml_document.xml_document <- function(x, ...) {
  x
}
