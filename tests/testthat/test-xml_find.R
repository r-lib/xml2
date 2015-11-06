context("xml_find")

# Find one ---------------------------------------------------------------------

test_that("xml_find_one returns empty object if no match", {
  x <- read_xml("<x><y/></x>")
  expect_equal(xml_find_one(x, ".//z"), list())
})

test_that("xml_find_one gives warning if more than one match", {
  x <- read_xml("<x><y/><y/></x>")
  expect_warning(y <- xml_find_one(x, ".//y"), "2 results found, but only returning first 1")
  expect_is(y, "xml_node")
})

# Find all ---------------------------------------------------------------------

test_that("unqualified names don't look in default ns", {
  x <- read_xml("ns-multiple-default.xml")

  expect_equal(length(xml_find_all(x, "//bar")), 0)
})

test_that("qualified names matches to namespace", {
  x <- read_xml("ns-multiple-default.xml")
  ns <- xml_ns(x)

  expect_equal(length(xml_find_all(x, "//d1:bar", ns)), 1)
  expect_equal(length(xml_find_all(x, "//d2:bar", ns)), 1)
})

test_that("warning if unknown namespace", {
  x <- read_xml("<foo><bar /></foo>")
  expect_warning(xml_find_all(x, "//g:bar"), "Undefined namespace prefix")
})

test_that("no matches returns empty nodeset", {
  x <- read_xml("<foo><bar /></foo>")
  expect_equal(length(xml_find_all(x, "//baz")), 0)
})
