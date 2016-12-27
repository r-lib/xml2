context("modify nodes")

test_that("modifying nodes works", {
  x <- read_xml("<x><y/></x>")
  node <- xml_find_first(x, "//x")

  expect_equal(xml_name(node), "x")

  node_set_name(node$node, "y")
  expect_equal(xml_name(node), "y")

  expect_equal(xml_text(node), "")

  node_set_content(node$node, "test")
  expect_equal(xml_text(node), "test")
})

test_that("xml_text<- only modifies text content", {
  x <- read_xml("<node>Text1<subnode/>text2</node>")

  expect_equal(xml_text(x), "Text1text2")

  # will only change the first text by default
  xml_text(x) <- "new_text1"
  expect_equal(xml_text(x), "new_text1text2")

  # You can change the second by explicitly selecting it
  text_node <- xml_find_first(x, "//text()[2]")
  xml_text(text_node) <- "new_text2"
  expect_equal(xml_text(x), "new_text1new_text2")
})

test_that("xml_text<- creates new text nodes if needed", {
  x <- read_xml("<node><subnode/></node>")
  xml_text(x) <- "test"

  expect_equal(xml_text(x), "test")
})

test_that("xml_remove removes nodes", {

  x <- read_xml("<parent><child>1</child><child>2<child>3</child></child></parent>")
  children <- xml_children(x)
  t1 <- children[[1]]
  xml_remove(children, free = TRUE)
  expect_equal(xml_text(x), "")
})

test_that("xml_replace replaces nodes", {

  x <- read_xml("<parent><child>1</child><child>2<child>3</child></child></parent>")
  children <- xml_children(x)
  t1 <- children[[1]]
  t2 <- children[[2]]
  t3 <- xml_children(children[[2]])[[1]]
  expect_equal(xml_text(x), "123")

  xml_replace(t1, t3)
  expect_equal(xml_text(x), "323")

  first_child <- xml_children(x)[[1]]
  xml_replace(first_child, t1, .copy = FALSE)
  expect_equal(xml_text(x), "123")
  xml_remove(first_child, free = TRUE)

  first_child <- xml_children(x)[[1]]
  xml_replace(first_child, t3, .copy = FALSE)
  expect_equal(xml_text(x), "32")
  xml_remove(first_child, free = TRUE)
})

test_that("xml_replace works with nodesets", {

  x <- read_xml("<parent><child>1</child><child>2<child>3</child></child></parent>")
  children <- xml_children(x)
  t1 <- children[[1]]
  xml_replace(children, t1)
  expect_equal(xml_text(x), "11")
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

  xml_add_sibling(t1, t3, .where = "before")
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

  xml_add_child(t1, t3, .copy = TRUE)
  expect_length(xml_children(t1), 1)
  expect_equal(xml_text(x), "1323")

  children <- xml_children(x)
  xml_add_child(children, t1)
  expect_equal(xml_text(x), "1313231313")
})

test_that("xml_add_child can create a new default namespace", {
  x <- xml_root(xml_add_child(xml_new_document(), "foo", xmlns = "bar"))

  expect_equal(unclass(xml_ns(x)), c(d1 = "bar"))
})

test_that("xml_add_child can create a new prefixed namespace", {
  x <- xml_root(xml_add_child(xml_new_document(), "foo", "xmlns:bar" = "baz"))

  expect_equal(unclass(xml_ns(x)), c(bar = "baz"))
})

test_that("xml_add_child can create a new attribute", {
  x <- xml_add_child(xml_new_document(), "foo", "bar" = "baz")

  expect_equal(xml_attr(x, "bar"), "baz")
})

test_that("xml_add_child can create new text", {
  x <- xml_add_child(xml_new_document(), "foo", "bar")

  expect_equal(xml_text(x), "bar")
})

test_that("xml_add_child can create a new node with the specified prefix", {
  x <- xml_root(xml_add_child(xml_new_document(), "foo", "xmlns:bar" = "baz"))

  t1 <- xml_add_child(x, "bar:qux")
  expect_equal(xml_name(t1), "qux")
  expect_equal(xml_name(t1, xml_ns(x)), "bar:qux")
})

test_that("xml_add_child can create a new node with the specified prefix", {
  x <- xml_root(xml_add_child(xml_new_document(), "foo", "xmlns:bar" = "baz"))

  expect_error(xml_add_child(x, "bar2:qux"), "No namespace with prefix `bar2` found")
})

test_that("xml_add_parent works with xml_node input", {
  x <- read_xml("<x><y/></x>")
  y <- xml_find_first(x, ".//y")
  xml_add_parent(y, "z")

  expect_equal(xml_name(xml_parent(y)), "z")
  expect_equal(xml_name(xml_child(x)), "z")
})

test_that("xml_add_parent works with xml_nodeset input", {
  x <- read_xml("<x><y/><y/></x>")
  y <- xml_find_all(x, ".//y")
  xml_add_parent(y, "z")

  expect_equal(xml_name(xml_parent(y)), c("z", "z"))
  expect_equal(xml_name(xml_child(x)), "z")
})

test_that("xml_add_parent works with xml_missing input", {
  x <- read_xml("<body>
    <p>Some <b>text</b>.</p>
    <p>Some <b>other</b>.</p>
    <p>No bold text</p>
    </body>")

    y <- xml_find_all(x, ".//p")
    z <- xml_find_first(y, ".//b")
    xml_add_parent(z, "em")

    expect_equal(xml_name(xml_parent(z)), c("em", "em"))
    expect_equal(xml_name(xml_children(y)), c("em", "em"))
})

test_that("xml_new_document adds a default character encoding", {

  x <- read_xml("<root>\u00E1\u00FC\u00EE</root>")
  expect_equal(as.character(x), "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<root>\u00E1\u00FC\u00EE</root>\n")

  x2 <- xml_new_document()
  xml_add_child(x2, "root", "\u00E1\u00FC\u00EE")
  expect_equal(as.character(x2), "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<root>\u00E1\u00FC\u00EE</root>\n")
})

test_that("xml_new_root is equivalent to using xml_new_document xml_add_child", {
  x1 <- xml_add_child(xml_new_document(), "foo", "bar")

  x2 <- xml_new_root("foo", "bar")

  expect_identical(as.character(x1), as.character(x2))
})

test_that("xml_add_child can insert anywhere in the child list", {
  x <- read_xml("<a/>")

  xml_add_child(x, "z")
  expect_equal(c("z"), xml_name(xml_children(x)))

  xml_add_child(x, "w", .where = 0)
  expect_equal(c("w", "z"), xml_name(xml_children(x)))

  xml_add_child(x, "y", .where = 1)
  expect_equal(c("w", "y", "z"), xml_name(xml_children(x)))

  xml_add_child(x, "x", .where = 1)
  expect_equal(c("w", "x", "y", "z"), xml_name(xml_children(x)))
})

test_that("xml_add_child can insert anywhere in a nodeset", {
  x <- read_xml("<body>
    <p>Some <b>text</b>.</p>
    <p>Some <b>other</b>.</p>
    <p>No bold text</p>
    </body>")

    y <- xml_find_all(x, ".//p")
    z <- xml_find_first(y, ".//b")

    xml_add_child(z, "bar")
    xml_add_child(z, "foo", .where = 0)

    expect_equal(c("foo", "bar", "foo", "bar"), xml_name(xml_children(z)))
})
