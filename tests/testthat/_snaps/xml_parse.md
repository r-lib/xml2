# read_xml errors with an empty document

    `x` must be a single string, not an empty character vector.

# parse_options errors when given an invalid option

    Code
      read_html(test_path("lego.html.bz2"), options = "INVALID")
    Condition
      Error in `read_html()`:
      x `options` "INVALID" is not a valid option.
      i Valid options are one of "RECOVER", "NOENT", "DTDLOAD", "DTDATTR", "DTDVALID", "NOERROR", "NOWARNING", "PEDANTIC", "NOBLANKS", "SAX1", "XINCLUDE", "NONET", "NODICT", "NSCLEAN", "NOCDATA", "NOXINCNODE", "COMPACT", "OLD10", ..., "IGNORE_ENC", or "BIG_LINES".
      i See read_html (`?xml2::read_html()`) for all options.

# read_xml and read_html fail with > 1 input

    `x` must be a single string, not a character vector.

