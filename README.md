# xml2

The xml2 package is a binding to [libxml2](http://xmlsoft.org), making it easy to work with HTML and XML from R. The API is somewhat inspired by [jQuery](http://jquery.com).

## Installation

xml2 is not yet available from CRAN, but you can install it from github with:

```R
# install.packages("devtools")
devtools::install_github("RcppCore/Rcpp")
devtools::install_github("hadley/xml2")
```

## Usage

```R
library("xml2"")
x <- xml("<foo> <bar> text <baz/> </bar> </foo>")
x

xml_name(x)
xml_children(x)
xml_text(x)
xml_find(x, ".//baz")

h <- html("<html><p>Hi <b>!")
h
xml_name(h)
xml_text(h)
```

There are three key classes:

* `xml_node`: a single node in a document.

* `xml_doc`: the complete document. Acting on a document is usually the same 
  as acting on the root node of the document.

* `xml_nodeset`: a __set__ of nodes within the document. Operations on 
  `xml_nodeset`s are vectorised, apply the operation over each node in the set.

## Compared to the XML package

xml2 has similar goals to the XML package. The main differences are:

* xml2 takes care of memory management for you. It will automatically
  free the memory used by an XML document as soon as the last reference
  to it goes away.

* xml2 only exposes a fraction of the functions that XML does. Currently,
  the biggest difference is that xml2 provides no way to modify an existing
  xml document or create a new one.

* xml2 has a very simple class hierarchy so don't need to think about exactly 
  what type of object you have, xml2 will just do the right thing.

* More convenient handling of namespaces - see `xml_ns()` to get started.
