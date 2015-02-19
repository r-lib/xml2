context("xml_name")

test_that("qualified names returned when ns given", {
  x <- read_xml("ns-multiple-default.xml")
  ns <- xml_ns(x)

  bars <- xml_children(xml_children(x))
  expect_equal(xml_name(bars), c("bar", "bar"))
  expect_equal(xml_name(bars, ns), c("d1:bar", "d2:bar"))
})

test_that("error if missing ns spec", {
  x <- read_xml("ns-multiple-default.xml")
  ns <- xml_ns(x)[1]

  bars <- xml_children(xml_children(x))
  expect_error(xml_name(bars, ns), "Couldn't find prefix")
})
