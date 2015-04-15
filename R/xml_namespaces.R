#' XML namespaces.
#'
#' \code{xml_ns} extracts all namespaces from a document, matching each
#' unique namespace url with the prefix it was first associated with. Default
#' namespaces are named \code{d1}, \code{d2} etc. Use \code{xml_ns_rename}
#' to change the prefixes. Once you have a namespace object, you can pass it to
#' other functions to work with fully qualified names instead of local names.
#'
#' @export
#' @inheritParams xml_name
#' @param old,... An existing xml_namespace object followed by name-value
#'   (old prefix-new prefix) pairs to replace.
#' @return A character vector with class \code{xml_namespace} so the
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
  stopifnot(inherits(x, "xml_document"))
  x <- doc_namespaces(x$doc)

  # Number default namespaces
  is_default <- names(x) == ""
  names(x)[is_default] <- paste0("d", seq_len(sum(is_default)))

  # Make prefixes unique
  names(x) <- make.unique(names(x), "")

  class(x) <- "xml_namespace"
  x
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
    stop("Some prefixes [", missing, "] don't already exist.", call. = FALSE)
  }

  names(old)[m] <- new
  old
}
