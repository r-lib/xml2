# Build against static libraries from rwinlib
if(!file.exists("../windows/libxml2-2.10.3/include/libxml2/libxml/parser.h")){
  download.file("https://github.com/rwinlib/libxml2/archive/v2.10.3.zip", "lib.zip", quiet = TRUE)
  dir.create("../windows", showWarnings = FALSE)
  unzip("lib.zip", exdir = "../windows")
  unlink("lib.zip")
}
