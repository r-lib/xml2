#' Coerce a R list to xml nodes.
#'
#' This turns an R list into the equivalent XML document. Not all R lists will
#' produce valid XML, in particular there can only be one root node and all
#' child nodes need to be named (or empty) lists.
#'
#' @inheritParams as_list
#' @include as_list.R xml_parse.R
#' @export
#' @examples
# empty lists generate empty nodes
#'as_xml(list(x = list()))
#'
#'# Nesting multiple nodes
#'as_xml(list(foo = list(bar = list(baz = list()))))
#'
#'# attributes are stored as R attributes
#'as_xml(list(foo = structure(list(), id = "a")))
#'as_xml(list(foo = list(
#'      bar = structure(list(), id = "a"),
#'      bar = structure(list(), id = "b"))))
as_xml <- function(x, ...) {
  UseMethod("as_xml")
}

#' @export
as_xml.character <- read_xml.character

#' @export
as_xml.raw <- read_xml.raw

#' @export
as_xml.connection <- read_xml.connection

#' @export
as_xml.response <- read_xml.response

#' @export
as_xml.list <- function(x, ..., missing = "elem") {
  if (length(x) > 1) {
    stop("Root nodes must be of length 1", call. = FALSE)
  }


  add_node <- function(x, parent, tag = NULL) {
    if (is.atomic(x)) {
      return(xml_set_text(parent, as.character(x)))
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
