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
    cli::cli_abort("Root nodes must be of length 1.")
  }
  if (length(x[[1]]) == 1 && is.vector(x[[1]])) {
    x[[1]] <- list(x[[1]])
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
      # Handle for duplicate-named elements
      item <- x[[i]]
      item_name <- names(x)[i]

      if (is_contain_duplicated(item)) {
        for (j in seq_along(item)) {
          sub_item <- item[[j]]
          new_node <- xml_add_child(parent, item_name)

          if (is.character(sub_item) && length(sub_item) == 1) {
            xml_text(new_node) <- sub_item
          } else if (is.list(sub_item)) {
            attr <- r_attrs_to_xml(attributes(sub_item))
            for (k in seq_along(attr)) {
              xml_set_attr(new_node, names(attr)[[k]], attr[[k]])
            }

            for (k in seq_along(sub_item)) {
              add_node(sub_item[[k]], new_node, names(sub_item)[k])
            }
          }
        }
      } else {
        add_node(item, parent, names(x)[[i]])
      }
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

is_contain_duplicated <- function(lst) {
  if (is.null(names(lst)) || all(names(lst) == "")) {
    if (length(lst) > 1 && all(sapply(lst, function(x) is.list(x) || is.character(x)))) {
      return(TRUE)
    }
  }
  return(FALSE)
}
