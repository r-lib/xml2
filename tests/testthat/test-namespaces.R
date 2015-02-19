context("Namespaces")

test_that("unique prefix-url combo unchanged", {
  x <- c(blah = "http://blah.com", rah = "http://rah.com")
  expect_equal(unique_ns(x), x)
})

test_that("first prefix kept", {
  x <- c(blah = "http://blah.com", rah = "http://blah.com")
  expect_equal(names(unique_ns(x)), "blah")
})
