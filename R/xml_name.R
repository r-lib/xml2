#' The (tag) name of an xml element.
#'
#' @param x A document, node, or node set.
#' @param ns Optionally, a named vector giving prefix-url pairs, as produced
#'   by [xml_ns()]. If provided, all names will be explicitly
#'   qualified with the ns prefix, i.e. if the element `bar` is defined
#'   in namespace `foo`, it will be called `foo:bar`. (And
#'   similarly for attributes). Default namespaces must be given an explicit
#'   name. The ns is ignored when using [xml_name<-()] and
#'   [xml_set_name()].
#' @return A character vector.
#' @export
#' @examples
#' x <- read_xml("<bar>123</bar>")
#' xml_name(x)
#'
#' y <- read_xml("<bar><baz>1</baz>abc<foo /></bar>")
#' z <- xml_children(y)
#' xml_name(xml_children(y))
xml_name <- function(x, ns = character()) {
  .Call(node_name, x, ns)
}

#' Modify the (tag) name of an element
#'
#' @param value a character vector with replacement name.
#' @rdname xml_name
#' @export
`xml_name<-` <- function(x, ns = character(), value) {
  UseMethod("xml_name<-")
}

#' @export
`xml_name<-.xml_node` <- function(x, ns = character(), value) {
  .Call(node_set_name, x$node, value)
  x
}

#' @export
`xml_name<-.xml_nodeset` <- function(x, ns = character(), value) {
  if (length(x) == 0) {
    return(x)
  }
  if (!is.list(ns)) {
    ns <- list(ns)
  }
  Map(`xml_name<-`, x, ns, value)
  x
}

#' @export
`xml_name<-.xml_missing` <- function(x, ns = character(), value) {
  x
}

set_name <- function(x, value, ns = character()) {
  xml_name(x = x, ns = ns) <- value
  x
}

#' @rdname xml_name
#' @export
xml_set_name <- function(x, value, ns = character()) {
  UseMethod("xml_set_name")
}

#' @export
xml_set_name.xml_node <- set_name

#' @export
xml_set_name.xml_nodeset <- set_name

#' @export
xml_set_name.xml_missing <- set_name
