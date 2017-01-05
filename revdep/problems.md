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
|date     |2017-01-05                             |

## Packages

|package   |*  |version    |date       |source                           |
|:---------|:--|:----------|:----------|:--------------------------------|
|BH        |   |1.62.0-1   |2016-11-19 |cran (@1.62.0-)                  |
|covr      |   |2.2.2      |2017-01-05 |Github (jimhester/covr@43af1f7)  |
|curl      |   |2.3        |2016-11-24 |cran (@2.3)                      |
|httr      |   |1.2.1      |2016-07-03 |cran (@1.2.1)                    |
|knitr     |   |1.15.1     |2016-11-22 |cran (@1.15.1)                   |
|magrittr  |   |1.5        |2014-11-22 |cran (@1.5)                      |
|Rcpp      |   |0.12.8.3   |2017-01-05 |Github (RcppCore/Rcpp@a53c4c5)   |
|rmarkdown |   |1.3        |2016-12-21 |cran (@1.3)                      |
|testthat  |   |1.0.2.9000 |2016-12-30 |Github (hadley/testthat@3b2f225) |
|xml2      |   |1.1.0      |2017-01-05 |local (jimhester/xml2@NA)        |

# Check results
4 packages with problems

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
6933 records found. Retrieving batch 1
131 records found. Retrieving batch 1
125058 records found. Retrieving batch 1
108967 records found. Retrieving batch 1
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

## tidyquant (0.1.0)
Maintainer: Matt Dancho <mdancho@gmail.com>  
Bug reports: https://github.com/mdancho84/tidyquant/issues

1 error  | 0 warnings | 0 notes

```
checking tests ... ERROR
Running the tests in ‘tests/testthat.R’ failed.
Last 13 lines of output:
         AAPL %>% tq_mutate_(x_fun = "close", mutate_fun = mutate_fun)
     }, paste0("fun = ", mutate_fun, " not a valid option.")) at testthat/test_tq_transform.R:118
  2: paste0("fun = ", mutate_fun, " not a valid option.") at /private/var/folders/dt/r5s12t392tb5sk181j3gs4zw0000gn/T/RtmphUL6BL/devtools13aac2becf413/hadley-testthat-3b2f225/R/expect-output.R:147
  
  testthat results ================================================================
  OK: 125 SKIPPED: 1 FAILED: 4
  1. Error: Test error on invalid x_fun, .x and .y inputs. (@test_tq_mutate.R#115) 
  2. Error: Test error on invalid x_fun, .x and .y inputs. (@test_tq_mutate.R#133) 
  3. Error: Test error on invalid x_fun, .x and .y inputs. (@test_tq_transform.R#100) 
  4. Error: Test error on invalid x_fun, .x and .y inputs. (@test_tq_transform.R#118) 
  
  Error: testthat unit tests failed
  Execution halted
```

