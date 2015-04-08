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
#' @param base_url When loading from a connection or a raw vector, this allows
#'   you to specify a base url. Base urls are used to turn relative urls into
#'   absolute.
#' @param n If \code{file} is a connection, the number of bytes to read per
#'    iteration. Defaults to 16kb.
#' @param verbose When reading from a slow connection, this prints some
#'    output on every iteration so you know its working.
#' @seealso \code{\link{xml}()} to create an xml object from a string.
#' @export
#' @examples
#' # Read directly with libxml
#' catalog <- read_xml("http://www.xmlfiles.com/examples/cd_catalog.xml")
#' # Read via R's connection interface
#' catalog <- read_xml(url("http://www.xmlfiles.com/examples/cd_catalog.xml"))
#'
#' # Or read from a raw vector
#' raw <- charToRaw("<x><y/></x>")
#' read_xml(raw)
#'
#' # Read an HTML file
#' html <- read_html("http://google.com")
read_xml <- function(file, encoding = NULL, base_url = NULL, n = 16384,
                     verbose = FALSE) {
  read_ml(file, encoding = encoding, base_url = base_url, n = n,
          verbose = verbose, html = FALSE)
}

#' @export
#' @rdname read_xml
read_html <- function(file, encoding = NULL, base_url = NULL, n = 16384,
                      verbose = FALSE) {
  read_ml(file, encoding = encoding, base_url = base_url, n = n,
    verbose = verbose, html = TRUE)
}

read_ml <- function(file, encoding = NULL, base_url = NULL, n = 16384,
                    html = FALSE, verbose = FALSE) {
  encoding <- encoding %||% ""
  base_url <- base_url %||% ""

  if (is.character(file)) {
    if (!is_url(file)) {
      file <- normalizePath(file, mustWork = TRUE)
    }
    doc <- doc_parse_file(file, encoding = encoding, html = html)
  } else if (is.raw(file)) {
    doc <- doc_parse_raw(file, encoding = encoding, base_url = base_url, html = html)
  } else if (inherits(file, "connection")) {
    doc <- doc_parse_connection(file, n = n, verbose = verbose, html = html)
  } else {
    stop("`file` must be a string, a connection or a raw vector", call. = FALSE)
  }

  xml_document(doc)
}

is_url <- function(x) grepl("^(file|http|ftp|https):", x)

doc_parse_connection <- function(con, n = 1000, verbose = TRUE, html = FALSE) {
  stopifnot(inherits(con, "connection"))
  if (html)
    stop("Parsing html from a connection not currently supported")

  if(!isOpen(con)){
    open(con, "rb")
    on.exit(close(con))
  }

  # Init new push parser
  p <- new_push_parser("myparser");
  if(verbose)
    cat("Parsing...")

  # Read from the connection until it is empty
  while(length(buf <- readBin(con, raw(), n))){
    feed_push_parser_raw(p, buf)
    if(verbose)
      cat(".")
  }

  # Close the parser
  close_push_parser(p)
  if(verbose)
    cat("done!\n")
  get_push_parser_doc(p)
}
