#' Extract or modify the text
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
xml_text.xml_missing <- function(x, trim = FALSE) {
  NA_character_
}

#' @export
xml_text.xml_node <- function(x, trim = FALSE) {
  node_text(x$node, trim = trim)
}

#' @export
xml_text.xml_nodeset <- function(x, trim = FALSE) {
  vapply(x, xml_text, trim = trim, FUN.VALUE = character(1))
}

#' @rdname xml_text
#' @param value character vector with replacement text.
#' @export
`xml_text<-` <- function(x, value) {
  UseMethod("xml_text<-")
}

#' @export
`xml_text<-.xml_nodeset` <- function(x, value) {
  # We need to do the modification in reverse order as the modification can
  # potentially delete nodes
  Map(`xml_text<-`, rev(x), rev(value))

  # what to return here, setting the text could invalidate some nodes in
  # the nodeset having pointers to free'd memory.
  x
}

#' @export
`xml_text<-.xml_node` <- function(x, value) {
  if (xml_type(x) != "text") {
    text_child <- xml_find_first(x, ".//text()[1]", ns = character())
    if (inherits(text_child, "xml_missing")) {
      node_append_content(x$node, value)
    } else {
      node_set_content(text_child$node, value)
    }
  } else {
    node_set_content(x$node, value)
  }

  x
}
