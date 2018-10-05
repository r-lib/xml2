#' Find nodes that match an xpath expression.
#'
#' Xpath is like regular expressions for trees - it's worth learning if
#' you're trying to extract nodes from arbitrary locations in a document.
#' Use \code{xml_find_all} to find all matches - if there's no match you'll
#' get an empty result. Use \code{xml_find_first} to find a specific match -
#' if there's no match you'll get an \code{xml_missing} node.
#'
#' @section Deprecated functions:
#' \code{xml_find_one()} has been deprecated. Instead use
#' \code{xml_find_first()}.

#' @param xpath A string containing a xpath (1.0) expression.
#' @inheritParams xml_name
#' @return \code{xml_find_all} always returns a nodeset: if there are no matches
#'   the nodeset will be empty. The result will always be unique; repeated
#'   nodes are automatically de-duplicated.
#'
#'   \code{xml_find_first} returns a node if applied to a node, and a nodeset
#'   if applied to a nodeset. The output is \emph{always} the same size as
#'   the input. If there are no matches, \code{xml_find_first} will return a
#'   missing node; if there are multiple matches, it will return the first
#'   only.
#'
#'   \code{xml_find_num}, \code{xml_find_chr}, \code{xml_find_lgl} return
#'   numeric, character and logical results respectively.
#' @export
#' @seealso \code{\link{xml_ns_strip}} to remove the default namespaces
#' @examples
#' x <- read_xml("<foo><bar><baz/></bar><baz/></foo>")
#' xml_find_all(x, ".//baz")
#' xml_path(xml_find_all(x, ".//baz"))
#'
#' # Note the difference between .// and //
#' # //  finds anywhere in the document (ignoring the current node)
#' # .// finds anywhere beneath the current node
#' (bar <- xml_find_all(x, ".//bar"))
#' xml_find_all(bar, ".//baz")
#' xml_find_all(bar, "//baz")
#'
#' # Find all vs find one -----------------------------------------------------
#' x <- read_xml("<body>
#'   <p>Some <b>text</b>.</p>
#'   <p>Some <b>other</b> <b>text</b>.</p>
#'   <p>No bold here!</p>
#' </body>")
#' para <- xml_find_all(x, ".//p")
#'
#' # If you apply xml_find_all to a nodeset, it finds all matches,
#' # de-duplicates them, and returns as a single list. This means you
#' # never know how many results you'll get
#' xml_find_all(para, ".//b")
#'
#' # xml_find_first only returns the first match per input node. If there are 0
#' # matches it will return a missing node
#' xml_find_first(para, ".//b")
#' xml_text(xml_find_first(para, ".//b"))
#'
#' # Namespaces ---------------------------------------------------------------
#' # If the document uses namespaces, you'll need use xml_ns to form
#' # a unique mapping between full namespace url and a short prefix
#' x <- read_xml('
#'  <root xmlns:f = "http://foo.com" xmlns:g = "http://bar.com">
#'    <f:doc><g:baz /></f:doc>
#'    <f:doc><g:baz /></f:doc>
#'  </root>
#' ')
#' xml_find_all(x, ".//f:doc")
#' xml_find_all(x, ".//f:doc", xml_ns(x))
xml_find_all <- function(x, xpath, ns = xml_ns(x)) {
  UseMethod("xml_find_all")
}

#' @export
xml_find_all.xml_missing <- function(x, xpath, ns = xml_ns(x)) {
  xml_nodeset()
}

#' @export
xml_find_all.xml_node <- function(x, xpath, ns = xml_ns(x)) {
  nodes <- xpath_search(x$node, x$doc, xpath = xpath, nsMap = ns, num_results = Inf)
  xml_nodeset(nodes)
}

#' @export
xml_find_all.xml_nodeset <- function(x, xpath, ns = xml_ns(x)) {
  if (length(x) == 0)
    return(xml_nodeset())

  nodes <- unlist(recursive = FALSE,
    lapply(x, function(x)
      xpath_search(x$node, x$doc, xpath = xpath, nsMap = ns, num_results = Inf)))

  xml_nodeset(nodes)
}

#' @export
#' @rdname xml_find_all
xml_find_first <- function(x, xpath, ns = xml_ns(x)) {
  UseMethod("xml_find_first")
}

xml_find_first.xml_missing <- function(x, xpath, ns = xml_ns(x)) {
  xml_missing()
}

#' @export
xml_find_first.xml_node <- function(x, xpath, ns = xml_ns(x)) {
  res <- xpath_search(x$node, x$doc, xpath = xpath, nsMap = ns, num_results = 1)
  if (length(res) == 1) {
     res[[1]]
  } else {
    res
  }
}

#' @export
xml_find_first.xml_nodeset <- function(x, xpath, ns = xml_ns(x)) {
  if (length(x) == 0)
    return(xml_nodeset())

  xml_nodeset(lapply(x, function(x)
      xml_find_first(x, xpath = xpath, ns = ns)), deduplicate = FALSE)
}


#' @export
#' @rdname xml_find_all
xml_find_num <- function(x, xpath, ns = xml_ns(x)) {
  UseMethod("xml_find_num")
}

#' @export
xml_find_num.xml_node <- function(x, xpath, ns = xml_ns(x)) {
  res <- xpath_search(x$node, x$doc, xpath = xpath, nsMap = ns, num_results = Inf)
  if (!is.numeric(res)) {
    stop("result of type: ", sQuote(class(res)), ", not numeric", call. = FALSE)
  }
  res
}

#' @export
xml_find_num.xml_nodeset <- function(x, xpath, ns = xml_ns(x)) {
  if (length(x) == 0)
    return(numeric())

  vapply(x, function(x) xml_find_num(x, xpath = xpath, ns = ns), numeric(1))
}

#' @export
xml_find_num.xml_missing <- function(x, xpath, ns = xml_ns(x)) {
   numeric(0)
}

#' @export
#' @rdname xml_find_all
xml_find_chr <- function(x, xpath, ns = xml_ns(x)) {
  UseMethod("xml_find_chr")
}

#' @export
xml_find_chr.xml_node <- function(x, xpath, ns = xml_ns(x)) {
  res <- xpath_search(x$node, x$doc, xpath = xpath, nsMap = ns, num_results = Inf)
  if (!is.character(res)) {
    stop("result of type: ", sQuote(class(res)), ", not character", call. = FALSE)
  }
  res
}

#' @export
xml_find_chr.xml_nodeset <- function(x, xpath, ns = xml_ns(x)) {
  if (length(x) == 0)
    return(character())

  vapply(x, function(x) xml_find_chr(x, xpath = xpath, ns = ns), character(1))
}

#' @export
xml_find_chr.xml_missing <- function(x, xpath, ns = xml_ns(x)) {
   character(0)
}

#' @export
#' @rdname xml_find_all
xml_find_lgl <- function(x, xpath, ns = xml_ns(x)) {
  UseMethod("xml_find_lgl")
}

#' @export
xml_find_lgl.xml_node <- function(x, xpath, ns = xml_ns(x)) {
  res <- xpath_search(x$node, x$doc, xpath = xpath, nsMap = ns, num_results = Inf)
  if (!is.logical(res)) {
    stop("result of type: ", sQuote(class(res)), ", not logical", call. = FALSE)
  }
  res
}

#' @export
xml_find_lgl.xml_nodeset <- function(x, xpath, ns = xml_ns(x)) {
  if (length(x) == 0)
    return(logical())

  vapply(x, function(x) xml_find_lgl(x, xpath = xpath, ns = ns), logical(1))
}

#' @export
xml_find_lgl.xml_missing <- function(x, xpath, ns = xml_ns(x)) {
   logical(0)
}

# Deprecated functions ----------------------------------------------------

#' @rdname xml_find_all
#' @usage NULL
#' @export
xml_find_one <- function(x, xpath, ns = xml_ns(x)) {
  .Deprecated("xml_find_first")
  UseMethod("xml_find_first")
}
