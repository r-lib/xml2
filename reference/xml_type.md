# Determine the type of a node.

Determine the type of a node.

## Usage

``` r
xml_type(x)
```

## Arguments

- x:

  A document, node, or node set.

## Examples

``` r
x <- read_xml("<foo> a <b /> <![CDATA[ blah]]></foo>")
xml_type(x)
#> [1] "element"
xml_type(xml_contents(x))
#> [1] "text"    "element" "text"    "cdata"  
```
