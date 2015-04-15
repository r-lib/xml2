#' Retrieve an attribute.
#'
#' \code{xml_attrs()} retrieves all attributes values as a named character
#' vector. \code{xml_attr()} retrieves the value of single attribute. If the
#' attribute doesn't exist, it will return \code{default}, which defaults to
#' \code{NA}. \code{xml_has_attr()} tests if an attribute is present.
#'
#' @inheritParams xml_name
#' @param attr Name of attribute to extract.
#' @param default Default value to use when attribute is not present.
#' @return \code{xml_attr()} returns a character vector. \code{NA} is used
#'  to represent of attributes that aren't defined.
#'
#'  \code{xml_has_attr()} returns a logical vector.
#'
#'  \code{xml_attrs()} returns a named character vector if \code{x} x is single
#'  node, or a list of character vectors if given a nodeset
#' @export
#' @examples
#' x <- read_xml("<root id='1'><child id ='a' /><child id='b' d='b'/></root>")
#' xml_attr(x, "id")
#' xml_attr(x, "apple")
#' xml_attrs(x)
#'
#' kids <- xml_children(x)
#' kids
#' xml_attr(kids, "id")
#' xml_has_attr(kids, "id")
#' xml_attrs(kids)
#'
#' # Missing attributes give missing values
#' xml_attr(xml_children(x), "d")
#' xml_has_attr(xml_children(x), "d")
#'
#' # If the document has a namespace, use the ns argument and
#' # qualified attribute names
#' x <- read_xml('
#'  <root xmlns:b="http://bar.com" xmlns:f="http://foo.com">
#'    <doc b:id="b" f:id="f" id="" />
#'  </root>
#' ')
#' doc <- xml_children(x)[[1]]
#' ns <- xml_ns(x)
#'
#' xml_attrs(doc)
#' xml_attrs(doc, ns)
#'
#' # If you don't supply a ns spec, you get the first matching attribute
#' xml_attr(doc, "id")
#' xml_attr(doc, "b:id", ns)
#' xml_attr(doc, "id", ns)
xml_attr <- function(x, attr, ns = character(), default = NA_character_) {
  UseMethod("xml_attr")
}

#' @export
xml_attr.xml_node <- function(x, attr, ns = character(),
                              default = NA_character_) {
  node_attr(x$node, name = attr, missing = default, nsMap = ns)
}

#' @export
xml_attr.xml_nodeset <- function(x, attr,  ns = character(),
                                 default = NA_character_) {
  vapply(x, xml_attr, attr = attr, default = default, ns = ns,
    FUN.VALUE = character(1))
}

#' @export
#' @rdname xml_attr
xml_has_attr <- function(x, attr, ns = character()) {
  !is.na(xml_attr(x, attr, ns = ns))
}

#' @export
#' @rdname xml_attr
xml_attrs <- function(x, ns = character()) UseMethod("xml_attrs")

#' @export
xml_attrs.xml_node <- function(x, ns = character()) {
  node_attrs(x$node, nsMap = ns)
}

#' @export
xml_attrs.xml_nodeset <- function(x, ns = character()) {
  lapply(x, xml_attrs, ns = ns)
}
