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

#' @export
`xml_text<-` <- function(x, value) UseMethod("xml_text<-")

# TODO: Should this only be called on TEXT nodes? If it is used on non-text nodes it will remove child nodes from the tree.
#
# node_set_content can modify the node such that it is no longer valid, so to
# be safe once we modify a node we have to return a NULL nodeset.
# See
# https://github.com/GNOME/libxml2/blob/e28939036281969477d3913a51c001bb7635fe54/doc/examples/xpath2.c#L163-L179
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
  node_set_content(x$node, value)
  x
}

