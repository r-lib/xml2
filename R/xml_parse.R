#' Create HTML or XML from a string.
#'
#' @export
#' @param x A string containing XML or HTML.
#' @param base_url A base url to use for relative links.
#' @return Both functions return a xml_doc
#' @examples
#' xml("<foo> 123 </foo>")
#' xml("<foo> \u00e5 </foo>")
#' xml("<foo><bar><baz /></bar><baz/></foo>")
#'
#' # The html parser converts potential malformed HTML into valid XML
#' html("<html> 123 </html>")
xml <- function(x, base_url = NULL) {
  xml_document(doc_parse_string(enc2utf8(x), "UTF-8", base_url %||% ""))
}

#' @export
#' @rdname xml
html <- function(x, base_url = NULL) {
  xml_document(doc_parse_string(enc2utf8(x), "UTF-8", base_url %||% "", html = TRUE))
}

#' Read HTML or XML from a stream or file.
#'
#' @param file A file, url, a connection, or a raw vector. Character vectors are
#'   passed on to libxml, which supports both local paths and urls.
#'   Connections are read in a chunk at a time; this is slower, but allows
#'   you to use any R connection.
#' @param encoding Specify a default encoding for the document. Unless
#'   otherwise specified XML documents are assumed to be in UTF-8 or
#'   UTF-16. If the document is not UTF-8/16, and lacks an explicit
#'   encoding directive, this allows you to supply a default.
#' @param ... Additional arguments passed on to methods.
#' @param as_html Optionally parse an xml file as if it's html.
#' @param xml_url When loading from a connection or a raw vector, this allows
#'   you to specify a base url. Base urls are used to turn relative urls into
#'   absolute.
#' @param n If \code{file} is a connection, the number of bytes to read per
#'    iteration. Defaults to 16kb.
#' @param verbose When reading from a slow connection, this prints some
#'    output on every iteration so you know its working.
#' @seealso \code{\link{xml}()} to create an xml object from a string.
#' @export
#' @examples
#' # You can read from a url:
#' catalog <- read_xml("http://www.xmlfiles.com/examples/cd_catalog.xml")
#' me <- read_html("http://had.co.nz")
#'
#' # Or read from a raw vector
#' raw <- charToRaw("<x><y/></x>")
#' read_xml(raw)
#'
#' # Read an HTML file
read_xml <- function(file, encoding = "", ..., as_html = FALSE) {
  UseMethod("read_xml")
}

#' @export
#' @rdname read_xml
read_html <- function(file, encoding = "", ...) {
  read_xml(file, encoding, ..., as_html = TRUE)
}

#' @export
#' @rdname read_xml
read_xml.character <- function(file, encoding = "", ..., as_html = FALSE) {
  con <- path_to_connection(file)
  if (inherits(con, "connection")) {
    read_xml.connection(con, encoding = encoding, ..., as_html = as_html, xml_url = file)
  } else {
    doc <- doc_parse_file(file, encoding = encoding, html = as_html)
    xml_document(doc)
  }
}

#' @export
#' @rdname read_xml
read_xml.raw <- function(file, encoding = "", xml_url = "", ...,
                         as_html = FALSE) {
  doc <- doc_parse_raw(file, encoding = encoding, base_url = xml_url, html = as_html)
  xml_document(doc)
}

#' @export
#' @rdname read_xml
read_xml.connection <- function(file, encoding = "", n = 16384, verbose = FALSE,
                                 ..., xml_url = "", as_html = FALSE) {
  if (!isOpen(file)){
    open(file, "rb")
    on.exit(close(file))
  }

  parser <- if (as_html) html_push_parse else xml_push_parse
  parser(file, uri = xml_url, n = n, verbose = verbose)
}

xml_push_parse <- function(con, uri = "", n = 16384, verbose = FALSE) {
  p <- xml_push_parser_create(uri);
  if (verbose)
    cat("Parsing...")

  while (length(buf <- readBin(con, raw(), n))){
    xml_push_parser_feed(p, buf)
    if (verbose)
      cat(".")
  }

  xml_push_parser_complete(p)
  xml_document(xml_push_parser_doc(p))
}

html_push_parse <- function(con, uri = "", n = 16384, verbose = FALSE) {
  p <- html_push_parser_create(uri);
  if (verbose)
    cat("Parsing...")

  while (length(buf <- readBin(con, raw(), n))){
    html_push_parser_feed(p, buf)
    if (verbose)
      cat(".")
  }

  html_push_parser_complete(p)
  xml_document(html_push_parser_doc(p))
}
