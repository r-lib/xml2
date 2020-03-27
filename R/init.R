.onLoad <- function(lib, pkg){
  .Call(init_libxml2)
}

libxml2_version <- function() {
  as.numeric_version(.Call(libxml2_version_))
}
