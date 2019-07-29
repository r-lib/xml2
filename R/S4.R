#' Register S4 classes
#'
#' @description
#' Classes are exported so they can be re-used within S4 classes, see [methods::setOldClass()].
#'
#' `xml_document`: a complete document.
#'
#' @name xml_document-class
#' @family xml_document
#' @importFrom methods setOldClass
#' @exportClass xml_document
#' @rdname oldclass
setOldClass("xml_document")

#' xml_missing class
#'
#' `xml_missing`: a missing object, e.g. for an empty result set.
#'
#' @name xml_missing-class
#' @family xml_missing
#' @exportClass xml_missing
#' @rdname oldclass
setOldClass("xml_missing")

#' xml_node Class
#'
#' `xml_node`: a single node in a document.
#'
#' @name xml_node-class
#' @family xml_node
#' @exportClass xml_node
#' @rdname oldclass
setOldClass("xml_node")

#' xml_nodeset Class
#'
#' `xml_nodeset`: a _set_ of nodes within a document.
#'
#' @name xml_nodeset-class
#' @family xml_nodeset
#' @exportClass xml_nodeset
#' @rdname oldclass
setOldClass("xml_nodeset")
