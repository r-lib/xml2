# XML namespaces.

`xml_ns` extracts all namespaces from a document, matching each unique
namespace url with the prefix it was first associated with. Default
namespaces are named `d1`, `d2` etc. Use `xml_ns_rename` to change the
prefixes. Once you have a namespace object, you can pass it to other
functions to work with fully qualified names instead of local names.

## Usage

``` r
xml_ns(x)

xml_ns_rename(old, ...)
```

## Arguments

- x:

  A document, node, or node set.

- old, ...:

  An existing xml_namespace object followed by name-value (old
  prefix-new prefix) pairs to replace.

## Value

A character vector with class `xml_namespace` so the default display is
a little nicer.

## Examples

``` r
x <- read_xml('
 <root>
   <doc1 xmlns = "http://foo.com"><baz /></doc1>
   <doc2 xmlns = "http://bar.com"><baz /></doc2>
 </root>
')
xml_ns(x)
#> d1 <-> http://foo.com
#> d2 <-> http://bar.com

# When there are default namespaces, it's a good idea to rename
# them to give informative names:
ns <- xml_ns_rename(xml_ns(x), d1 = "foo", d2 = "bar")
ns
#> foo <-> http://foo.com
#> bar <-> http://bar.com

# Now we can pass ns to other xml function to use fully qualified names
baz <- xml_children(xml_children(x))
xml_name(baz)
#> [1] "baz" "baz"
xml_name(baz, ns)
#> [1] "foo:baz" "bar:baz"

xml_find_all(x, "//baz")
#> {xml_nodeset (0)}
xml_find_all(x, "//foo:baz", ns)
#> {xml_nodeset (1)}
#> [1] <baz/>

str(as_list(x))
#> List of 1
#>  $ root:List of 2
#>   ..$ doc1:List of 1
#>   .. ..$ baz: list()
#>   .. ..- attr(*, "xmlns")= chr "http://foo.com"
#>   ..$ doc2:List of 1
#>   .. ..$ baz: list()
#>   .. ..- attr(*, "xmlns")= chr "http://bar.com"
str(as_list(x, ns))
#> List of 1
#>  $ root:List of 2
#>   ..$ foo:doc1:List of 1
#>   .. ..$ foo:baz: list()
#>   .. ..- attr(*, "xmlns")= chr "http://foo.com"
#>   ..$ bar:doc2:List of 1
#>   .. ..$ bar:baz: list()
#>   .. ..- attr(*, "xmlns")= chr "http://bar.com"
```
