# Setup

## Platform

|setting  |value                        |
|:--------|:----------------------------|
|version  |R version 3.3.0 (2016-05-03) |
|system   |x86_64, darwin13.4.0         |
|ui       |X11                          |
|language |(EN)                         |
|collate  |en_US.UTF-8                  |
|tz       |America/New_York             |
|date     |2016-06-14                   |

## Packages

|package   |*  |version    |date       |source                 |
|:---------|:--|:----------|:----------|:----------------------|
|BH        |   |1.60.0-2   |2016-05-07 |cran (@1.60.0-)        |
|covr      |   |2.0.1      |2016-04-06 |cran (@2.0.1)          |
|curl      |   |0.9.7      |2016-04-10 |cran (@0.9.7)          |
|httr      |   |1.1.0      |2016-01-28 |cran (@1.1.0)          |
|knitr     |   |1.13       |2016-05-09 |cran (@1.13)           |
|magrittr  |   |1.5        |2014-11-22 |cran (@1.5)            |
|Rcpp      |   |0.12.5     |2016-05-14 |cran (@0.12.5)         |
|rmarkdown |   |0.9.6      |2016-05-01 |cran (@0.9.6)          |
|testthat  |*  |1.0.2      |2016-04-23 |cran (@1.0.2)          |
|xml2      |*  |0.1.2.9000 |2016-06-14 |local (jimhester/xml2) |

# Check results
4 packages with problems

## docxtractr (0.1.0.9000)
Maintainer: Bob Rudis <bob@rudis.net>

0 errors | 1 warning  | 0 notes

```
checking examples ... WARNING
Found the following significant warnings:

  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
... 23 lines ...
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
Deprecated functions may be defunct as soon as of the next release of
R.
See ?Deprecated.
```

## rversions (1.0.2)
Maintainer: Gabor Csardi <csardi.gabor@gmail.com>  
Bug reports: https://github.com/metacran/rversions/issues

0 errors | 1 warning  | 0 notes

```
checking examples ... WARNING
Found the following significant warnings:

  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
  Warning: 'xml_find_one' is deprecated.
Deprecated functions may be defunct as soon as of the next release of
R.
See ?Deprecated.
```

## rvest (0.3.1)
Maintainer: Hadley Wickham <hadley@rstudio.com>

1 error  | 0 warnings | 0 notes

```
checking examples ... ERROR
Running examples in ‘rvest-Ex.R’ failed
The error most likely occurred in:

> base::assign(".ptime", proc.time(), pos = "CheckExEnv")
> ### Name: html
> ### Title: Parse an HTML page.
> ### Aliases: html read_xml.response read_xml.session
> ### Keywords: deprecated
> 
... 127 lines ...
      {cdata}
    <div [id]>
    <div [id]>
      <script>
        {cdata}
> google %>% html_nodes("div")
{xml_nodeset (13)}
Error in nchar(desc) : invalid multibyte string, element 10
Calls: <Anonymous> -> print.xml_nodeset -> show_nodes -> nchar
Execution halted
** found \donttest examples: check also with --run-donttest
```

## rvg (0.0.9)
Maintainer: David Gohel <david.gohel@ardata.fr>  
Bug reports: https://github.com/davidgohel/rvg/issues

1 error  | 0 warnings | 0 notes

```
checking tests ... ERROR
Running the tests in ‘tests/testthat.R’ failed.
Last 13 lines of output:
  1. Failure: pptx background does not exist if background is transparent (@test-bg.R#46) 
  2. Failure: docx background does not exist if background is transparent (@test-bg.R#91) 
  3. Failure: svg background does not exist if background is transparent (@test-bg.R#129) 
  4. Failure: check docx editable properties (@test-dml-editable.R#24) 
  5. Failure: check pptx editable properties (@test-dml-editable.R#47) 
  6. Failure: check xlsx editable properties (@test-dml-editable.R#71) 
  7. Failure: segments don't have fill (@test-docx-lines.R#14) 
  8. Failure: lines don't have fill (@test-docx-lines.R#27) 
  9. Failure: polygons without border (@test-docx-lines.R#57) 
  1. ...
  
  Error: testthat unit tests failed
  Execution halted
```

