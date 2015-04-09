#' @useDynLib xml2
#' @importFrom Rcpp sourceCpp
NULL

# node -------------------------------------------------------------------------

xml_node <- function(node, doc) {
  structure(list(node = node, doc = doc), class = "xml_node")
}

#' @export
as.character.xml_node <- function(x, ...) {
  node_format(x$doc, x$node)
}

#' @export
print.xml_node <- function(x, width = getOption("width"), max_n = 20, ...) {
  cat("{xml_node}\n")
  cat("<", xml_name(x), ">\n", sep = "")
  show_nodes(xml_children(x), width = width, max_n = max_n)
}

# document ---------------------------------------------------------------------

xml_document <- function(doc) {
  x <- xml_node(doc_root(doc), doc)
  class(x) <- c("xml_document", class(x))
  x
}

#' @export
print.xml_document <- function(x, width = getOption("width"), max_n = 20, ...) {
  cat("{xml_document}\n")
  cat("<", xml_name(x), ">\n", sep = "")
  show_nodes(xml_children(x), width = width, max_n = max_n)
}

#' @export
as.character.xml_document <- function(x, ...) {
  doc_format(x$doc)
}

# nodeset ----------------------------------------------------------------------

xml_nodeset <- function(nodes = list()) {
  structure(nodes, class = "xml_nodeset")
}

#' @param nodes A list (possible nested) of external pointers to nodes
#' @return a nodeset
#' @noRd
make_nodeset <- function(nodes, doc) {
  nodes <- unlist(nodes, recursive = FALSE)
  nodes <- nodes[!nodes_duplicated(nodes)]

  xml_nodeset(lapply(nodes, xml_node, doc = doc))
}

#' @export
print.xml_nodeset <- function(x, width = getOption("width"), max_n = 20, ...) {
  n <- length(x)
  cat("{xml_nodeset (", n, ")}\n", sep = "")

  if (n > 0)
    show_nodes(x, width = width, max_n = max_n)
}

#' @export
as.character.xml_nodeset <- function(x, ...) {
  vapply(x, as.character, FUN.VALUE = character(1))
}

#' @export
`[.xml_nodeset` <- function(x, i, ...) {
  xml_nodeset(NextMethod())
}

show_nodes <- function(x, width = getOption("width"), max_n = 20) {
  stopifnot(inherits(x, "xml_nodeset"))

  n <- length(x)
  if (n == 0)
    return()

  if (n > max_n) {
    n <- max_n
    x <- x[seq_len(n)]
    trunc <- TRUE
  } else {
    trunc <- FALSE
  }

  label <- format(paste0("[", seq_len(n), "]"), justify = "right")
  contents <- encodeString(vapply(x, function(x) node_format(x$doc, x$node),
    FUN.VALUE = character(1)))

  desc <- paste0(label, " ", contents)
  needs_trunc <- nchar(desc) > width
  desc[needs_trunc] <- paste(substr(desc[needs_trunc], 1, width - 3), "...")

  cat(desc, sep = "\n")
  if (trunc) {
    cat("...\n")
  }
}


nodeset_apply <- function(x, fun, ...) UseMethod("nodeset_apply")

#' @export
nodeset_apply.xml_nodeset <- function(x, fun, ...) {
  if (length(x) == 0)
    return(xml_nodeset())

  make_nodeset(lapply(x, function(x) fun(x$node, ...)), x[[1]]$doc)
}

#' @export
nodeset_apply.xml_node <- function(x, fun, ...) {
  nodes <- fun(x$node, ...)
  xml_nodeset(lapply(nodes, xml_node, doc = x$doc))
}
