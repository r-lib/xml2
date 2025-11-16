libxml2_version <- function() {
  as.numeric_version(.Call(libxml2_version_))
}

xml_parse_options <- function() {
  .Call(xml_parse_options_)
}

xml_save_options <- function() {
  .Call(xml_save_options_)
}

download_file_callback <- function(url){
  tmp <- tempfile()
  on.exit(unlink(tmp))
  download.file(url, tmp, quiet = TRUE)
  readBin(tmp, raw(), file.info(tmp)$size)
}
