path_to_connection <- function(path) {
  if (!is.character(path))
    return(path)

  if (is_url(path)) {
    if (requireNamespace("curl", quietly = TRUE)) {
      return(curl::curl(path))
    } else {
      return(url(path))
    }
  }

  path <- check_path(path)
  switch(tools::file_ext(path),
    gz = gzfile(path, ""),
    bz2 = bzfile(path, ""),
    xz = xzfile(path, ""),
    zip = zipfile(path, ""),
    path
  )
}

is_url <- function(path) {
  grepl("^(http|ftp)s?://", path)
}

check_path <- function(path) {
  if (file.exists(path))
    return(normalizePath(path, "/", mustWork = FALSE))

  stop("'", path, "' does not exist",
    if (!is_absolute_path(path))
      paste0(" in current working directory ('", getwd(), "')"),
    ".",
    call. = FALSE
  )
}

is_absolute_path <- function(path) {
  grepl("^(/|[A-Za-z]:|\\\\|~)", path)
}

zipfile <- function(path, open = "r") {
  files <- utils::unzip(path, list = TRUE)
  file <- files$Name[[1]]

  if (nrow(files) > 1) {
    message("Multiple files in zip: reading '", file, "'")
  }

  unz(path, file, open = open)
}
