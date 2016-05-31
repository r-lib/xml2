context("format")
test_that("format.xml_node prints attributes for root nodes", {

  x <- read_xml("<parent foo = 'bar' />")
  expect_equal(format(x), "<parent foo=\"bar\">")
})
test_that("format.xml_node prints namespaces for root nodes", {

  x <- read_xml("<parent/>")
  expect_equal(format(x), "<parent>")

  y <- read_xml("<parent xmlns = 'tag:james.f.hester@gmail.com,2016:bar' />")
  expect_equal(format(y), "<parent xmlns=\"tag:james.f.hester@gmail.com,2016:bar\">")

  z <- read_xml("<parent xmlns:foo = 'tag:james.f.hester@gmail.com,2016:bar' />")
  expect_equal(format(z), "<parent xmlns:foo=\"tag:james.f.hester@gmail.com,2016:bar\">")
})
