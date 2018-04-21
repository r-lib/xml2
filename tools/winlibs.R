# Build against static libraries from rwinlib
VERSION <- commandArgs(TRUE)
if(!file.exists(sprintf("../windows/libxml2-%s/include/libxml2/libxml/parser.h", VERSION))){
  if(getRversion() < "3.3.0") setInternet2()
  download.file(sprintf("https://github.com/rwinlib/libxml2/archive/v%s.zip", VERSION), "lib.zip", quiet = TRUE)
  dir.create("../windows", showWarnings = FALSE)
  unzip("lib.zip", exdir = "../windows")
  unlink("lib.zip")
}
