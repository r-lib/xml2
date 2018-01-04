#' The URL of an XML document
#'
#' This is useful for interpreting relative urls with \code{\link{url_relative}}.
#'
#' @param x A node or document.
#' @return A character vector of length 1. Returns \code{NA} if the name is
#'   not set.
#' @export
#' @examples
#' catalog <- read_xml(xml2_example("cd_catalog.xml"))
#' xml_url(catalog)
#'
#' x <- read_xml("<foo/>")
#' xml_url(x)
xml_url <- function(x) {
  UseMethod("xml_url")
}

#' @export
xml_url.xml_missing <- function(x) {
  NA_character_
}

#' @export
xml_url.xml_node <- function(x) {
  doc_url(x$doc)
}

#' @export
xml_url.xml_nodeset <- function(x) {
  vapply(x, doc_url, character(1))
}
