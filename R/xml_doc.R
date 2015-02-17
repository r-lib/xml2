#' @useDynLib xml2
#' @importFrom Rcpp sourceCpp
NULL

xml_doc <- function(doc) {
  structure(list(doc = doc), class = "xml_doc")
}

#' Parse XML string
#'
#' @export
#' @param x an xml string
#' @param base_url A base url to use for relative links.
#' @param encoding A default encoding to use.
#' @param options Additional options passed on to \code{xmlRead*}.
#'   For expert use only.
#' @examples
#' xml_parse("<foo> 123 </foo>")
xml_parse <- function(x, base_url = NULL, encoding = NULL, options = NULL){
  xml_doc(doc_parse_string(x, encoding %||% "", base_url %||% "", options %||% 0))
}

#' @export
print.xml_doc <- function(x, ...){
  cat(doc_format(x$doc), "\n")
}
