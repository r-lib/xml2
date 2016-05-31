context("xml_children")

x <- read_xml("<foo> <bar><boo /></bar> <baz/> </foo>")

test_that("xml_child() returns the proper child", {
  expect_equal(xml_child(x), xml_children(x)[[1L]])

  expect_equal(xml_child(x, 2), xml_children(x)[[2L]])
})

test_that("xml_child() returns child by name", {
  expect_equal(xml_child(x, "baz"), xml_find_first(x, "./baz"))
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
