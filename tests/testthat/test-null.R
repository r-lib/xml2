context("Null XPtr")

data <- read_xml("ns-multiple.xml")
tf <- tempfile()
on.exit(unlink(tf))
saveRDS(data, file = tf)
x <- readRDS(tf)

test_that("accessors all fail rather than crash with NULL Xptrs", {

  expect_error(as_list(x), "external pointer is not valid")

  expect_error(html_structure(x), "external pointer is not valid")

  expect_error(xml_add_child(x, x), "external pointer is not valid")
  expect_error(xml_add_sibling(x, x), "external pointer is not valid")

  expect_error(xml_attr(x, "foo"), "external pointer is not valid")
  expect_error(xml_attr(x, "foo") <- "bar", "external pointer is not valid")

  expect_error(xml_attrs(x), "external pointer is not valid")
  expect_error(xml_attrs(x) <- list(), "external pointer is not valid")

  expect_error(xml_child(x), "external pointer is not valid")
  expect_error(xml_children(x), "external pointer is not valid")

  expect_error(xml_contents(x), "external pointer is not valid")

  expect_error(xml_double(x), "external pointer is not valid")

  expect_error(xml_find_all(x, ""), "external pointer is not valid")
  expect_error(xml_find_chr(x, ""), "external pointer is not valid")
  expect_error(xml_find_first(x, ""), "external pointer is not valid")
  expect_error(xml_find_lgl(x, ""), "external pointer is not valid")
  expect_error(xml_find_num(x, ""), "external pointer is not valid")

  expect_error(xml_has_attr(x, ""), "external pointer is not valid")

  expect_error(xml_integer(x), "external pointer is not valid")

  expect_error(xml_length(x), "external pointer is not valid")

  expect_error(xml_name(x), "external pointer is not valid")
  expect_error(xml_name(x) <- "foo", "external pointer is not valid")

  expect_error(xml_ns(x), "external pointer is not valid")
  expect_error(xml_ns_strip(x), "external pointer is not valid")

  expect_error(xml_parent(x), "external pointer is not valid")
  expect_error(xml_parents(x), "external pointer is not valid")

  expect_error(xml_path(x), "external pointer is not valid")

  expect_error(xml_remove(x), "external pointer is not valid")

  expect_error(xml_replace(x, x), "external pointer is not valid")

  expect_error(xml_set_namespace(x, "foo"), "external pointer is not valid")

  expect_error(xml_siblings(x), "external pointer is not valid")

  expect_error(xml_structure(x), "external pointer is not valid")

  expect_error(xml_text(x), "external pointer is not valid")
  expect_error(xml_text(x) <- "test", "external pointer is not valid")

  expect_error(xml_type(x), "external pointer is not valid")

  expect_error(xml_url(x), "external pointer is not valid")
})
