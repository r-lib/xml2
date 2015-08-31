# Build against libxml2 from Rtools
if (!file.exists("../windows/libxml2-2.9.2/include/libxml/parser.h")) {
  if(getRversion() < "3.3.0") setInternet2()
  download.file("https://github.com/rwinlib/libxml2/archive/v2.9.2.zip", "lib.zip", quiet = TRUE)
  dir.create("../windows", showWarnings = FALSE)
  unzip("lib.zip", exdir = "../windows")
  unlink("lib.zip")
}
