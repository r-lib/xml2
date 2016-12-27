context("dtd")

test_that("xml_dtd works", {

  r <- xml_new_root(xml_dtd(name = "html", external_id = "-//W3C//DTD XHTML 1.0 Transitional//EN", system_id = "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"))
  expect_identical("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n", as.character(r))

  no_name <- xml_new_root(xml_dtd(external_id = "-//W3C//DTD XHTML 1.0 Transitional//EN", system_id = "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"))
  expect_identical("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE  PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n", as.character(no_name))

  no_name_external_id <- xml_new_root(xml_dtd(system_id = "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"))
  expect_identical("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE  SYSTEM \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n", as.character(no_name_external_id))

  no_name_external_id_internal_id <- xml_new_root(xml_dtd())
  expect_identical("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE >\n", as.character(no_name_external_id_internal_id))
})
