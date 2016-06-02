context("xml_text")

test_that("xml_text returns only text without markup", {
  x <- read_xml("<p>This is some text. This is <b>bold!</b></p>")

  expect_equal(xml_text(x), "This is some text. This is bold!")

  expect_equal(xml_text(xml_children(x)), "bold!")
})

test_that("xml_text returns only text without markup", {
  x <- read_xml("<p>This is some text. This is <b>bold!</b></p>")

  expect_equal(xml_text(x), "This is some text. This is bold!")

  expect_equal(xml_text(xml_children(x)), "bold!")
})

test_that("xml_text works properly with xml_nodeset objects", {
  x <- read_xml("<x>This is some text. <x>This is some nested text.</x></x>")

  expect_equal(xml_text(x), "This is some text. This is some nested text.")

  expect_equal(xml_text(xml_find_all(x, "//x")),
    c("This is some text. This is some nested text.", "This is some nested text."))
})

test_that("xml_text trims whisespace if requested", {
  x <- read_xml("<p>   Some text    </p>")
  expect_equal(xml_text(x),
    "   Some text    ")

  expect_equal(xml_text(x, trim = TRUE),
    "Some text")
})

test_that("xml_integer() returns an integer vector", {
  x <- read_xml("<plot><point x='1' y='2' /><point x='2' y='1' /></plot>")

  expect_equal(xml_integer(xml_find_all(x, "//@x")),
    c(1L, 2L))
})


test_that("xml_double() returns a numeric vector", {
  x <- read_xml("<earth><point latitude = '42.3466456' longitude = '-71.0390351' /><point latitude = '-36.8523378' longitude = '174.7691073' /></earth>")

  expect_equal(xml_double(xml_find_all(x, "//@latitude")), c(42.3466456, -36.8523378))
})
