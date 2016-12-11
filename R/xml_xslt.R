#' XSLT 1.0 Transformations
#'
#' Transform an XML document by applying an XSL stylesheet.
#'
#' This implementation supports XSLT 1.0 features plus most of the EXSLT set of
#' processor-portable extensions functions. Unfortunately XSLT 2.0 or 3.0 features
#' are only available in proprietary libraries and currently unsupported. However
#' XSLT 2.0 is not widely adopted anyway because it is also unavailable in most
#' browsers.
#'
#' @export
#' @inheritParams xml_name
#' @param stylesheet an xml document containing an XSL stylesheet
xml_xslt <- function(x, stylesheet){
  UseMethod("xml_xslt")
}

#' @export
xml_xslt.xml_document <- function(x, stylesheet){
  stopifnot(inherits(stylesheet, "xml_document"))
  xml_document(doc_xslt_apply(x$doc, stylesheet$doc))
}
