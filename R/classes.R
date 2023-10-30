#' @useDynLib xml2, .registration = TRUE
NULL

#' Construct a cdata node
#' @param content The CDATA content, does not include `<![CDATA[`
#' @examples
#' x <- xml_new_root("root")
#' xml_add_child(x, xml_cdata("<d/>"))
#' as.character(x)
#' @export
xml_cdata <- function(content) {
  class(content) <- "xml_cdata"
  content
}

#' Construct a comment node
#' @param content The comment content
#' @examples
#' x <- xml_new_document()
#' r <- xml_add_child(x, "root")
#' xml_add_child(r, xml_comment("Hello!"))
#' as.character(x)
#' @export
xml_comment <- function(content) {
  class(content) <- "xml_comment"
  content
}

#' Construct a document type definition
#'
#' This is used to create simple document type definitions. If you need to
#' create a more complicated definition with internal subsets it is recommended
#' to parse a string directly with `read_xml()`.
#' @param name The name of the declaration
#' @param external_id The external ID of the declaration
#' @param system_id The system ID of the declaration
#' @examples
#' r <- xml_new_root(
#'   xml_dtd(
#'     "html",
#'     "-//W3C//DTD XHTML 1.0 Transitional//EN",
#'     "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"
#'   )
#' )
#'
#' # Use read_xml directly for more complicated DTD
#' d <- read_xml(
#'   '<!DOCTYPE doc [
#' <!ELEMENT doc (#PCDATA)>
#' <!ENTITY foo " test ">
#' ]>
#' <doc>This is a valid document &foo; !</doc>'
#' )
#' @export
xml_dtd <- function(name = "", external_id = "", system_id = "") {
  out <- list(name = name, external_id = external_id, system_id = system_id)
  class(out) <- "xml_dtd"
  out
}
