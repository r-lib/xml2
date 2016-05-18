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
