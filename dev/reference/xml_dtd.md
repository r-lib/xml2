# Construct a document type definition

This is used to create simple document type definitions. If you need to
create a more complicated definition with internal subsets it is
recommended to parse a string directly with
[`read_xml()`](http://xml2.r-lib.org/dev/reference/read_xml.md).

## Usage

``` r
xml_dtd(name = "", external_id = "", system_id = "")
```

## Arguments

- name:

  The name of the declaration

- external_id:

  The external ID of the declaration

- system_id:

  The system ID of the declaration

## Examples

``` r
r <- xml_new_root(
  xml_dtd(
    "html",
    "-//W3C//DTD XHTML 1.0 Transitional//EN",
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"
  )
)

# Use read_xml directly for more complicated DTD
d <- read_xml(
  '<!DOCTYPE doc [
<!ELEMENT doc (#PCDATA)>
<!ENTITY foo " test ">
]>
<doc>This is a valid document &foo; !</doc>'
)
```
