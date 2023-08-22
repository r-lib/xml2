path_to_connection <- function(path, check = c("file", "dir")) {
  check <- match.arg(check)

  if (!is.character(path) || length(path) != 1L) {
    return(path)
  }

  if (is_url(path)) {
    if (requireNamespace("curl", quietly = TRUE)) {
      return(curl::curl(path))
    } else {
      return(url(path))
    }
  }

  if (check == "file") {
    path <- check_path(path)
  } else {
    path <- file.path(check_path(dirname(path)), basename(path))
  }
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

check_path <- function(path, call = caller_env()) {
  if (file.exists(path)) {
    return(normalizePath(path, "/", mustWork = FALSE))
  }


  msg <- "{.file {path}} does not exist"
  if (!is_absolute_path(path)) {
    msg <- paste0(msg, " in current working directory ({.path {getwd()}})")
  }
  msg <- paste0(msg, ".")

  cli::cli_abort(msg, call = call)
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
