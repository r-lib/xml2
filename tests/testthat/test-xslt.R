context("XSL Transformation")

test_that("XML document gets properly transformed using a stylesheet", {
  doc <- read_xml("cd_catalog.xml")
  stylesheet <- read_xml("cd_catalog.xslt")
  output <- xml_xslt(doc, stylesheet)
  orig <- read_xml("cd_catalog.html")
  expect_equal(as.character(output), as.character(orig))
})
