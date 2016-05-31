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

test_that("aliased prefixes retained", {
  ns <- unclass(xml_ns(read_xml("ns-multiple-aliases.xml")))
  expect_equal(ns, c(b = "http://bar.com", c = "http://bar.com"))
})


# Low-level character vector tests ---------------------------------------------

test_that("unique prefix-url combo unchanged", {
  x <- c(blah = "http://blah.com", rah = "http://rah.com")
  expect_equal(unique_ns(x), x)
})

test_that("all prefixs kept", {
  x <- c(blah = "http://blah.com", rah = "http://blah.com")
  expect_equal(names(unique_ns(x)), c("blah", "rah"))
})

test_that("multiple default namespaces can be stripped", {
  x <- read_xml("ns-multiple-default.xml")
  ns <- unclass(xml_ns(x))
  expect_equal(ns, c(d1 = "http://foo.com", d2 = "http://bar.com"))
  expect_equal(length(xml_find_all(x, "//bar")), 0)

  xml_ns_strip(x)
  ns <- unclass(xml_ns(x))

  expect_equivalent(ns, character())
  expect_equal(length(xml_find_all(x, "//bar")), 2)
})
