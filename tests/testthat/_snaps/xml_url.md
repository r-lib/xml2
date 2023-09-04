# url_absolute

    Code
      url_absolute(c(".", "..", "/", "/x"), c("http://hadley.nz/a/b/c/d",
        "http://foo.bar"))
    Condition
      Error:
      ! Base URL must be a character vector of length 1

# url_escape

    Code
      url_escape("a b c", reserved = c("a", "b"))
    Condition
      Error:
      ! `reserved` must be a character vector of length 1

