# Read HTML or XML.

Read HTML or XML.

## Usage

``` r
read_xml(x, encoding = "", ..., as_html = FALSE, options = "NOBLANKS")

read_html(
  x,
  encoding = "",
  ...,
  options = c("RECOVER", "NOERROR", "NOBLANKS", "HUGE")
)

# S3 method for class 'character'
read_xml(x, encoding = "", ..., as_html = FALSE, options = "NOBLANKS")

# S3 method for class 'raw'
read_xml(
  x,
  encoding = "",
  base_url = "",
  ...,
  as_html = FALSE,
  options = "NOBLANKS"
)

# S3 method for class 'connection'
read_xml(
  x,
  encoding = "",
  n = 64 * 1024,
  verbose = FALSE,
  ...,
  base_url = "",
  as_html = FALSE,
  options = "NOBLANKS"
)
```

## Arguments

- x:

  A string, a connection, or a raw vector.

  A string can be either a path, a url or literal xml. Urls will be
  converted into connections either using
  [`base::url`](https://rdrr.io/r/base/connections.html) or, if
  installed, [`curl::curl`](https://rdrr.io/pkg/curl/man/curl.html).
  Local paths ending in `.gz`, `.bz2`, `.xz`, `.zip` will be
  automatically uncompressed.

  If a connection, the complete connection is read into a raw vector
  before being parsed.

- encoding:

  Specify a default encoding for the document. Unless otherwise
  specified XML documents are assumed to be in UTF-8 or UTF-16. If the
  document is not UTF-8/16, and lacks an explicit encoding directive,
  this allows you to supply a default.

- ...:

  Additional arguments passed on to methods.

- as_html:

  Optionally parse an xml file as if it's html.

- options:

  Set parsing options for the libxml2 parser. Zero or more of

  RECOVER

  :   recover on errors

  NOENT

  :   substitute entities

  DTDLOAD

  :   load the external subset

  DTDATTR

  :   default DTD attributes

  DTDVALID

  :   validate with the DTD

  NOERROR

  :   suppress error reports

  NOWARNING

  :   suppress warning reports

  PEDANTIC

  :   pedantic error reporting

  NOBLANKS

  :   remove blank nodes

  SAX1

  :   use the SAX1 interface internally

  XINCLUDE

  :   Implement XInclude substitution

  NONET

  :   Forbid network access

  NODICT

  :   Do not reuse the context dictionary

  NSCLEAN

  :   remove redundant namespaces declarations

  NOCDATA

  :   merge CDATA as text nodes

  NOXINCNODE

  :   do not generate XINCLUDE START/END nodes

  COMPACT

  :   compact small text nodes; no modification of the tree allowed
      afterwards (will possibly crash if you try to modify the tree)

  OLD10

  :   parse using XML-1.0 before update 5

  NOBASEFIX

  :   do not fixup XINCLUDE xml:base uris

  HUGE

  :   relax any hardcoded limit from the parser

  OLDSAX

  :   parse using SAX2 interface before 2.7.0

  IGNORE_ENC

  :   ignore internal document encoding hint

  BIG_LINES

  :   Store big lines numbers in text PSVI field

- base_url:

  When loading from a connection, raw vector or literal html/xml, this
  allows you to specify a base url for the document. Base urls are used
  to turn relative urls into absolute urls.

- n:

  If `file` is a connection, the number of bytes to read per iteration.
  Defaults to 64kb.

- verbose:

  When reading from a slow connection, this prints some output on every
  iteration so you know its working.

## Value

An XML document. HTML is normalised to valid XML - this may not be
exactly the same transformation performed by the browser, but it's a
reasonable approximation.

## Setting the "user agent" header

When performing web scraping tasks it is both good practice — and often
required — to set the [user
agent](https://en.wikipedia.org/wiki/User_agent) request header to a
specific value. Sometimes this value is assigned to emulate a browser in
order to have content render in a certain way (e.g.
`Mozilla/5.0 (Windows NT 5.1; rv:52.0) Gecko/20100101 Firefox/52.0` to
emulate more recent Windows browsers). Most often, this value should be
set to provide the web resource owner information on who you are and the
intent of your actions like this Google scraping bot user agent
identifier: `Googlebot/2.1 (+http://www.google.com/bot.html)`.

You can set the HTTP user agent for URL-based requests using
[`httr::set_config()`](https://httr.r-lib.org/reference/set_config.html)
and
[`httr::user_agent()`](https://httr.r-lib.org/reference/user_agent.html):

`httr::set_config(httr::user_agent("me@example.com; +https://example.com/info.html"))`

[`httr::set_config()`](https://httr.r-lib.org/reference/set_config.html)
changes the configuration globally,
[`httr::with_config()`](https://httr.r-lib.org/reference/with_config.html)
can be used to change configuration temporarily.

## Examples

``` r
# Literal xml/html is useful for small examples
read_xml("<foo><bar /></foo>")
#> {xml_document}
#> <foo>
#> [1] <bar/>
read_html("<html><title>Hi<title></html>")
#> {html_document}
#> <html>
#> [1] <head>\n<meta http-equiv="Content-Type" content="text/html; char ...
read_html("<html><title>Hi")
#> {html_document}
#> <html>
#> [1] <head>\n<meta http-equiv="Content-Type" content="text/html; char ...

# From a local path
read_html(system.file("extdata", "r-project.html", package = "xml2"))
#> {html_document}
#> <html lang="en">
#> [1] <head>\n<meta http-equiv="Content-Type" content="text/html; char ...
#> [2] <body>\n    <div class="container page">\n      <div class="row" ...

if (FALSE) { # \dontrun{
# From a url
cd <- read_xml(xml2_example("cd_catalog.xml"))
me <- read_html("http://had.co.nz")
} # }
```
