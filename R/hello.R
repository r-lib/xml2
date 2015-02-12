#' Parse XML string
#' 
#' @useDynLib xml2 R_xml_parse
#' @export
#' @examples xml_parse("<foo> 123 </foo>")
xml_parse <- function(x){
  .Call(R_xml_parse, x)
}

#' @useDynLib xml2 R_doc_to_string
#' @export
print.xmlDocPtr <- function(x, ...){
  cat(doc_to_string(x))
}

doc_to_string <- function(x){
  .Call(R_doc_to_string, x)
}
