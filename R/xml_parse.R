#' Read HTML or XML.
#'
#' @section Setting the "user agent" header:
#'
#' When performing web scraping tasks it is both good practice --- and often required ---
#' to set the [user agent](https://en.wikipedia.org/wiki/User_agent) request header
#' to a specific value. Sometimes this value is assigned to emulate a browser in order
#' to have content render in a certain way (e.g. `Mozilla/5.0 (Windows NT 5.1; rv:52.0)
#' Gecko/20100101 Firefox/52.0` to emulate more recent Windows browsers). Most often,
#' this value should be set to provide the web resource owner information on who you are
#' and the intent of your actions like this Google scraping bot user agent identifier:
#' `Googlebot/2.1 (+http://www.google.com/bot.html)`.
#'
#' You can set the HTTP user agent for URL-based requests using [httr::set_config()] and [httr::user_agent()]:
#'
#' `httr::set_config(httr::user_agent("me@@example.com; +https://example.com/info.html"))`
#'
#' [httr::set_config()] changes the configuration globally,
#' [httr::with_config()] can be used to change configuration temporarily.
#'
#' @param x A string, a connection, or a raw vector.
#'
#'   A string can be either a path, a url or literal xml. Urls will
#'   be converted into connections either using `base::url` or, if
#'   installed, `curl::curl`. Local paths ending in `.gz`,
#'   `.bz2`, `.xz`, `.zip` will be automatically uncompressed.
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
#' @param n If `file` is a connection, the number of bytes to read per
#'    iteration. Defaults to 64kb.
#' @param verbose When reading from a slow connection, this prints some
#'    output on every iteration so you know its working.
#' @param options Set parsing options for the libxml2 parser. Zero or more of
#' \Sexpr[results=rd, stage=build]{xml2:::describe_options(xml2:::xml_parse_options())}
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
#' \dontrun{
#' # From a url
#' cd <- read_xml(xml2_example("cd_catalog.xml"))
#' me <- read_html("http://had.co.nz")
#' }
read_xml <- function(x, encoding = "", ..., as_html = FALSE, options = "NOBLANKS") {
  UseMethod("read_xml")
}

#' @export
#' @rdname read_xml
read_html <- function(x,
                      encoding = "",
                      ...,
                      options = c("RECOVER", "NOERROR", "NOBLANKS")) {
  UseMethod("read_html")
}

#' @export
read_html.default <- function(x,
                              encoding = "",
                              ...,
                              options = c("RECOVER", "NOERROR", "NOBLANKS")) {
  options <- parse_options(options, xml_parse_options())

  suppressWarnings(read_xml(x, encoding = encoding, ..., as_html = TRUE, options = options))
}

#' @export
read_html.response <- function(x,
                               encoding = "",
                               options = c("RECOVER", "NOERROR", "NOBLANKS"),
                               ...) {
  check_installed("httr")

  options <- parse_options(options, xml_parse_options())

  httr::stop_for_status(x)
  content <- httr::content(x, as = "raw")
  xml2::read_html(content, encoding = encoding, options = options, ...)
}

#' @export
#' @rdname read_xml
read_xml.character <- function(x,
                               encoding = "",
                               ...,
                               as_html = FALSE,
                               options = "NOBLANKS") {
  check_string(x)

  options <- parse_options(options, xml_parse_options())
  if (grepl("<|>", x)) {
    read_xml.raw(charToRaw(enc2utf8(x)), "UTF-8", ..., as_html = as_html, options = options)
  } else {
    con <- path_to_connection(x)
    if (inherits(con, "connection")) {
      read_xml.connection(con,
        encoding = encoding, ..., as_html = as_html,
        base_url = x, options = options
      )
    } else {
      doc <- .Call(doc_parse_file, con,
        encoding = encoding, as_html = as_html,
        options = options
      )
      xml_document(doc)
    }
  }
}

#' @export
#' @rdname read_xml
read_xml.raw <- function(x,
                         encoding = "",
                         base_url = "",
                         ...,
                         as_html = FALSE,
                         options = "NOBLANKS") {
  options <- parse_options(options, xml_parse_options())

  doc <- .Call(doc_parse_raw, x, encoding, base_url, as_html, options)
  xml_document(doc)
}

#' @export
#' @rdname read_xml
read_xml.connection <- function(x,
                                encoding = "",
                                n = 64 * 1024,
                                verbose = FALSE,
                                ...,
                                base_url = "",
                                as_html = FALSE,
                                options = "NOBLANKS") {
  options <- parse_options(options, xml_parse_options())

  if (!isOpen(x)) {
    open(x, "rb")
    on.exit(close(x))
  }

  raw <- .Call(read_connection_, x, n)
  read_xml.raw(raw,
    encoding = encoding, base_url = base_url, as_html =
      as_html, options = options
  )
}

#' @export
read_xml.response <- function(x,
                              encoding = "",
                              base_url = "",
                              ...,
                              as_html = FALSE,
                              options = "NOBLANKS") {
  check_installed("httr")

  options <- parse_options(options, xml_parse_options())
  httr::stop_for_status(x)
  content <- httr::content(x, as = "raw")
  xml2::read_xml(content,
    encoding = encoding, base_url = if (nzchar(base_url)) base_url else x$url,
    as_html = as_html, option = options, ...
  )
}

#' Download a HTML or XML file
#'
#' Libcurl implementation of `C_download` (the "internal" download method)
#' with added support for https, ftps, gzip, etc. Default behavior is identical
#' to [download.file()], but request can be fully configured by passing
#' a custom [curl::handle()].
#' @inherit curl::curl_download
#' @param file A character string with the name where the downloaded file is
#'   saved.
#' @seealso [curl_download][curl::curl_download]
#' @export
#' @examples
#' \dontrun{
#' download_html("http://tidyverse.org/index.html")
#' }
download_xml <- function(url,
                         file = basename(url),
                         quiet = TRUE,
                         mode = "wb",
                         handle = curl::new_handle()) {
  check_installed("curl", "to use `download_xml()`.")

  curl::curl_download(url, file, quiet = quiet, mode = mode, handle = handle)

  invisible(file)
}

#' @export
#' @rdname download_xml
download_html <- download_xml
