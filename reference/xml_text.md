# Extract or modify the text

`xml_text` returns a character vector, `xml_double` returns a numeric
vector, `xml_integer` returns an integer vector.

## Usage

``` r
xml_text(x, trim = FALSE)

xml_text(x) <- value

xml_set_text(x, value)

xml_double(x)

xml_integer(x)
```

## Arguments

- x:

  A document, node, or node set.

- trim:

  If `TRUE` will trim leading and trailing spaces.

- value:

  character vector with replacement text.

## Value

A character vector, the same length as x.

## Examples

``` r
x <- read_xml("<p>This is some text. This is <b>bold!</b></p>")
xml_text(x)
#> [1] "This is some text. This is bold!"
xml_text(xml_children(x))
#> [1] "bold!"

x <- read_xml("<x>This is some text. <x>This is some nested text.</x></x>")
xml_text(x)
#> [1] "This is some text. This is some nested text."
xml_text(xml_find_all(x, "//x"))
#> [1] "This is some text. This is some nested text."
#> [2] "This is some nested text."                   

x <- read_xml("<p>   Some text    </p>")
xml_text(x, trim = TRUE)
#> [1] "Some text"

# xml_double() and xml_integer() are useful for extracting numeric attributes
x <- read_xml("<plot><point x='1' y='2' /><point x='2' y='1' /></plot>")
xml_integer(xml_find_all(x, "//@x"))
#> [1] 1 2
```
