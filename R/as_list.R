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
#' as_list(read_xml("<foo><bar>a</bar><bar>b</bar></foo>"))
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

#' Coerce xml nodes to a list with better handling duplicate elements
#'
#' This turns an XML document (or node or nodeset) into the equivalent R
#' list. This functions like `as_list()` but ensures elements with duplicate
#' names are put into indexed lists.
#'
#' @inheritParams xml_name
#' @param ... Needed for compatibility with generic. Unused.
#' @export
#'
#' @examples
#' # With duplicate elements
#' xml <- read_xml("<content><x>a</x><x>b</x></content>")
#' lst <- as_list(xml)
#' lst$content$x        # Returns "a" solely
#' lst2 <- as_list2(xml)
#' lst2$content$x       # Returns "a" and "b"
#' lst2$content$x[[1]]  # Returns "a"
#' lst2$content$x[[2]]  # Returns "b"
#'
#' # With attributes preserved
#' xml <- read_xml("<w aa='0'><x a='1' b='2'><y>3</y><z>4</z></x></w>")
#' as_list2(xml)
as_list2 <- function(x, ns = character(), ...) {
  result <- as_list(x, ns = ns, ...)

  if (length(result) == 1 && length(unlist(result)) == 1) {
    item <- unlist(result)
    result <- list(unname(item))
    names(result) <- names(item)
  } else {
    result <- deduplicate(result)
  }
  return(result)
}


#' Deduplicate named elements in a list
#' @param lst A list potentially containing duplicate named elements
#' @return A list with duplicate elements consolidated
#' @export
deduplicate <- function(lst) {
  if (!is.list(lst) || length(lst) == 0 || is.null(names(lst)) || all(names(lst) == "")) {
    return(lst)
  }

  attrs <- attributes(lst)

  nms <- names(lst)

  duplicated_names <- unique(nms[duplicated(nms[nms != ""])])

  if (length(duplicated_names) == 0) {
    # Recursively deal with duplications in the list
    result <- lapply(lst, deduplicate)
    attributes(result) <- attrs
    return(result)
  }

  for (name in duplicated_names) {
    deduplicated_index <- which(nms == name)

    values <- lapply(deduplicated_index, function(i) {
      if (is.list(lst[[i]]) && length(lst[[i]]) == 1 && is.character(lst[[i]][[1]])) {
        return(lst[[i]][[1]])
      } else {
        # Fallback option
        return(lst[[i]])
      }
    })

    lst[[deduplicated_index[1]]] <- values

    if (length(deduplicated_index) > 1) {
      lst <- lst[-deduplicated_index[-1]]
      nms <- nms[-deduplicated_index[-1]]
    }
    names(lst) <- nms
  }

  for (i in seq_along(lst)) {
    if (is.list(lst[[i]]) && !(i %in% which(names(lst) %in% duplicated_names))) {
      lst[[i]] <- deduplicate(lst[[i]])
    }
  }

  attrs$names <- names(lst)
  attributes(lst) <- attrs
  return(lst)
}
