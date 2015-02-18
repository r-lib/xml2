#' Search for matching xpath expressions.
#'
#' @param xpath A string containing a xpath expression.
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
xml_find <- function(x, xpath, ...) {
  UseMethod("xml_find")
}

#' @export
xml_find.xml_nodeset <- function(x, xpath, ...) {
  nodeset_apply(x, node_find, doc = x$doc, xpath = xpath)
}
