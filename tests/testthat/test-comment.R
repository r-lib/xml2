context("comment")

test_that("Comment creation works", {
  x <- xml_new_document()
  r <- xml_add_child(x, "root")
  xml_add_child(r, xml_comment("Hello!"))
  expect_identical(as.character(x),  "<?xml version=\"1.0\"?>\n<root><!--Hello!--></root>\n")
})

