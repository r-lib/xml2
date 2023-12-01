# read_xml errors with an empty document

    Code
      read_xml(character())
    Condition
      Error in `read_xml()`:
      ! `x` must be a single string, not an empty character vector.

# read_xml and read_html fail with > 1 input

    Code
      read_xml(c("foo", "bar"))
    Condition
      Error in `read_xml()`:
      ! `x` must be a single string, not a character vector.
    Code
      read_html(c("foo", "bar"))
    Condition
      Error in `read_xml()`:
      ! `x` must be a single string, not a character vector.

