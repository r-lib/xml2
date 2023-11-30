# xml_find_num errors with non numeric results

    Element at path `//z` must be a number, not a <xml_missing> object.

# xml_find_int errors with non integer results

    Code
      xml_find_int(x, "//z")
    Condition
      Error in `xml_find_int()`:
      ! Element at path `//z` must be a whole number, not a <xml_missing> object.
    Code
      xml_find_int(x, "//y")
    Condition
      Error in `xml_find_int()`:
      ! Element at path `//y` must be a whole number, not a list.
    Code
      xml_find_int(x, "number(1.1)")
    Condition
      Error in `xml_find_int()`:
      ! Element at path `number(1.1)` must be a whole number, not the number 1.1.

# xml_find_chr errors with non character results

    Element at path `//z` must be a single string, not a <xml_missing> object.

# xml_find_lgl errors with non logical results

    Element at path `//z` must be `TRUE` or `FALSE`, not a <xml_missing> object.

