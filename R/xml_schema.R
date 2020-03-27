#' Validate XML schema
#'
#' Validate an XML document against an XML 1.0 schema.
#'
#' @inheritParams xml_name
#' @return TRUE or FALSE
#' @export
#' @param schema an XML document containing the schema
#' @examples # Example from https://msdn.microsoft.com/en-us/library/ms256129(v=vs.110).aspx
#' doc <- read_xml(system.file("extdata/order-doc.xml", package = "xml2"))
#' schema <- read_xml(system.file("extdata/order-schema.xml", package = "xml2"))
#' xml_validate(doc, schema)
xml_validate <- function(x, schema) {
  UseMethod("xml_validate")
}

#' @export
xml_validate.xml_document <- function(x, schema) {
  stopifnot(inherits(schema, "xml_document"))
  .Call(doc_validate, x$doc, schema$doc)
}
