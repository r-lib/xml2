# write_xml errors for incorrect directory and with invalid inputs

    Code
      x <- read_xml("<x/>")
      filename <- "does_not_exist/test.xml"
      write_xml(x, filename)
    Condition
      Error in `path_to_connection()`:
      ! 'does_not_exist' does not exist in current working directory ('C:/Users/RoyO/Documents/rrr-forks/xml2/tests/testthat').
    Code
      write_xml(x, c("test.xml", "foo"))
    Condition
      Error in `write_xml()`:
      ! `file` must be a single string, not a character vector.

# write_xml works with nodeset input and connections

    Code
      filename <- "../test.xml.gz"
      write_xml(y, filename, options = "no_declaration")
    Condition
      Error in `write_xml()`:
      ! Can only save length 1 node sets
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

