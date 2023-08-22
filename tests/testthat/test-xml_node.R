test_that("print method is correct", {
  x <- read_html(test_path("lego.html.bz2"))
  body <- xml_find_first(x, "//body")
  expect_snapshot(print(body))
})
