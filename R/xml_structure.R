#' Show the structure of an html/xml document.
#'
#' Show the structure of an html/xml document without displaying any of
#' the values. This is useful if you want to get a high level view of the
#' way a document is organised.
#'
#' @param x HTML/XML document (or part there of)
#' @param indent Number of spaces to ident
#' @export
#' @examples
#' xml_structure(xml("<a><b><c/><c/></b><d/></a>"))
#'
#' rproj <- read_html(system.file("extdata","r-project.html", package = "xml2"))
#' xml_structure(rproj)
#' xml_structure(xml_find_all(rproj, ".//p"))
xml_structure <- function(x, indent = 2) {
  UseMethod("xml_structure")
}

#' @export
xml_structure.xml_nodeset <-  function(x, indent = 2) {
  for (i in seq_along(x)) {
    cat("[[", i, "]]\n", sep = "")
    print_xml_structure(x[[i]], indent = indent)
    cat("\n")
  }

  invisible()
}

#' @export
xml_structure.xml_node <-  function(x, indent = 2) {
    print_xml_structure(x, indent = indent)

    invisible()
}

print_xml_structure <- function(x, prefix = 0, indent = 2) {
  padding <- paste(rep(" ", prefix), collapse = "")
  type <- xml_type(x)

  if (type == "element") {
    attr <- xml_attrs(x)
    if (length(attr) > 0) {
      attr_str <- paste0(" [", paste0(names(attr), collapse = ", "), "]")
    } else {
      attr_str <- ""
    }

    node <- paste0("<", xml_name(x), attr_str, ">")

    cat(padding, node, "\n", sep = "")
    lapply(xml_contents(x),
      print_xml_structure, prefix = prefix + indent, indent = indent)
  } else {
    cat(padding, "{", type, "}\n", sep = "")
  }
}
