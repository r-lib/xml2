#' The URL of an XML document
#'
#' This is useful for interpreting relative urls with [url_relative()].
#'
#' @param x A node or document.
#' @return A character vector of length 1. Returns `NA` if the name is
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
  .Call(doc_url, x$doc)
}

#' @export
xml_url.xml_nodeset <- function(x) {
  vapply(x, function(x) .Call(doc_url, x), character(1))
}

#' Convert between relative and absolute urls.
#'
#' @param x A character vector of urls relative to that base
#' @param base A string giving a base url.
#' @return A character vector of urls
#' @seealso \code{\link{xml_url}} to retrieve the URL associated with a document
#' @export
#' @examples
#' url_absolute(c(".", "..", "/", "/x"), "http://hadley.nz/a/b/c/d")
#'
#' url_relative("http://hadley.nz/a/c", "http://hadley.nz")
#' url_relative("http://hadley.nz/a/c", "http://hadley.nz/")
#' url_relative("http://hadley.nz/a/c", "http://hadley.nz/a/b")
#' url_relative("http://hadley.nz/a/c", "http://hadley.nz/a/b/")
#' @export
url_absolute <- function(x, base) {
  .Call(url_absolute_, x, base)
}

#' @rdname url_absolute
#' @export
url_relative <- function(x, base) {
  .Call(url_relative_, x, base)
}

#' Escape and unescape urls.
#'
#' @param x A character vector of urls.
#' @param reserved A string containing additional characters to avoid escaping.
#' @export
#' @examples
#' url_escape("a b c")
#' url_escape("a b c", "")
#'
#' url_unescape("a%20b%2fc")
#' url_unescape("%C2%B5")
url_escape <- function(x, reserved = "") {
  .Call(url_escape_, x, reserved)
}

#' @rdname url_escape
#' @export
url_unescape <- function(x) {
  .Call(url_unescape_, x)
}

#' Parse a url into its component pieces.
#'
#' @param x A character vector of urls.
#' @return A dataframe with one row for each element of \code{x} and
#'   columns: scheme, server, port, user, path, query, fragment.
#' @export
#' @examples
#' url_parse("http://had.co.nz/")
#' url_parse("http://had.co.nz:1234/")
#' url_parse("http://had.co.nz:1234/?a=1&b=2")
#' url_parse("http://had.co.nz:1234/?a=1&b=2#def")
url_parse <- function(x) {
  .Call(url_parse_, x)
}
