context("comment")

test_that("Comment creation works", {
  x <- xml_new_root("root")
  xml_add_child(x, xml_comment("Hello!"))
  expect_identical("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<root><!--Hello!--></root>\n", as.character(x, options = ""))
})

