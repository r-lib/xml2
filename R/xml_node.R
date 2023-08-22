# node -------------------------------------------------------------------------

xml_node <- function(node = NULL, doc = NULL) {
  if (inherits(node, "xml_node")) {
    node
  } else {
    out <- list(node = node, doc = doc)
    class(out) <- "xml_node"
    out
  }
}

#' @export
as.character.xml_node <- function(x, ..., options = "format", encoding = "UTF-8") {
  options <- parse_options(options, xml_save_options())
  .Call(node_write_character, x$node, encoding, options)
}

#' @export
print.xml_node <- function(x, width = getOption("width"), max_n = 20, ...) {
  cat("{", doc_type(x), "_node}\n", sep = "")
  cat(format(x), "\n", sep = "")
  show_nodes(xml_children(x), width = width, max_n = max_n)
}

#' @export
is.na.xml_node <- function(x) {
  FALSE
}
