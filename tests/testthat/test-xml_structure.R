context("xml_structure")

test_that("xml_structure", {
  expect_output(xml_structure(read_xml("<a><b><c/><c/></b><d/></a>")),
"<a>
  <b>
    <c>
    <c>
  <d>")
})
