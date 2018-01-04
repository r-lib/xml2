context("xml_attrs")

test_that("missing attributes returned as NA by default", {
  x <- read_xml("<x/>")
  expect_equal(xml_attr(x, "id"), NA_character_)
})

test_that("missing attributes returned as NA", {
  x <- read_xml("<x/>")
  expect_equal(xml_attr(x, "id", default = 1), "1")
})

test_that("attributes are correctly found", {
  x <- read_xml("<x id='1' />")

  expect_true(xml_has_attr(x, "id"))

  expect_false(xml_has_attr(x, "id2"))
})

test_that("returning an attribute node prints properly", {
  x <- read_xml("<a><b c='1' /></a>")

  t1 <- xml_find_first(x, "//@c")

  expect_equal(format(t1), "<c>")
})

# Namespaces -------------------------------------------------------------------

# Default namespace doesn't apply to attributes

test_that("qualified names returned when ns given", {
  x <- read_xml("ns-multiple.xml")
  ns <- xml_ns(x)

  bars <- xml_children(xml_children(x))
  attr <- xml_attrs(bars, ns)

  expect_equal(names(attr[[1]]), "f:id")
  expect_equal(names(attr[[2]]), "g:id")
})


x <- read_xml('
 <root xmlns:b="http://bar.com" xmlns:f="http://foo.com">
   <doc b:id="b" f:id="f" id="" />
   <doc b:id="b" f:id="f" id="" />
 </root>
')
doc <- xml_children(x)[[1]]
docs <- xml_find_all(x, "//doc")
ns <- xml_ns(x)

test_that("qualified attributes get own values", {
  expect_equal(xml_attrs(doc, ns), c("b:id" = "b", "f:id" = "f", "id" = ""))
})

test_that("unqualified name gets unnamespace attribute", {
  expect_equal(xml_attr(doc, "id", ns), "")
})

test_that("namespace names gets namespaced attribute", {
  expect_equal(xml_attr(doc, "b:id", ns), "b")
  expect_equal(xml_attr(doc, "f:id", ns), "f")
})

test_that("xml_attr<- modifies properties", {
  xml_attr(doc, "id", ns) <- "test"
  expect_equal(xml_attr(doc, "id", ns), "test")

  xml_attr(doc, "b:id", ns) <- "b_test"
  expect_equal(xml_attr(doc, "b:id", ns), "b_test")

  xml_attr(doc, "f:id", ns) <- "f_test"
  expect_equal(xml_attr(doc, "f:id", ns), "f_test")

  xml_attr(docs, "f:id", ns) <- "f_test2"
  expect_equal(xml_attr(docs, "f:id", ns), c("f_test2", "f_test2"))

  xml_attr(docs, "f:id", ns) <- NULL
  expect_equal(xml_attr(docs, "f:id", ns), c(NA_character_, NA_character_))
})

test_that("xml_attrs<- modifies all attributes", {
  expect_error(xml_attrs(doc) <- 1, "`value` must be a named character vector or `NULL`")
  expect_error(xml_attrs(doc) <- "test", "`value` must be a named character vector or `NULL`")

  xml_attrs(doc, ns) <- c("b:id" = "b", "f:id" = "f", "id" = "test")
  expect_equal(xml_attrs(doc, ns), c("b:id" = "b", "id" = "test", "f:id" = "f"))

  xml_attrs(doc, ns) <- c("b:id" = "b", "f:id" = "f")
  expect_equal(xml_attrs(doc, ns), c("b:id" = "b", "f:id" = "f"))

  xml_attrs(doc, ns) <- c("b:id" = "b", "id" = "test")
  expect_equal(xml_attrs(doc, ns), c("b:id" = "b", "id" = "test"))

  expect_error(xml_attrs(docs) <- "test", "`value` must be a list of named character vectors")

  xml_attrs(docs, ns) <- c("b:id" = "b", "id" = "test")
  expect_equal(xml_attrs(docs, ns),
    list(
      c("b:id" = "b", "id" = "test"),
      c("b:id" = "b", "id" = "test")))

  xml_attrs(docs, ns) <- NULL
  expect_equivalent(xml_attrs(docs, ns), list(character(0), character(0)))
})

test_that("xml_attr<- accepts non-character values", {
  x <- read_xml('<svg><rect /></svg>')
  svg <- xml_root(x)

  xml_attr(svg, "width") <- 8L
  expect_that(xml_attr(svg, "width"), equals("8"))

  xml_attr(svg, "height") <- 12.5
  expect_that(xml_attr(svg, "height"), equals("12.5"))

  expect_that(xml_attrs(svg), equals(c(width = "8", height = "12.5")))

  xml_attrs(svg) <- c(width = 14L, height = 23.45)
  expect_that(xml_attrs(svg), equals(c(width = "14", height = "23.45")))
})

test_that("xml_attr<- can set empty strings, and removes attributes with NULL", {
  x <- read_xml("<x><y /></x>")
  xml_attr(x, "test") <- ""
  expect_equal(xml_attr(x, "test"), "")

  xml_attr(x, "test") <- NULL
  expect_equal(xml_attr(x, "test"), NA_character_)
})

test_that("xml_attr<- removes namespaces if desired", {
  xml_attr(x, "xmlns:b") <- NULL

  expect_equal(xml_attrs(x), c("xmlns:f" = "http://foo.com"))
})

test_that("xml_attr<- removes namespaces if desired", {
  x <- read_xml("<a xmlns = 'tag:foo'><b/></a>")

  # cannot find //b with a default namespace
  expect_equal(length(xml_find_all(x, "//b")), 0)

  # unless we specify it explicitly
  expect_equal(length(xml_find_all(x, "//b")), 0)
  expect_equal(length(xml_find_all(x, "//d1:b", xml_ns(x))), 1)

  # but can find it once we remove the namespace
  xml_attr(x, "xmlns") <- NULL
  expect_equal(length(xml_find_all(x, "//b")), 1)

  # and add the old namespace back
  xml_attr(x, "xmlns") <- "tag:foo"
  expect_equal(xml_attr(x, "xmlns"), "tag:foo")
  expect_equal(length(xml_find_all(x, "//b")), 0)
  expect_equal(length(xml_find_all(x, "//d1:b", xml_ns(x))), 1)

  expect_equal(xml_attr(x, "xmlns"), "tag:foo")
})

test_that("xml_attr<- removes prefixed namespaces if desired", {
  x <- read_xml("<a xmlns:pre = 'tag:foo'><pre:b/></a>")

  # cannot find //b with a prefixed namespace
  expect_equal(length(xml_find_all(x, "//b")), 0)

  # unless we specify it explicitly
  expect_equal(length(xml_find_all(x, "//b")), 0)
  expect_equal(length(xml_find_all(x, "//pre:b", xml_ns(x))), 1)

  # but can find it once we remove the namespace
  xml_attr(x, "xmlns:pre") <- NULL
  expect_equal(length(xml_find_all(x, "//b")), 1)

  # and add the old namespace back
  xml_attr(x, "xmlns:pre") <- "tag:foo"
  xml_set_namespace(xml_children(x)[[1]], "pre")
  expect_equal(xml_attr(x, "xmlns:pre"), "tag:foo")
  expect_equal(length(xml_find_all(x, "//b")), 0)
  expect_equal(length(xml_find_all(x, "//pre:b", xml_ns(x))), 1)

  expect_equal(xml_attr(x, "xmlns:pre"), "tag:foo")
})

test_that("xml_set_attr works identically to xml_attr<-", {
  content <- "<a><b><c/></b><b/></a>"
  x <- read_xml(content)
  y <- read_xml(content)

  xml_attr(x, "a") <- "test"
  xml_set_attr(y, "a", "test")

  expect_equal(as.character(x), as.character(y))

  bx <- xml_find_all(x, "//b")
  by <- xml_find_all(y, "//b")

  xml_attr(bx, "b") <- "test2"
  xml_set_attr(by, "b", "test2")

  expect_equal(as.character(x), as.character(y))

  # No errors for xml_missing
  mss <- xml_find_first(bx, "./c")
  expect_error(xml_attr(mss[[2]], "b") <- "blah", NA)
  expect_error(xml_set_attr(mss[[2]], "b", "blah"), NA)
})

test_that("xml_set_attrs works identically to xml_attrs<-", {
  content <- "<a><b><c/></b><b/></a>"
  x <- read_xml(content)
  y <- read_xml(content)

  xml_attrs(x) <- c(a = "test")
  xml_set_attrs(y, c(a = "test"))

  expect_equal(as.character(x), as.character(y))

  bx <- xml_find_all(x, "//b")
  by <- xml_find_all(y, "//b")

  xml_attrs(bx) <- c(b = "test2")
  xml_set_attrs(by, c(b = "test2"))

  expect_equal(as.character(x), as.character(y))

  # No errors for xml_missing
  mss <- xml_find_first(bx, "./c")
  expect_error(xml_attrs(mss[[2]]) <- c("b" = "blah"), NA)
  expect_error(xml_set_attrs(mss[[2]], c("b" = "blah")), NA)
})
