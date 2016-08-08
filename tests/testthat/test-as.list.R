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

test_that("xml names are preserved when attributes exist", {
  expect_equal(list_xml("<x a='1' b='2'><y>3</y><z>4</z></x>"),
               structure(list(y = list('3'), z = list('4')), names = c("y", "z"), a = "1", b = "2"))
})

test_that("special attributes are escaped", {
  expect_equal(list_xml("<x a='1' b='2' names='esc'><y>3</y><z>4</z></x>"),
               structure(list(y = list('3'), z = list('4')), names = c("y", "z"), a = "1", b = "2", .names='esc'))
})
