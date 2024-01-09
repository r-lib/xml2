# write_xml errors for incorrect directory and with invalid inputs

    Code
      write_xml(x, c("test.xml", "foo"))
    Condition
      Error in `write_xml()`:
      ! `file` must be a single string, not a character vector.

# write_xml works with nodeset input and connections

    Code
      write_xml(y[1], c(filename, "foo"))
    Condition
      Error in `write_xml()`:
      ! `file` must be a single string, not a character vector.

# write_xml works with node input and files

    Code
      write_xml(y, c(filename, "foo"))
    Condition
      Error in `write_xml()`:
      ! `file` must be a single string, not a character vector.

