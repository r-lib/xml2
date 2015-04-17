.onUnload <- function(libpath) {
  gc() # trigger finalisers
  library.dynam.unload("xml2", libpath)
}
