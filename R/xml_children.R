#' Navigate around the family tree.
#'
#' \code{xml_children} returns only elements, \code{xml_contents} returns
#' all nodes. \code{xml_length} returns the number of children.
#' \code{xml_parent} returns the parent node, \code{xml_parents}
#' returns all parents up to the root. \code{xml_siblings} returns all nodes
#' at the same level. \code{xml_child} makes it easy to specify a specific
#' child to return.
#'
#' @inheritParams xml_name
#' @param only_elements For \code{xml_length}, should it count all children,
#'   or just children that are elements (the default)?
#' @param search For \code{xml_child}, either the child number to return (by
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
  nodeset_apply(x, node_children)
}

#' @export
#' @rdname xml_children
xml_child <- function(x, search = 1, ns = xml_ns(x)) {
  if (length(search) != 1) {
    stop("`search` must be of length 1", call. = FALSE)
  }

  if (is.numeric(search)) {
    xml_children(x)[[search]]
  } else if (is.character(search)) {
    xml_find_first(x, xpath = paste0("./", search), ns = ns)
  } else {
    stop("`search` must be `numeric` or `character`", call. = FALSE)
  }
}

#' @export
#' @rdname xml_children
xml_contents <- function(x) {
  nodeset_apply(x, node_children, onlyNode = FALSE)
}

#' @export
#' @rdname xml_children
xml_parents <- function(x) {
  nodeset_apply(x, node_parents)
}

#' @export
#' @rdname xml_children
xml_siblings <- function(x) {
  nodeset_apply(x, node_siblings)
}

#' @export
#' @rdname xml_children
xml_parent <- function(x) {
  UseMethod("xml_parent")
}

#' @export
xml_parent.xml_missing <- function(x) {
  structure(list(), class = "xml_missing")
}

#' @export
xml_parent.xml_node <- function(x) {
  xml_node(node_parent(x$node), x$doc)
}

#' @export
xml_parent.xml_nodeset <- function(x) {
  nodeset_apply(x, node_parent)
}


#' @export
#' @rdname xml_children
xml_length <- function(x, only_elements = TRUE) {
  UseMethod("xml_length")
}

#' @export
xml_length.xml_missing <- function(x, only_elements = TRUE) {
  0L
}

#' @export
xml_length.xml_node <- function(x, only_elements = TRUE) {
  node_length(x$node, onlyNode = only_elements)
}

#' @export
xml_length.xml_nodeset <- function(x, only_elements = TRUE) {
  if (length(x) == 0)
    return(0L)

  vapply(x, node_length, onlyNode = only_elements, FUN.VALUE = integer(1))
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
  if (!doc_has_root(x$doc)) {
    structure(list(), class = "xml_missing")
  } else {
    xml_document(x$doc)
  }
}
