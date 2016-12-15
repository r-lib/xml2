# Setup

## Platform

|setting  |value                        |
|:--------|:----------------------------|
|version  |R version 3.3.2 (2016-10-31) |
|system   |x86_64, darwin13.4.0         |
|ui       |X11                          |
|language |(EN)                         |
|collate  |en_US.UTF-8                  |
|tz       |Europe/Amsterdam             |
|date     |2016-12-15                   |

## Packages

|package |*  |version    |date       |source                         |
|:-------|:--|:----------|:----------|:------------------------------|
|Rcpp    |   |0.12.8.2   |2016-12-15 |Github (RcppCore/Rcpp@e4ca728) |
|xml2    |   |1.0.0.9002 |2016-12-15 |local (NA/NA@c038a36)          |

# Check results
2 packages with problems

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

## ReporteRs (0.8.7)
Maintainer: David Gohel <david.gohel@lysis-consultants.fr>  
Bug reports: https://github.com/davidgohel/ReporteRs/issues

1 error  | 0 warnings | 0 notes

```
checking whether package ‘ReporteRs’ can be installed ... ERROR
Installation failed.
See ‘/Users/jeroen/workspace/xml2/revdep/checks/ReporteRs.Rcheck/00install.out’ for details.
```

