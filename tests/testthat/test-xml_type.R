test_that("xml_type() works", {
  x <- read_xml("<body>
    <p>Some <b>text</b>.</p>
    <p>Some <i>other</i>.</p>
    <p>No bold text</p>
    </body>")

  children <- xml_children(x)
  x <- xml_find_first(children, ".//b|.//i")

  expect_equal(xml_type(x[[1]]), "element")
  expect_equal(xml_type(x[[3]]), NA_character_)

  expect_equal(xml_type(x), c("element", "element", NA))

  empty <- xml_children(x)
  expect_identical(xml_type(empty), character())
})
