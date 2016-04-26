`xml_contents<-` <- function(x, value) UseMethod("xml_contents<-")

`xml_contents<-.default` <- function(x, value) {
  stop("`xml_contents<-` must be run on a `xml_node` or `xml_nodeset`", call. = FALSE)
}

# node_set_content can modify the node such that it is no longer valid, so to
# be safe once we modify a node we have to return a NULL nodeset.
# See
# https://github.com/GNOME/libxml2/blob/e28939036281969477d3913a51c001bb7635fe54/doc/examples/xpath2.c#L163-L179
`xml_contents<-.xml_nodeset` <- function(x, value) {
  # We need to do the modification in reverse order as the modification can
  # potentially delete nodes
  lapply(rev(x), `xml_contents<-`, value = value)

  # what to return here, setting the contents could invalidate some nodes in
  # the nodeset having pointers to free'd memory.
  NULL
}

`xml_contents<-.xml_node` <- function(x, value) {
  node_set_content(x$node, value)
  x
}

`xml_attr<-` <- function(x, ...) UseMethod("xml_attr<-")

`xml_attr<-.xml_node` <- function(x, attr, ns = character(), value) {
  if (is.null(value)) {
    node_remove_attr(x$node, name = attr, nsMap = ns)
  } else {
    node_set_attr(x$node, name = attr, nsMap = ns, value)
  }
  x
}
