#' Extract the text
#'
#' @inheritParams xml_name
#' @return A character vector, the same length as x.
#' @examples
#' x <- xml("<p>This is some text. This is <b>bold!</b></p>")
#' xml_text(x)
#' xml_text(xml_children(x))
#'
#' x <- xml("<x>This is some text. <x>This is some nested text.</x></x>")
#' xml_text(x)
#' xml_text(xml_find(x, "//x"))
#' @export
xml_text <- function(x) {
  UseMethod("xml_text")
}

#' @export
xml_text.xml_node <- function(x) {
  node_text(x$node)
}

#' @export
xml_text.xml_nodeset <- function(x) {
  vapply(x, xml_text, FUN.VALUE = character(1))
}
