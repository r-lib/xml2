nodeset_apply <- function(x, fun, ...) UseMethod("nodeset_apply")

#' @export
nodeset_apply.xml_missing <- function(x, fun, ...) {
  xml_nodeset()
}

#' @export
nodeset_apply.xml_nodeset <- function(x, fun, ...) {
  if (length(x) == 0) {
    return(xml_nodeset())
  }

  is_missing <- is.na(x)
  res <- list(length(x))

  res[is_missing] <- list(xml_missing())
  if (any(!is_missing)) {
    res[!is_missing] <- lapply(x[!is_missing], function(x) fun(x$node, ...))
  }

  make_nodeset(res, x[[1]]$doc)
}

#' @export
nodeset_apply.xml_node <- function(x, fun, ...) {
  nodes <- fun(x$node, ...)
  xml_nodeset(lapply(nodes, xml_node, doc = x$doc))
}

#' @export
nodeset_apply.xml_document <- function(x, fun, ...) {
  if (inherits(x, "xml_node")) {
    NextMethod()
  } else {
    xml_nodeset()
  }
}
