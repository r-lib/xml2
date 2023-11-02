test_that("xml_text returns only text without markup", {
  x <- read_xml("<p>This is some text. This is <b>bold!</b></p>")

  expect_identical(xml_text(x), "This is some text. This is bold!")

  expect_identical(xml_text(xml_children(x)), "bold!")
})

test_that("xml_text works properly with xml_nodeset objects", {
  x <- read_xml("<body>
    <p>Some <b>text</b>.</p>
    <p>Some <i>other</i>.</p>
    <p>No bold text</p>
    </body>")

  children <- xml_children(x)
  x <- xml_find_first(children, ".//b|.//i")

  expect_identical(
    xml_text(x),
    c("text", "other", NA)
  )
})

test_that("xml_text<- and xml_set_text work properly with xml_nodeset objects", {
  x <- read_xml("<x>This is some text. <x>This is some nested text.</x></x>")

  expect_identical(xml_text(x), "This is some text. This is some nested text.")

  xml_text(x) <- "test"
  expect_identical(xml_text(x), "testThis is some nested text.")
  xml_set_text(x, "test2")
  expect_identical(xml_text(x), "test2This is some nested text.")
})

test_that("xml_text trims whitespace if requested, including non-breaking spaces", {
  x <- read_html("<p>   Some text &euro;  &nbsp;</p>")
  expect_identical(
    xml_text(x),
    "   Some text \u20ac  \u00a0"
  )

  expect_identical(
    xml_text(x, trim = TRUE),
    "Some text \u20ac"
  )

  x2 <- read_html("<body><p>   Some text &euro;  &nbsp;</p><p>  and more &euro; text   &nbsp;</body>")
  expect_identical(
    xml_text(xml_find_all(x2, ".//p"), trim = TRUE),
    c("Some text \u20ac", "and more \u20ac text")
  )
})

test_that("xml_integer() returns an integer vector", {
  x <- read_xml("<plot><point x='1' y='2' /><point x='2' y='1' /></plot>")

  expect_identical(
    xml_integer(xml_find_all(x, "//@x")),
    c(1L, 2L)
  )
})


test_that("xml_double() returns a numeric vector", {
  x <- read_xml("<earth><point latitude = '42.3466456' longitude = '-71.0390351' /><point latitude = '-36.8523378' longitude = '174.7691073' /></earth>")

  expect_identical(xml_double(xml_find_all(x, "//@latitude")), c(42.3466456, -36.8523378))
})
