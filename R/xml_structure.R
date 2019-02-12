#' Show the structure of an html/xml document.
#'
#' Show the structure of an html/xml document without displaying any of
#' the values. This is useful if you want to get a high level view of the
#' way a document is organised. Compared to \code{xml_structure},
#' \code{html_structure} prints the id and class attributes.
#'
#' @param x HTML/XML document (or part there of)
#' @param indent Number of spaces to ident
#' @param ... Arguments (excluding \code{sep}) to be passed to \code{\link[base]{cat}}
#' @export
#' @examples
#' xml_structure(read_xml("<a><b><c/><c/></b><d/></a>"))
#'
#' rproj <- read_html(system.file("extdata","r-project.html", package = "xml2"))
#' xml_structure(rproj)
#' xml_structure(xml_find_all(rproj, ".//p"))
#'
#' h <- read_html("<body><p id = 'a'></p><p class = 'c d'></p></body>")
#' html_structure(h)
xml_structure <- function(x, indent = 2L, ...) {
  tree_structure(x, indent = indent, html = FALSE, ...)
}

#' @export
#' @rdname xml_structure
html_structure <- function(x, indent = 2L, ...) {
  tree_structure(x, indent = indent, html = TRUE, ...)
}

tree_structure <- function(x, indent = 2L, html = FALSE, ...) {
  UseMethod("tree_structure")
}

#' @export
tree_structure.xml_missing <- function(x, indent = 2L, html = FALSE, ...) {
  NA_character_
}

#' @export
tree_structure.xml_nodeset <- function(x, indent = 2L, html = FALSE, ...) {
  for (i in seq_along(x)) {
    cat("[[", i, "]]\n", sep = "", ...)
    print_xml_structure(x[[i]], indent = indent, html = html, ...)
    cat("\n", ...)
  }

  invisible()
}

#' @export
tree_structure.xml_node <-  function(x, indent = 2L, html = FALSE, ...) {
  print_xml_structure(x, indent = indent, html = html, ...)
  invisible()
}

print_xml_structure <- function(x, prefix = 0L, indent = 2L, html = FALSE, ...) {
  padding <- paste(rep.int(" ", prefix), collapse = "")
  type <- xml_type(x)

  if (type == "element") {

    attr <- xml_attrs(x)
    if (html) {
      html_attrs <- list()
      if ("id" %in% names(attr)) {
        html_attrs$id <- paste0("#", attr[["id"]])
        attr <- attr[setdiff(names(attr), "id")]
      }

      if ("class" %in% names(attr)) {
        html_attrs$class <- paste0(".", gsub(" ", ".", attr[["class"]], fixed = TRUE))
        attr <- attr[setdiff(names(attr), "class")]
      }

      attr_str <- paste(unlist(html_attrs), collapse = " ")
    } else {
      attr_str <- ""
    }

    if (length(attr) > 0L) {
      attr_str <- paste0(attr_str, " [", paste0(names(attr), collapse = ", "), "]")
    }

    node <- paste0("<", xml_name(x), attr_str, ">")

    cat(padding, node, "\n", sep = "", ...)
    lapply(xml_contents(x), print_xml_structure, prefix = prefix + indent,
      indent = indent, html = html, ...)
  } else {
    cat(padding, "{", type, "}\n", sep = "", ...)
  }
}
