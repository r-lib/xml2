# Changelog

## xml2 1.5.1

CRAN release: 2025-12-01

- Avoid shared libxml2 on MacOS because this reveals bugs in R.app
  ([\#471](https://github.com/r-lib/xml2/issues/471))

## xml2 1.5.0

CRAN release: 2025-11-17

- Experimental custom myExternalEntityLoader on libxml2 2.15 and up.

## xml2 1.4.1

CRAN release: 2025-10-27

- Remove a test that broke with libxml2 2.15

## xml2 1.4.0

CRAN release: 2025-08-20

- read_html() now allows huge elements by default
  ([\#455](https://github.com/r-lib/xml2/issues/455))

- Workaround for xQuartz/Cocoa on MacOS hitting our global error
  handler.

- Avoid accessing some struct internals disallowed in libxml2 2.14

## xml2 1.3.8

CRAN release: 2025-03-14

- Replace new “non-api” call IS_S4_OBJECT with Rf_isS4

- Windows: update fallback libs (for R \< 4.3) to libxml2 2.11.5

- Compile with C_VISIBILITY and CXX_VISIBILITY on supported platforms

## xml2 1.3.7

CRAN release: 2025-02-28

- Windows: use libxml2 from Rtools if found

- Update maintainer

- Minor cleanups

## xml2 1.3.6

CRAN release: 2023-12-04

- Now compatible with libxml2 2.12.0 and later
  ([@KNnut](https://github.com/KNnut)).

- Fixed format string issues detected in R-devel.

- Remove unused dependencies on glue, withr and lifecycle
  ([@mgirlich](https://github.com/mgirlich)).

- [`print()`](https://rdrr.io/r/base/print.html) is faster for very long
  `xml_nodeset` inputs
  ([\#366](https://github.com/r-lib/xml2/issues/366),
  [@michaelchirico](https://github.com/michaelchirico)).

- [`xml_attr()`](http://xml2.r-lib.org/dev/reference/xml_attr.md),
  [`xml_attrs()`](http://xml2.r-lib.org/dev/reference/xml_attr.md),
  [`xml_double()`](http://xml2.r-lib.org/dev/reference/xml_text.md),
  [`xml_integer()`](http://xml2.r-lib.org/dev/reference/xml_text.md),
  [`xml_length()`](http://xml2.r-lib.org/dev/reference/xml_children.md),
  [`xml_name()`](http://xml2.r-lib.org/dev/reference/xml_name.md),
  [`xml_path()`](http://xml2.r-lib.org/dev/reference/xml_path.md),
  [`xml_text()`](http://xml2.r-lib.org/dev/reference/xml_text.md), and
  [`xml_type()`](http://xml2.r-lib.org/dev/reference/xml_type.md) no
  longer use S3 dispatch but instead dispatch in C, leading to
  considerable performance improvements in many cases
  ([@mgirlich](https://github.com/mgirlich),
  [\#400](https://github.com/r-lib/xml2/issues/400)).

- [`xml_find_int()`](http://xml2.r-lib.org/dev/reference/xml_find_all.md)
  analogous to
  [`xml_find_num()`](http://xml2.r-lib.org/dev/reference/xml_find_all.md)
  for returning integers matched by an XPath
  ([\#365](https://github.com/r-lib/xml2/issues/365),
  [@michaelchirico](https://github.com/michaelchirico)).

- [`xml_serialize()`](http://xml2.r-lib.org/dev/reference/xml_serialize.md)
  now includes the document type so that
  [`xml_unserialize()`](http://xml2.r-lib.org/dev/reference/xml_serialize.md)
  works also for HTML documents
  ([\#407](https://github.com/r-lib/xml2/issues/407),
  [@HenrikBengtsson](https://github.com/HenrikBengtsson)).

## xml2 1.3.5

CRAN release: 2023-07-06

- Small speedup for
  [`xml_find_all()`](http://xml2.r-lib.org/dev/reference/xml_find_all.md)
  ([@mgirlich](https://github.com/mgirlich),
  [\#393](https://github.com/r-lib/xml2/issues/393)).

- Fixes for R CMD check problems.

## xml2 1.3.4

CRAN release: 2023-04-27

- Fixes for R CMD check problems.

- Windows: update to libxml2 2.10.3

## xml2 1.3.3

CRAN release: 2021-11-30

- Hadley Wickham is now (again) the maintainer.

- xml2 has been re-licensed as MIT
  ([\#317](https://github.com/r-lib/xml2/issues/317)).

- `xml_find_all.xml_node()` fails more informatively the `xpath`
  parameter is the wrong type
  ([@michaelchirico](https://github.com/michaelchirico))

- [`xml_find_all.xml_nodeset()`](http://xml2.r-lib.org/dev/reference/xml_find_all.md)
  gains a `flatten` argument to control whether to return a single
  nodeset or a list of nodesets
  ([\#311](https://github.com/r-lib/xml2/issues/311),
  [@jakejh](https://github.com/jakejh))

- [`write_xml()`](http://xml2.r-lib.org/dev/reference/write_xml.md) and
  [`write_html()`](http://xml2.r-lib.org/dev/reference/write_xml.md) now
  return NULL invisibly, as they did prior to version 1.3.0
  ([\#307](https://github.com/r-lib/xml2/issues/307))

- `XPtr` gets explicit copy constructor and assignment operator
  definitions, which were two missing components of the [Rule of
  three](https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming))
  ([@michaelchirico](https://github.com/michaelchirico))

- Windows: update to libxml2 2.9.10 and libxslt 1.1.34 and add ucrt libs

## xml2 1.3.2

CRAN release: 2020-04-23

- [`read_html()`](http://xml2.r-lib.org/dev/reference/read_xml.md) and
  [`read_xml()`](http://xml2.r-lib.org/dev/reference/read_xml.md) now
  error if passed strings of length greater than one
  ([\#121](https://github.com/r-lib/xml2/issues/121))

- [`read_xml.raw()`](http://xml2.r-lib.org/dev/reference/read_xml.md)
  had an inadvertent regression in 1.3.0 and is now again fixed
  ([\#300](https://github.com/r-lib/xml2/issues/300))

- Compilation fix on macOS 10.15.4
  ([@kevinushey](https://github.com/kevinushey),
  [\#296](https://github.com/r-lib/xml2/issues/296))

## xml2 1.3.1

CRAN release: 2020-04-09

- [`read_html()`](http://xml2.r-lib.org/dev/reference/read_xml.md) now
  again works with HTML files with non-ASCII encodings
  ([\#293](https://github.com/r-lib/xml2/issues/293)).

## xml2 1.3.0

CRAN release: 2020-04-01

- Removes the Rcpp dependency

## xml2 1.2.5

CRAN release: 2020-03-11

- Fix compilation issue on macOS versions after High Sierra when not
  using homebrew supplied libxml2

## xml2 1.2.4

CRAN release: 2020-03-10

- Fix potential dangling pointer with internal `asXmlChar()` function
  ([@michaelquinn32](https://github.com/michaelquinn32),
  [\#287](https://github.com/r-lib/xml2/issues/287)).

- [`as_xml_document()`](http://xml2.r-lib.org/dev/reference/as_xml_document.md)
  now handles cases with text nodes trailing normal nodes
  ([\#274](https://github.com/r-lib/xml2/issues/274)).

- [`xml_add_child()`](http://xml2.r-lib.org/dev/reference/xml_replace.md)
  can now create nodes with a `par` attribute. These previously errored
  due to partial name matching of the `parent` function in the internal
  `create_node()` function. ([@jennybc](https://github.com/jennybc),
  [\#285](https://github.com/r-lib/xml2/issues/285))

- `libxml2_version()` now returns a semantic version rather than
  alphanumeric version, so “2.9.10” \> “2.9.9”
  ([\#277](https://github.com/r-lib/xml2/issues/277))

## xml2 1.2.2

CRAN release: 2019-08-09

- Export S4 classes with documentation, so they can be used in other
  packages without Warnings ([@nuest](https://github.com/nuest),
  [\#267](https://github.com/r-lib/xml2/issues/267))

## xml2 1.2.1

CRAN release: 2019-07-29

### New Features

- xml2 now has a pkgdown site! <https://xml2.r-lib.org>
  ([@jayhesselberth](https://github.com/jayhesselberth),
  [\#211](https://github.com/r-lib/xml2/issues/211)).

- Windows: upgrade to libxml2 2.9.8

- print methods now match the type of document,
  e.g. [`read_html()`](http://xml2.r-lib.org/dev/reference/read_xml.md)
  prints as “{html_document}” rather than “{xml_document}”
  ([\#227](https://github.com/r-lib/xml2/issues/227))

### Bugfixes and Miscellaneous features

- Generic xml2 error are now forwarded as R errors. Previously these
  errors were output to stderr, so could not be suppressed
  ([\#209](https://github.com/r-lib/xml2/issues/209)).

- Fix for ICU 59+ defaulting to use char16_t, which is only available in
  C++11 ([\#231](https://github.com/r-lib/xml2/issues/231))

- No longer uses the C connections API

- Better error message when trying to run
  [`download_xml()`](http://xml2.r-lib.org/dev/reference/download_xml.md)
  without the curl package installed
  ([\#262](https://github.com/r-lib/xml2/issues/262))

- xml2 classes are now registered for use with S4 by calling
  `setOldClass()` ([\#248](https://github.com/r-lib/xml2/issues/248))

- Nodes with nested data type definition entities now work without
  crashing ([\#241](https://github.com/r-lib/xml2/issues/241))

- Test failure fixed due to behavior change with relative paths in
  libxml2 2.9.9 ([\#245](https://github.com/r-lib/xml2/issues/245)).

- [`read_xml()`](http://xml2.r-lib.org/dev/reference/read_xml.md) now
  has a better error message when given zero length character inputs
  ([\#212](https://github.com/r-lib/xml2/issues/212)).

- [`read_xml()`](http://xml2.r-lib.org/dev/reference/read_xml.md) and
  [`read_html()`](http://xml2.r-lib.org/dev/reference/read_xml.md) now
  automatically check if the response succeeded before trying to read
  from a HTTP response
  ([\#255](https://github.com/r-lib/xml2/issues/255)).

- [`xml_root()`](http://xml2.r-lib.org/dev/reference/xml_children.md)
  can now create root nodes with namespaces
  ([\#239](https://github.com/r-lib/xml2/issues/239))

- [`xml_set_attr()`](http://xml2.r-lib.org/dev/reference/xml_attr.md) no
  longer crashes if you try to set the same namespace on the same node
  multiple times ([\#253](https://github.com/r-lib/xml2/issues/253)).

- [`xml_set_attr()`](http://xml2.r-lib.org/dev/reference/xml_attr.md)
  now recycles the values if needed
  ([\#221](https://github.com/r-lib/xml2/issues/221))

- [`xml_structure()`](http://xml2.r-lib.org/dev/reference/xml_structure.md)
  gains a `file` argument, to support writing to a file rather than the
  console ([\#244](https://github.com/r-lib/xml2/issues/244)).

## xml2 1.2.0

CRAN release: 2018-01-24

### Breaking changes

- [`as_list()`](http://xml2.r-lib.org/dev/reference/as_list.md) on
  `xml_document` objects did not properly include the root node in the
  returned list. Previous behavior can be obtained by using
  `as_list()[[1L]]` in place of
  [`as_list()`](http://xml2.r-lib.org/dev/reference/as_list.md).

### New Features

- [`download_xml()`](http://xml2.r-lib.org/dev/reference/download_xml.md)
  and
  [`download_html()`](http://xml2.r-lib.org/dev/reference/download_xml.md)
  helper functions to make it easy to download files
  ([\#193](https://github.com/r-lib/xml2/issues/193)).

- [`xml_attr()`](http://xml2.r-lib.org/dev/reference/xml_attr.md) can
  now set attributes with no value
  ([\#198](https://github.com/r-lib/xml2/issues/198)).

- [`xml_serialize()`](http://xml2.r-lib.org/dev/reference/xml_serialize.md)
  and
  [`xml_unserialize()`](http://xml2.r-lib.org/dev/reference/xml_serialize.md)
  now create file connections when given character input
  ([\#179](https://github.com/r-lib/xml2/issues/179)).

### Bugfixes

- [`xml_find_first()`](http://xml2.r-lib.org/dev/reference/xml_find_all.md)
  no longer de-duplicates results, so the results are always the same
  length as the inputs (as documented)
  ([\#194](https://github.com/r-lib/xml2/issues/194)).

- xml2 can now build using libxml2 2.7.0

- Use Rcpp symbol registration and visibility to prevent symbol
  conflicts on Linux

- [`xml_add_child()`](http://xml2.r-lib.org/dev/reference/xml_replace.md)
  now requires less resources to insert a node when called with
  `.where = 0L` ([@heckendorfc](https://github.com/heckendorfc),
  [\#175](https://github.com/r-lib/xml2/issues/175)).

- Fixed failing examples due to a change in an external resource.

## xml2 1.1.1

CRAN release: 2017-01-24

- This is a small point release addressing installation issues found
  with older libxml2 versions shipped with RedHat Linux 6 / CentOS 6
  ([\#163](https://github.com/r-lib/xml2/issues/163),
  [\#164](https://github.com/r-lib/xml2/issues/164)).

## xml2 1.1.0

CRAN release: 2017-01-07

### New Features

- [`write_xml()`](http://xml2.r-lib.org/dev/reference/write_xml.md) and
  [`write_html()`](http://xml2.r-lib.org/dev/reference/write_xml.md) now
  accept connections as well as filenames for output.
  ([\#157](https://github.com/r-lib/xml2/issues/157))

- [`xml_add_child()`](http://xml2.r-lib.org/dev/reference/xml_replace.md)
  now takes a `.where` argument specifying where to add the new
  children. ([\#138](https://github.com/r-lib/xml2/issues/138))

- `as_xml()` generic function to convert R objects to xml. The most
  important method is for lists and enables full roundtrip support for
  going to and back from xml for lists and enables full roundtrip
  support to and from XML.
  ([\#137](https://github.com/r-lib/xml2/issues/137),
  [\#143](https://github.com/r-lib/xml2/issues/143))

- [`xml_new_root()`](http://xml2.r-lib.org/dev/reference/xml_new_document.md)
  can be used to create a new document and a root node in one step
  ([\#131](https://github.com/r-lib/xml2/issues/131)).

- [`xml_add_parent()`](http://xml2.r-lib.org/dev/reference/xml_replace.md)
  inserts a new node between the node and its parent
  ([\#129](https://github.com/r-lib/xml2/issues/129))

- Add
  [`xml_validate()`](http://xml2.r-lib.org/dev/reference/xml_validate.md)
  to validate a document against an xml schema
  ([\#31](https://github.com/r-lib/xml2/issues/31),
  [@jeroenooms](https://github.com/jeroenooms)).

- Export `xml2_types.h` to allow for extension packages such as xslt.

- [`xml_comment()`](http://xml2.r-lib.org/dev/reference/xml_comment.md)
  allows you to add comment nodes to a document.
  ([\#111](https://github.com/r-lib/xml2/issues/111))

- [`xml_cdata()`](http://xml2.r-lib.org/dev/reference/xml_cdata.md)
  allows you to add CDATA nodes to a document.
  ([\#128](https://github.com/r-lib/xml2/issues/128))

- Add
  [`xml_set_text()`](http://xml2.r-lib.org/dev/reference/xml_text.md)
  and
  [`xml_set_name()`](http://xml2.r-lib.org/dev/reference/xml_name.md)
  equivalent to `xml_text<-` and `xml_name<-`.
  ([\#130](https://github.com/r-lib/xml2/issues/130)).

- Add
  [`xml_set_attr()`](http://xml2.r-lib.org/dev/reference/xml_attr.md)
  and
  [`xml_set_attrs()`](http://xml2.r-lib.org/dev/reference/xml_attr.md)
  equivalent to `xml_attr<-` and `xml_attrs<-`.
  ([\#109](https://github.com/r-lib/xml2/issues/109),
  [\#130](https://github.com/r-lib/xml2/issues/130))

- Add [`write_html()`](http://xml2.r-lib.org/dev/reference/write_xml.md)
  method ([\#133](https://github.com/r-lib/xml2/issues/133)).

### Bugfixes

- [`xml_new_document()`](http://xml2.r-lib.org/dev/reference/xml_new_document.md)
  now explicitly sets the encoding (default UTF-8)
  ([\#142](https://github.com/r-lib/xml2/issues/142))

- Document formatting options for
  [`write_xml()`](http://xml2.r-lib.org/dev/reference/write_xml.md)
  ([\#132](https://github.com/r-lib/xml2/issues/132))

- Add missing methods for xml_missing objects.
  ([\#134](https://github.com/r-lib/xml2/issues/134))

- Bugfix for xml_length.xml_nodeset that caused it to fail
  unconditionally. ([\#140](https://github.com/r-lib/xml2/issues/140))

- [`is.na()`](https://rdrr.io/r/base/NA.html) now returns `TRUE` for
  `xml_missing` objects.
  ([\#139](https://github.com/r-lib/xml2/issues/139))

- Trim non-breaking spaces in `xml_text(trim = TRUE)`
  ([\#151](https://github.com/r-lib/xml2/issues/151)).

- Allow setting non-character attributes (values are coerced to
  characters). ([@sjp](https://github.com/sjp),
  [\#117](https://github.com/r-lib/xml2/issues/117),
  [\#122](https://github.com/r-lib/xml2/issues/122)).

- Fixed return value in call to vapply in xml_integer.xml_nodeset.
  ([@ddiez](https://github.com/ddiez),
  [\#146](https://github.com/r-lib/xml2/issues/146),
  [\#147](https://github.com/r-lib/xml2/issues/147)).

- Allow docs missing a root element to be created and printed.
  ([@sjp](https://github.com/sjp),
  [\#126](https://github.com/r-lib/xml2/issues/126),
  [\#121](https://github.com/r-lib/xml2/issues/121)).

- xml_add\_\* methods now return invisibly.
  ([@sjp](https://github.com/sjp),
  [\#124](https://github.com/r-lib/xml2/issues/124))

- [`as_list()`](http://xml2.r-lib.org/dev/reference/as_list.md) now
  preserves element names when attributes exist, and escapes XML
  attributes that conflict with special R attributes
  ([@peterfoley](https://github.com/peterfoley),
  [\#115](https://github.com/r-lib/xml2/issues/115)).

## xml2 1.0.0

CRAN release: 2016-06-24

- All C++ functions now use `checked_get()` instead of
  [`get()`](https://rdrr.io/r/base/get.html) where possible, so NULL
  XPtrs properly throw an error rather than crashing.
  ([@jimhester](https://github.com/jimhester),
  [\#101](https://github.com/r-lib/xml2/issues/101),
  [\#104](https://github.com/r-lib/xml2/issues/104)).

- [`xml_integer()`](http://xml2.r-lib.org/dev/reference/xml_text.md) and
  [`xml_double()`](http://xml2.r-lib.org/dev/reference/xml_text.md)
  functions to make it easy to extract integer and double text from
  nodes ([@jimhester](https://github.com/jimhester),
  [\#97](https://github.com/r-lib/xml2/issues/97),
  [\#99](https://github.com/r-lib/xml2/issues/99)).

- xml2 now supports modification and creation of XML nodes. New
  functions
  [`xml_new_document()`](http://xml2.r-lib.org/dev/reference/xml_new_document.md),
  `xml_new_child()`, `xml_new_sibling()`,
  [`xml_set_namespace()`](http://xml2.r-lib.org/dev/reference/xml_set_namespace.md),
  ,
  [`xml_remove()`](http://xml2.r-lib.org/dev/reference/xml_replace.md),
  [`xml_replace()`](http://xml2.r-lib.org/dev/reference/xml_replace.md),
  [`xml_root()`](http://xml2.r-lib.org/dev/reference/xml_children.md)
  and replacement methods for
  [`xml_name()`](http://xml2.r-lib.org/dev/reference/xml_name.md),
  [`xml_attr()`](http://xml2.r-lib.org/dev/reference/xml_attr.md),
  [`xml_attrs()`](http://xml2.r-lib.org/dev/reference/xml_attr.md) and
  [`xml_text()`](http://xml2.r-lib.org/dev/reference/xml_text.md)
  ([@jimhester](https://github.com/jimhester),
  [\#9](https://github.com/r-lib/xml2/issues/9)
  [\#76](https://github.com/r-lib/xml2/issues/76))

- [`xml_ns()`](http://xml2.r-lib.org/dev/reference/xml_ns.md) now keeps
  namespace prefixes that point to the same URI
  ([@jimhester](https://github.com/jimhester),
  [\#35](https://github.com/r-lib/xml2/issues/35),
  [\#95](https://github.com/r-lib/xml2/issues/95)).

- [`read_xml()`](http://xml2.r-lib.org/dev/reference/read_xml.md) and
  [`read_html()`](http://xml2.r-lib.org/dev/reference/read_xml.md)
  methods added for
  [`httr::response()`](https://httr.r-lib.org/reference/response.html)
  objects. ([@jimhester](https://github.com/jimhester),
  [\#63](https://github.com/r-lib/xml2/issues/63),
  [\#93](https://github.com/r-lib/xml2/issues/93))

- [`xml_child()`](http://xml2.r-lib.org/dev/reference/xml_children.md)
  function to make selecting children a little easier
  ([@jimhester](https://github.com/jimhester),
  [\#23](https://github.com/r-lib/xml2/issues/23),
  [\#94](https://github.com/r-lib/xml2/issues/94))

- [`xml_find_one()`](http://xml2.r-lib.org/dev/reference/xml_find_all.md)
  has been deprecated in favor of
  [`xml_find_first()`](http://xml2.r-lib.org/dev/reference/xml_find_all.md)
  ([@jimhester](https://github.com/jimhester),
  [\#58](https://github.com/r-lib/xml2/issues/58),
  [\#92](https://github.com/r-lib/xml2/issues/92))

- `xml_read()` functions now default to passing the document’s namespace
  object. Namespace definitions can now be removed as well as added and
  [`xml_ns_strip()`](http://xml2.r-lib.org/dev/reference/xml_ns_strip.md)
  added to remove all default namespaces from a document.
  ([@jimhester](https://github.com/jimhester),
  [\#28](https://github.com/r-lib/xml2/issues/28),
  [\#89](https://github.com/r-lib/xml2/issues/89))

- `xml_read()` gains a `options` argument to control all available
  parsing options, including `HUGE` to turn off limits for parsing very
  large documents and now drops blank text nodes by default, mimicking
  default behavior of XML package.
  ([@jimhester](https://github.com/jimhester),
  [\#49](https://github.com/r-lib/xml2/issues/49),
  [\#62](https://github.com/r-lib/xml2/issues/62),
  [\#85](https://github.com/r-lib/xml2/issues/85),
  [\#88](https://github.com/r-lib/xml2/issues/88))

- `xml_write()` expands the path on filenames, so directories can be
  specified with ‘~/’ ([@jimhester](https://github.com/jimhester),
  [\#86](https://github.com/r-lib/xml2/issues/86),
  [\#80](https://github.com/r-lib/xml2/issues/80))

- [`xml_find_one()`](http://xml2.r-lib.org/dev/reference/xml_find_all.md)
  now returns a ‘xml_missing’ node object if there are 0 matches
  ([@jimhester](https://github.com/jimhester),
  [\#55](https://github.com/r-lib/xml2/issues/55),
  [\#53](https://github.com/r-lib/xml2/issues/53), hadley/rvest#82).

- [`xml_find_num()`](http://xml2.r-lib.org/dev/reference/xml_find_all.md),
  [`xml_find_chr()`](http://xml2.r-lib.org/dev/reference/xml_find_all.md),
  [`xml_find_lgl()`](http://xml2.r-lib.org/dev/reference/xml_find_all.md)
  functions added to return numeric, character and logical results from
  XPath expressions. ([@jimhester](https://github.com/jimhester),
  [\#55](https://github.com/r-lib/xml2/issues/55))

- [`xml_name()`](http://xml2.r-lib.org/dev/reference/xml_name.md) and
  [`xml_text()`](http://xml2.r-lib.org/dev/reference/xml_text.md) always
  correctly encode returned value as UTF-8
  ([\#54](https://github.com/r-lib/xml2/issues/54)).

## xml2 0.1.2

CRAN release: 2015-09-01

- Improved configure script - now works again on R-devel on windows.

- Compiles with older versions of libxml2.,

## xml2 0.1.1

CRAN release: 2015-06-02

- Make configure script more cross platform.

- Add
  [`xml_length()`](http://xml2.r-lib.org/dev/reference/xml_children.md)
  to count the number of children
  ([\#32](https://github.com/r-lib/xml2/issues/32)).
