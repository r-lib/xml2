#' Find nodes that match an xpath expression.
#'
#' Xpath is like regular expressions for trees - it's worth learning if
#' you're trying to extract nodes from arbitrary locations in a document.
#'
#' @param xpath A string containing a xpath (1.0) expression.
#' @inheritParams xml_name
#' @return Always returns a nodeset. If \code{x} was a nodeset, the output
#'   is automatically de-duplicated.
#' @export
#' @examples
#' x <- xml("<foo><bar><baz/></bar><baz/></foo>")
#' xml_find(x, ".//baz")
#' xml_path(xml_find(x, ".//baz"))
#'
#' # Note the difference between .// and //
#' # //  finds anywhere in the document (ignoring the current node)
#' # .// finds anywhere beneath the current node
#' (bar <- xml_find(x, ".//bar"))
#' xml_find(bar, ".//baz")
#' xml_find(bar, "//baz")
#'
#' # If the document uses namespaces, you'll need use xml_ns to form
#' # a unique mapping between full namespace url and a short prefix
#' x <- xml('
#'  <root xmlns:f = "http://foo.com" xmlns:g = "http://bar.com">
#'    <f:doc><g:baz /></f:doc>
#'    <f:doc><g:baz /></f:doc>
#'  </root>
#' ')
#' xml_find(x, ".//f:doc")
#' xml_find(x, ".//f:doc", xml_ns(x))
xml_find <- function(x, xpath, ns = character()) {
  UseMethod("xml_find")
}

#' @export
xml_find.xml_node <- function(x, xpath, ns = character()) {
  nodes <- node_find(x$node, x$doc, xpath = xpath, nsMap = ns)
  make_nodeset(nodes, x$doc)
}

#' @export
xml_find.xml_nodeset <- function(x, xpath, ns = character()) {
  if (length(x) == 0)
    return(xml_nodeset())

  nodes <- lapply(x, function(x) node_find(x$node, x$doc, xpath = xpath, nsMap = ns))
  make_nodeset(nodes, x[[1]]$doc)
}
