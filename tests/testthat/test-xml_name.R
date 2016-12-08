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

test_that("xml_name<- modifies the name", {
  x <- read_xml("ns-multiple-default.xml")
  ns <- xml_ns(x)

  bars <- xml_children(xml_children(x))
  bar <- bars[[1]]

  xml_name(bar) <- "foo"
  expect_equal(xml_name(bar), "foo")
  expect_equal(xml_name(bar, ns), "d1:foo")

  # ns is ignored
  xml_name(bar, ns) <- "bar"
  expect_equal(xml_name(bar), "bar")
  expect_equal(xml_name(bar, ns), "d1:bar")

  xml_name(bars) <- "foo"
  expect_equal(xml_name(bars), c("foo", "foo"))

  old_mss <- mss <- xml_missing()
  xml_name(mss) <- "foo"
  expect_identical(old_mss, mss)
})

test_that("xml_set_name modifies the name", {
  x <- read_xml("ns-multiple-default.xml")
  ns <- xml_ns(x)

  bars <- xml_children(xml_children(x))
  bar <- bars[[1]]

  xml_set_name(bar, "foo")
  expect_equal(xml_name(bar), "foo")
  expect_equal(xml_name(bar, ns), "d1:foo")

  # ns is ignored
  xml_set_name(bar, "bar", ns)
  expect_equal(xml_name(bar), "bar")
  expect_equal(xml_name(bar, ns), "d1:bar")

  xml_set_name(bars, "foo")
  expect_equal(xml_name(bars), c("foo", "foo"))

  old_mss <- mss <- xml_missing()
  xml_set_name(mss, "foo")
  expect_identical(old_mss, mss)
})
