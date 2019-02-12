context("xml_structure")

test_that("xml_structure", {
  expect_output(xml_structure(read_xml("<a><b><c/><c/></b><d/></a>")),
"<a>
  <b>
    <c>
    <c>
  <d>")

  # indent argument
  expect_output(xml_structure(read_xml("<a><b><c/><c/></b><d/></a>"), indent = 0L),
"<a>
<b>
<c>
<c>
<d>")

  # writing to a file, #244
  tmp = tempfile()
  xml_structure(read_xml("<a><b><c/><c/></b><d/></a>"), file = tmp, append = TRUE)
  expect_equal(readLines(tmp), c("<a>", "  <b>", "    <c>", "    <c>", "  <d>"))
})
