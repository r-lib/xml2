#' The URL of an XML document
#'
#' This is useful for interpreting relative urls with \code{\link{url_relative}}.
#'
#' @param x A node or document.
#' @return A character vector of length 1. Returns \code{NA} if the name is
#'   not set.
#' @export
#' @examples
#' catalog <- read_xml("http://www.xmlfiles.com/examples/cd_catalog.xml")
#' xml_url(catalog)
#'
#' x <- read_xml("<foo/>")
#' xml_url(x)
xml_url <- function(x) {
  UseMethod("xml_url")
}

#' @export
xml_url.xml_node <- function(x) {
  doc_url(x$doc)
}
