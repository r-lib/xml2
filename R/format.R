#' @export
format.xml_node <- function(x, ...) {
  attrs <- xml_attrs(x)
  paste0("<",
    paste(
      c(
        xml_name(x),
        format_attributes(attrs)
      ),
      collapse = " "
    ),
    ">"
  )
}

format_attributes <- function(x) {
  if (length(x) == 0) {
    character(0)
  } else {
    paste(names(x), quote_str(x), sep = "=")
  }
}
