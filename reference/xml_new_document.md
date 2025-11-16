# Create a new document, possibly with a root node

`xml_new_document` creates only a new document without a root node. In
most cases you should instead use `xml_new_root`, which creates a new
document and assigns the root node in one step.

## Usage

``` r
xml_new_document(version = "1.0", encoding = "UTF-8")

xml_new_root(
  .value,
  ...,
  .copy = inherits(.value, "xml_node"),
  .version = "1.0",
  .encoding = "UTF-8"
)
```

## Arguments

- version:

  The version number of the document.

- encoding:

  The character encoding to use in the document. The default encoding is
  ‘UTF-8’. Available encodings are specified at
  <http://xmlsoft.org/html/libxml-encoding.html#xmlCharEncoding>.

- .value:

  node to insert.

- ...:

  If named attributes or namespaces to set on the node, if unnamed text
  to assign to the node.

- .copy:

  whether to copy the `.value` before replacing. If this is `FALSE` then
  the node will be moved from it's current location.

- .version:

  The version number of the document, passed to
  `xml_new_document(version)`.

- .encoding:

  The encoding of the document, passed to `xml_new_document(encoding)`.

## Value

A `xml_document` object.
