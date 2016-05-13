# xml2 0.1.2.9000

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
