#' Coerce xml nodes to a list.
#'
#' This turns an XML document (or node or nodeset) into the equivalent R
#' list. Note that this is `as_list()`, not `as.list()`:
#' `lapply()` automatically calls `as.list()` on its inputs, so
#' we can't override the default.
#'
#' `as_list` currently only handles the four most common types of
#' children that an element might have:
#'
#' \itemize{
#'   \item Other elements, converted to lists.
#'   \item Attributes, stored as R attributes. Attributes that have special meanings in R
#'           ([class()], [comment()], [dim()],
#'           [dimnames()], [names()], [row.names()] and
#'           [tsp()]) are escaped with '.'
#'   \item Text, stored as a character vector.
#' }
#'
#' @inheritParams xml_name
#' @param ... Needed for compatibility with generic. Unused.
#' @export
#' @examples
#' as_list(read_xml("<foo> a <b /><c><![CDATA[<d></d>]]></c></foo>"))
#' as_list(read_xml("<foo> <bar><baz /></bar> </foo>"))
#' as_list(read_xml("<foo id = 'a'></foo>"))
#' as_list(read_xml("<foo><bar id='a'/><bar id='b'/></foo>"))
as_list <- function(x, ns = character(), ...) {
  UseMethod("as_list")
}

#' @export
as_list.xml_missing <- function(x, ns = character(), ...) {
  list()
}

#' @export
as_list.xml_document <- function(x, ns = character(), ...) {
  if (!inherits(x, "xml_node")) {
    return(list())
  }

  out <- list(NextMethod())
  names(out) <- xml_name(x)
  out
}

#' @export
as_list.xml_node <- function(x, ns = character(), ...) {
  contents <- xml_contents(x)
  if (length(contents) == 0) {
    # Base case - contents
    type <- xml_type(x)

    if (type %in% c("text", "cdata")) {
      return(xml_text(x))
    }
    if (type != "element" && type != "document") {
      return(paste("[", type, "]"))
    }

    out <- list()
  } else {
    out <- lapply(seq_along(contents), function(i) as_list(contents[[i]], ns = ns))

    nms <- ifelse(xml_type(contents) == "element", xml_name(contents, ns = ns), "")
    if (any(nms != "")) {
      names(out) <- nms
    }
  }

  # Add xml attributes as R attributes
  attributes(out) <- c(list(names = names(out)), xml_to_r_attrs(xml_attrs(x, ns = ns)))

  out
}

#' @export
as_list.xml_nodeset <- function(x, ns = character(), ...) {
  lapply(seq_along(x), function(i) as_list(x[[i]], ns = ns))
}

special_attributes <- c("class", "comment", "dim", "dimnames", "names", "row.names", "tsp")

xml_to_r_attrs <- function(x) {
  if (length(x) == 0) {
    return(NULL)
  }
  # escape special names
  special <- names(x) %in% special_attributes
  names(x)[special] <- paste0(".", names(x)[special])
  as.list(x)
}

r_attrs_to_xml <- function(x) {
  if (length(x) == 0) {
    return(NULL)
  }

  # Drop R special attributes
  x <- x[!names(x) %in% special_attributes]

  # Rename any xml attributes needed
  special <- names(x) %in% paste0(".", special_attributes)

  names(x)[special] <- sub("^\\.", "", names(x)[special])
  x
}
