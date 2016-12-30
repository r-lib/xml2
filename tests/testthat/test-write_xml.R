context("write_xml")

test_that("write_xml errors for incorrect directory and with invalid inputs", {
  x <- read_xml("<x/>")
  filename <- ".../test.xml"
  expect_error(write_xml(x, filename), "'...' does not exist in current working directory")


  expect_error(write_xml(x, c("test.xml", "foo")), "`file` must be a non-zero character of length 1")
})

test_that("write_xml works with relative file paths", {
  x <- read_xml("<x/>")

  filename <- "../test.xml"
  on.exit(unlink(filename))
  write_xml(x, filename, options = "no_declaration")
  expect_identical(readChar(filename, 1000L), "<x/>\n")
})

test_that("write_xml works with no options", {
  x <- read_xml("<x/>")

  filename <- "../test.xml"
  on.exit(unlink(filename))
  write_xml(x, filename, options = NULL)
  expect_identical(readChar(filename, 1000L), "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<x/>\n")
})

test_that("write_xml works with an explicit connections", {
  x <- read_xml("<x/>")

  filename <- "../test.xml"
  file <- file(filename, "wb")
  on.exit(unlink(filename))
  write_xml(x, file, options = "no_declaration")
  close(file)
  expect_identical(readChar(filename, 1000L), "<x/>\n")
})

test_that("write_xml works with an implicit connections", {
  x <- read_xml("<x/>")

  filename <- "../test.xml.gz"
  write_xml(x, filename, options = "no_declaration")
  file <- gzfile(filename, "rb")
  on.exit({unlink(filename); close(file)})
  expect_identical(readChar(file, 1000L), "<x/>\n")
})

test_that("write_xml works with nodeset input and files", {
  x <- read_xml("<x><y/><y><z/></y></x>")
  y <- xml_find_all(x, "//y")

  filename <- "../test.xml"
  on.exit(unlink(filename))
  expect_error(write_xml(y, filename, options = "no_declaration"),
    "Can only save length 1 node sets")

  write_xml(y[1], filename, options = "no_declaration")
  expect_identical(readChar(filename, 1000L), "<y/>")
})

test_that("write_xml works with nodeset input and connections", {
  x <- read_xml("<x><y/><y/></x>")
  y <- xml_find_all(x, "//y")

  filename <- "../test.xml.gz"
  expect_error(write_xml(y, filename, options = "no_declaration"),
    "Can only save length 1 node sets")

  expect_error(write_xml(y[1], c(filename, "foo")), "`file` must be a non-zero character of length 1")

  write_xml(y[1], filename, options = "no_declaration")
  file <- gzfile(filename, "rb")
  on.exit({unlink(filename); close(file)})
  expect_identical(readChar(file, 1000L), "<y/>")
})

test_that("write_xml works with node input and files", {
  x <- read_xml("<x><y/><y/></x>")
  y <- xml_find_first(x, "//y")

  filename <- "../test.xml"
  expect_error(write_xml(y, c(filename, "foo")), "`file` must be a non-zero character of length 1")

  write_xml(y, filename, options = "no_declaration")
  on.exit(unlink(filename))
  expect_identical(readChar(filename, 1000L), "<y/>")
})

test_that("write_xml works with node input and connections", {
  x <- read_xml("<x><y/><y/></x>")
  y <- xml_find_first(x, "//y")

  filename <- "../test.xml.gz"
  write_xml(y, filename, options = "no_declaration")
  file <- gzfile(filename, "rb")
  on.exit({unlink(filename); close(file)})
  expect_identical(readChar(file, 1000L), "<y/>")
})

test_that("write_html work with html input", {
  x <- read_html("<html><title>Foo</title></html>")

  filename <- "../test.html.gz"
  write_html(x, filename)
  file <- gzfile(filename, "rb")
  on.exit({unlink(filename); close(file)})
  expect_identical(readChar(file, 1000L),
    "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\" \"http://www.w3.org/TR/REC-html40/loose.dtd\">\n<html><head>\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n<title>Foo</title>\n</head></html>\n")
})
