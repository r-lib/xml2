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

to_named_char <- function(x) {
  if (is.character(x)) {
    return(x)
  }

  if (is.list(x)) {
    x <- unlist(x)
  }

  if (!is.character(x)) {
    nms <- names(x)
    x <- as.character(x)
    names(x) <- nms
  }

  x
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
