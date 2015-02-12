#' @useDynLib xml2 R_xml_init
.onLoad <- function(libname, pkgname){
  .Call(R_xml_init)
}
