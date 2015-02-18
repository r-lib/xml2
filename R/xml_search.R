#' Search for matching xpath expressions.
#'
#' @param xpath A string containing a xpath expression.
#' @inheritParams xml_name
#' @export
#' @examples
#' x <- xml("<foo><bar><baz/></bar><baz/></foo>")
#' xml_search(x, ".//baz")
#'
#' # Note the difference between .// and //
#' # //  finds anywhere in the document (ignoring the current node)
#' # .// finds anywhere beneath the current node
#' (bar <- xml_search(x, ".//bar"))
#' xml_search(bar, ".//baz")
#' xml_search(bar, "//baz")
xml_search <- function(x, xpath, ...) {
  UseMethod("xml_search")
}

#' @export
xml_search.xml_node <- function(x, xpath, ...) {
  xml_nodeset(node_search(x$node, x$doc, xpath), x$doc)
}

#' @export
xml_search.xml_doc <- function(x, xpath, ...) {
  xml_search(xml_root(x), xpath)
}

#' @export
xml_search.xml_nodeset <- function(x, xpath, ...) {
  unlist(lapply(x, xml_search, xpath, ...), recursive = FALSE)
}

