xml_document <- function(doc) {
  if (.Call(doc_has_root, doc)) {
    x <- xml_node(.Call(doc_root, doc), doc)
    class(x) <- c("xml_document", class(x))
    x
  } else {
    out <- list(doc = doc)
    class(out) <- "xml_document"
    out
  }
}

doc_type <- function(x) {
  if (is.null(x$doc)) {
    return("xml")
  }
  if (.Call(doc_is_html, x$doc)) {
    "html"
  } else {
    "xml"
  }
}

#' @export
print.xml_document <- function(x, width = getOption("width"), max_n = 20, ...) {
  doc <- xml_document(x$doc)
  cat("{", doc_type(x), "_document}\n", sep = "")
  if (inherits(doc, "xml_node")) {
    cat(format(doc), "\n", sep = "")
    show_nodes(xml_children(doc), width = width, max_n = max_n)
  }
}

#' @export
as.character.xml_document <- function(x, ..., options = "format", encoding = "UTF-8") {
  options <- parse_options(options, xml_save_options())
  .Call(doc_write_character, x$doc, encoding, options)
}
