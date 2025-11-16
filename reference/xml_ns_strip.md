# Strip the default namespaces from a document

Strip the default namespaces from a document

## Usage

``` r
xml_ns_strip(x)
```

## Arguments

- x:

  A document, node, or node set.

## Examples

``` r
x <- read_xml(
  "<foo xmlns = 'http://foo.com'>
   <baz/>
   <bar xmlns = 'http://bar.com'>
     <baz/>
   </bar>
  </foo>"
)
# Need to specify the default namespaces to find the baz nodes
xml_find_all(x, "//d1:baz")
#> {xml_nodeset (1)}
#> [1] <baz/>
xml_find_all(x, "//d2:baz")
#> {xml_nodeset (1)}
#> [1] <baz/>

# After stripping the default namespaces you can find both baz nodes directly
xml_ns_strip(x)
xml_find_all(x, "//baz")
#> {xml_nodeset (2)}
#> [1] <baz/>
#> [2] <baz/>
```
