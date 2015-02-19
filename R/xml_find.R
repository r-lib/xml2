#' Find nodes that match an xpath expression.
#'
#' Xpath is like regular expressions for trees - it's worth learning if
#' you're trying to extract nodes from arbitrary locations in a document.
#'
#' @param xpath A string containing a xpath (1.0) expression.
#' @inheritParams xml_name
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
#' # If the document uses namespaces, you'll need use xml_ns:
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
xml_find.xml_nodeset <- function(x, xpath, ns = character()) {
  nodeset_apply(x, node_find, doc = x$doc, xpath = xpath, ns = ns)
}
