`xml_contents<-` <- function(x, value) UseMethod("xml_contents<-")

`xml_contents<-.default` <- function(x, value) {
  stop("`xml_contents<-` must be run on a `xml_node` or `xml_nodeset`", call. = FALSE)
}

# node_set_content can modify the node such that it is no longer valid, so to
# be safe once we modify a node we have to return a NULL nodeset.
# See
# https://github.com/GNOME/libxml2/blob/e28939036281969477d3913a51c001bb7635fe54/doc/examples/xpath2.c#L163-L179
# for more details. In general invalidating previous pointers is going to be an
# issue for all mutation functions.
`xml_contents<-.xml_nodeset` <- function(x, value) {
  # We need to do the modification in reverse order as the modification can
  # potentially delete nodes
  lapply(rev(x), `xml_contents<-`, value = value)
  NULL
}

`xml_contents<-.xml_node` <- function(x, value) {
  node_set_content(x$node, value)
  x
}
