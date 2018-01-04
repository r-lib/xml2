context("xml_serialize")

x <- read_xml("<a>
  <b><c>123</c></b>
  <b><c>456</c></b>
  </a>")
test_that("xml_serialize and xml_unserialize work with xml_document input", {
  out <- xml_unserialize(xml_serialize(x, NULL))
  expect_identical(as.character(x), as.character(out))

  f <- tempfile()
  on.exit(unlink(f))

  xml_serialize(x, f)
  expect_identical(as.character(xml_unserialize(f)), as.character(x))
})

test_that("xml_serialize and xml_unserialize work with xml_node input", {
  b <- xml_find_first(x, "//b")
  out <- xml_unserialize(xml_serialize(b, NULL))
  expect_identical(as.character(b), as.character(out))

  f <- tempfile()
  on.exit(unlink(f))

  xml_serialize(b, f)
  expect_identical(as.character(xml_unserialize(f)), as.character(b))
})

test_that("xml_serialize and xml_unserialize work with xml_nodeset input", {
  b <- xml_find_all(x, "//b")
  out <- xml_unserialize(xml_serialize(b, NULL))
  expect_identical(as.character(b), as.character(out))

  f <- tempfile()
  on.exit(unlink(f))

  xml_serialize(b, f)
  expect_identical(as.character(xml_unserialize(f)), as.character(b))
})

test_that("xml_unserialize throws an error if given a invalid object", {
  expect_error(xml_unserialize(serialize(1, NULL)), "Not a serialized xml2 object")
})
