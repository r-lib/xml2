test_that("print method is correct", {
  x <- read_html(test_path("lego.html.bz2"))

  expect_snapshot(print(x))
})
