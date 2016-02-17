context("modify nodes")

test_that("modifying nodes works", {
  x <- read_xml("<x><y/></x>")
  node <- xml_find_one(x, "//x")

  expect_equal(xml_name(node), "x")

  node_set_name(node$node, "y")
  expect_equal(xml_name(node), "y")

  expect_equal(xml_text(node), "")
  node_set_content(node$node, "test")
  expect_equal(xml_text(node), "test")
})
