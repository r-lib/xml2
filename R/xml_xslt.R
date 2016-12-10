#' Apply XSLT Stylesheet
#'
#' Transform an XML document using an XSL stylesheet.
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
