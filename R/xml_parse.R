#' Create HTML or XML from a string.
#'
#' @export
#' @param x A string containing XML or HTML.
#' @param base_url A base url to use for relative links.
#' @return Both functions return a xml_doc
#' @examples
#' xml("<foo> 123 </foo>")
#' xml("<foo> \u00e5 </foo>")
#'
#' # The html parser converts potential malformed HTML into valid XML
#' html("<html> 123 </html>")
xml <- function(x, base_url = NULL) {
  xml_doc(doc_parse_string(enc2utf8(x), "UTF-8", base_url %||% ""))
}

#' @export
#' @rdname xml
html <- function(x, base_url = NULL) {
  xml_doc(doc_parse_string(enc2utf8(x), "UTF-8", base_url %||% "", html = TRUE))
}

#' Read HTML or XML from a stream or file.
#'
#' @param file A file, url or a connection object. Character vectors are
#'   passed on to libxml, which supports both local paths and urls.
#'   Connections are read in a chunk at a time; this is slower, but allows
#'   you to use any R connection.
#' @param encoding Specify a default encoding for the document. Unless
#'   otherwise specified XML documented are assumed to be in UTF-8 or
#'   UTF-16. If the document is not UTF-8/16, and lacks an explicit
#'   encoding directive, this allows you to supply a default.
#' @param n If \code{file} is a connection, the number of bytes to read per
#'    iteration. Defaults to 16kb.
#' @param verbose When reading from a slow connection, this prints some
#'    output on every iteration so you know its working.
#' @export
#' @examples
#' # Read directly with libxml
#' catalog <- read_xml("http://www.xmlfiles.com/examples/cd_catalog.xml")
#' # Read via R's connection interface
#' catalog <- read_xml(url("http://www.xmlfiles.com/examples/cd_catalog.xml"))
#'
#' # Read an HTML file
#' html <- read_html("http://google.com")
read_xml <- function(file, encoding = NULL, n = 16384, verbose = FALSE) {
  encoding <- encoding %||% ""
  if (is.character(file)) {
    read_xml_file(file, encoding)
  } else {
    read_xml_con(file, n = n, verbose = verbose)
  }
}

#' @export
#' @rdname read_xml
read_html <- function(file, encoding = NULL, n = 16384, verbose = FALSE) {
  encoding <- encoding %||% ""
  if (is.character(file)) {
    read_xml_file(file, encoding, TRUE)
  } else {
    stop("Reading HTML from a connection not currently supported")
  }
}


read_xml_file <- function(path, encoding, html = FALSE) {
  xml_doc(doc_parse_file(path, encoding, html = html))
}

read_xml_con <- function(con, n = 1000, verbose = TRUE){
  stopifnot(is(con, "connection"))
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
  xml_doc(get_push_parser_doc(p))
}
