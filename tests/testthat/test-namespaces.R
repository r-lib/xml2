context("Namespaces")

# XML parsing tests ------------------------------------------------------------

test_that("multiple default namespaces given unique names", {
  ns <- unclass(xml_ns(read_xml("ns-multiple-default.xml")))
  expect_equal(ns, c(d1 = "http://foo.com", d2 = "http://bar.com"))
})

test_that("repeated prefixes given unique names", {
  ns <- unclass(xml_ns(read_xml("ns-multiple-prefix.xml")))
  expect_equal(ns, c(b = "http://baz.com", b1 = "http://bar.com"))
})


# Low-level character vector tests ---------------------------------------------

test_that("unique prefix-url combo unchanged", {
  x <- c(blah = "http://blah.com", rah = "http://rah.com")
  expect_equal(unique_ns(x), x)
})

test_that("first prefix kept", {
  x <- c(blah = "http://blah.com", rah = "http://blah.com")
  expect_equal(names(unique_ns(x)), "blah")
})
