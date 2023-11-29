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

#' Wrapper for encodeString() that takes width into consideration
#'
#' encodeString() is relatively expensive to run (see #366), so
#'   avoid doing so to very wide inputs by first trimming inputs
#'   to approximately the correct width, then encoding. A second
#'   round of truncation occurs after encoding to account for
#'   any newly-inserted characters bumping an input too wide.
#' @noRd
encode_with_width <- function(x, width) {
  truncate_raw <- nchar(x) > width
  x[truncate_raw] <- substr(x[truncate_raw], 1L, width - 3L)
  x <- encodeString(x)
  truncate_encoded <- truncate_raw | nchar(x) > width
  x[truncate_encoded] <- paste(substr(x[truncate_encoded], 1L, width - 3L), "...")
  x
}

show_nodes <- function(x, width = getOption("width"), max_n = 20) {
  stopifnot(inherits(x, "xml_nodeset"))

  n <- length(x)
  if (n == 0) {
    return()
  }

  trunc <- n > max_n
  if (trunc) {
    n <- max_n
    x <- x[seq_len(n)]
  }

  label <- format(paste0("[", seq_len(n), "]"), justify = "right")
  contents <- vapply(x, as.character, FUN.VALUE = character(1L))

  desc <- encode_with_width(paste(label, contents), width)

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
