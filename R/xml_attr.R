#' Retrieve an attribute.
#'
#' `xml_attrs()` retrieves all attributes values as a named character
#' vector, `xml_attrs() <-` or `xml_set_attrs()` sets all attribute
#' values. `xml_attr()` retrieves the value of single attribute and
#' `xml_attr() <-` or `xml_set_attr()` modifies its value. If the
#' attribute doesn't exist, it will return `default`, which defaults to
#' `NA`. `xml_has_attr()` tests if an attribute is present.
#'
#' @inheritParams xml_name
#' @param attr Name of attribute to extract.
#' @param default Default value to use when attribute is not present.
#' @return `xml_attr()` returns a character vector. `NA` is used
#'  to represent of attributes that aren't defined.
#'
#'  `xml_has_attr()` returns a logical vector.
#'
#'  `xml_attrs()` returns a named character vector if `x` x is single
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
#'
#' # Can set a single attribute with `xml_attr() <-` or `xml_set_attr()`
#' xml_attr(doc, "id") <- "one"
#' xml_set_attr(doc, "id", "two")
#'
#' # Or set multiple attributes with `xml_attrs()` or `xml_set_attrs()`
#' xml_attrs(doc) <- c("b:id" = "one", "f:id" = "two", "id" = "three")
#' xml_set_attrs(doc, c("b:id" = "one", "f:id" = "two", "id" = "three"))
xml_attr <- function(x, attr, ns = character(), default = NA_character_) {
  .Call(node_attr, x, attr, as.character(default), ns)
}

#' @export
#' @rdname xml_attr
xml_has_attr <- function(x, attr, ns = character()) {
  !is.na(xml_attr(x, attr, ns = ns))
}

#' @export
#' @rdname xml_attr
xml_attrs <- function(x, ns = character()) {
  .Call(node_attrs, x, nsMap = ns)
}

#' @param value character vector of new value.
#' @rdname xml_attr
#' @export
`xml_attr<-` <- function(x, attr, ns = character(), value) {
  UseMethod("xml_attr<-")
}

#' @export
`xml_attr<-.xml_node` <- function(x, attr, ns = character(), value) {
  if (is.null(value)) {
    .Call(node_remove_attr, x$node, attr, ns)
  } else {
    value <- as.character(value)
    .Call(node_set_attr, x$node, attr, value, ns)
  }
  x
}

#' @export
`xml_attr<-.xml_nodeset` <- function(x, attr, ns = character(), value) {
  if (length(x) == 0) {
    return(x)
  }

  if (length(value) == 0) {
    value <- list(value)
  }

  mapply(`xml_attr<-`, x, attr = attr, value = value, SIMPLIFY = FALSE, MoreArgs = list(ns = ns))
  x
}

#' @export
`xml_attr<-.xml_missing` <- function(x, attr, ns = character(), value) {
  x
}

#' @rdname xml_attr
#' @export
xml_set_attr <- function(x, attr, value, ns = character()) {
  UseMethod("xml_set_attr")
}

# This function definition is used for all methods, we need to rearrange the `ns`
# argument to be at the end of the set function
set_attr_fun <- function(x, attr, value, ns = character()) {
  xml_attr(x = x, attr = attr, ns = ns) <- value
}

#' @export
xml_set_attr.xml_node <- set_attr_fun

#' @export
xml_set_attr.xml_nodeset <- set_attr_fun

#' @export
xml_set_attr.xml_missing <- set_attr_fun

#' @rdname xml_attr
#' @export
`xml_attrs<-` <- function(x, ns = character(), value) {
  UseMethod("xml_attrs<-")
}

#' @export
`xml_attrs<-.xml_node` <- function(x, ns = character(), value) {
  if (!is_named(value)) {
    cli::cli_abort("{.arg value} must be a named character vector or `NULL`")
  }

  attrs <- names(value)

  # as.character removes all attributes (including names)
  value <- stats::setNames(as.character(value), attrs)

  current_attrs <- names(xml_attrs(x, ns = ns))

  existing <- intersect(current_attrs, attrs)
  new <- setdiff(attrs, current_attrs)
  removed <- setdiff(current_attrs, attrs)

  # replace existing attributes and add new ones
  Map(function(attr, val) {
    xml_attr(x, attr, ns) <- val
  }, attr = c(existing, new), value[c(existing, new)])


  # Remove attributes which no longer exist
  Map(function(attr) {
    xml_attr(x, attr, ns) <- NULL
  }, attr = removed)

  x
}

#' @export
`xml_attrs<-.xml_nodeset` <- function(x, ns = character(), value) {
  if (length(x) == 0) {
    return(x)
  }
  if (!is.list(ns)) {
    ns <- list(ns)
  }
  if (!is.list(value)) {
    value <- list(value)
  }
  if (!all(vapply(value, is_named, logical(1)))) {
    cli::cli_abort("{.arg {value}} must be a list of named character vectors.")
  }

  Map(`xml_attrs<-`, x, ns, value)

  x
}

#' @export
`xml_attrs<-.xml_missing` <- function(x, ns = character(), value) {
  x
}

#' @rdname xml_attr
#' @export
xml_set_attrs <- function(x, value, ns = character()) {
  UseMethod("xml_set_attrs")
}

# This function definition is used for all methods, we need to rearrange the `ns`
# argument to be at the end of the set function
set_attrs_fun <- function(x, value, ns = character()) {
  xml_attrs(x = x, ns = ns) <- value
}

#' @export
xml_set_attrs.xml_node <- set_attrs_fun

#' @export
xml_set_attrs.xml_nodeset <- set_attrs_fun

#' @export
xml_set_attrs.xml_missing <- set_attrs_fun
