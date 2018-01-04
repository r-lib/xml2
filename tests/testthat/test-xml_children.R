context("xml_children")

x <- read_xml("<foo> <bar><boo /></bar> <baz/> </foo>")

test_that("xml_child() returns the proper child", {
  expect_identical(xml_child(x), xml_children(x)[[1L]])

  expect_identical(xml_child(x, 2), xml_children(x)[[2L]])
})

test_that("xml_child() returns child by name", {
  expect_identical(xml_child(x, "baz"), xml_find_first(x, "./baz"))
})

test_that("xml_child() errors if more than one search is given", {
  expect_error(xml_child(x, 1:2), "`search` must be of length 1")
})

test_that("xml_child() errors if search is not numeric or character", {
  expect_error(xml_child(x, TRUE), "`search` must be `numeric` or `character`")
  expect_error(xml_child(x, as.factor("test")), "`search` must be `numeric` or `character`")
  expect_error(xml_child(x, raw(1)), "`search` must be `numeric` or `character`")
  expect_error(xml_child(x, list(1)), "`search` must be `numeric` or `character`")
})

test_that("xml_length", {
  expect_equal(xml_length(x), 2)
  all <- xml_find_all(x, "//*")
  expect_equal(xml_length(all), c(2, 1, 0, 0))
})

test_that("xml_parent", {
  expect_identical(unclass(xml_parent(xml_child(x))), unclass(x))
})

test_that("xml_parents", {
  expect_equal(
    xml_name(xml_parents(xml_find_first(x, "//boo"))),
    c("bar", "foo"))
})

test_that("xml_root", {
  doc <- xml_new_document()

  expect_is(xml_root(doc), "xml_missing")

  a <- xml_add_child(doc, "a")
  b <- xml_add_child(doc, "b")

  expect_that(xml_name(xml_root(b)), equals("a"))
  expect_that(xml_name(xml_root(doc)), equals("a"))
})
