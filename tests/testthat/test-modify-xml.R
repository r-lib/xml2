context("modify nodes")

test_that("modifying nodes works", {
  x <- read_xml("<x><y/></x>")
  node <- xml_find_one(x, "//x")

  expect_equal(xml_name(node), "x")

  node_set_name(node$node, "y")
  expect_equal(xml_name(node), "y")

  expect_equal(xml_text(node), "")

  node_set_content(node$node, "test")
  expect_equal(xml_text(node), "test")
})

test_that("xml_text<- modifies xml content", {
  x <- read_xml("test3.xml")
  y <- xml_find_all(x, "//discarded")
  xml_text(y) <- "discarded"
  tmp_file <- tempfile()

  write_xml(x, tmp_file)

  # verify output matches that from the xpath2 utility in libxml2
  # https://raw.githubusercontent.com/GNOME/libxml2/3eaedba1b64180668fdab7ad2eba549586017bf3/doc/examples/xpath2.res
  expect_equal(readLines(tmp_file), readLines("xpath2.res"))
})


test_that("xml_replace replaces nodes", {

  x <- read_xml("<parent><child>1</child><child>2<child>3</child></child></parent>")
  children <- xml_children(x)
  t1 <- children[[1]]
  t2 <- children[[2]]
  t3 <- xml_children(children[[2]])[[1]]
  expect_equal(xml_text(x), "123")

  xml_replace(t1) <- t3
  expect_equal(xml_text(x), "323")

  first_child <- xml_children(x)[[1]]
  xml_replace(first_child) <- t1
  expect_equal(xml_text(x), "123")

  first_child <- xml_children(x)[[1]]
  xml_replace(first_child, copy = FALSE) <- t3
  expect_equal(xml_text(x), "32")
})

test_that("xml_sibling adds a sibling node", {
  x <- read_xml("<parent><child>1</child><child>2<child>3</child></child></parent>")
  children <- xml_children(x)
  t1 <- children[[1]]
  t2 <- children[[2]]
  t3 <- xml_children(children[[2]])[[1]]

  xml_add_sibling(t1, t3)
  expect_length(xml_siblings(t1), 2)
  expect_equal(xml_text(x), "1323")

  xml_add_sibling(t1, t3, where = "before")
  expect_length(xml_siblings(t1), 3)
  expect_equal(xml_text(x), "31323")

  children <- xml_children(x)
  xml_add_sibling(children, t1)
  expect_equal(xml_text(x), "311131231")
})

test_that("xml_add_child adds a child node", {
  x <- read_xml("<parent><child>1</child><child>2<child>3</child></child></parent>")
  children <- xml_children(x)
  t1 <- children[[1]]
  t2 <- children[[2]]
  t3 <- xml_children(children[[2]])[[1]]

  expect_length(xml_children(t1), 0)

  xml_add_child(t1, t3)
  expect_length(xml_children(t1), 1)
  expect_equal(xml_text(x), "1323")

  children <- xml_children(x)
  xml_add_child(children, t1)
  expect_equal(xml_text(x), "1313231313")
})
