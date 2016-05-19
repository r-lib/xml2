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
#' @param options Set parsing options for the libxml2 parser. These are
#' specified as a character vector of options to set. Available values are
#' \describe{
#'   \item{RECOVER}{recover on errors}
#'   \item{NOENT}{substitute entities}
#'   \item{DTDLOAD}{load the external subset}
#'   \item{DTDATTR}{default DTD attributes}
#'   \item{DTDVALID}{validate with the DTD}
#'   \item{NOERROR}{suppress error reports}
#'   \item{NOWARNING}{suppress warning reports}
#'   \item{PEDANTIC}{pedantic error reporting}
#'   \item{NOBLANKS}{remove blank nodes}
#'   \item{SAX1}{use the SAX1 interface internally}
#'   \item{XINCLUDE}{Implement XInclude substitition}
#'   \item{NONET}{Forbid network access}
#'   \item{NODICT}{Do not reuse the context dictionary}
#'   \item{NSCLEAN}{remove redundant namespaces declarations}
#'   \item{NOCDATA}{merge CDATA as text nodes}
#'   \item{NOXINCNODE}{do not generate XINCLUDE START/END nodes}
#'   \item{COMPACT}{compact small text nodes; no modification of the tree allowed afterwards (will possibly crash if you try to modify the tree)}
#'   \item{OLD10}{parse using XML-1.0 before update 5}
#'   \item{NOBASEFIX}{do not fixup XINCLUDE xml:base uris}
#'   \item{HUGE}{relax any hardcoded limit from the parser}
#'   \item{OLDSAX}{parse using SAX2 interface before 2.7.0}
#'   \item{IGNORE_ENC}{ignore internal document encoding hint}
#'   \item{BIG_LINES}{Store big lines numbers in text PSVI field}
#' }
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
read_xml <- function(x, encoding = "", ..., as_html = FALSE, options = "NOBLANKS") {
  UseMethod("read_xml")
}

#' @export
#' @rdname read_xml
read_html <- function(x, encoding = "", ..., options = c("RECOVER", "NOERROR", "NOBLANKS")) {
  suppressWarnings(read_xml(x, encoding, ..., as_html = TRUE, options = options))
}

#' @export
#' @rdname read_xml
read_xml.character <- function(x, encoding = "", ..., as_html = FALSE,
                               options = "NOBLANKS") {

  options <- parse_options(options)
  if (grepl("<|>", x)) {
    read_xml.raw(charToRaw(enc2utf8(x)), "UTF-8", ..., as_html = as_html, options = options)
  } else {
    con <- path_to_connection(x)
    if (inherits(con, "connection")) {
      read_xml.connection(con, encoding = encoding, ..., as_html = as_html,
        base_url = x, options = options)
    } else {
      doc <- doc_parse_file(con, encoding = encoding, as_html = as_html,
        options = options)
      xml_document(doc)
    }
  }
}

#' @export
#' @rdname read_xml
read_xml.raw <- function(x, encoding = "", base_url = "", ...,
                         as_html = FALSE, options = "NOBLANKS") {
  options <- parse_options(options)

  doc <- doc_parse_raw(x, encoding = encoding, base_url = base_url,
    as_html = as_html, options = options)
  xml_document(doc)
}

#' @export
#' @rdname read_xml
read_xml.connection <- function(x, encoding = "", n = 64 * 1024,
                                verbose = FALSE, ..., base_url = "",
                                as_html = FALSE, options = "NOBLANKS") {
  if (!isOpen(x)) {
    open(x, "rb")
    on.exit(close(x))
  }

  raw <- read_connection_(x, n)
  read_xml.raw(raw, encoding = encoding, base_url = base_url, as_html =
    as_html, options = options)
}

`%<<%` <- function(a, n) bitwShiftL(a, n)

# http://xmlsoft.org/html/libxml-parser.html#xmlParserOption
parser_options <- c(
  "RECOVER" = 1 %<<% 0,
  "NOENT" = 1 %<<% 1,
  "DTDLOAD" = 1 %<<% 2,
  "DTDATTR" = 1 %<<% 3,
  "DTDVALID" = 1 %<<% 4,
  "NOERROR" = 1 %<<% 5,
  "NOWARNING" = 1 %<<% 6,
  "PEDANTIC" = 1 %<<% 7,
  "NOBLANKS" = 1 %<<% 8,
  "SAX1" = 1 %<<% 9,
  "XINCLUDE" = 1 %<<% 10,
  "NONET" = 1 %<<% 11,
  "NODICT" = 1 %<<% 12,
  "NSCLEAN" = 1 %<<% 13,
  "NOCDATA" = 1 %<<% 14,
  "NOXINCNODE" = 1 %<<% 15,
  "COMPACT" = 1 %<<% 16,
  "OLD10" = 1 %<<% 17,
  "NOBASEFIX" = 1 %<<% 18,
  "HUGE" = 1 %<<% 19,
  "OLDSAX" = 1 %<<% 20,
  "OLDSAX" = 1 %<<% 20,
  "IGNORE_ENC" = 1 %<<% 21,
  "BIG_LINES" = 1 %<<% 22)

parse_options <- function(options) {
  if (is.numeric(options)) {
     return(options)
  }
  mtch <- pmatch(options, names(parser_options))
  if (any(is.na(mtch))) {
    stop("`options` ", options[is.na(mtch)][1L], " is not a valid option", call. = FALSE)
  }

  sum(parser_options[mtch])
}
