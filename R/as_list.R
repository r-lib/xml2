#' Coerce xml nodes to a list.
#'
#' This turns an XML document (or node or nodeset) into the equivalent R
#' list. Note that this is \code{as_list()}, not \code{as.list()}:
#' \code{lapply()} automatically calls \code{as.list()} on its inputs, so
#' we can't override the default.
#'
#' \code{as_list} currently only handles the four most common types of
#' children that an element might have:
#'
#' \itemize{
#'   \item Other elements, converted to lists.
#'   \item Attributes, stored as R attributes.
#'   \item Text, stored as a character vector.
#' }
#'
#' @inheritParams xml_name
#' @param ... Needed for compatability with generic. Unused.
#' @export
#' @examples
#' as_list(xml("<foo> a <b /><c><![CDATA[<d></d>]]></c></foo>"))
#' as_list(xml("<foo> <bar><baz /></bar> </foo>"))
#' as_list(xml("<foo id = 'a'></foo>"))
#' as_list(xml("<foo><bar id='a'/><bar id='b'/></foo>"))
as_list <- function(x, ns = character(), ...) {
  if (length(x$nodes) > 1) {
    # Deal with nodesets
    return(lapply(seq_along(x), function(i) as.list(x[[i]], ns = ns)))
  }

  contents <- xml_contents(x)
  if (length(contents) == 0) {
    # Base case - contents
    type <- xml_type(x)

    if (type %in% c("text", "cdata"))
      return(xml_text(x))
    if (type != "element" && type != "document")
      return(paste("[", type, "]"))

    out <- list()
  } else {
    out <- lapply(seq_along(contents), function(i) as.list(contents[[i]], ns = ns))

    nms <- ifelse(xml_type(contents) == "element", xml_name(contents, ns = ns), "")
    if (any(nms != "")) {
      names(out) <- nms
    }
  }

  # Add attributes as .attr element - that's an invalid xml attribute name
  # so there shouldn't be a clash.
  attr <- xml_attrs(x, ns = ns)[[1]]
  if (length(attr) > 0)
    attributes(out) <- as.list(attr)

  out
}
