#' Extract or modify the text
#'
#' `xml_text` returns a character vector, `xml_double` returns a
#' numeric vector, `xml_integer` returns an integer vector.
#' @inheritParams xml_name
#' @param trim If `TRUE` will trim leading and trailing spaces.
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
#'
#' # xml_double() and xml_integer() are useful for extracting numeric attributes
#' x <- read_xml("<plot><point x='1' y='2' /><point x='2' y='1' /></plot>")
#' xml_integer(xml_find_all(x, "//@x"))
#' @export
xml_text <- function(x, trim = FALSE) {
  res <- .Call(node_text, x)
  if (isTRUE(trim)) {
    res <- trim_text(res)
  }
  res
}

trim_text <- function(x) {
  x <- sub("^[[:space:]\u00a0]+", "", x)
  sub("[[:space:]\u00a0]+$", "", x)
}

#' @rdname xml_text
#' @param value character vector with replacement text.
#' @export
`xml_text<-` <- function(x, value) {
  UseMethod("xml_text<-")
}

#' @export
`xml_text<-.xml_nodeset` <- function(x, value) {
  if (length(x) == 0) {
    return(x)
  }
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
      .Call(node_append_content, x$node, value)
    } else {
      .Call(node_set_content, text_child$node, value)
    }
  } else {
    .Call(node_set_content, x$node, value)
  }

  x
}

#' @export
`xml_text<-.xml_missing` <- function(x, value) {
  NA_character_
}

#' @export
#' @rdname xml_text
`xml_set_text` <- `xml_text<-`

#' @rdname xml_text
#' @export
xml_double <- function(x) {
  as.numeric(xml_text(x))
}

#' @rdname xml_text
#' @export
xml_integer <- function(x) {
  as.integer(xml_text(x))
}
