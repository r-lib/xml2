#' @export
format.xml_node <- function(x, ...) {
  attrs <- xml_attrs(x)
  paste("<",
    paste(
      c(
        xml_name(x),
        format_attributes(attrs)
      ),
      collapse = " "
    ),
    ">",
    sep = ""
  )
}

format_attributes <- function(x) {
  if (length(x) == 0) {
    character(0)
  } else {
    paste(names(x), quote_str(x), sep = "=")
  }
}
