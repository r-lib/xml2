if (!file.exists("../windows/libxml2/include/libxml2/libxml")) {
  unlink("../windows", recursive = TRUE)
  url <- if (grepl("aarch", R.version$platform)) {
    "https://github.com/r-windows/bundles/releases/download/libxml2-2.11.5/libxml2-2.11.5-clang-aarch64.tar.xz"
  } else if (grepl("clang", Sys.getenv('R_COMPILED_BY'))) {
    "https://github.com/r-windows/bundles/releases/download/libxml2-2.11.5/libxml2-2.11.5-clang-x86_64.tar.xz"
  } else if (getRversion() >= "4.2") {
    "https://github.com/r-windows/bundles/releases/download/libxml2-2.11.5/libxml2-2.11.5-ucrt-x86_64.tar.xz"
  } else {
    "https://github.com/rwinlib/libxml2/archive/v2.10.3.tar.gz"
  }
  download.file(url, basename(url), quiet = TRUE)
  dir.create("../windows", showWarnings = FALSE)
  untar(basename(url), exdir = "../windows", tar = 'internal')
  unlink(basename(url))
  setwd("../windows")
  file.rename(list.files(), 'libxml2')
}
