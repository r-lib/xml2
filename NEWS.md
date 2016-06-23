# xml2 1.0.0

* `xml_integer()` and `xml_double()` functions to make it easy to extract
  integer and double text from nodes (@jimhester, #97, #99).

* xml2 now supports modification and creation of XML nodes. New functions
  `xml_new_document()`, `xml_new_child()`, `xml_new_sibling()`,
  `xml_set_namespace()`, , `xml_remove()`, `xml_replace()`, `xml_root()`
  and replacement methods for `xml_name()`, `xml_attr()`, `xml_attrs()` and
  `xml_text()` (@jimhester, #9 #76)

* `xml_ns()` now keeps namespace prefixes that point to the same URI
  (@jimhester, #35, #95).

* `read_xml()` and `read_html()` methods added for `httr::response()` objects.
  (@jimhester, #63, #93)

* `xml_child()` function to make selecting children a little easier
  (@jimhester, #23, #94)

* `xml_find_one()` has been deprecated in favor of `xml_find_first()`
  (@jimhester, #58, #92)

* `xml_read()` functions now default to passing the document's namespace
  object. Namespace definitions can now be removed as well as added and
  `xml_ns_strip()` added to remove all default namespaces from a document.
  (@jimhester, #28, #89)

* `xml_read()` gains a `options` argument to control all available parsing
  options, including `HUGE` to turn off limits for parsing very large
  documents and now drops blank text nodes by default, mimicking default
  behavior of XML package. (@jimhester, #49, #62, #85, #88)

* `xml_write()` expands the path on filenames, so directories can be specified
  with '~/' (@jimhester, #86, #80)

* `xml_find_one()` now returns a 'xml_missing' node object if there are 0
  matches (@jimhester, #55, #53, hadley/rvest#82).

* `xml_find_num()`, `xml_find_chr()`, `xml_find_lgl()` functions added to
  return numeric, character and logical results from XPath expressions. (@jimhester, #55)

* `xml_name()` and `xml_text()` always correctly encode returned value as
  UTF-8 (#54).

# xml2 0.1.2

* Improved configure script - now works again on R-devel on windows.

* Compiles with older versions of libxml2.,

# xml2 0.1.1

* Make configure script more cross platform.

* Add `xml_length()` to count the number of children (#32).
