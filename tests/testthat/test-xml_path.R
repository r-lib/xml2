test_that("xml_path nodeset output matches individual node paths", {
  x <- read_xml(
    paste0(
      "<?pi top?>",
      "<root xmlns='urn:default' xmlns:p='urn:p'>",
      "<a plain='1' p:attr='2'/>",
      "<a>one<![CDATA[two]]>three</a>",
      "<!-- first --><!-- second -->",
      "<?pi one?><?pi two?>",
      "</root>"
    )
  )

  nodes <- xml_find_all(x, "//*|//@*|//text()|//comment()|//processing-instruction()")
  individual <- vapply(seq_along(nodes), function(i) xml_path(nodes[[i]]), character(1))

  expect_identical(xml_path(nodes), individual)
})
