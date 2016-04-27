## Questions
# 1. Assignment methods for xml_missing objects? Error, warning or identity

#' @export
`xml_attr<-` <- function(x, ...) UseMethod("xml_attr<-")

#' @export
`xml_attr<-.xml_node` <- function(x, attr, ns = character(), value) {
  if (is.null(value)) {
    node_remove_attr(x$node, name = attr, nsMap = ns)
  } else {
    node_set_attr(x$node, name = attr, nsMap = ns, value)
  }
  x
}

#' @export
`xml_attr<-.xml_nodeset` <- function(x, attr, ns = character(), value) {
  lapply(x, `xml_attr<-`, attr = attr, ns = ns, value = value)
  x
}

#' @export
`xml_attrs<-` <- function(x, ...) UseMethod("xml_attrs<-")

#' @export
`xml_attrs<-.xml_node` <- function(x, ns = character(), value) {
  if (!is_named_or_null(value)) {
    stop("`value` must be a named character vector or `NULL`", call. = FALSE)
  }

  attrs <- names(value)

  current_attrs <- names(xml_attrs(x, ns = ns))

  existing <- intersect(current_attrs, attrs)
  new <- setdiff(attrs, current_attrs)
  removed <- setdiff(current_attrs, attrs)

  Map(function(attr, val) {
      xml_attr(x, attr, ns) <- val
  }, attr = c(existing, new), value[c(existing, new)])


  Map(function(attr) {
    xml_attr(x, attr, ns) <- NULL
  }, attr = removed)

  x
}

#' @export
`xml_attrs<-.xml_nodeset` <- function(x, ns = character(), value) {
  if (!is.list(value)) {
     value <- list(value)
  }
  if (!all(vapply(value, is_named_or_null, logical(1)))) {
    stop("`value` must be a list of named character vectors")
  }

  for (i in seq_along(x)) {

    # recycle value if necessary
    xml_attrs(x[[i]], ns) <- value[[((i - 1) %% length(value)) + 1]]
  }

  x
}

# @param ns ignored for assignment
#' @export
`xml_name<-` <- function(x, ns = character(), value) {
   UseMethod("xml_name<-")
}

#' @export
`xml_name<-.xml_node` <- function(x, ns = character(), value) {
  node_set_name(x$node, value)
  x
}

#' @export
`xml_name<-.xml_nodeset` <- function(x, ns = character(), value) {
  lapply(x, `xml_name<-`, ns = ns, value)
  x
}
