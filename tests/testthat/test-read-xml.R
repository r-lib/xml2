context("read_xml")

test_that("read_html correctly parses malformed document", {
  lego <- read_html("lego.html.bz2")
  expect_equal(length(xml_find_all(lego, ".//p")), 39)
})

test_that("parse_options errors when given an invalid option", {
  expect_error(parse_options("INVALID"),
    "`options` INVALID is not a valid option")

  expect_error(read_html("lego.html.bz2", options = "INVALID"),
    "`options` INVALID is not a valid option")
})

test_that("read_html properly passes parser arguments", {
  blanks <- read_html("cd_catalog.xml.bz2", options = c("RECOVER", "NOERROR"))
  expect_equal(as_list(blanks)$body$catalog$cd[[1]],
    "\r\n    ")

  no_blanks <- read_html("cd_catalog.xml.bz2", options = c("RECOVER", "NOERROR", "NOBLANKS"))

  expect_equal(as_list(no_blanks)$body$catalog$cd[[1]],
    list("Empire Burlesque"))
})
