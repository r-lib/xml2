# Coerce a R list to xml nodes.

This turns an R list into the equivalent XML document. Not all R lists
will produce valid XML, in particular there can only be one root node
and all child nodes need to be named (or empty) lists. R attributes
become XML attributes and R names become XML node names.

## Usage

``` r
as_xml_document(x, ...)
```

## Arguments

- x:

  A document, node, or node set.

- ...:

  Needed for compatibility with generic. Unused.

## Examples

``` r
as_xml_document(list(x = list()))
#> {xml_document}
#> <x>

# Nesting multiple nodes
as_xml_document(list(foo = list(bar = list(baz = list()))))
#> {xml_document}
#> <foo>
#> [1] <bar>\n  <baz/>\n</bar>

# attributes are stored as R attributes
as_xml_document(list(foo = structure(list(), id = "a")))
#> {xml_document}
#> <foo id="a">
as_xml_document(list(foo = list(
  bar = structure(list(), id = "a"),
  bar = structure(list(), id = "b")
)))
#> {xml_document}
#> <foo>
#> [1] <bar id="a"/>
#> [2] <bar id="b"/>
```
