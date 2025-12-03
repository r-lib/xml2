# Retrieve an attribute.

`xml_attrs()` retrieves all attributes values as a named character
vector, `xml_attrs() <-` or `xml_set_attrs()` sets all attribute values.
`xml_attr()` retrieves the value of single attribute and `xml_attr() <-`
or `xml_set_attr()` modifies its value. If the attribute doesn't exist,
it will return `default`, which defaults to `NA`. `xml_has_attr()` tests
if an attribute is present.

## Usage

``` r
xml_attr(x, attr, ns = character(), default = NA_character_)

xml_has_attr(x, attr, ns = character())

xml_attrs(x, ns = character())

xml_attr(x, attr, ns = character()) <- value

xml_set_attr(x, attr, value, ns = character())

xml_attrs(x, ns = character()) <- value

xml_set_attrs(x, value, ns = character())
```

## Arguments

- x:

  A document, node, or node set.

- attr:

  Name of attribute to extract.

- ns:

  Optionally, a named vector giving prefix-url pairs, as produced by
  [`xml_ns()`](http://xml2.r-lib.org/dev/reference/xml_ns.md). If
  provided, all names will be explicitly qualified with the ns prefix,
  i.e. if the element `bar` is defined in namespace `foo`, it will be
  called `foo:bar`. (And similarly for attributes). Default namespaces
  must be given an explicit name. The ns is ignored when using
  [`xml_name<-()`](http://xml2.r-lib.org/dev/reference/xml_name.md) and
  [`xml_set_name()`](http://xml2.r-lib.org/dev/reference/xml_name.md).

- default:

  Default value to use when attribute is not present.

- value:

  character vector of new value.

## Value

`xml_attr()` returns a character vector. `NA` is used to represent of
attributes that aren't defined.

`xml_has_attr()` returns a logical vector.

`xml_attrs()` returns a named character vector if `x` x is single node,
or a list of character vectors if given a nodeset

## Examples

``` r
x <- read_xml("<root id='1'><child id ='a' /><child id='b' d='b'/></root>")
xml_attr(x, "id")
#> [1] "1"
xml_attr(x, "apple")
#> [1] NA
xml_attrs(x)
#>  id 
#> "1" 

kids <- xml_children(x)
kids
#> {xml_nodeset (2)}
#> [1] <child id="a"/>
#> [2] <child id="b" d="b"/>
xml_attr(kids, "id")
#> [1] "a" "b"
xml_has_attr(kids, "id")
#> [1] TRUE TRUE
xml_attrs(kids)
#> [[1]]
#>  id 
#> "a" 
#> 
#> [[2]]
#>  id   d 
#> "b" "b" 
#> 

# Missing attributes give missing values
xml_attr(xml_children(x), "d")
#> [1] NA  "b"
xml_has_attr(xml_children(x), "d")
#> [1] FALSE  TRUE

# If the document has a namespace, use the ns argument and
# qualified attribute names
x <- read_xml('
 <root xmlns:b="http://bar.com" xmlns:f="http://foo.com">
   <doc b:id="b" f:id="f" id="" />
 </root>
')
doc <- xml_children(x)[[1]]
ns <- xml_ns(x)

xml_attrs(doc)
#>  id  id  id 
#> "b" "f" "b" 
xml_attrs(doc, ns)
#> b:id f:id   id 
#>  "b"  "f"   "" 

# If you don't supply a ns spec, you get the first matching attribute
xml_attr(doc, "id")
#> [1] "b"
xml_attr(doc, "b:id", ns)
#> [1] "b"
xml_attr(doc, "id", ns)
#> [1] ""

# Can set a single attribute with `xml_attr() <-` or `xml_set_attr()`
xml_attr(doc, "id") <- "one"
xml_set_attr(doc, "id", "two")

# Or set multiple attributes with `xml_attrs()` or `xml_set_attrs()`
xml_attrs(doc) <- c("b:id" = "one", "f:id" = "two", "id" = "three")
xml_set_attrs(doc, c("b:id" = "one", "f:id" = "two", "id" = "three"))
```
