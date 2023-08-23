test_that("multiplication works", {
  x <- sample_nodeset()

  expect_equal(xml_type(x[[1]]), "element")
  expect_equal(xml_type(x[[3]]), NA_character_)

  expect_equal(xml_type(x), c("element", "element", NA))

  empty <- xml_children(x)
  expect_identical(xml_type(empty), character())
})
