context("xml_find")

test_that("unqualified names don't look in default ns", {
  x <- read_xml("ns-multiple-default.xml")

  expect_equal(length(xml_find(x, "//bar")), 0)
})

test_that("qualified names matches to namespace", {
  x <- read_xml("ns-multiple-default.xml")
  ns <- xml_ns(x)

  expect_equal(length(xml_find(x, "//d1:bar", ns)), 1)
  expect_equal(length(xml_find(x, "//d2:bar", ns)), 1)
})

test_that("warning if unknown namespace", {
  x <- xml("<foo><bar /></foo>")
  expect_warning(xml_find(x, "//g:bar"), "Undefined namespace prefix")
})

test_that("no matches returns empty nodeset", {
  x <- xml("<foo><bar /></foo>")
  expect_equal(length(xml_find(x, "//baz")), 0)
})
