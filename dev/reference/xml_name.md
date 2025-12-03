# The (tag) name of an xml element.

The (tag) name of an xml element.

Modify the (tag) name of an element

## Usage

``` r
xml_name(x, ns = character())

xml_name(x, ns = character()) <- value

xml_set_name(x, value, ns = character())
```

## Arguments

- x:

  A document, node, or node set.

- ns:

  Optionally, a named vector giving prefix-url pairs, as produced by
  [`xml_ns()`](http://xml2.r-lib.org/dev/reference/xml_ns.md). If
  provided, all names will be explicitly qualified with the ns prefix,
  i.e. if the element `bar` is defined in namespace `foo`, it will be
  called `foo:bar`. (And similarly for attributes). Default namespaces
  must be given an explicit name. The ns is ignored when using
  `xml_name<-()` and `xml_set_name()`.

- value:

  a character vector with replacement name.

## Value

A character vector.

## Examples

``` r
x <- read_xml("<bar>123</bar>")
xml_name(x)
#> [1] "bar"

y <- read_xml("<bar><baz>1</baz>abc<foo /></bar>")
z <- xml_children(y)
xml_name(xml_children(y))
#> [1] "baz" "foo"
```
