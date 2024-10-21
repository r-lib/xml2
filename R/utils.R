`%||%` <- function(a, b) if (is.null(a)) b else a

is_named <- function(x) {
  all(has_names(x))
}

has_names <- function(x) {
  nms <- names(x)
  if (is.null(nms)) {
    rep(FALSE, length(x))
  } else {
    !(is.na(nms) | nms == "")
  }
}

# non smart quote version of sQuote
quote_str <- function(x, quote = "\"") {
  if (!length(x)) {
    return(character(0))
  }

  paste0(quote, x, quote)
}

# Format the C bitwise flags for display in Rd. The input object is a named
# integer vector with a 'descriptions' character vector attribute that
# corresponds to each flag.
describe_options <- function(x) {
  paste0(
    "\\describe{\n",
    paste0("  \\item{", names(x), "}{", attr(x, "descriptions"), "}", collapse = "\n"),
    "\n}"
  )
}

s_quote <- function(x) paste0("'", x, "'")

# Similar to match.arg, but returns character() with NULL or empty input and
# errors if any of the inputs are not found (fixing
# https://bugs.r-project.org/bugzilla3/show_bug.cgi?id=16659)
parse_options <- function(arg, options, error_call = caller_env()) {
  if (is.numeric(arg)) {
    return(as.integer(arg))
  }

  if (is.null(arg) || !any(nzchar(arg))) {
    return(0L)
  }

  # set duplicates.ok = TRUE so any duplicates are counted differently than
  # non-matches, then take only unique results
  i <- pmatch(arg, names(options), duplicates.ok = TRUE)
  if (anyNA(i)) {
    cli::cli_abort(c(
      x = "{.arg options} {.val {arg[is.na(i)][1L]}} is not a valid option.",
      i = "Valid options are one of {.or {.val {names(options)}}}.",
      i = "See {.help [read_html](xml2::read_html)} for all options."
    ),
    call = error_call)
  }
  sum(options[unique(i)])
}

#' Get path to a xml2 example
#'
#' xml2 comes bundled with a number of sample files in its \sQuote{inst/extdata}
#' directory. This function makes them easy to access.
#' @param path Name of file. If `NULL`, the example files will be listed.
#' @export
xml2_example <- function(path = NULL) {
  if (is.null(path)) {
    dir(system.file("extdata", package = "xml2"))
  } else {
    system.file("extdata", path, package = "xml2", mustWork = TRUE)
  }
}
