# Escape and unescape urls.

Escape and unescape urls.

## Usage

``` r
url_escape(x, reserved = "")

url_unescape(x)
```

## Arguments

- x:

  A character vector of urls.

- reserved:

  A string containing additional characters to avoid escaping.

## Examples

``` r
url_escape("a b c")
#> [1] "a%20b%20c"
url_escape("a b c", "")
#> [1] "a%20b%20c"

url_unescape("a%20b%2fc")
#> [1] "a b/c"
url_unescape("%C2%B5")
#> [1] "µ"
```
