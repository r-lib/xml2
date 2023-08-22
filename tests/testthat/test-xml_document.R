test_that("print method is correct", {
  x <- read_html(test_path("lego.html.bz2"))

  expect_output_file(print(x), "output/print-xml_document.txt", update = FALSE)
})
