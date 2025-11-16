# Validate XML schema

Validate an XML document against an XML 1.0 schema.

## Usage

``` r
xml_validate(x, schema)
```

## Arguments

- x:

  A document, node, or node set.

- schema:

  an XML document containing the schema

## Value

TRUE or FALSE

## Examples

``` r
# Example from https://msdn.microsoft.com/en-us/library/ms256129(v=vs.110).aspx
doc <- read_xml(system.file("extdata/order-doc.xml", package = "xml2"))
schema <- read_xml(system.file("extdata/order-schema.xml", package = "xml2"))
xml_validate(doc, schema)
#> [1] TRUE
#> attr(,"errors")
#> character(0)
```
