# Find one ---------------------------------------------------------------------

test_that("xml_find_first returns a missing object if no match", {
  x <- read_xml("<x><y/></x>")
  expect_equal(xml_find_first(x, ".//z"), xml_missing())
})

test_that("xml_find_first returns the first match if more than one match", {
  x <- read_xml("<x><y/><y/></x>")
  y <- xml_find_first(x, ".//y")
  expect_s3_class(y, "xml_node")
})

test_that("xml_find_first does not deduplicate identical results", {
  x <- read_xml("<x><y/><y/></x>")
  y <- xml_find_all(x, ".//y")
  z <- xml_find_first(y, "..")
  expect_s3_class(z, "xml_nodeset")
  expect_equal(length(z), 2)
})

# Find all ---------------------------------------------------------------------

test_that("unqualified names don't look in default ns", {
  x <- read_xml(test_path("ns-multiple-default.xml"))

  expect_equal(length(xml_find_all(x, "//bar")), 0)
})

test_that("qualified names matches to namespace", {
  x <- read_xml(test_path("ns-multiple-default.xml"))
  ns <- xml_ns(x)

  expect_equal(length(xml_find_all(x, "//d1:bar", ns)), 1)
  expect_equal(length(xml_find_all(x, "//d2:bar", ns)), 1)
})

test_that("warning if unknown namespace", {
  x <- read_xml("<foo><bar /></foo>")
  maybe_error(
    expect_warning(xml_find_all(x, "//g:bar"), "Undefined namespace prefix"),
    "evaluation failed"
  )
})

test_that("no matches returns empty nodeset", {
  x <- read_xml("<foo><bar /></foo>")
  expect_equal(length(xml_find_all(x, "//baz")), 0)
})

test_that("xml_find_all returns nodeset or list of nodesets based on flatten", {
  x <- read_xml("<body><p>Some <b>text</b>.</p>
                 <p>Some <b>other</b> <b>text</b>.</p>
                 <p>No bold here!</p></body>")
  y <- xml_find_all(x, ".//p")
  z <- xml_find_all(y, ".//b", flatten = FALSE)
  expect_s3_class(xml_find_all(y, ".//b"), "xml_nodeset")
  expect_type(z, "list")
  expect_s3_class(z[[1L]], "xml_nodeset")
})

# Find num ---------------------------------------------------------------------
test_that("xml_find_num errors with non numeric results", {
  x <- read_xml("<x><y/><y/></x>")
  expect_snapshot_error({
    xml_find_num(x, "//z")
    xml_find_num(x, "//y")
    xml_find_num(x, "1=1")
    xml_find_num(x, "string(5)")
  })
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

# Find int ---------------------------------------------------------------------
test_that("xml_find_int errors with non integer results", {
  x <- read_xml("<x><y/><y/></x>")
  expect_snapshot(error = TRUE, {
    xml_find_int(x, "//z")
    xml_find_int(x, "//y")
    xml_find_int(x, "number(1.1)")
  })
})

test_that("xml_find_int returns a integer result", {
  x <- read_xml("<x><y>1</y><y/></x>")

  expect_identical(xml_find_int(x, "1 div floor(-0.1)"), -1L)
  expect_identical(xml_find_int(x, "number(//y)"), 1L)
  expect_identical(xml_find_int(x, "string-length(string('abcd'))"), 4L)
})

# Find chr ---------------------------------------------------------------------
test_that("xml_find_chr errors with non character results", {
  x <- read_xml("<x><y/><y/></x>")
  expect_snapshot_error({
    xml_find_chr(x, "//z")
    xml_find_chr(x, "//y")
    xml_find_chr(x, "1=1")
    xml_find_chr(x, "1+1")
  })
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
  expect_snapshot_error({
    xml_find_lgl(x, "//z")
    xml_find_lgl(x, "//y")
    xml_find_lgl(x, "string(5)")
    xml_find_lgl(x, "1+1")
  })
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

test_that("Searches with entities work (#241)", {
  res <- read_xml(test_path("records.xml"), options = "DTDVALID")

  field1 <- xml_find_all(res, "//field1")

  expect_equal(xml_text(field1), "foo bar Quantitative Consultancy")
})

test_that("A helpful error is given from non-string xpath in xml_find_first/all", {
  node <- read_xml("<a>1</a>")

  expect_error(xml_find_all(node, 1), "XPath must be a string", fixed = TRUE)
  expect_error(xml_find_first(node, 1), "XPath must be a string", fixed = TRUE)
})
