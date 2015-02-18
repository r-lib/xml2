#' Extract the text
#'
#' @inheritParams xml_name
#' @return A character vector, the same length as x.
#' @examples
#' x <- xml("<p>This is some text. This is <b>bold!</b></p>")
#' xml_text(x)
#' xml_text(xml_children(x))
#' @export
xml_text <- function(x, ...) {
  UseMethod("xml_text")
}

#' @export
xml_text.xml_nodeset <- function(x, ...) {
  vapply(x$node, node_text, FUN.VALUE = character(1))
}
