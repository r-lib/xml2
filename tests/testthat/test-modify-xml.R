context("modify nodes")

test_that("modifying existing nodes works", {

})
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

test_that("Creating nodes works", {
  d <- doc_new("1.0")
  root_node <- node_new("html")
  doc_set_root(d, root_node)
  n <- node_new_child(root_node, "a", "Zombo.com!")
  node_new_prop(n, "href", "http://www.zombo.com")

  top <- xml_node(root_node, d)
  expect_equal(xml_length(top), 1L)
  expect_equal(xml_name(top), "html")

  child <- xml_children(top)[[1L]]
  expect_equal(xml_name(child), "a")
  expect_equal(xml_text(child), "Zombo.com!")
  expect_equal(xml_attrs(child), c(href = "http://www.zombo.com"))
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
