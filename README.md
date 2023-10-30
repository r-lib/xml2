
<!-- README.md is generated from README.Rmd. Please edit that file -->

# xml2

<!-- badges: start -->

[![CRAN_Status_Badge](https://www.r-pkg.org/badges/version/xml2)](https://cran.r-project.org/package=xml2)
[![Codecov test
coverage](https://codecov.io/gh/r-lib/xml2/branch/master/graph/badge.svg)](https://app.codecov.io/gh/r-lib/xml2?branch=main)
[![R build
status](https://github.com/r-lib/xml2/workflows/R-CMD-check/badge.svg)](https://github.com/r-lib/xml2/actions)
[![R-CMD-check](https://github.com/r-lib/xml2/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/r-lib/xml2/actions/workflows/R-CMD-check.yaml)
<!-- badges: end -->

The xml2 package is a binding to [libxml2](http://xmlsoft.org), making
it easy to work with HTML and XML from R. The API is somewhat inspired
by [jQuery](https://jquery.com).

## Installation

You can install xml2 from CRAN,

``` r
install.packages("xml2")
```

or you can install the development version from github, using
`devtools`:

``` r
# install.packages("pak")
pak::pak("r-lib/xml2")
```

## Usage

``` r
library("xml2")
x <- read_xml("<foo> <bar> text <baz/> </bar> </foo>")
x

xml_name(x)
xml_children(x)
xml_text(x)
xml_find_all(x, ".//baz")

h <- read_html("<html><p>Hi <b>!")
h
xml_name(h)
xml_text(h)
```

There are three key classes:

- `xml_node`: a single node in a document.

- `xml_doc`: the complete document. Acting on a document is usually the
  same as acting on the root node of the document.

- `xml_nodeset`: a **set** of nodes within the document. Operations on
  `xml_nodeset`s are vectorised, apply the operation over each node in
  the set.

## Compared to the XML package

xml2 has similar goals to the XML package. The main differences are:

- xml2 takes care of memory management for you. It will automatically
  free the memory used by an XML document as soon as the last reference
  to it goes away.

- xml2 has a very simple class hierarchy so you don’t need to think
  about exactly what type of object you have, xml2 will just do the
  right thing.

- More convenient handling of namespaces in Xpath expressions - see
  `xml_ns()` and `xml_ns_strip()` to get started.

## Code of Conduct

Please note that the xml2 project is released with a [Contributor Code
of Conduct](https://xml2.r-lib.org/CODE_OF_CONDUCT.html). By
contributing to this project, you agree to abide by its terms.
