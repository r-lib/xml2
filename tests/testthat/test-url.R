context("url")

test_that("url_absolute", {
  expect_equal(
    url_absolute(c(".", "..", "/", "/x"), "http://hadley.nz/a/b/c/d"),
    c("http://hadley.nz/a/b/c/", "http://hadley.nz/a/b/", "http://hadley.nz/", "http://hadley.nz/x"))

    expect_error(url_absolute(c(".", "..", "/", "/x"), c("http://hadley.nz/a/b/c/d", "http://foo.bar")),
      "Base URL must be length 1")
})

test_that("url_relative", {

  expect_equal(
    url_relative("http://hadley.nz/a/c", "http://hadley.nz"),
    "/a/c")

  expect_equal(
    url_relative("http://hadley.nz/a/c", "http://hadley.nz/"),
    "../a/c")

  expect_equal(
    url_relative("http://hadley.nz/a/c", "http://hadley.nz/a/b"),
    "c")

  expect_equal(
    url_relative("http://hadley.nz/a/c", "http://hadley.nz/a/b/"),
    "../c")

    expect_error(url_relative("http://hadley.nz/a/c", c("http://hadley.nz/a/b/c/d", "http://foo.bar")),
      "Base URL must be length 1")
})

test_that("url_parse", {

  expect_equal(
    url_parse("http://had.co.nz/"),
    data.frame(scheme = "http", server = "had.co.nz", port = NA_integer_,
      user = "", path = "/", query = "", fragment = "", stringsAsFactors = FALSE))

  expect_equal(
    url_parse("http://had.co.nz:1234/"),
    data.frame(scheme = "http", server = "had.co.nz", port = 1234L,
      user = "", path = "/", query = "", fragment = "", stringsAsFactors = FALSE))

  expect_equal(
    url_parse("http://had.co.nz:1234/?a=1&b=2"),
    data.frame(scheme = "http", server = "had.co.nz", port = 1234L,
      user = "", path = "/", query = "a=1&b=2", fragment = "", stringsAsFactors = FALSE))

  expect_equal(
    url_parse("http://had.co.nz:1234/?a=1&b=2#def"),
    data.frame(scheme = "http", server = "had.co.nz", port = 1234L,
      user = "", path = "/", query = "a=1&b=2", fragment = "def", stringsAsFactors = FALSE))
})

test_that("url_escape", {
  expect_error(url_escape("a b c", reserved = c("a", "b")),
    "`reserved` must be character vector of length 1")

  expect_equal(
    url_escape("a b c"),
    "a%20b%20c")

  expect_equal(
    url_escape("a b c", " "),
    "a b c")

  expect_equal(
    url_unescape("a%20b%2fc"),
    "a b/c")

  expect_equal(
    url_unescape("%C2%B5"),
    "\u00B5")
})
