# Navigate around the family tree.

`xml_children` returns only elements, `xml_contents` returns all nodes.
`xml_length` returns the number of children. `xml_parent` returns the
parent node, `xml_parents` returns all parents up to the root.
`xml_siblings` returns all nodes at the same level. `xml_child` makes it
easy to specify a specific child to return.

## Usage

``` r
xml_children(x)

xml_child(x, search = 1, ns = xml_ns(x))

xml_contents(x)

xml_parents(x)

xml_siblings(x)

xml_parent(x)

xml_length(x, only_elements = TRUE)

xml_root(x)
```

## Arguments

- x:

  A document, node, or node set.

- search:

  For `xml_child`, either the child number to return (by position), or
  the name of the child node to return. If there are multiple child
  nodes with the same name, the first will be returned

- ns:

  Optionally, a named vector giving prefix-url pairs, as produced by
  [`xml_ns()`](http://xml2.r-lib.org/reference/xml_ns.md). If provided,
  all names will be explicitly qualified with the ns prefix, i.e. if the
  element `bar` is defined in namespace `foo`, it will be called
  `foo:bar`. (And similarly for attributes). Default namespaces must be
  given an explicit name. The ns is ignored when using
  [`xml_name<-()`](http://xml2.r-lib.org/reference/xml_name.md) and
  [`xml_set_name()`](http://xml2.r-lib.org/reference/xml_name.md).

- only_elements:

  For `xml_length`, should it count all children, or just children that
  are elements (the default)?

## Value

A node or nodeset (possibly empty). Results are always de-duplicated.

## Examples

``` r
x <- read_xml("<foo> <bar><boo /></bar> <baz/> </foo>")
xml_children(x)
#> {xml_nodeset (2)}
#> [1] <bar>\n  <boo/>\n</bar>
#> [2] <baz/>
xml_children(xml_children(x))
#> {xml_nodeset (1)}
#> [1] <boo/>
xml_siblings(xml_children(x)[[1]])
#> {xml_nodeset (1)}
#> [1] <baz/>

# Note the each unique node only appears once in the output
xml_parent(xml_children(x))
#> {xml_nodeset (1)}
#> [1] <foo>\n  <bar>\n    <boo/>\n  </bar>\n  <baz/>\n</foo>

# Mixed content
x <- read_xml("<foo> a <b/> c <d>e</d> f</foo>")
# Childen gets the elements, contents gets all node types
xml_children(x)
#> {xml_nodeset (2)}
#> [1] <b/>
#> [2] <d>e</d>
xml_contents(x)
#> {xml_nodeset (5)}
#> [1]  a 
#> [2] <b/>
#> [3]  c 
#> [4] <d>e</d>
#> [5]  f

xml_length(x)
#> [1] 2
xml_length(x, only_elements = FALSE)
#> [1] 5

# xml_child makes it easier to select specific children
xml_child(x)
#> {xml_node}
#> <b>
xml_child(x, 2)
#> {xml_node}
#> <d>
xml_child(x, "baz")
#> {xml_missing}
#> <NA>
```
