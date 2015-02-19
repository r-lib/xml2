context("xml_attrs")

# Default namespace doesn't apply to attributes

test_that("qualified names returned when ns given", {
  x <- read_xml("ns-multiple.xml")
  ns <- xml_ns(x)

  bars <- xml_children(xml_children(x))
  attr <- xml_attrs(bars, ns)

  expect_equal(names(attr[[1]]), "f:id")
  expect_equal(names(attr[[2]]), "g:id")
})
