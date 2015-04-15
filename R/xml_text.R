#' Extract the text
#'
#' @inheritParams xml_name
#' @param trim If \code{TRUE} will trim leading and trailing spaces.
#' @return A character vector, the same length as x.
#' @examples
#' x <- read_xml("<p>This is some text. This is <b>bold!</b></p>")
#' xml_text(x)
#' xml_text(xml_children(x))
#'
#' x <- read_xml("<x>This is some text. <x>This is some nested text.</x></x>")
#' xml_text(x)
#' xml_text(xml_find_all(x, "//x"))
#'
#' x <- read_xml("<p>   Some text    </p>")
#' xml_text(x, trim = TRUE)
#' @export
xml_text <- function(x, trim = FALSE) {
  UseMethod("xml_text")
}

#' @export
xml_text.xml_node <- function(x, trim = FALSE) {
  node_text(x$node, trim = trim)
}

#' @export
xml_text.xml_nodeset <- function(x, trim = FALSE) {
  vapply(x, xml_text, trim = trim, FUN.VALUE = character(1))
}
