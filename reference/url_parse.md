# Parse a url into its component pieces.

Parse a url into its component pieces.

## Usage

``` r
url_parse(x)
```

## Arguments

- x:

  A character vector of urls.

## Value

A dataframe with one row for each element of `x` and columns: scheme,
server, port, user, path, query, fragment.

## Examples

``` r
url_parse("http://had.co.nz/")
#>   scheme    server port user path query fragment
#> 1   http had.co.nz   NA         /               
url_parse("http://had.co.nz:1234/")
#>   scheme    server port user path query fragment
#> 1   http had.co.nz 1234         /               
url_parse("http://had.co.nz:1234/?a=1&b=2")
#>   scheme    server port user path   query fragment
#> 1   http had.co.nz 1234         / a=1&b=2         
url_parse("http://had.co.nz:1234/?a=1&b=2#def")
#>   scheme    server port user path   query fragment
#> 1   http had.co.nz 1234         / a=1&b=2      def
```
