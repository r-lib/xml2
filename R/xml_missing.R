#' Construct an missing xml object
#' @export
#' @keywords internal
xml_missing <- function() {
  out <- list()
  class(out) <- "xml_missing"
  out
}

format.xml_missing <- function(x, ...) {
  "<NA>"
}

#' @export
print.xml_missing <- function(x, width = getOption("width"), max_n = 20, ...) {
  cat("{xml_missing}\n")
  cat(format(x), "\n", sep = "")
}

#' @export
as.character.xml_missing <- function(x, ...) {
  NA_character_
}

# These mimic the behavior of NA[[1]], NA[[2]], NA[1], NA[2]

#' @export
`[.xml_missing` <- function(x, i, ...) x

#' @export
`[[.xml_missing` <- function(x, i, ...) if (i == 1L) x else abort("subscript out of bounds")

#' @export
is.na.xml_missing <- function(x) {
  TRUE
}
