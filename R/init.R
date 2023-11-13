.onLoad <- function(lib, pkg) {
  init_libxml2()
}

libxml2_version <- function() {
  as.numeric_version(libxml2_version_())
}

xml_parse_options <- function() {
  xml_parse_options_()
}

xml_save_options <- function() {
  xml_save_options_()
}
