# xml2

The xml2 package is a binding to [libxml2](http://xmlsoft.org), making it easy to use XML from R.

## Installation

xml2 is not yet available from CRAN, but you can install it from github with:

```R
# install.packages("devtools")
devtools::install_github("hadley/xml2")
```

## Usage

```R
library(xml2)
x <- xml("<foo> <bar> text <baz/> </bar> </foo>")
x

xml_name(x)
xml_children(x)
xml_text(x)
```

## Compared to the XML package

The XML package has similar goals to xml2. The main differences are:

* xml2 takes care of memory management for you. It will automatically
  free the memory used by an XML document as soon as the last reference
  to it goes away.

* xml2 only exposes a fraction of the functions that XML does. Currently,
  the biggest difference is that xml2 provides no way to modify an existing
  xml document or create a new one.

* xml2 uses S3, not S4. Every function is generic, with methods for 
  documents, nodes and nodesets. This should mean you don't need to think
  about exactly what type of object you have, xml2 will just do the write
  thing.
