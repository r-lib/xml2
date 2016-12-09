context("xml_nodeset")

test_that("methods work on empty nodesets", {

  x <- read_xml("<a><b/></a>")
  empty <- xml_find_all(x, "//c")

  expect_error(empty[[1]], "subscript out of bounds")
  expect_identical(empty[1], empty)
  test <- empty

  xml_attr(test, "test") <- 1
  expect_identical(test, empty)

  xml_attrs(test) <- c("test" = 1)
  expect_identical(test, empty)

  xml_name(test) <- "test"
  expect_identical(test, empty)

  xml_text(test) <- "test"
  expect_identical(test, empty)

  expect_identical(as.character(empty), character(0))
  expect_identical(as_list(empty), list())
  expect_identical(nodeset_apply(empty, identical), empty)
  expect_output(print(empty), "\\{xml_nodeset \\(0\\)\\}")
  expect_output(tree_structure(empty), NA)

  xml_add_child(test, "test")
  expect_identical(test, empty)

  xml_add_sibling(test, "test")
  expect_identical(test, empty)

  expect_identical(xml_attr(empty, "test"), character())
  expect_identical(xml_attrs(empty), list())
  expect_identical(xml_double(empty), numeric())
  expect_identical(xml_find_all(empty), empty)
  expect_identical(xml_find_chr(empty), character())
  expect_identical(xml_find_first(empty), empty)
  expect_identical(xml_find_lgl(empty), logical())
  expect_identical(xml_find_num(empty), numeric())
  expect_identical(xml_integer(empty), integer())
  expect_identical(xml_length(empty), 0L)
  expect_identical(xml_name(empty), character())
  expect_identical(xml_ns(empty), character())
  expect_identical(xml_parent(empty), empty)
  expect_identical(xml_path(empty), character())

  xml_remove(test)
  expect_identical(test, empty)

  xml_replace(test)
  expect_identical(test, empty)

  xml_set_attr(test, "test", 1)
  expect_identical(test, empty)

  xml_set_attrs(test, c("test" = 1))
  expect_identical(test, empty)

  xml_set_name(test, "test")
  expect_identical(test, empty)

  xml_set_text(test, "test")
  expect_identical(test, empty)

  expect_identical(xml_siblings(empty), empty)
  expect_output(xml_structure(empty), NA)

  expect_identical(xml_text(empty), character())
  expect_identical(xml_type(empty), character())
  expect_identical(xml_url(empty), character())
})
