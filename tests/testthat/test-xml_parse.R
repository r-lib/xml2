test_that("download_xml fails if curl is not installed", {

  mockery::stub(download_xml, "requireNamespace", function(...) FALSE)

  expect_error(
    download_xml("http://httpbin.org/xml"),
    "`curl` must be installed to use `download_xml\\(\\)`"
  )
})

test_that("read_xml and read_html fail for bad status codes", {

  skip_on_cran()
  skip_if_not_installed("httr")

  expect_error(
    read_xml(httr::GET("http://httpbin.org/status/404")),
    class = "http_404"
  )

  expect_error(
    read_html(httr::GET("http://httpbin.org/status/404")),
    class = "http_404"
  )
})
