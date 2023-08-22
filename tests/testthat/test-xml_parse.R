test_that("download_xml fails if curl is not installed", {
  skip("how to test error with `check_installed()`?")
  mockery::stub(download_xml, "requireNamespace", function(...) FALSE)

  expect_error(
    download_xml("http://httpbin.org/xml"),
    "`curl` must be installed to use `download_xml\\(\\)`"
  )
})

test_that("read_xml errors with an empty document", {
  expect_snapshot_error({read_xml(character())})

  tf <- tempfile()
  file.create(tf)
  on.exit(unlink(tf))

  expect_error(read_xml(tf), "Document is empty")
})

test_that("read_html correctly parses malformed document", {
  lego <- read_html(test_path("lego.html.bz2"))
  expect_equal(length(xml_find_all(lego, ".//p")), 39)
})

test_that("parse_options errors when given an invalid option", {
  expect_error(
    parse_options("INVALID", xml_parse_options()),
    "`options` 'INVALID' is not a valid option"
  )

  expect_error(
    read_html(test_path("lego.html.bz2"), options = "INVALID"),
    "`options` 'INVALID' is not a valid option"
  )

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
  expect_equal(
    as_list(blanks)$html$body$catalog$cd[[1]],
    "\r\n    "
  )

  no_blanks <- read_html(xml2_example("cd_catalog.xml"), options = c("RECOVER", "NOERROR", "NOBLANKS"))

  expect_equal(
    as_list(no_blanks)$html$body$catalog$cd[[1]],
    list("Empire Burlesque")
  )
})

test_that("read_xml works with httr response objects", {
  skip("httpbin is unreliable")
  x <- read_xml(httr::GET("http://httpbin.org/xml"))

  expect_s3_class(x, "xml_document")

  expect_equal(length(xml_find_all(x, "//slide")), 2)
})

test_that("read_xml and read_html fail for bad status codes", {
  skip("httpbin is unreliable")

  expect_error(
    read_xml(httr::GET("http://httpbin.org/status/404")),
    class = "http_404"
  )

  expect_error(
    read_html(httr::GET("http://httpbin.org/status/404")),
    class = "http_404"
  )
})

test_that("read_xml works with raw inputs", {
  x <- read_xml("<foo/>")
  expect_equal(xml_url(x), NA_character_)
})

test_that("read_html works with non-ASCII encodings", {
  tmp <- tempfile()
  on.exit(unlink(tmp))

  writeLines("<html><body>\U2019</body></html>", tmp, useBytes = TRUE)
  res <- read_html(tmp, encoding = "UTF-8")

  expect_equal(
    as.character(res, options = ""),
    "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\" \"http://www.w3.org/TR/REC-html40/loose.dtd\">\n<html><body>\U2019</body></html>\n"
  )
})

test_that("read_xml and read_html fail with > 1 input", {
  expect_snapshot_error({
    read_xml(c("foo", "bar"))
    read_html(c("foo", "bar"))
  })
})
