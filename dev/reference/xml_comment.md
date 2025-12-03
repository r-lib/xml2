# Construct a comment node

Construct a comment node

## Usage

``` r
xml_comment(content)
```

## Arguments

- content:

  The comment content

## Examples

``` r
x <- xml_new_document()
r <- xml_add_child(x, "root")
xml_add_child(r, xml_comment("Hello!"))
as.character(x)
#> [1] "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<root>\n  <!--Hello!-->\n</root>\n"
```
