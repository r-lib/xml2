#' Find nodes that match an xpath expression.
#'
#' Xpath is like regular expressions for trees - it's worth learning if
#' you're trying to extract nodes from arbitrary locations in a document.
#' Use \code{xml_find_all} to find all matches - if there's no match you'll
#' get an empty result. Use \code{xml_find_one} to find a specific match -
#' if there's no match you'll get an error.
#'
#' @param xpath A string containing a xpath (1.0) expression.
#' @inheritParams xml_name
#' @return \code{xml_find_all} always returns a nodeset: if there are no matches
#'   the nodeset will be empty. The result will always be unique; repeated
#'   nodes are automatically de-duplicated.
#'
#'   \code{xml_find_one} returns a node if applied to a node, and a nodeset
#'   if applied to a nodeset. The output is \emph{always} the same size as
#'   the input. If there are no matches, \code{xml_find_one} will throw an
#'   error; if there are multiple matches, it will use the first with a warning.
#' @export
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
#'</body>")
#' para <- xml_find_all(x, ".//p")
#'
#' # If you apply xml_find_all to a nodeset, it finds all matches,
#' # de-duplicates them, and returns as a single list. This means you
#' # never know how many results you'll get
#' xml_find_all(para, ".//b")
#'
#' # xml_find_one only returns one match per input node. If there are 0
#' # matches it will throw an error; if there are more than one it picks
#' # the first with a warning
#' xml_find_one(para, ".//b")
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
xml_find_all <- function(x, xpath, ns = character()) {
  UseMethod("xml_find_all")
}

#' @export
xml_find_all.xml_node <- function(x, xpath, ns = character()) {
  nodes <- node_find_all(x$node, x$doc, xpath = xpath, nsMap = ns)
  make_nodeset(nodes, x$doc)
}

#' @export
xml_find_all.xml_nodeset <- function(x, xpath, ns = character()) {
  if (length(x) == 0)
    return(xml_nodeset())

  nodes <- lapply(x, function(x) node_find_all(x$node, x$doc, xpath = xpath, nsMap = ns))
  make_nodeset(nodes, x[[1]]$doc)
}

#' @export
#' @rdname xml_find_all
xml_find_one <- function(x, xpath, ns = character()) {
  UseMethod("xml_find_one")
}

#' @export
xml_find_one.xml_node <- function(x, xpath, ns = character()) {
  node <- node_find_one(x$node, x$doc, xpath = xpath, nsMap = ns)
  xml_node(node, x$doc)
}

#' @export
xml_find_one.xml_nodeset <- function(x, xpath, ns = character()) {
  if (length(x) == 0)
    return(xml_nodeset())

  nodes <- lapply(x, function(x) node_find_one(x$node, x$doc, xpath = xpath, nsMap = ns))
  xml_nodeset(lapply(nodes, function(y) xml_node(y, x[[1]]$doc)))
}
