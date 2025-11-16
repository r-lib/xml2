# Serializing XML objects to connections.

Serializing XML objects to connections.

## Usage

``` r
xml_serialize(object, connection, ...)

xml_unserialize(connection, ...)
```

## Arguments

- object:

  R object to serialize.

- connection:

  an open [connection](https://rdrr.io/r/base/connections.html) or (for
  `serialize`) `NULL` or (for `unserialize`) a raw vector (see
  ‘Details’).

- ...:

  Additional arguments passed to
  [`read_xml()`](http://xml2.r-lib.org/reference/read_xml.md).

## Value

For `serialize`, `NULL` unless `connection = NULL`, when the result is
returned in a raw vector.

For `unserialize` an R object.

## Examples

``` r
library(xml2)
x <- read_xml("<a>
  <b><c>123</c></b>
  <b><c>456</c></b>
</a>")

b <- xml_find_all(x, "//b")
out <- xml_serialize(b, NULL)
xml_unserialize(out)
#> {xml_nodeset (2)}
#> [1] <b>\n  <c>123</c>\n</b>
#> [2] <b>\n  <c>456</c>\n</b>
```
