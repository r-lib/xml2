# xml2 1.1.1

* This is a small point release addressing installation issues found with older
  libxml2 versions shipped with RedHat Linux 6 / CentOS 6 (#163, #164).

# xml2 1.1.0

## New Features
* `write_xml()` and `write_html()` now accept connections as well as filenames
  for output. (#157)

* `xml_add_child()` now takes a `.where` argument specifying where to add the
  new children. (#138)

* `as_xml()` generic function to convert R objects to xml. The most important
  method is for lists and enables full roundtrip support for going to and back
  from xml for lists and enables full roundtrip support to and from XML. (#137, #143)

* `xml_new_root()` can be used to create a new document and a root node in one step (#131).

* `xml_add_parent()` inserts a new node between the node and its parent (#129)

* Add `xml_validate()` to validate a document against an xml schema (#31, @jeroenooms).

* Export `xml2_types.h` to allow for extension packages such as xslt.

* `xml_comment()` allows you to add comment nodes to a document. (#111)

* `xml_cdata()` allows you to add CDATA nodes to a document. (#128)

* Add `xml_set_text()` and `xml_set_name()` equivalent to `xml_text<-` and `xml_name<-`. (#130).

* Add `xml_set_attr()` and `xml_set_attrs()` equivalent to `xml_attr<-` and `xml_attrs<-`. (#109, #130)

* Add `write_html()` method (#133).

## Bugfixes

* `xml_new_document()` now explicitly sets the encoding (default UTF-8) (#142)

* Document formatting options for `write_xml()` (#132)

* Add missing methods for xml_missing objects. (#134)

* Bugfix for xml_length.xml_nodeset that caused it to fail unconditionally. (#140)

* `is.na()` now returns `TRUE` for `xml_missing` objects. (#139)

* Trim non-breaking spaces in `xml_text(trim = TRUE)` (#151).

* Allow setting non-character attributes (values are coerced to characters). (@sjp, #117, #122).

* Fixed return value in call to vapply in xml_integer.xml_nodeset. (@ddiez, #146, #147).

* Allow docs missing a root element to be created and printed. (@sjp, #126, #121).

* xml_add_* methods now return invisibly. (@sjp, #124)

* `as_list()` now preserves element names when attributes exist, and escapes
  XML attributes that conflict with special R attributes (@peterfoley, #115).

# xml2 1.0.0

* All C++ functions now use `checked_get()` instead of `get()` where possible,
  so NULL XPtrs properly throw an error rather than crashing. (@jimhester,
  #101, #104).

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
