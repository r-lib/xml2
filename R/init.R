.onLoad <- function(lib, pkg) {
  .Call(init_libxml2)
}

libxml2_version <- function() {
  as.numeric_version(.Call(libxml2_version_))
}

xml_parse_options <- function() {
  .Call(xml_parse_options_)
}

xml_save_options <- function() {
  .Call(xml_save_options_)
}
