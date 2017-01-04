context("print")

x <- read_html("lego.html.bz2")
body <- xml_find_first(x, "//body")
divs <- xml_find_all(body, ".//div")[1:10]
quicklinks <- xml_find_first(body, "//div[contains(@div, 'quicklinks')]")

test_that("print method is correct", {
  expect_output_file(print(x), "output/print-xml_document.txt", update = FALSE)

  body <- xml_find_first(x, "//body")
  expect_output_file(print(body), "output/print-xml_node.txt", update = FALSE)

  divs <- xml_find_all(body, ".//div")[1:10]
  expect_output_file(print(divs), "output/print-xml_nodeset.txt", update = FALSE)
})

test_that("xml_structure is correct", {
  quicklinks <- xml_find_first(x, "//div[contains(@div, 'quicklinks')]")
  expect_output_file(html_structure(quicklinks), "output/html_structure.txt", update = FALSE)
})
