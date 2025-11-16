# Construct a cdata node

Construct a cdata node

## Usage

``` r
xml_cdata(content)
```

## Arguments

- content:

  The CDATA content, does not include `<![CDATA[`

## Examples

``` r
x <- xml_new_root("root")
xml_add_child(x, xml_cdata("<d/>"))
as.character(x)
#> [1] "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<root><![CDATA[<d/>]]></root>\n"
```
