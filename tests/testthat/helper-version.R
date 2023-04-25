skip_on_http_error <- function(code) {
  tryCatch(
    code,
    http_error = function(x) {
      skip("Request failed")
    }
  )
}
