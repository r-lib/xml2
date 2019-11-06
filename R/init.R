.onLoad <- function(lib, pkg){
  init_libxml2()
}

libxml2_version <- function() {
  as.numeric_version(libxml2_version_())
}
