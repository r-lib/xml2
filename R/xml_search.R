#' Search for matching xpath expressions.
#'
#' @param xpath A string containing a xpath expression.
#' @inheritParams xml_name
#' @export
#' @examples
#' x <- xml("<foo><bar><baz/></bar><baz/></foo>")
#' xml_search(x, ".//baz")
#' xml_path(xml_search(x, ".//baz"))
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
xml_search.xml_nodeset <- function(x, xpath, ...) {
  nodeset_apply(x, node_search, doc = x$doc, xpath = xpath)
}
