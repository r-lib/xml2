
xml_nodeset <- function(nodes, doc) {
  structure(
    lapply(nodes, xml_node, doc = doc),
    class = "xml_nodeset"
  )
}

#' @export
print.xml_nodeset <- function(x, ...) {
  if (length(x) == 0) {
    cat("<Empty nodeset>\n")
    return()
  }

  NextMethod()
}

#' Collect children nodes
#' @export
xml_children <- function(x) {
  UseMethod("xml_children")
}

#' @export
xml_children.xml_node <- function(x) {
  xml_nodeset(node_children(x$node), x$doc)
}
#' @export
xml_children.xml_nodeset <- function(x) {
  lapply(x, xml_children)
}
#' @export
xml_children.xml_doc <- function(x) {
  xml_children(xml_root(x))
}
