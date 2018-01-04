context("xml_find")

# Find one ---------------------------------------------------------------------

test_that("xml_find_first returns a missing object if no match", {
  x <- read_xml("<x><y/></x>")
  expect_equal(xml_find_first(x, ".//z"), xml_missing())
})

test_that("xml_find_first returns the first match if more than one match", {
  x <- read_xml("<x><y/><y/></x>")
  y <- xml_find_first(x, ".//y")
  expect_is(y, "xml_node")
})

test_that("xml_find_first does not deduplicate identical results", {
  x <- read_xml("<x><y/><y/></x>")
  y <- xml_find_all(x, ".//y")
  z <- xml_find_first(y, "..")
  expect_is(z, "xml_nodeset")
  expect_equal(length(z), 2)
})

# Find all ---------------------------------------------------------------------

test_that("unqualified names don't look in default ns", {
  x <- read_xml("ns-multiple-default.xml")

  expect_equal(length(xml_find_all(x, "//bar")), 0)
})

test_that("qualified names matches to namespace", {
  x <- read_xml("ns-multiple-default.xml")
  ns <- xml_ns(x)

  expect_equal(length(xml_find_all(x, "//d1:bar", ns)), 1)
  expect_equal(length(xml_find_all(x, "//d2:bar", ns)), 1)
})

test_that("warning if unknown namespace", {
  x <- read_xml("<foo><bar /></foo>")
  expect_warning(xml_find_all(x, "//g:bar"), "Undefined namespace prefix")
})

test_that("no matches returns empty nodeset", {
  x <- read_xml("<foo><bar /></foo>")
  expect_equal(length(xml_find_all(x, "//baz")), 0)
})

# Find num ---------------------------------------------------------------------
test_that("xml_find_num errors with non numeric results", {
  x <- read_xml("<x><y/><y/></x>")
  expect_error(xml_find_num(x, "//z"), "result of type:.*xml_missing.*, not numeric")
  expect_error(xml_find_num(x, "//y"), "result of type:.*list.*, not numeric")
  expect_error(xml_find_num(x, "1=1"), "result of type:.*logical.*, not numeric")
  expect_error(xml_find_num(x, "string(5)"), "result of type:.*character.*, not numeric")
})

test_that("xml_find_num returns a numeric result", {
  x <- read_xml("<x><y>1</y><y/></x>")
  expect_equal(xml_find_num(x, "1 div 0"), Inf)

  expect_equal(xml_find_num(x, "-1 div 0"), -Inf)

  expect_equal(xml_find_num(x, "0 div 0"), NaN)

  expect_equal(xml_find_num(x, "1 div floor(-0.1)"), -1)

  expect_equal(xml_find_num(x, "1 div floor(0)"), Inf)

  expect_equal(xml_find_num(x, "1 div floor(-0)"), -Inf)
})

# Find chr ---------------------------------------------------------------------
test_that("xml_find_chr errors with non character results", {
  x <- read_xml("<x><y/><y/></x>")
  expect_error(xml_find_chr(x, "//z"), "result of type:.*xml_missing.*, not character")
  expect_error(xml_find_chr(x, "//y"), "result of type:.*list.*, not character")
  expect_error(xml_find_chr(x, "1=1"), "result of type:.*logical.*, not character")
  expect_error(xml_find_chr(x, "1+1"), "result of type:.*numeric.*, not character")
})

test_that("xml_find_chr returns a character result", {
  x <- read_xml("<x><y>1</y><y/></x>")
  expect_equal(xml_find_chr(x, "string(5)"), "5")

  expect_equal(xml_find_chr(x, "string(0.5)"), "0.5")

  expect_equal(xml_find_chr(x, "string(-0.5)"), "-0.5")

  expect_equal(xml_find_chr(x, "concat(\"titi\", \"toto\")"), "tititoto")

  expect_equal(xml_find_chr(x, "substring(\"12345\", 2, 3)"), "234")

  expect_equal(xml_find_chr(x, "substring(\"12345\", 2)"), "2345")

  expect_equal(xml_find_chr(x, "substring(\"12345\", -4)"), "12345")
})

# Find lgl ---------------------------------------------------------------------
test_that("xml_find_lgl errors with non logical results", {
  x <- read_xml("<x><y/><y/></x>")
  expect_error(xml_find_lgl(x, "//z"), "result of type:.*xml_missing.*, not logical")
  expect_error(xml_find_lgl(x, "//y"), "result of type:.*list.*, not logical")
  expect_error(xml_find_lgl(x, "string(5)"), "result of type:.*character.*, not logical")
  expect_error(xml_find_lgl(x, "1+1"), "result of type:.*numeric.*, not logical")
})

test_that("xml_find_lgl returns a logical result", {
  x <- read_xml("<x><y>1</y><y/></x>")

  expect_equal(xml_find_lgl(x, "1=1"), TRUE)

  expect_equal(xml_find_lgl(x, "1!=1"), FALSE)

  expect_equal(xml_find_lgl(x, "true()=true()"), TRUE)

  expect_equal(xml_find_lgl(x, "true()=false()"), FALSE)

  expect_equal(xml_find_lgl(x, "'test'='test'"), TRUE)
})

test_that("Searches with empty inputs retain type stability", {
  empty <- xml_nodeset()

  expect_equal(xml_find_num(empty, "1 div 0"), integer())

  expect_equal(xml_find_chr(empty, "string(0.5)"), character())

  expect_equal(xml_find_lgl(empty, "1=1"), logical())
})
