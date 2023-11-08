#' Navigate around the family tree.
#'
#' `xml_children` returns only elements, `xml_contents` returns
#' all nodes. `xml_length` returns the number of children.
#' `xml_parent` returns the parent node, `xml_parents`
#' returns all parents up to the root. `xml_siblings` returns all nodes
#' at the same level. `xml_child` makes it easy to specify a specific
#' child to return.
#'
#' @inheritParams xml_name
#' @param only_elements For `xml_length`, should it count all children,
#'   or just children that are elements (the default)?
#' @param search For `xml_child`, either the child number to return (by
#'   position), or the name of the child node to return. If there are multiple
#'   child nodes with the same name, the first will be returned
#' @return A node or nodeset (possibly empty). Results are always de-duplicated.
#' @export
#' @examples
#' x <- read_xml("<foo> <bar><boo /></bar> <baz/> </foo>")
#' xml_children(x)
#' xml_children(xml_children(x))
#' xml_siblings(xml_children(x)[[1]])
#'
#' # Note the each unique node only appears once in the output
#' xml_parent(xml_children(x))
#'
#' # Mixed content
#' x <- read_xml("<foo> a <b/> c <d>e</d> f</foo>")
#' # Childen gets the elements, contents gets all node types
#' xml_children(x)
#' xml_contents(x)
#'
#' xml_length(x)
#' xml_length(x, only_elements = FALSE)
#'
#' # xml_child makes it easier to select specific children
#' xml_child(x)
#' xml_child(x, 2)
#' xml_child(x, "baz")
xml_children <- function(x) {
  nodeset_apply(x, function(x) .Call(node_children, x, TRUE))
}

#' @export
#' @rdname xml_children
xml_child <- function(x, search = 1, ns = xml_ns(x)) {
  if (length(search) != 1) {
    cli::cli_abort("{.arg {search}} must be of length 1.")
  }

  if (is.numeric(search)) {
    xml_children(x)[[search]]
  } else if (is.character(search)) {
    xml_find_first(x, xpath = paste0("./", search), ns = ns)
  } else {
    cli::cli_abort("{.arg search} must be `numeric` or `character`.")
  }
}

#' @export
#' @rdname xml_children
xml_contents <- function(x) {
  nodeset_apply(x, function(x) .Call(node_children, x, FALSE))
}

#' @export
#' @rdname xml_children
xml_parents <- function(x) {
  nodeset_apply(x, function(x) .Call(node_parents, x))
}

#' @export
#' @rdname xml_children
xml_siblings <- function(x) {
  nodeset_apply(x, function(x) .Call(node_siblings, x, TRUE))
}

#' @export
#' @rdname xml_children
xml_parent <- function(x) {
  UseMethod("xml_parent")
}

#' @export
xml_parent.xml_missing <- function(x) {
  xml_missing()
}

#' @export
xml_parent.xml_node <- function(x) {
  xml_node(.Call(node_parent, x$node), x$doc)
}

#' @export
xml_parent.xml_nodeset <- function(x) {
  nodeset_apply(x, function(x) .Call(node_parent, x))
}


#' @export
#' @rdname xml_children
xml_length <- function(x, only_elements = TRUE) {
  .Call(node_length, x, only_elements)
}

#' @export
#' @rdname xml_children
xml_root <- function(x) {
  stopifnot(inherits(x, c("xml_node", "xml_document", "xml_nodeset")))

  if (inherits(x, "xml_nodeset")) {
    if (length(x) == 0) {
      return(NULL)
    } else {
      return(xml_root(x[[1]]))
    }
  }
  if (!.Call(doc_has_root, x$doc)) {
    xml_missing()
  } else {
    xml_document(x$doc)
  }
}
