#' @useDynLib xml2
#' @importFrom Rcpp sourceCpp
NULL

#' Parse XML string
#'
#' @export
#' @param x an xml string
#' @param base_url A base url to use for relative links.
#' @param encoding A default encoding to use.
#' @param options Additional options passed on to \code{xmlRead*}.
#'   For expert use only.
#' @examples
#' xml_parse_string("<foo> 123 </foo>")
xml_parse_string <- function(x, base_url = NULL, encoding = NULL, options = NULL){
  xml_doc(parse_xml_string(x, encoding %||% "", base_url %||% "", options %||% 0))
}

xml_doc <- function(x) {
  structure(list(x), class = "xml_doc")
}

#' @export
print.xml_doc <- function(x, ...){
  cat(xml_doc_format(x[[1]]), "\n")
}
