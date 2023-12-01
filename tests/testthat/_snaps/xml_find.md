# xml_find_num errors with non numeric results

    Code
      xml_find_num(x, "//z")
    Condition
      Error in `xml_find_num()`:
      ! Element at path `//z` must be a number, not a <xml_missing> object.
    Code
      xml_find_num(x, "//y")
    Condition
      Error in `xml_find_num()`:
      ! Element at path `//y` must be a number, not a list.
    Code
      xml_find_num(x, "1=1")
    Condition
      Error in `xml_find_num()`:
      ! Element at path `1=1` must be a number, not `TRUE`.
    Code
      xml_find_num(x, "string(5)")
    Condition
      Error in `xml_find_num()`:
      ! Element at path `string(5)` must be a number, not the string "5".

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

    Code
      xml_find_chr(x, "//z")
    Condition
      Error in `xml_find_chr()`:
      ! Element at path `//z` must be a single string, not a <xml_missing> object.
    Code
      xml_find_chr(x, "//y")
    Condition
      Error in `xml_find_chr()`:
      ! Element at path `//y` must be a single string, not a list.
    Code
      xml_find_chr(x, "1=1")
    Condition
      Error in `xml_find_chr()`:
      ! Element at path `1=1` must be a single string, not `TRUE`.
    Code
      xml_find_chr(x, "1+1")
    Condition
      Error in `xml_find_chr()`:
      ! Element at path `1+1` must be a single string, not the number 2.

# xml_find_lgl errors with non logical results

    Code
      xml_find_lgl(x, "//z")
    Condition
      Error in `xml_find_lgl()`:
      ! Element at path `//z` must be `TRUE` or `FALSE`, not a <xml_missing> object.
    Code
      xml_find_lgl(x, "//y")
    Condition
      Error in `xml_find_lgl()`:
      ! Element at path `//y` must be `TRUE` or `FALSE`, not a list.
    Code
      xml_find_lgl(x, "string(5)")
    Condition
      Error in `xml_find_lgl()`:
      ! Element at path `string(5)` must be `TRUE` or `FALSE`, not the string "5".
    Code
      xml_find_lgl(x, "1+1")
    Condition
      Error in `xml_find_lgl()`:
      ! Element at path `1+1` must be `TRUE` or `FALSE`, not the number 2.

