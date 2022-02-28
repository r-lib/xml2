#' Register S4 classes
#'
#' @description
#' Classes are exported so they can be re-used within S4 classes, see [methods::setOldClass()].
#'
#' * `xml_document`: a complete document.
#' * `xml_nodeset`: a _set_ of nodes within a document.
#' * `xml_missing`: a missing object, e.g. for an empty result set.
#' * `xml_node`: a single node in a document.
#'
#' @importFrom methods setOldClass
#' @keywords internal
#' @rdname oldclass
#' @name xml_document-class
#' @exportClass xml_document
setOldClass("xml_document")

#' @name xml_missing-class
#' @exportClass xml_missing
#' @rdname oldclass
setOldClass("xml_missing")

#' @name xml_node-class
#' @exportClass xml_node
#' @rdname oldclass
setOldClass("xml_node")

#' @name xml_nodeset-class
#' @exportClass xml_nodeset
#' @rdname oldclass
setOldClass("xml_nodeset")
