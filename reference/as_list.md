# Coerce xml nodes to a list.

This turns an XML document (or node or nodeset) into the equivalent R
list. Note that this is `as_list()`, not
[`as.list()`](https://rdrr.io/r/base/list.html):
[`lapply()`](https://rdrr.io/r/base/lapply.html) automatically calls
[`as.list()`](https://rdrr.io/r/base/list.html) on its inputs, so we
can't override the default.

## Usage

``` r
as_list(x, ns = character(), ...)
```

## Arguments

- x:

  A document, node, or node set.

- ns:

  Optionally, a named vector giving prefix-url pairs, as produced by
  [`xml_ns()`](http://xml2.r-lib.org/reference/xml_ns.md). If provided,
  all names will be explicitly qualified with the ns prefix, i.e. if the
  element `bar` is defined in namespace `foo`, it will be called
  `foo:bar`. (And similarly for attributes). Default namespaces must be
  given an explicit name. The ns is ignored when using
  [`xml_name<-()`](http://xml2.r-lib.org/reference/xml_name.md) and
  [`xml_set_name()`](http://xml2.r-lib.org/reference/xml_name.md).

- ...:

  Needed for compatibility with generic. Unused.

## Details

`as_list` currently only handles the four most common types of children
that an element might have:

- Other elements, converted to lists.

- Attributes, stored as R attributes. Attributes that have special
  meanings in R ([`class()`](https://rdrr.io/r/base/class.html),
  [`comment()`](https://rdrr.io/r/base/comment.html),
  [`dim()`](https://rdrr.io/r/base/dim.html),
  [`dimnames()`](https://rdrr.io/r/base/dimnames.html),
  [`names()`](https://rdrr.io/r/base/names.html),
  [`row.names()`](https://rdrr.io/r/base/row.names.html) and
  [`tsp()`](https://rdrr.io/r/stats/tsp.html)) are escaped with '.'

- Text, stored as a character vector.

## Examples

``` r
as_list(read_xml("<foo> a <b /><c><![CDATA[<d></d>]]></c></foo>"))
#> $foo
#> $foo[[1]]
#> [1] " a "
#> 
#> $foo$b
#> list()
#> 
#> $foo$c
#> $foo$c[[1]]
#> [1] "<d></d>"
#> 
#> 
#> 
as_list(read_xml("<foo> <bar><baz /></bar> </foo>"))
#> $foo
#> $foo$bar
#> $foo$bar$baz
#> list()
#> 
#> 
#> 
as_list(read_xml("<foo id = 'a'></foo>"))
#> $foo
#> list()
#> attr(,"id")
#> [1] "a"
#> 
as_list(read_xml("<foo><bar id='a'/><bar id='b'/></foo>"))
#> $foo
#> $foo$bar
#> list()
#> attr(,"id")
#> [1] "a"
#> 
#> $foo$bar
#> list()
#> attr(,"id")
#> [1] "b"
#> 
#> 
```
