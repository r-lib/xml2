# Write XML or HTML to disk.

This writes out both XML and normalised HTML. The default behavior will
output the same format which was read. If you want to force output pass
`option = "as_xml"` or `option = "as_html"` respectively.

## Usage

``` r
write_xml(x, file, ...)

# S3 method for class 'xml_document'
write_xml(x, file, ..., options = "format", encoding = "UTF-8")

write_html(x, file, ...)

# S3 method for class 'xml_document'
write_html(x, file, ..., options = "format", encoding = "UTF-8")
```

## Arguments

- x:

  A document or node to write to disk. It's not possible to save
  nodesets containing more than one node.

- file:

  Path to file or connection to write to.

- ...:

  additional arguments passed to methods.

- options:

  default: ‘format’. Zero or more of

  format

  :   Format output

  no_declaration

  :   Drop the XML declaration

  no_empty_tags

  :   Remove empty tags

  no_xhtml

  :   Disable XHTML1 rules

  require_xhtml

  :   Force XHTML rules

  as_xml

  :   Force XML output

  as_html

  :   Force HTML output

  format_whitespace

  :   Format with non-significant whitespace

- encoding:

  The character encoding to use in the document. The default encoding is
  ‘UTF-8’. Available encodings are specified at
  <http://xmlsoft.org/html/libxml-encoding.html#xmlCharEncoding>.

## Examples

``` r
h <- read_html("<p>Hi!</p>")

tmp <- tempfile(fileext = ".xml")
write_xml(h, tmp, options = "format")
readLines(tmp)
#> [1] "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\" \"http://www.w3.org/TR/REC-html40/loose.dtd\">"
#> [2] "<html><body><p>Hi!</p></body></html>"                                                                          

# write formatted HTML output
write_html(h, tmp, options = "format")
readLines(tmp)
#> [1] "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\" \"http://www.w3.org/TR/REC-html40/loose.dtd\">"
#> [2] "<html><body><p>Hi!</p></body></html>"                                                                          
```
