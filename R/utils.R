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
