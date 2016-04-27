`%||%` <- function(a, b) if (is.null(a)) b else a

is_named <- function(x) {
   nm <- names(x)
  !is.null(nm) && all(nm != "")
}

is_named_or_null <- function(x) {
  is.null(x) || is_named(x)
}
