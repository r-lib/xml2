# Modify a tree by inserting, replacing or removing nodes

`xml_add_sibling()` and `xml_add_child()` are used to insert a node as a
sibling or a child. `xml_add_parent()` adds a new parent in between the
input node and the current parent. `xml_replace()` replaces an existing
node with a new node. `xml_remove()` removes a node from the tree.

## Usage

``` r
xml_replace(.x, .value, ..., .copy = TRUE)

xml_add_sibling(.x, .value, ..., .where = c("after", "before"), .copy = TRUE)

xml_add_child(.x, .value, ..., .where = length(xml_children(.x)), .copy = TRUE)

xml_add_parent(.x, .value, ...)

xml_remove(.x, free = FALSE)
```

## Arguments

- .x:

  a document, node or nodeset.

- .value:

  node to insert.

- ...:

  If named attributes or namespaces to set on the node, if unnamed text
  to assign to the node.

- .copy:

  whether to copy the `.value` before replacing. If this is `FALSE` then
  the node will be moved from it's current location.

- .where:

  to add the new node, for `xml_add_child` the position after which to
  add, use `0` for the first child. For `xml_add_sibling` either
  ‘"before"’ or ‘"after"’ indicating if the new node should be before or
  after `.x`.

- free:

  When removing the node also free the memory used for that node. Note
  if you use this option you cannot use any existing objects pointing to
  the node or its children, it is likely to crash R or return garbage.

## Details

Care needs to be taken when using `xml_remove()`,
