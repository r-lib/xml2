context("read_xml")

test_that("read_html correctly parses malformed document", {
  lego <- read_html("lego.html.bz2")
  expect_equal(length(xml_find_all(lego, ".//p")), 39)
})

test_that("parse_options errors when given an invalid option", {
  expect_error(parse_options("INVALID", xml_parse_options()),
    "`options` 'INVALID' is not a valid option")

  expect_error(read_html("lego.html.bz2", options = "INVALID"),
    "`options` 'INVALID' is not a valid option")

  # Empty inputs returned as 0
  expect_identical(0L, parse_options("", xml_parse_options()))
  expect_identical(0L, parse_options(NULL, xml_parse_options()))

  # Numerics returned as integers
  expect_identical(12L, parse_options(12L, xml_parse_options()))
  expect_identical(12L, parse_options(12, xml_parse_options()))

  # Multiple inputs summed
  expect_identical(3L, parse_options(c("RECOVER", "NOENT"), xml_parse_options()))
})

test_that("read_html properly passes parser arguments", {

  skip_if_not(libxml2_version() >= "2.9.2")

  blanks <- read_html(xml2_example("cd_catalog.xml"), options = c("RECOVER", "NOERROR"))
  expect_equal(as_list(blanks)$html$body$catalog$cd[[1]],
    "\r\n    ")

  no_blanks <- read_html(xml2_example("cd_catalog.xml"), options = c("RECOVER", "NOERROR", "NOBLANKS"))

  expect_equal(as_list(no_blanks)$html$body$catalog$cd[[1]],
    list("Empire Burlesque"))
})

test_that("read_xml works with httr response objects", {
  skip_on_cran()

  x <- read_xml(httr::GET("http://httpbin.org/xml"))
  expect_is(x, "xml_document")

  expect_equal(length(xml_find_all(x, "//slide")), 2)
})

test_that("read_html works with httr response objects", {
  skip_on_cran()

  x <- read_html(httr::GET("http://httpbin.org/xml"))
  expect_is(x, "xml_document")

  expect_equal(length(xml_find_all(x, "//slide")), 2)
})
