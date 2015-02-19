#' XML namespaces.
#'
#' \code{xml_ns} extracts all namespaces from a document, matching each
#' unique namespace url with the prefix it was first associated with. Default
#' namespaces are named \code{d1}, \code{d2} etc. Use \code{xml_ns_rename}
#' to change the prefixes.
#'
#' @export
#' @inheritParams xml_name
#' @param old,... An existing xml_namespace object followed by name-value
#'   (old prefix-new prefix) pairs to replace.
#' @return A character vector with class \code{xml_namespace} so the
#'   default display is a little nicer.
xml_ns <- function(x) {
  x <- doc_namespaces(x$doc)

  # Number default namespaces
  is_default <- is.na(names(x))
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
