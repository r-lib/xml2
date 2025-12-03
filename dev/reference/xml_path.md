# Retrieve the xpath to a node

This is useful when you want to figure out where nodes matching an xpath
expression live in a document.

## Usage

``` r
xml_path(x)
```

## Arguments

- x:

  A document, node, or node set.

## Value

A character vector.

## Examples

``` r
x <- read_xml("<foo><bar><baz /></bar><baz /></foo>")
xml_path(xml_find_all(x, ".//baz"))
#> [1] "/foo/bar/baz" "/foo/baz"    
```
