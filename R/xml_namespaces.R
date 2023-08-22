#' XML namespaces.
#'
#' `xml_ns` extracts all namespaces from a document, matching each
#' unique namespace url with the prefix it was first associated with. Default
#' namespaces are named `d1`, `d2` etc. Use `xml_ns_rename`
#' to change the prefixes. Once you have a namespace object, you can pass it to
#' other functions to work with fully qualified names instead of local names.
#'
#' @export
#' @inheritParams xml_name
#' @param old,... An existing xml_namespace object followed by name-value
#'   (old prefix-new prefix) pairs to replace.
#' @return A character vector with class `xml_namespace` so the
#'   default display is a little nicer.
#' @examples
#' x <- read_xml('
#'  <root>
#'    <doc1 xmlns = "http://foo.com"><baz /></doc1>
#'    <doc2 xmlns = "http://bar.com"><baz /></doc2>
#'  </root>
#' ')
#' xml_ns(x)
#'
#' # When there are default namespaces, it's a good idea to rename
#' # them to give informative names:
#' ns <- xml_ns_rename(xml_ns(x), d1 = "foo", d2 = "bar")
#' ns
#'
#' # Now we can pass ns to other xml function to use fully qualified names
#' baz <- xml_children(xml_children(x))
#' xml_name(baz)
#' xml_name(baz, ns)
#'
#' xml_find_all(x, "//baz")
#' xml_find_all(x, "//foo:baz", ns)
#'
#' str(as_list(x))
#' str(as_list(x, ns))
xml_ns <- function(x) {
  UseMethod("xml_ns")
}

#' @export
xml_ns.xml_document <- function(x) {
  if (length(x) == 0) {
    return(character())
  }

  stopifnot(inherits(x, "xml_document"))
  doc <- x$doc
  x <- .Call(doc_namespaces, doc)

  # Number default namespaces
  is_default <- names(x) == ""
  names(x)[is_default] <- paste0("d", seq_len(sum(is_default)))

  # Make prefixes unique
  names(x) <- make.unique(names(x), "")

  class(x) <- "xml_namespace"

  x
}

#' @export
xml_ns.xml_node <- function(x) {
  xml_ns(xml_root(x))
}

#' @export
xml_ns.xml_nodeset <- function(x) {
  if (length(x) == 0) {
    return(character())
  }
  xml_ns(x[[1]])
}

#' @export
xml_ns.xml_missing <- function(x) {
  character()
}

#' @export
print.xml_namespace <- function(x, ...) {
  prefix <- format(names(x))

  cat(paste0(prefix, " <-> ", x, collapse = "\n"), "\n", sep = "")
}

#' @export
#' @rdname xml_ns
xml_ns_rename <- function(old, ...) {
  new <- c(...)

  m <- match(names(new), names(old))
  if (any(is.na(m))) {
    missing <- paste(names(new)[is.na(m)], collapse = ", ")
    cli::cli_abort("Some prefixes [{missing}] don't already exist.")
  }

  names(old)[m] <- new
  old
}
