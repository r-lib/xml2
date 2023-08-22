xml_nodeset <- function(nodes = list(), deduplicate = TRUE) {
  if (isTRUE(deduplicate)) {
    nodes <- nodes[!.Call(nodes_duplicated, nodes)]
  }
  class(nodes) <- "xml_nodeset"
  nodes
}

#' @param nodes A list (possible nested) of external pointers to nodes
#' @return a nodeset
#' @noRd
make_nodeset <- function(nodes, doc) {
  nodes <- unlist(nodes, recursive = FALSE)

  xml_nodeset(lapply(nodes, xml_node, doc = doc))
}

#' @export
print.xml_nodeset <- function(x, width = getOption("width"), max_n = 20, ...) {
  n <- length(x)
  cat("{", doc_type(x), "_nodeset (", n, ")}\n", sep = "")

  if (n > 0) {
    show_nodes(x, width = width, max_n = max_n)
  }
}

#' @export
as.character.xml_nodeset <- function(x, ...) {
  vapply(x, as.character, FUN.VALUE = character(1))
}

#' @export
`[.xml_nodeset` <- function(x, i, ...) {
  if (length(x) == 0) {
    return(x)
  }
  xml_nodeset(NextMethod())
}

show_nodes <- function(x, width = getOption("width"), max_n = 20) {
  stopifnot(inherits(x, "xml_nodeset"))

  n <- length(x)
  if (n == 0) {
    return()
  }

  if (n > max_n) {
    n <- max_n
    x <- x[seq_len(n)]
    trunc <- TRUE
  } else {
    trunc <- FALSE
  }

  label <- format(paste0("[", seq_len(n), "]"), justify = "right")
  contents <- encodeString(vapply(x, as.character, FUN.VALUE = character(1)))

  desc <- paste0(label, " ", contents)
  needs_trunc <- nchar(desc) > width
  desc[needs_trunc] <- paste(substr(desc[needs_trunc], 1, width - 3), "...")

  cat(desc, sep = "\n")
  if (trunc) {
    cat("...\n")
  }
  invisible()
}

#' @export
is.na.xml_nodeset <- function(x) {
  vapply(x, is.na, logical(1))
}
