context("read_xml")

test_that("read_html correctly parses malformed document", {
  lego <- read_html("lego.html.bz2")
  expect_equal(length(xml_find_all(lego, ".//p")), 39)
})
