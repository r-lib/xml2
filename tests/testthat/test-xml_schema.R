context("xml_schema")

test_that("xml schema validates", {
  doc <- read_xml(system.file("extdata/order-doc.xml", package = "xml2"))
  schema <- read_xml(system.file("extdata/order-schema.xml", package = "xml2"))
  expect_true(xml_validate(doc, schema))
})

test_that("xml schema errors", {
  str <- readLines(system.file("extdata/order-doc.xml", package = "xml2"))
  str <- sub("<quantity>1", "<quantity>", str)
  str <- sub("95819", "ABC95819", str)
  str <- sub('partNum="926-AA"', "", str)
  doc <- read_xml(paste(str, collapse = "\n"))
  schema <- read_xml(system.file("extdata/order-schema.xml", package = "xml2"))
  out <- xml_validate(doc, schema)
  expect_false(out)
  errors <- attr(out, "errors")
  expect_is(errors, "character")
  expect_length(errors, 4)
})
