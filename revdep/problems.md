# Setup

## Platform

|setting  |value                                  |
|:--------|:--------------------------------------|
|version  |R version 3.3.2 RC (2016-10-26 r71594) |
|system   |x86_64, darwin13.4.0                   |
|ui       |X11                                    |
|language |(EN)                                   |
|collate  |en_US.UTF-8                            |
|tz       |America/New_York                       |
|date     |2016-12-30                             |

## Packages

|package   |*  |version    |date       |source                           |
|:---------|:--|:----------|:----------|:--------------------------------|
|BH        |   |1.62.0-1   |2016-11-19 |cran (@1.62.0-)                  |
|covr      |   |2.2.1      |2016-12-30 |Github (jimhester/covr@7e49d3e)  |
|curl      |   |2.3        |2016-11-24 |cran (@2.3)                      |
|httr      |   |1.2.1      |2016-07-03 |cran (@1.2.1)                    |
|knitr     |   |1.15.1     |2016-11-22 |cran (@1.15.1)                   |
|magrittr  |   |1.5        |2014-11-22 |cran (@1.5)                      |
|Rcpp      |   |0.12.8.3   |2016-12-30 |Github (RcppCore/Rcpp@2883ef3)   |
|rmarkdown |   |1.3        |2016-12-21 |cran (@1.3)                      |
|testthat  |   |1.0.2.9000 |2016-12-30 |Github (hadley/testthat@3b2f225) |
|xml2      |   |1.0.0.9002 |2016-12-30 |local (jimhester/xml2@NA)        |

# Check results
4 packages with problems

## covr (2.2.1)
Maintainer: Jim Hester <james.f.hester@gmail.com>  
Bug reports: https://github.com/jimhester/covr/issues

1 error  | 0 warnings | 0 notes

```
checking tests ... ERROR
Running the tests in ‘tests/testthat.R’ failed.
Last 13 lines of output:
  1. Failure: it works with coverage objects (@test-cobertura.R#7) ---------------
  readLines(tmp)[-2] not equal to readLines("cobertura.xml")[-2].
  1/35 mismatches
  x[1]: "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
  y[1]: "<?xml version=\"1.0\"?>"
  
  
  testthat results ================================================================
  OK: 231 SKIPPED: 3 FAILED: 1
  1. Failure: it works with coverage objects (@test-cobertura.R#7) 
  
  Error: testthat unit tests failed
  Execution halted
```

## europepmc (0.1.0)
Maintainer: Najko Jahn <najko.jahn@gmail.com>  
Bug reports: http://github.com/ropensci/europepmc/issues

0 errors | 1 warning  | 0 notes

```
checking re-building of vignette outputs ... WARNING
Error in re-building vignettes:
  ...
264 records found. Retrieving batch 1
339 records found. Retrieving batch 1
6929 records found. Retrieving batch 1
131 records found. Retrieving batch 1
125037 records found. Retrieving batch 1
108948 records found. Retrieving batch 1
197 records found. Returning 25
18 records found. Returning 18
Quitting from lines 176-177 (rebi-vignettes.Rmd) 
Error: processing vignette 'rebi-vignettes.Rmd' failed with diagnostics:
Internal Server Error (HTTP 500).
Execution halted

```

## gesis (0.2)
Maintainer: Eric Persson <expersso5@gmail.com>

1 error  | 1 warning  | 0 notes

```
checking tests ... ERROR
Running the tests in ‘tests/testthat.R’ failed.
Last 13 lines of output:
  > library(gesis)
  > 
  > test_check("gesis")
  1. Failure: get_study_groups() works (@test-availability.R#6) ------------------
  nrow(groups) is not strictly more than 0. Difference: 0
  
  
  testthat results ================================================================
  OK: 3 SKIPPED: 0 FAILED: 1
  1. Failure: get_study_groups() works (@test-availability.R#6) 
  
  Error: testthat unit tests failed
  Execution halted

checking re-building of vignette outputs ... WARNING
Error in re-building vignettes:
  ...
Quitting from lines 60-61 (gesis.Rmd) 
Error: processing vignette 'gesis.Rmd' failed with diagnostics:
invalid 'description' argument
Execution halted

```

## htmltidy (0.3.0)
Maintainer: Bob Rudis <bob@rud.is>  
Bug reports: https://github.com/hrbrmstr/htmltidy/issues

0 errors | 1 warning  | 0 notes

```
checking whether package ‘htmltidy’ can be installed ... WARNING
Found the following significant warnings:
  language.c:41:5: warning: flexible array initialization is a GNU extension [-Wgnu-flexible-array-initializer]
See ‘/Users/jhester/Dropbox/projects/xml2/revdep/checks/htmltidy.Rcheck/00install.out’ for details.
```

