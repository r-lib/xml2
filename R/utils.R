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

is_installed <- function(pkg) {
  requireNamespace(pkg, quietly = TRUE)
}

need_package <- function(pkg) {
  if (is_installed(pkg)) return(invisible())

  stop("Please install ", pkg, " package", call. = FALSE)
}

# Format the C bitwise flags for display in Rd. The input object is a named
# integer vector with a 'description' character vector attribute that
# corresponds to each flag.
describe_options <- function(x) {
  paste0("\\describe{\n",
    paste0("  \\item{", names(x), "}{", attr(x, "description"), "}", collapse = "\n"),
  "\n}")
}
