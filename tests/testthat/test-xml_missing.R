context("xml_missing")
x <- read_xml("<body>
  <p>Some <b>text</b>.</p>
  <p>Some <b>other</b>.</p>
  <p>No bold text</p>
  </body>")
para <- xml_find_all(x, ".//p")
b <- xml_find_first(para, ".//b")
mss <- b[[3]]

test_that("xml_find returns nodes of class 'xml_missing' for missing nodes", {
    expect_equal(length(b), 3L)
    expect_equal(vapply(b, length, integer(1)), c(2L, 2L, 0L))
    expect_is(mss, "xml_missing")
})

test_that("xml_missing methods return properly for all S3 methods", {

  expect_equal(as.character(mss), NA_character_)
  expect_equal(as_list(mss), list())
  expect_equal(nodeset_apply(mss), xml_nodeset())
  expect_output(print(mss), "\\{xml_missing\\}\n<NA>")
  expect_equal(tree_structure(mss), NA_character_)
  expect_error(write_xml(mss), "Missing data cannot be written")
  expect_error(write_html(mss), "Missing data cannot be written")
  expect_equal(xml_attr(mss), NA_character_)
  expect_equal(xml_attrs(mss), NA_character_)
  expect_equal(xml_find_all(mss), xml_nodeset())
  expect_equal(xml_find_chr(mss), character())
  expect_equal(xml_find_lgl(mss), logical())
  expect_equal(xml_find_num(mss), numeric())
  expect_equal(xml_find_first(mss), xml_missing())
  expect_equal(xml_length(mss), 0L)
  expect_equal(xml_name(mss), NA_character_)
  expect_equal(xml_parent(mss), xml_missing())
  expect_equal(xml_path(mss), NA_character_)
  expect_equal(xml_text(mss), NA_character_)
  expect_equal(xml_type(mss), NA_character_)
  expect_equal(xml_url(mss), NA_character_)
})

test_that("is.na() should return TRUE for xml_missing",
  expect_true(is.na(xml_missing()))
)
