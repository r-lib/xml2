# Convert between relative and absolute urls.

Convert between relative and absolute urls.

## Usage

``` r
url_absolute(x, base)

url_relative(x, base)
```

## Arguments

- x:

  A character vector of urls relative to that base

- base:

  A string giving a base url.

## Value

A character vector of urls

## See also

[`xml_url`](http://xml2.r-lib.org/dev/reference/xml_url.md) to retrieve
the URL associated with a document

## Examples

``` r
url_absolute(c(".", "..", "/", "/x"), "http://hadley.nz/a/b/c/d")
#> [1] "http://hadley.nz/a/b/c/" "http://hadley.nz/a/b/"  
#> [3] "http://hadley.nz/"       "http://hadley.nz/x"     

url_relative("http://hadley.nz/a/c", "http://hadley.nz")
#> [1] "/a/c"
url_relative("http://hadley.nz/a/c", "http://hadley.nz/")
#> [1] "a/c"
url_relative("http://hadley.nz/a/c", "http://hadley.nz/a/b")
#> [1] "c"
url_relative("http://hadley.nz/a/c", "http://hadley.nz/a/b/")
#> [1] "../c"
```
