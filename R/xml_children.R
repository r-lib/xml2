#' Navigate around the family tree.
#'
#' \code{xml_children} returns only elements, \code{xml_contents} returns
#' all nodes. \code{xml_length} returns the number of children.
#' \code{xml_parent} returns the parent node, \code{xml_parents}
#' returns all parents up to the root. \code{xml_siblings} returns all nodes
#' at the same level.
#'
#' @inheritParams xml_name
#' @param only_elements For \code{xml_length}, should it count all children,
#'   or just children that are elements (the default)?
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
xml_children <- function(x) {
  nodeset_apply(x, node_children)
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
xml_length.xml_node <- function(x, only_elements = TRUE) {
  node_length(x$node, onlyNode = only_elements)
}

#' @export
xml_length.xml_nodeset <- function(x, only_elements = TRUE) {
  if (length(x) == 0)
    return(integer)

  vapply(x, node_length, onlyNode = only_elements, FUN.VALUE = integer(1))
}
