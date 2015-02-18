#' @useDynLib xml2
#' @importFrom Rcpp sourceCpp
NULL

# document ---------------------------------------------------------------------

xml_document <- function(doc) {
  structure(
    list(
      doc = doc,
      nodes = list(doc_root(doc))
    ),
    class = c("xml_document", "xml_nodeset")
  )
}

#' @export
print.xml_document <- function(x, width = getOption("width"), max_n = 20, ...) {
  cat("{xml_document}\n")
  show_nodes(xml_children(x), width = width, max_n = max_n)
}

# node -------------------------------------------------------------------------

xml_nodeset <- function(nodes, doc) {
  structure(
    list(
      doc = doc,
      nodes = nodes
    ),
    class = "xml_nodeset"
  )
}

#' @export
print.xml_nodeset <- function(x, width = getOption("width"), max_n = 20, ...) {
  n <- length(x$nodes)
  cat("{xml_nodeset (", n, ")}\n", sep = "")

  if (n > 0)
    show_nodes(x, width = width, max_n = max_n)
}

show_nodes <- function(x, width = getOption("width"), max_n = 20) {
  n <- length(x$nodes)
  if (n > max_n) {
    n <- max_n
    trunc <- TRUE
  } else {
    trunc <- FALSE
  }

  label <- format(paste0("[", seq_len(n), "]"), justify = "right")
  contents <- encodeString(vapply(x$nodes, node_format, doc = x$doc,
    FUN.VALUE = character(1)))

  desc <- paste0(label, " ", contents)
  needs_trunc <- nchar(desc) > width
  desc[needs_trunc] <- paste(substr(desc[needs_trunc], 1, width - 3), "...")

  cat(desc, sep = "\n")
  if (trunc) {
    cat("...\n")
  }
}

nodeset_apply <- function(x, fun, ...) {
  out <- lapply(x$nodes, fun, ...)
  out <- unlist(out, recursive = FALSE)
  out <- out[!nodes_duplicated(out)]
  xml_nodeset(out, x$doc)
}

# Subsetting -------------------------------------------------------------------

#' @export
`[.xml_nodeset` <- function(x, i, ...) {
  x$nodes <- x$nodes[i]
  x
}

#' @export
`[[.xml_nodeset` <- function(x, i, ...) {
  xml_nodeset(list(x$nodes[[i]]), x$doc)
}

#' @export
`[[.xml_document` <- function(x, i, ...) {
  xml_contents(x)[[i]]
}

#' @export
`[.xml_document` <- function(x, i, ...) {
  xml_contents(x)[i]
}

# Pretend to be a vector -------------------------------------------------------

#' @export
names.xml_nodset <- function(x) NULL

#' @export
length.xml_nodeset <- function(x) length(x$nodes)

#' @export
length.xml_document <- function(x) node_count_children(x$nodes[[1]])

#' @export
str.xml_nodeset <- function(object, indent.str = " ", ...) {
  cat(indent.str, class(object)[1], "[", length(object), "]\n", sep = "")
}
