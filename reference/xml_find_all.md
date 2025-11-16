# Find nodes that match an xpath expression.

Xpath is like regular expressions for trees - it's worth learning if
you're trying to extract nodes from arbitrary locations in a document.
Use `xml_find_all` to find all matches - if there's no match you'll get
an empty result. Use `xml_find_first` to find a specific match - if
there's no match you'll get an `xml_missing` node.

## Usage

``` r
xml_find_all(x, xpath, ns = xml_ns(x), ...)

# S3 method for class 'xml_nodeset'
xml_find_all(x, xpath, ns = xml_ns(x), flatten = TRUE, ...)

xml_find_first(x, xpath, ns = xml_ns(x))

xml_find_num(x, xpath, ns = xml_ns(x))

xml_find_int(x, xpath, ns = xml_ns(x))

xml_find_chr(x, xpath, ns = xml_ns(x))

xml_find_lgl(x, xpath, ns = xml_ns(x))
```

## Arguments

- x:

  A document, node, or node set.

- xpath:

  A string containing an xpath (1.0) expression.

- ns:

  Optionally, a named vector giving prefix-url pairs, as produced by
  [`xml_ns()`](http://xml2.r-lib.org/reference/xml_ns.md). If provided,
  all names will be explicitly qualified with the ns prefix, i.e. if the
  element `bar` is defined in namespace `foo`, it will be called
  `foo:bar`. (And similarly for attributes). Default namespaces must be
  given an explicit name. The ns is ignored when using
  [`xml_name<-()`](http://xml2.r-lib.org/reference/xml_name.md) and
  [`xml_set_name()`](http://xml2.r-lib.org/reference/xml_name.md).

- ...:

  Further arguments passed to or from other methods.

- flatten:

  A logical indicating whether to return a single, flattened nodeset or
  a list of nodesets.

## Value

`xml_find_all` returns a nodeset if applied to a node, and a nodeset or
a list of nodesets if applied to a nodeset. If there are no matches, the
nodeset(s) will be empty. Within each nodeset, the result will always be
unique; repeated nodes are automatically de-duplicated.

`xml_find_first` returns a node if applied to a node, and a nodeset if
applied to a nodeset. The output is *always* the same size as the input.
If there are no matches, `xml_find_first` will return a missing node; if
there are multiple matches, it will return the first only.

`xml_find_num`, `xml_find_chr`, `xml_find_lgl` return numeric, character
and logical results respectively.

## Deprecated functions

`xml_find_one()` has been deprecated. Instead use `xml_find_first()`.

## See also

[`xml_ns_strip()`](http://xml2.r-lib.org/reference/xml_ns_strip.md) to
remove the default namespaces

## Examples

``` r
x <- read_xml("<foo><bar><baz/></bar><baz/></foo>")
xml_find_all(x, ".//baz")
#> {xml_nodeset (2)}
#> [1] <baz/>
#> [2] <baz/>
xml_path(xml_find_all(x, ".//baz"))
#> [1] "/foo/bar/baz" "/foo/baz"    

# Note the difference between .// and //
# //  finds anywhere in the document (ignoring the current node)
# .// finds anywhere beneath the current node
(bar <- xml_find_all(x, ".//bar"))
#> {xml_nodeset (1)}
#> [1] <bar>\n  <baz/>\n</bar>
xml_find_all(bar, ".//baz")
#> {xml_nodeset (1)}
#> [1] <baz/>
xml_find_all(bar, "//baz")
#> {xml_nodeset (2)}
#> [1] <baz/>
#> [2] <baz/>

# Find all vs find one -----------------------------------------------------
x <- read_xml("<body>
  <p>Some <b>text</b>.</p>
  <p>Some <b>other</b> <b>text</b>.</p>
  <p>No bold here!</p>
</body>")
para <- xml_find_all(x, ".//p")

# By default, if you apply xml_find_all to a nodeset, it finds all matches,
# de-duplicates them, and returns as a single nodeset. This means you
# never know how many results you'll get
xml_find_all(para, ".//b")
#> {xml_nodeset (3)}
#> [1] <b>text</b>
#> [2] <b>other</b>
#> [3] <b>text</b>

# If you set flatten to FALSE, though, xml_find_all will return a list of
# nodesets, where each nodeset contains the matches for the corresponding
# node in the original nodeset.
xml_find_all(para, ".//b", flatten = FALSE)
#> [[1]]
#> {xml_nodeset (1)}
#> [1] <b>text</b>
#> 
#> [[2]]
#> {xml_nodeset (2)}
#> [1] <b>other</b>
#> [2] <b>text</b>
#> 
#> [[3]]
#> {xml_nodeset (0)}
#> 

# xml_find_first only returns the first match per input node. If there are 0
# matches it will return a missing node
xml_find_first(para, ".//b")
#> {xml_nodeset (3)}
#> [1] <b>text</b>
#> [2] <b>other</b>
#> [3] NA
xml_text(xml_find_first(para, ".//b"))
#> [1] "text"  "other" NA     

# Namespaces ---------------------------------------------------------------
# If the document uses namespaces, you'll need use xml_ns to form
# a unique mapping between full namespace url and a short prefix
x <- read_xml('
 <root xmlns:f = "http://foo.com" xmlns:g = "http://bar.com">
   <f:doc><g:baz /></f:doc>
   <f:doc><g:baz /></f:doc>
 </root>
')
xml_find_all(x, ".//f:doc")
#> {xml_nodeset (2)}
#> [1] <f:doc>\n  <g:baz/>\n</f:doc>
#> [2] <f:doc>\n  <g:baz/>\n</f:doc>
xml_find_all(x, ".//f:doc", xml_ns(x))
#> {xml_nodeset (2)}
#> [1] <f:doc>\n  <g:baz/>\n</f:doc>
#> [2] <f:doc>\n  <g:baz/>\n</f:doc>
```
