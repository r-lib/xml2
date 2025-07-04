% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/xml_parse.R
\name{read_xml}
\alias{read_xml}
\alias{read_html}
\alias{read_xml.character}
\alias{read_xml.raw}
\alias{read_xml.connection}
\title{Read HTML or XML.}
\usage{
read_xml(x, encoding = "", ..., as_html = FALSE, options = "NOBLANKS")

read_html(
  x,
  encoding = "",
  ...,
  options = c("RECOVER", "NOERROR", "NOBLANKS", "HUGE")
)

\method{read_xml}{character}(x, encoding = "", ..., as_html = FALSE, options = "NOBLANKS")

\method{read_xml}{raw}(
  x,
  encoding = "",
  base_url = "",
  ...,
  as_html = FALSE,
  options = "NOBLANKS"
)

\method{read_xml}{connection}(
  x,
  encoding = "",
  n = 64 * 1024,
  verbose = FALSE,
  ...,
  base_url = "",
  as_html = FALSE,
  options = "NOBLANKS"
)
}
\arguments{
\item{x}{A string, a connection, or a raw vector.

A string can be either a path, a url or literal xml. Urls will
be converted into connections either using \code{base::url} or, if
installed, \code{curl::curl}. Local paths ending in \code{.gz},
\code{.bz2}, \code{.xz}, \code{.zip} will be automatically uncompressed.

If a connection, the complete connection is read into a raw vector before
being parsed.}

\item{encoding}{Specify a default encoding for the document. Unless
otherwise specified XML documents are assumed to be in UTF-8 or
UTF-16. If the document is not UTF-8/16, and lacks an explicit
encoding directive, this allows you to supply a default.}

\item{...}{Additional arguments passed on to methods.}

\item{as_html}{Optionally parse an xml file as if it's html.}

\item{options}{Set parsing options for the libxml2 parser. Zero or more of
\Sexpr[results=rd, stage=build]{xml2:::describe_options(xml2:::xml_parse_options())}}

\item{base_url}{When loading from a connection, raw vector or literal
html/xml, this allows you to specify a base url for the document. Base
urls are used to turn relative urls into absolute urls.}

\item{n}{If \code{file} is a connection, the number of bytes to read per
iteration. Defaults to 64kb.}

\item{verbose}{When reading from a slow connection, this prints some
output on every iteration so you know its working.}
}
\value{
An XML document. HTML is normalised to valid XML - this may not
be exactly the same transformation performed by the browser, but it's
a reasonable approximation.
}
\description{
Read HTML or XML.
}
\section{Setting the "user agent" header}{


When performing web scraping tasks it is both good practice --- and often required ---
to set the \href{https://en.wikipedia.org/wiki/User_agent}{user agent} request header
to a specific value. Sometimes this value is assigned to emulate a browser in order
to have content render in a certain way (e.g. \verb{Mozilla/5.0 (Windows NT 5.1; rv:52.0) Gecko/20100101 Firefox/52.0} to emulate more recent Windows browsers). Most often,
this value should be set to provide the web resource owner information on who you are
and the intent of your actions like this Google scraping bot user agent identifier:
\verb{Googlebot/2.1 (+http://www.google.com/bot.html)}.

You can set the HTTP user agent for URL-based requests using \code{\link[httr:set_config]{httr::set_config()}} and \code{\link[httr:user_agent]{httr::user_agent()}}:

\code{httr::set_config(httr::user_agent("me@example.com; +https://example.com/info.html"))}

\code{\link[httr:set_config]{httr::set_config()}} changes the configuration globally,
\code{\link[httr:with_config]{httr::with_config()}} can be used to change configuration temporarily.
}

\examples{
# Literal xml/html is useful for small examples
read_xml("<foo><bar /></foo>")
read_html("<html><title>Hi<title></html>")
read_html("<html><title>Hi")

# From a local path
read_html(system.file("extdata", "r-project.html", package = "xml2"))

\dontrun{
# From a url
cd <- read_xml(xml2_example("cd_catalog.xml"))
me <- read_html("http://had.co.nz")
}
}
