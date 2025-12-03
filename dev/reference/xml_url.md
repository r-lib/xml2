# The URL of an XML document

This is useful for interpreting relative urls with
[`url_relative()`](http://xml2.r-lib.org/dev/reference/url_absolute.md).

## Usage

``` r
xml_url(x)
```

## Arguments

- x:

  A node or document.

## Value

A character vector of length 1. Returns `NA` if the name is not set.

## Examples

``` r
catalog <- read_xml(xml2_example("cd_catalog.xml"))
xml_url(catalog)
#> [1] "/home/runner/work/_temp/Library/xml2/extdata/cd_catalog.xml"

x <- read_xml("<foo/>")
xml_url(x)
#> [1] NA
```
