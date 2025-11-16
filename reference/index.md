# Package index

## Read and write documents

- [`read_xml()`](http://xml2.r-lib.org/reference/read_xml.md)
  [`read_html()`](http://xml2.r-lib.org/reference/read_xml.md) : Read
  HTML or XML.
- [`write_xml()`](http://xml2.r-lib.org/reference/write_xml.md)
  [`write_html()`](http://xml2.r-lib.org/reference/write_xml.md) : Write
  XML or HTML to disk.
- [`download_xml()`](http://xml2.r-lib.org/reference/download_xml.md)
  [`download_html()`](http://xml2.r-lib.org/reference/download_xml.md) :
  Download a HTML or XML file

## Class coercion

- [`as_list()`](http://xml2.r-lib.org/reference/as_list.md) : Coerce xml
  nodes to a list.
- [`as_xml_document()`](http://xml2.r-lib.org/reference/as_xml_document.md)
  : Coerce a R list to xml nodes.

## URL manipulation

- [`url_absolute()`](http://xml2.r-lib.org/reference/url_absolute.md)
  [`url_relative()`](http://xml2.r-lib.org/reference/url_absolute.md) :
  Convert between relative and absolute urls.
- [`url_escape()`](http://xml2.r-lib.org/reference/url_escape.md)
  [`url_unescape()`](http://xml2.r-lib.org/reference/url_escape.md) :
  Escape and unescape urls.
- [`url_parse()`](http://xml2.r-lib.org/reference/url_parse.md) : Parse
  a url into its component pieces.

## Create and modify and document

- [`xml_new_document()`](http://xml2.r-lib.org/reference/xml_new_document.md)
  [`xml_new_root()`](http://xml2.r-lib.org/reference/xml_new_document.md)
  : Create a new document, possibly with a root node
- [`xml_replace()`](http://xml2.r-lib.org/reference/xml_replace.md)
  [`xml_add_sibling()`](http://xml2.r-lib.org/reference/xml_replace.md)
  [`xml_add_child()`](http://xml2.r-lib.org/reference/xml_replace.md)
  [`xml_add_parent()`](http://xml2.r-lib.org/reference/xml_replace.md)
  [`xml_remove()`](http://xml2.r-lib.org/reference/xml_replace.md) :
  Modify a tree by inserting, replacing or removing nodes
- [`xml_attr()`](http://xml2.r-lib.org/reference/xml_attr.md)
  [`xml_has_attr()`](http://xml2.r-lib.org/reference/xml_attr.md)
  [`xml_attrs()`](http://xml2.r-lib.org/reference/xml_attr.md)
  [`` `xml_attr<-`() ``](http://xml2.r-lib.org/reference/xml_attr.md)
  [`xml_set_attr()`](http://xml2.r-lib.org/reference/xml_attr.md)
  [`` `xml_attrs<-`() ``](http://xml2.r-lib.org/reference/xml_attr.md)
  [`xml_set_attrs()`](http://xml2.r-lib.org/reference/xml_attr.md) :
  Retrieve an attribute.
- [`xml_name()`](http://xml2.r-lib.org/reference/xml_name.md)
  [`` `xml_name<-`() ``](http://xml2.r-lib.org/reference/xml_name.md)
  [`xml_set_name()`](http://xml2.r-lib.org/reference/xml_name.md) : The
  (tag) name of an xml element.
- [`xml_set_namespace()`](http://xml2.r-lib.org/reference/xml_set_namespace.md)
  : Set the node's namespace
- [`xml_text()`](http://xml2.r-lib.org/reference/xml_text.md)
  [`` `xml_text<-`() ``](http://xml2.r-lib.org/reference/xml_text.md)
  [`xml_set_text()`](http://xml2.r-lib.org/reference/xml_text.md)
  [`xml_double()`](http://xml2.r-lib.org/reference/xml_text.md)
  [`xml_integer()`](http://xml2.r-lib.org/reference/xml_text.md) :
  Extract or modify the text
- [`xml_cdata()`](http://xml2.r-lib.org/reference/xml_cdata.md) :
  Construct a cdata node
- [`xml_comment()`](http://xml2.r-lib.org/reference/xml_comment.md) :
  Construct a comment node
- [`xml_dtd()`](http://xml2.r-lib.org/reference/xml_dtd.md) : Construct
  a document type definition
- [`xml_ns_strip()`](http://xml2.r-lib.org/reference/xml_ns_strip.md) :
  Strip the default namespaces from a document

## Search and navigate a document

- [`xml_find_all()`](http://xml2.r-lib.org/reference/xml_find_all.md)
  [`xml_find_first()`](http://xml2.r-lib.org/reference/xml_find_all.md)
  [`xml_find_num()`](http://xml2.r-lib.org/reference/xml_find_all.md)
  [`xml_find_int()`](http://xml2.r-lib.org/reference/xml_find_all.md)
  [`xml_find_chr()`](http://xml2.r-lib.org/reference/xml_find_all.md)
  [`xml_find_lgl()`](http://xml2.r-lib.org/reference/xml_find_all.md) :
  Find nodes that match an xpath expression.
- [`xml_attr()`](http://xml2.r-lib.org/reference/xml_attr.md)
  [`xml_has_attr()`](http://xml2.r-lib.org/reference/xml_attr.md)
  [`xml_attrs()`](http://xml2.r-lib.org/reference/xml_attr.md)
  [`` `xml_attr<-`() ``](http://xml2.r-lib.org/reference/xml_attr.md)
  [`xml_set_attr()`](http://xml2.r-lib.org/reference/xml_attr.md)
  [`` `xml_attrs<-`() ``](http://xml2.r-lib.org/reference/xml_attr.md)
  [`xml_set_attrs()`](http://xml2.r-lib.org/reference/xml_attr.md) :
  Retrieve an attribute.
- [`xml_path()`](http://xml2.r-lib.org/reference/xml_path.md) : Retrieve
  the xpath to a node

## Inspect a document

- [`xml_ns()`](http://xml2.r-lib.org/reference/xml_ns.md)
  [`xml_ns_rename()`](http://xml2.r-lib.org/reference/xml_ns.md) : XML
  namespaces.
- [`xml_ns_strip()`](http://xml2.r-lib.org/reference/xml_ns_strip.md) :
  Strip the default namespaces from a document
- [`xml_children()`](http://xml2.r-lib.org/reference/xml_children.md)
  [`xml_child()`](http://xml2.r-lib.org/reference/xml_children.md)
  [`xml_contents()`](http://xml2.r-lib.org/reference/xml_children.md)
  [`xml_parents()`](http://xml2.r-lib.org/reference/xml_children.md)
  [`xml_siblings()`](http://xml2.r-lib.org/reference/xml_children.md)
  [`xml_parent()`](http://xml2.r-lib.org/reference/xml_children.md)
  [`xml_length()`](http://xml2.r-lib.org/reference/xml_children.md)
  [`xml_root()`](http://xml2.r-lib.org/reference/xml_children.md) :
  Navigate around the family tree.
- [`xml_structure()`](http://xml2.r-lib.org/reference/xml_structure.md)
  [`html_structure()`](http://xml2.r-lib.org/reference/xml_structure.md)
  : Show the structure of an html/xml document.
- [`xml_type()`](http://xml2.r-lib.org/reference/xml_type.md) :
  Determine the type of a node.
- [`xml_url()`](http://xml2.r-lib.org/reference/xml_url.md) : The URL of
  an XML document
- [`xml_validate()`](http://xml2.r-lib.org/reference/xml_validate.md) :
  Validate XML schema

## Utilities

- [`xml_serialize()`](http://xml2.r-lib.org/reference/xml_serialize.md)
  [`xml_unserialize()`](http://xml2.r-lib.org/reference/xml_serialize.md)
  : Serializing XML objects to connections.
- [`xml2_example()`](http://xml2.r-lib.org/reference/xml2_example.md) :
  Get path to a xml2 example
