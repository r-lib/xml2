maybe_error <- function(code, ...) {
  tryCatch(code, error = function(e) expect_error(stop(e), ...))
}
