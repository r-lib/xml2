#' @useDynLib xml2
#' @importFrom Rcpp sourceCpp
NULL

# node -------------------------------------------------------------------------

xml_node <- function(node = NULL, doc = NULL) {
  if (inherits(node, "xml_node")) {
    node
  } else {
    structure(list(node = node, doc = doc), class = "xml_node")
  }
}

#' @export
as.character.xml_node <- function(x, ...) {
  node_format_xml(x$doc, x$node)
}

#' @export
print.xml_node <- function(x, width = getOption("width"), max_n = 20, ...) {
  cat("{xml_node}\n")
  cat(format(x), "\n", sep = "")
  show_nodes(xml_children(x), width = width, max_n = max_n)
}

#' @export
print.xml_missing <- function(x, width = getOption("width"), max_n = 20, ...) {
  cat("{xml_missing}\n")
  cat(format(x), "\n", sep = "")
}

# document ---------------------------------------------------------------------

xml_document <- function(doc) {
  if (doc_has_root(doc)) {
    x <- xml_node(doc_root(doc), doc)
    class(x) <- c("xml_document", class(x))
    x
  } else {
    structure(list(doc = doc), class = "xml_document")
  }
}

#' @export
print.xml_document <- function(x, width = getOption("width"), max_n = 20, ...) {
  doc <- xml_document(x$doc)
  cat("{xml_document}\n")
  if (inherits(doc, "xml_node")) {
    cat(format(doc), "\n", sep = "")
    show_nodes(xml_children(doc), width = width, max_n = max_n)
  }
}

#' @export
as.character.xml_document <- function(x, ...) {
  doc_format_xml(x$doc)
}

# nodeset ----------------------------------------------------------------------

xml_nodeset <- function(nodes = list()) {
  nodes <- nodes[!nodes_duplicated(nodes)]
  structure(nodes, class = "xml_nodeset")
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
  if (length(x) == 0) {
    return(x)
  }
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


nodeset_apply <- function(x, fun, ...) UseMethod("nodeset_apply")

#' @export
nodeset_apply.xml_missing <- function(x, fun, ...) {
  xml_nodeset()
}

#' @export
nodeset_apply.xml_nodeset <- function(x, fun, ...) {
  if (length(x) == 0)
    return(xml_nodeset())

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

#' @export
format.xml_node <- function(x, ...) {
  attrs <- xml_attrs(x)
  paste("<",
    paste(
      c(xml_name(x),
        format_attributes(attrs)),
      collapse = " "),
    ">", sep = "")
}

format_attributes <- function(x) {
  if (length(x) == 0) {
    character(0)
  } else {
    paste(names(x), quote_str(x), sep = "=")
  }
}

#' Construct an missing xml object
#' @export
#' @keywords internal
xml_missing <- function() {
  structure(list(), class = "xml_missing")
}

#' @export
is.na.xml_missing <- function(x) {
  TRUE
}

#' @export
is.na.xml_nodeset <- function(x) {
  vapply(x, is.na, logical(1))
}

#' @export
is.na.xml_node <- function(x) {
  FALSE
}

format.xml_missing <- function(x, ...) {
  "<NA>"
}

#' @export
as.character.xml_missing <- function(x, ...) {
  NA_character_
}

# These mimic the behavior of NA[[1]], NA[[2]], NA[1], NA[2]

#' @export
`[.xml_missing` <- function(x, i, ...) x

#' @export
`[[.xml_missing` <- function(x, i, ...) if (i == 1L) x else stop("subscript out of bounds")

#' Construct a cdata node
#' @param content The CDATA content, does not include \code{<![CDATA[}
#' @examples
#' x <- xml_new_root("root")
#' xml_add_child(x, xml_cdata("<d/>"))
#' as.character(x)
#' @export
xml_cdata <- function(content) {
  structure(content, class = "xml_cdata")
}

#' Construct a comment node
#' @param content The comment content
#' @examples
#' x <- xml_new_document()
#' r <- xml_add_child(x, "root")
#' xml_add_child(r, xml_comment("Hello!"))
#' as.character(x)
#' @export
xml_comment <- function(content) {
  structure(content, class = "xml_comment")
}
