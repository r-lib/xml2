context("cdata")

test_that("CDATA creation works", {
  x <- xml_new_document()
  r <- xml_add_child(x, "root")
  xml_add_child(r, xml_cdata("<d/>"))
  expect_identical(as.character(x),  "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<root><![CDATA[<d/>]]></root>\n")
})
