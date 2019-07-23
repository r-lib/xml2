test_that("download_xml fails if curl is not installed", {

  mockery::stub(download_xml, "requireNamespace", function(...) FALSE)

  expect_error(
    download_xml("http://httpbin.org/xml"),
    "`curl` must be installed to use `download_xml\\(\\)`"
  )
})
