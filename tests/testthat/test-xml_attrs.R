context("xml_attrs")

test_that("missing attributes returned as NA by default", {
  x <- read_xml("<x/>")
  expect_equal(xml_attr(x, "id"), NA_character_)
})

test_that("missing attributes returned as NA", {
  x <- read_xml("<x/>")
  expect_equal(xml_attr(x, "id", default = 1), "1")
})

# Namespaces -------------------------------------------------------------------

# Default namespace doesn't apply to attributes

test_that("qualified names returned when ns given", {
  x <- read_xml("ns-multiple.xml")
  ns <- xml_ns(x)

  bars <- xml_children(xml_children(x))
  attr <- xml_attrs(bars, ns)

  expect_equal(names(attr[[1]]), "f:id")
  expect_equal(names(attr[[2]]), "g:id")
})


x <- read_xml('
 <root xmlns:b="http://bar.com" xmlns:f="http://foo.com">
   <doc b:id="b" f:id="f" id="" />
 </root>
')
doc <- xml_children(x)[[1]]
ns <- xml_ns(x)

test_that("qualified attributes get own values", {
  expect_equal(xml_attrs(doc, ns), c("b:id" = "b", "f:id" = "f", "id" = ""))
})

test_that("unqualified name gets unnamespace attribute", {
  expect_equal(xml_attr(doc, "id", ns), "")
})

test_that("namespace names gets namespaced attribute", {
  expect_equal(xml_attr(doc, "b:id", ns), "b")
  expect_equal(xml_attr(doc, "f:id", ns), "f")
})
