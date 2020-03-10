library(testthat)
library(xml2)

is_solaris <- tolower(Sys.info()[["sysname"]]) == "sunos"

if (!is_solaris) {
  test_check("xml2")
}
