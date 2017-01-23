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
|date     |2017-01-23                             |

## Packages

|package   |*  |version    |date       |source                           |
|:---------|:--|:----------|:----------|:--------------------------------|
|BH        |   |1.62.0-1   |2016-11-19 |cran (@1.62.0-)                  |
|covr      |   |2.2.2      |2017-01-23 |Github (jimhester/covr@accef86)  |
|curl      |   |2.3        |2016-11-24 |cran (@2.3)                      |
|httr      |   |1.2.1      |2016-07-03 |cran (@1.2.1)                    |
|knitr     |   |1.15.1     |2016-11-22 |cran (@1.15.1)                   |
|magrittr  |   |1.5        |2014-11-22 |cran (@1.5)                      |
|Rcpp      |   |0.12.9.1   |2017-01-23 |Github (RcppCore/Rcpp@271148a)   |
|rmarkdown |   |1.3        |2016-12-21 |cran (@1.3)                      |
|testthat  |   |1.0.2.9000 |2016-12-30 |Github (hadley/testthat@3b2f225) |
|xml2      |   |1.1.1      |2017-01-23 |local (jimhester/xml2@NA)        |

# Check results
5 packages with problems

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

## lumendb (0.2.1)
Maintainer: Thomas J. Leeper <thosjleeper@gmail.com>  
Bug reports: https://github.com/leeper/lumendb/issues

1 error  | 0 warnings | 0 notes

```
checking tests ... ERROR
Running the tests in ‘tests/testthat.R’ failed.
Last 13 lines of output:
  
  1. Failure: Search Works (@tests.R#28) -----------------------------------------
  length(s2) not equal to 2.
  1/1 mismatches
  [1] 0 - 2 == -2
  
  
  testthat results ================================================================
  OK: 4 SKIPPED: 1 FAILED: 1
  1. Failure: Search Works (@tests.R#28) 
  
  Error: testthat unit tests failed
  Execution halted
```

## sbtools (1.1.6)
Maintainer: Tim Kern <kernt@usgs.gov>  
Bug reports: https://github.com/USGS-R/sbtools/issues

2 errors | 0 warnings | 0 notes

```
checking examples ... ERROR
Running examples in ‘sbtools-Ex.R’ failed
The error most likely occurred in:

> base::assign(".ptime", proc.time(), pos = "CheckExEnv")
> ### Name: item_get
> ### Title: Retrieve SB item
> ### Aliases: item_get
> 
> ### ** Examples
> 
> # Get an item
> item_get("4f4e4b24e4b07f02db6aea14")
Error: GET failed to https://www.sciencebase.gov/catalog/item/4f4e4b24e4b07f02db6aea14. check authorization and/or content
Execution halted

checking tests ... ERROR
Running the tests in ‘tests/testthat.R’ failed.
Last 13 lines of output:
         session = session) at /Users/jhester/Dropbox/projects/xml2/revdep/checks/sbtools.Rcheck/00_pkg_src/sbtools/R/sb_item.R:75
  14: handle_errors(r, url, "GET", supported_types) at /Users/jhester/Dropbox/projects/xml2/revdep/checks/sbtools.Rcheck/00_pkg_src/sbtools/R/REST_helpers.R:40
  15: stop(method, " failed to ", url, ". check authorization and/or content", call. = FALSE) at /Users/jhester/Dropbox/projects/xml2/revdep/checks/sbtools.Rcheck/00_pkg_src/sbtools/R/REST_helpers.R:99
  
  testthat results ================================================================
  OK: 10 SKIPPED: 3 FAILED: 4
  1. Failure: generic post fails w/o auth (@test-REST.R#5) 
  2. Failure: generic post fails w/o auth (@test-REST.R#10) 
  3. Failure: generic post fails w/o auth (@test-REST.R#14) 
  4. Error: generic get w/ and w/o auth (@test-REST.R#29) 
  
  Error: testthat unit tests failed
  Execution halted
```

## taxize (0.8.4)
Maintainer: Scott Chamberlain <myrmecocystus@gmail.com>  
Bug reports: https://github.com/ropensci/taxize/issues

1 error  | 0 warnings | 0 notes

```
checking package dependencies ... ERROR
Package required but not available: ‘worrms’

See section ‘The DESCRIPTION file’ in the ‘Writing R Extensions’
manual.
```

## tidyquant (0.3.0)
Maintainer: Matt Dancho <mdancho@gmail.com>  
Bug reports: https://github.com/mdancho84/tidyquant/issues

1 error  | 0 warnings | 0 notes

```
checking tests ... ERROR
Running the tests in ‘tests/testthat.R’ failed.
Last 13 lines of output:
         AAPL %>% tq_mutate_(ohlc_fun = "close", mutate_fun = mutate_fun)
     }, paste0("fun = ", mutate_fun, " not a valid option.")) at testthat/test_tq_transform.R:141
  2: paste0("fun = ", mutate_fun, " not a valid option.") at /private/var/folders/dt/r5s12t392tb5sk181j3gs4zw0000gn/T/RtmphUL6BL/devtools13aac2becf413/hadley-testthat-3b2f225/R/expect-output.R:147
  
  testthat results ================================================================
  OK: 144 SKIPPED: 1 FAILED: 4
  1. Error: Test error on invalid ohlc_fun, x and y inputs. (@test_tq_mutate.R#151) 
  2. Error: Test error on invalid ohlc_fun, x and y inputs. (@test_tq_mutate.R#169) 
  3. Error: Test error on invalid ohlc_fun, x and y inputs. (@test_tq_transform.R#123) 
  4. Error: Test error on invalid ohlc_fun, x and y inputs. (@test_tq_transform.R#141) 
  
  Error: testthat unit tests failed
  Execution halted
```

