#' Read HTML or XML.
#'
#' @param x A string, a connection, or a raw vector.
#'
#'   A string can be either a path, a url or literal xml. Urls will
#'   be converted into connections either using \code{base::url} or, if
#'   installed, \code{curl::curl}. Local paths ending in \code{.gz},
#'   \code{.bz2}, \code{.xz}, \code{.zip} will be automatically uncompressed.
#'
#'   If a connection, the complete connection is read into a raw vector before
#'   being parsed.
#' @param encoding Specify a default encoding for the document. Unless
#'   otherwise specified XML documents are assumed to be in UTF-8 or
#'   UTF-16. If the document is not UTF-8/16, and lacks an explicit
#'   encoding directive, this allows you to supply a default.
#' @param ... Additional arguments passed on to methods.
#' @param as_html Optionally parse an xml file as if it's html.
#' @param base_url When loading from a connection, raw vector or literal
#'   html/xml, this allows you to specify a base url for the document. Base
#'   urls are used to turn relative urls into absolute urls.
#' @param n If \code{file} is a connection, the number of bytes to read per
#'    iteration. Defaults to 64kb.
#' @param verbose When reading from a slow connection, this prints some
#'    output on every iteration so you know its working.
#' @return An XML document. HTML is normalised to valid XML - this may not
#'   be exactly the same transformation performed by the browser, but it's
#'   a reasonable approximation.
#' @export
#' @examples
#' # Literal xml/html is useful for small examples
#' read_xml("<foo><bar /></foo>")
#' read_html("<html><title>Hi<title></html>")
#' read_html("<html><title>Hi")
#'
#' # From a local path
#' read_html(system.file("extdata", "r-project.html", package = "xml2"))
#'
#' # From a url
#' cd <- read_xml("http://www.xmlfiles.com/examples/cd_catalog.xml")
#' me <- read_html("http://had.co.nz")
read_xml <- function(x, encoding = "", ..., as_html = FALSE) {
  UseMethod("read_xml")
}

#' @export
#' @rdname read_xml
read_html <- function(x, encoding = "", ...) {
  suppressWarnings(read_xml(x, encoding, ..., as_html = TRUE))
}

#' @export
#' @rdname read_xml
read_xml.character <- function(x, encoding = "", ..., as_html = FALSE) {
  if (grepl("<|>", x)) {
    read_xml.raw(charToRaw(enc2utf8(x)), "UTF-8", ..., as_html = as_html)
  } else {
    con <- path_to_connection(x)
    if (inherits(con, "connection")) {
      read_xml.connection(con, encoding = encoding, ..., as_html = as_html,
        base_url = x)
    } else {
      doc <- doc_parse_file(con, encoding = encoding, as_html = as_html)
      xml_document(doc)
    }
  }
}

#' @export
#' @rdname read_xml
read_xml.raw <- function(x, encoding = "", base_url = "", ...,
                         as_html = FALSE) {
  doc <- doc_parse_raw(x, encoding = encoding, base_url = base_url, as_html = as_html)
  xml_document(doc)
}

#' @export
#' @rdname read_xml
read_xml.connection <- function(x, encoding = "", n = 64 * 1024,
                                verbose = FALSE, ..., base_url = "",
                                as_html = FALSE) {
  if (!isOpen(x)) {
    open(x, "rb")
    on.exit(close(x))
  }

  raw <- read_connection_(x, n)
  read_xml.raw(raw, encoding = encoding, base_url = base_url, as_html = as_html)
}
