context("as_list")

list_xml <- function(x) as_list(read_xml(x))

test_that("empty elements become empty lists", {
  expect_equal(list_xml("<x></x>"), list())
  expect_equal(list_xml("<x><y/></x>"), list(y = list()))
  expect_equal(list_xml("<x><y><z/></y></x>"), list(y = list(z = list())))
})

test_that("text nodes become character vectors", {
  expect_equal(list_xml("<x>a</x>"), list("a"))
  expect_equal(list_xml("<x><y>a</y></x>"), list(y = list("a")))
})

test_that("cdata nodes become character vectors", {
  expect_equal(list_xml("<x><![CDATA[<y/>]]></x>"), list("<y/>"))
})

test_that("xml attributes become R attibutes", {
  expect_equal(list_xml("<x a='1' b='2'></x>"), structure(list(), a = "1", b = "2"))
})
