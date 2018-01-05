# aire.zmvm

Version: 0.5.0

## In both

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 38 marked UTF-8 strings
    
    ```

# algorithmia

Version: 0.0.2

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespaces in Imports field not imported from:
      ‘rjson’ ‘xml2’
      All declared Imports should be used.
    
    
    
    
    
    
    ```

# ameco

Version: 0.2.8

## In both

*   checking installed package size ... NOTE
    ```
      installed size is 15.7Mb
      sub-directories of 1Mb or more:
        data  15.6Mb
    ```

# aptg

Version: 0.1.0

## In both

*   R CMD check timed out
    

# assertive.types

Version: 0.0-3

## In both

*   checking Rd cross-references ... NOTE
    ```
    Package unavailable to check Rd xrefs: ‘pryr’
    
    ```

# banxicoR

Version: 0.9.0

## In both

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 148 marked UTF-8 strings
    ```

# binman

Version: 0.1.0

## In both

*   checking tests ...
    ```
    ...
    
    
    
     ERROR
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
                 stop("Function ", name, " not found in environment ", environmentName(env), 
                     ".", call. = FALSE)
             mock(name = name, env = env, new = eval(new_values[[qual_name]], eval_env, eval_env))
         })
      4: FUN(X[[i]], ...)
      5: stop("Can't mock functions in base packages (", pkg_name, ")", call. = FALSE)
      
      ══ testthat results  ═══════════════════════════════════════════════════════════
      OK: 28 SKIPPED: 0 FAILED: 3
      1. Error: canDownloadFiles (@test-download_files.R#9) 
      2. Error: canReturnEmptyDFWhenEmptyDownloadFiles (@test-download_files.R#27) 
      3. Error: canProcessYaml (@test-process_yaml.R#7) 
      
      Error: testthat unit tests failed
      Execution halted
    ```

# biolink

Version: 0.1.3

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘utils’
      All declared Imports should be used.
    
    
    
    
    
    
    
    
    ```

# breathtestcore

Version: 0.4.0

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    ...
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

*   checking Rd cross-references ... NOTE
    ```
    Package unavailable to check Rd xrefs: ‘breathteststan’
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# cdcfluview

Version: 0.7.0

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘units’
      All declared Imports should be used.
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# cifti

Version: 0.4.2

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespaces in Imports field not imported from:
      ‘base64enc’ ‘rgl’
      All declared Imports should be used.
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# congressbr

Version: 0.1.1

## In both

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 1 marked UTF-8 string
    
    ```

# cycleRtools

Version: 1.1.1

## In both

*   checking package dependencies ... NOTE
    ```
    Package suggested but not available for checking: ‘RCurl’
    ```

# dataRetrieval

Version: 2.7.3

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    ...
    reason: Error in loadNamespace(name) : there is no package called 'formatR'
    
    Warning in block_exec(params) :
      failed to tidy R code in chunk <openLibraryTest>
    reason: Error in loadNamespace(name) : there is no package called 'formatR'
    
    Warning in block_exec(params) :
      failed to tidy R code in chunk <getSiteApp>
    reason: Error in loadNamespace(name) : there is no package called 'formatR'
    
    Warning in block_exec(params) :
      failed to tidy R code in chunk <saveData>
    reason: Error in loadNamespace(name) : there is no package called 'formatR'
    
    --smart/-S has been removed.  Use +smart or -smart extension instead.
    For example: pandoc -f markdown+smart -t markdown-smart.
    Try pandoc --help for more information.
    Error: processing vignette 'dataRetrieval.Rmd' failed with diagnostics:
    pandoc document conversion failed with error 2
    Execution halted
    
    ```

# datasus

Version: 0.4.0

## In both

*   checking package dependencies ... ERROR
    ```
    Package required but not available: ‘RCurl’
    
    See section ‘The DESCRIPTION file’ in the ‘Writing R Extensions’
    manual.
    ```

# dataverse

Version: 0.2.0

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    ...
    Execution halted
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# dwapi

Version: 0.1.1

## In both

*   checking tests ...
    ```
     ERROR
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
      ══ testthat results  ═══════════════════════════════════════════════════════════
      OK: 48 SKIPPED: 0 FAILED: 13
      1. Error: get_table_as_dataframe making the correct HTTR request (@test_download_table_as_data_frame.R#22) 
      2. Error: getDataset making the correct HTTR request (@test_get_dataset.R#20) 
      3. Error: get_table_schema making the correct HTTR request (@test_get_table_schema.R#20) 
      4. Error: list_tables making the correct HTTR request (@test_list_tables.R#20) 
      5. Error: replaceDataset making the correct HTTR request (@test_replace_dataset.R#23) 
      6. Error: SPARQL query making the correct HTTR request (@test_sparql.R#30) 
      7. Error: SQL query making the correct HTTR request (@test_sql.R#24) 
      8. Error: sync making the correct HTTR request (@test_sync_dataset.R#20) 
      9. Error: update_dataset making the correct HTTR request (@test_update_dataset.R#22) 
      1. ...
      
      Error: testthat unit tests failed
      Execution halted
    ```

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘xml2’
      All declared Imports should be used.
    
    
    
    ```

# ecb

Version: 0.2

## In both

*   checking examples ... ERROR
    ```
    Running examples in ‘ecb-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: convert_dates
    > ### Title: Format date variable retrieved from the SDW into a proper date
    > ###   variable
    > ### Aliases: convert_dates
    > 
    > ### ** Examples
    > 
    > hicp <- get_data("ICP.M.U2.N.000000.4.ANR")
    Error in loadNamespace(i, c(lib.loc, .libPaths()), versionCheck = vI[[i]]) : 
      there is no package called ‘RCurl’
    Calls: get_data ... tryCatch -> tryCatchList -> tryCatchOne -> <Anonymous>
    Execution halted
    ```

*   checking tests ...
    ```
    ...
    
    
    
     ERROR
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
      2: rsdmx::readSDMX at .../revdep/checks/ecb/new/ecb.Rcheck/00_pkg_src/ecb/R/main.R:100
      3: getExportedValue(pkg, name)
      4: asNamespace(ns)
      5: getNamespace(ns)
      6: tryCatch(loadNamespace(name), error = function(e) stop(e))
      7: tryCatchList(expr, classes, parentenv, handlers)
      8: tryCatchOne(expr, names, parentenv, handlers[[1L]])
      9: value[[3L]](cond)
      
      ══ testthat results  ═══════════════════════════════════════════════════════════
      OK: 8 SKIPPED: 0 FAILED: 1
      1. Error: get_data returns a data frame (@tests.R#6) 
      
      Error: testthat unit tests failed
      Execution halted
    ```

*   checking re-building of vignette outputs ... WARNING
    ```
    Error in re-building vignettes:
      ...
    Quitting from lines 129-138 (ecb_sdw.Rmd) 
    Error: processing vignette 'ecb_sdw.Rmd' failed with diagnostics:
    there is no package called 'RCurl'
    Execution halted
    
    
    ```

# ecoseries

Version: 0.1.5

## In both

*   checking package dependencies ... ERROR
    ```
    Package required but not available: ‘RCurl’
    
    See section ‘The DESCRIPTION file’ in the ‘Writing R Extensions’
    manual.
    ```

# eechidna

Version: 1.1

## In both

*   checking installed package size ... NOTE
    ```
      installed size is  6.4Mb
      sub-directories of 1Mb or more:
        data   4.9Mb
        doc    1.2Mb
    ```

# EML

Version: 1.0.3

## In both

*   checking installed package size ... NOTE
    ```
      installed size is  7.7Mb
      sub-directories of 1Mb or more:
        R     1.3Mb
        xsd   5.4Mb
    ```

# etl

Version: 0.3.7

## In both

*   checking package dependencies ... NOTE
    ```
    Package suggested but not available for checking: ‘macleish’
    ```

# ExpressionAtlas

Version: 1.4.0

## In both

*   checking whether package ‘ExpressionAtlas’ can be installed ... ERROR
    ```
    Installation failed.
    See ‘.../revdep/checks/ExpressionAtlas/new/ExpressionAtlas.Rcheck/00install.out’ for details.
    ```

## Installation

### Devel

```
* installing *source* package ‘ExpressionAtlas’ ...
** R
** data
** inst
** preparing package for lazy loading
Error: package or namespace load failed for ‘GenomeInfoDb’ in loadNamespace(j <- i[[1L]], c(lib.loc, .libPaths()), versionCheck = vI[[j]]):
 there is no package called ‘RCurl’
Error : package ‘GenomeInfoDb’ could not be loaded
ERROR: lazy loading failed for package ‘ExpressionAtlas’
* removing ‘.../revdep/checks/ExpressionAtlas/new/ExpressionAtlas.Rcheck/ExpressionAtlas’

```
### CRAN

```
* installing *source* package ‘ExpressionAtlas’ ...
** R
** data
** inst
** preparing package for lazy loading
Error: package or namespace load failed for ‘GenomeInfoDb’ in loadNamespace(j <- i[[1L]], c(lib.loc, .libPaths()), versionCheck = vI[[j]]):
 there is no package called ‘RCurl’
Error : package ‘GenomeInfoDb’ could not be loaded
ERROR: lazy loading failed for package ‘ExpressionAtlas’
* removing ‘.../revdep/checks/ExpressionAtlas/old/ExpressionAtlas.Rcheck/ExpressionAtlas’

```
# flextable

Version: 0.4.0

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘lazyeval’
      All declared Imports should be used.
    
    
    
    
    
    
    
    
    ```

# GenomicDataCommons

Version: 1.0.5

## In both

*   checking whether package ‘GenomicDataCommons’ can be installed ... ERROR
    ```
    Installation failed.
    See ‘.../revdep/checks/GenomicDataCommons/new/GenomicDataCommons.Rcheck/00install.out’ for details.
    ```

## Installation

### Devel

```
* installing *source* package ‘GenomicDataCommons’ ...
** R
** inst
** preparing package for lazy loading
Error in loadNamespace(j <- i[[1L]], c(lib.loc, .libPaths()), versionCheck = vI[[j]]) : 
  there is no package called ‘RCurl’
ERROR: lazy loading failed for package ‘GenomicDataCommons’
* removing ‘.../revdep/checks/GenomicDataCommons/new/GenomicDataCommons.Rcheck/GenomicDataCommons’

```
### CRAN

```
* installing *source* package ‘GenomicDataCommons’ ...
** R
** inst
** preparing package for lazy loading
Error in loadNamespace(j <- i[[1L]], c(lib.loc, .libPaths()), versionCheck = vI[[j]]) : 
  there is no package called ‘RCurl’
ERROR: lazy loading failed for package ‘GenomicDataCommons’
* removing ‘.../revdep/checks/GenomicDataCommons/old/GenomicDataCommons.Rcheck/GenomicDataCommons’

```
# gfer

Version: 0.1.9

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘tidyr’
      All declared Imports should be used.
    
    
    
    
    
    
    
    
    
    
    
    ```

# glassdoor

Version: 0.7.6

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘xml2’
      All declared Imports should be used.
    
    
    ```

# htmltidy

Version: 0.4.0

## In both

*   checking whether package ‘htmltidy’ can be installed ... WARNING
    ```
    Found the following significant warnings:
      language.c:41:5: warning: flexible array initialization is a GNU extension [-Wgnu-flexible-array-initializer]
    See ‘.../revdep/checks/htmltidy/new/htmltidy.Rcheck/00install.out’ for details.
    ```

# icd

Version: 2.3.1

## In both

*   checking installed package size ... NOTE
    ```
      installed size is  7.4Mb
      sub-directories of 1Mb or more:
        R      2.3Mb
        data   1.3Mb
        doc    2.1Mb
        libs   1.2Mb
    ```

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 55 marked UTF-8 strings
    ```

# icesSAG

Version: 1.3-2

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘icesSAG-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: getSAGGraphs
    > ### Title: Get Summary Graphs of Stock Assessment Output
    > ### Aliases: getSAGGraphs
    > 
    > ### ** Examples
    > 
    > assessmentKey <- findAssessmentKey("cod", 2015)
    GETing ... http://sg.ices.dk/StandardGraphsWebServices.asmx/getListStocks?year=2015
    > graphs <- getSAGGraphs(assessmentKey[1])
    > plot(graphs)
    Error in UseMethod("as.raster") : 
      no applicable method for 'as.raster' applied to an object of class "c('ices_standardgraph_list', 'list')"
    Calls: plot ... plot.ices_standardgraph_list -> <Anonymous> -> rasterGrob -> as.raster
    Execution halted
    ```

*   checking tests ...
    ```
    ...
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# incadata

Version: 0.6.1

## In both

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 568 marked UTF-8 strings
    ```

# ionicons

Version: 0.1.1

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘png’
      All declared Imports should be used.
    
    
    
    ```

# itunesr

Version: 0.1

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘curl’
      All declared Imports should be used.
    
    
    ```

# kableExtra

Version: 0.6.1

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    ...
    Error producing PDF.
    ! Missing number, treated as zero.
    <to be read again> 
                       {
    l.612 \linewidth {
    
    Error: processing vignette 'awesome_table_in_pdf.Rmd' failed with diagnostics:
    pandoc document conversion failed with error 43
    Execution halted
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# kokudosuuchi

Version: 0.4.1

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘stringi’
      All declared Imports should be used.
    
    
    
    
    
    
    
    
    ```

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 52458 marked UTF-8 strings
    ```

# MazamaSpatialUtils

Version: 0.5.2

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    Error in re-building vignettes:
      ...
    --smart/-S has been removed.  Use +smart or -smart extension instead.
    For example: pandoc -f markdown+smart -t markdown-smart.
    Try pandoc --help for more information.
    Error: processing vignette 'introduction.Rmd' failed with diagnostics:
    pandoc document conversion failed with error 2
    Execution halted
    
    
    
    
    
    ```

# mlbgameday

Version: 0.0.1

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    Error in re-building vignettes:
      ...
    Quitting from lines 69-80 (pitch_plotting.Rmd) 
    Error: processing vignette 'pitch_plotting.Rmd' failed with diagnostics:
    package or namespace load failed for 'pitchRx' in loadNamespace(j <- i[[1L]], c(lib.loc, .libPaths()), versionCheck = vI[[j]]):
     there is no package called 'RCurl'
    Execution halted
    
    
    
    
    ```

*   checking dependencies in R code ... NOTE
    ```
    Namespaces in Imports field not imported from:
      ‘doParallel’ ‘iterators’ ‘parallel’
      All declared Imports should be used.
    
    
    
    
    
    
    
    
    
    ```

# mregions

Version: 0.1.6

## In both

*   checking package dependencies ... NOTE
    ```
    Package which this enhances but not available for checking: ‘leaflet’
    ```

# nonmemica

Version: 0.7.9

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    Error in re-building vignettes:
      ...
    --smart/-S has been removed.  Use +smart or -smart extension instead.
    For example: pandoc -f markdown+smart -t markdown-smart.
    Try pandoc --help for more information.
    Error: processing vignette 'parameter-table.Rmd' failed with diagnostics:
    pandoc document conversion failed with error 2
    Execution halted
    
    
    
    
    
    
    
    
    ```

# OECD

Version: 0.2.2

## In both

*   checking tests ...
    ```
    ...
    
    
     ERROR
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
      4: getExportedValue(pkg, name)
      5: asNamespace(ns)
      6: getNamespace(ns)
      7: tryCatch(loadNamespace(name), error = function(e) stop(e))
      8: tryCatchList(expr, classes, parentenv, handlers)
      9: tryCatchOne(expr, names, parentenv, handlers[[1L]])
      10: value[[3L]](cond)
      
      ══ testthat results  ═══════════════════════════════════════════════════════════
      OK: 0 SKIPPED: 0 FAILED: 2
      1. Error: get_data_structure returns a list of data frame with positive length (@tests.R#4) 
      2. Error: get_dataset returns a data frame with positive length (@tests.R#13) 
      
      Error: testthat unit tests failed
      Execution halted
    
    ```

*   checking re-building of vignette outputs ... WARNING
    ```
    Error in re-building vignettes:
      ...
    Quitting from lines 68-70 (oecd_vignette_main.Rmd) 
    Error: processing vignette 'oecd_vignette_main.Rmd' failed with diagnostics:
    there is no package called 'RCurl'
    Execution halted
    
    
    
    
    ```

# petro.One

Version: 0.1.1

## In both

*   checking tests ...
    ```
    ...
    
    
    
     ERROR
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
      9: all.equal.numeric(x, y, tolerance = tolerance, check.attributes = check.attributes, 
             ...)
      10: stop(gettextf("'%s' must be logical", "check.attributes"), domain = NA)
      
      ══ testthat results  ═══════════════════════════════════════════════════════════
      OK: 77 SKIPPED: 0 FAILED: 6
      1. Error: when read_multipage conference-paper gets almost 3000 rows (@test_multipage.R#46) 
      2. Error: when read_multipage standard type only (@test_multipage.R#79) 
      3. Error: when read_multipage journal-paper only (@test_multipage.R#90) 
      4. Error: when read_multipage journal-paper only (@test_multipage.R#97) 
      5. Error: when read_multipage journal-paper only (@test_multipage.R#104) 
      6. Error: expect_equal_scale is 10% tolerance (@test_utils.R#6) 
      
      Error: testthat unit tests failed
      Execution halted
    ```

*   checking dependencies in R code ... NOTE
    ```
    Namespaces in Imports field not imported from:
      ‘Rgraphviz’ ‘cluster’ ‘graph’
      All declared Imports should be used.
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# polmineR

Version: 0.7.5

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    ...
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

*   checking package dependencies ... NOTE
    ```
    Packages suggested but not available for checking:
      ‘polmineR.Rcpp’ ‘europarl.en’
    ```

# prisonbrief

Version: 0.1.0

## In both

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 2 marked UTF-8 strings
    ```

# prodigenr

Version: 0.3.0

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘stats’
      All declared Imports should be used.
    
    
    ```

# PWFSLSmoke

Version: 0.99.33

## In both

*   checking package dependencies ... ERROR
    ```
    Package required but not available: ‘RCurl’
    
    See section ‘The DESCRIPTION file’ in the ‘Writing R Extensions’
    manual.
    ```

# rccmisc

Version: 0.3.7

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘dplyr’
      All declared Imports should be used.
    ```

# RDML

Version: 0.9-9

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    ...
    Approximate and calculated Tm varri. This is an expected behaviour 
    
    			 but the calculation should be confirmed with a plot (see examples of diffQ).
    6.533866827983022021.9375753397427
    The Tm calculation (fit, adj. R squared ~ 0.849, NRMSE ~ 0.088) is not optimal presumably
    due to noisy data. Check raw melting curve (see examples of diffQ).
    --smart/-S has been removed.  Use +smart or -smart extension instead.
    For example: pandoc -f markdown+smart -t markdown-smart.
    Try pandoc --help for more information.
    Error: processing vignette 'CreateRDML.Rmd' failed with diagnostics:
    pandoc document conversion failed with error 2
    Execution halted
    
    
    
    
    
    
    
    
    
    ```

# refimpact

Version: 1.0.0

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘curl’
      All declared Imports should be used.
    ```

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 85 marked UTF-8 strings
    ```

# repurrrsive

Version: 0.1.0

## In both

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 8 marked UTF-8 strings
    ```

# rerddap

Version: 0.4.2

## In both

*   checking package dependencies ... NOTE
    ```
    Package which this enhances but not available for checking: ‘taxize’
    ```

# Rilostat

Version: 0.2

## In both

*   checking package dependencies ... ERROR
    ```
    Package required but not available: ‘RCurl’
    
    See section ‘The DESCRIPTION file’ in the ‘Writing R Extensions’
    manual.
    ```

# rio

Version: 0.5.5

## Newly broken

*   checking tests ...
    ```
    ...
    Running the tests in ‘tests/test-all.R’ failed.
    Last 13 lines of output:
      Length mismatch: comparison on first 11 components
      Component 1: Numeric: lengths (1, 32) differ
      Component 2: Numeric: lengths (1, 32) differ
      Component 3: Numeric: lengths (1, 32) differ
      Component 4: Numeric: lengths (1, 32) differ
      Component 5: Numeric: lengths (1, 32) differ
      Component 6: Numeric: lengths (1, 32) differ
      Component 7: Numeric: lengths (1, 32) differ
      Component 8: Numeric: lengths (1, 32) differ
      ...
      
      ══ DONE ════════════════════════════════════════════════════════════════════════
      Keep trying!
      Error: Test failures
      Execution halted
    
    
    
    
    ```

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    ...
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# rNOMADS

Version: 2.3.8

## In both

*   checking package dependencies ... ERROR
    ```
    Package required but not available: ‘RCurl’
    
    See section ‘The DESCRIPTION file’ in the ‘Writing R Extensions’
    manual.
    ```

# rpx

Version: 1.12.3

## In both

*   checking package dependencies ... ERROR
    ```
    Package required but not available: ‘RCurl’
    
    See section ‘The DESCRIPTION file’ in the ‘Writing R Extensions’
    manual.
    ```

# rscopus

Version: 0.5.3

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘tidyr’
      All declared Imports should be used.
    
    ```

# RTCGA

Version: 1.6.0

## In both

*   checking examples ... ERROR
    ```
    Running examples in ‘RTCGA-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: boxplotTCGA
    > ### Title: Create Boxplots for TCGA Datasets
    > ### Aliases: boxplotTCGA
    > 
    > ### ** Examples
    > 
    > library(RTCGA.rnaseq)
    Error in library(RTCGA.rnaseq) : 
      there is no package called ‘RTCGA.rnaseq’
    Execution halted
    ```

*   checking tests ...
    ```
     ERROR
    Running the tests in ‘tests/testthat.R’ failed.
    Complete output:
      > library(testthat)
      > library(RTCGA)
      Welcome to the RTCGA (version: 1.6.0).
      > library(RTCGA.rnaseq)
      Error in library(RTCGA.rnaseq) : 
        there is no package called 'RTCGA.rnaseq'
      Execution halted
    ```

*   checking re-building of vignette outputs ... WARNING
    ```
    ...
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

*   checking package dependencies ... NOTE
    ```
    Packages suggested but not available for checking:
      ‘RTCGA.rnaseq’ ‘RTCGA.clinical’ ‘RTCGA.mutations’ ‘RTCGA.RPPA’
      ‘RTCGA.mRNA’ ‘RTCGA.miRNASeq’ ‘RTCGA.methylation’ ‘RTCGA.CNV’
      ‘RTCGA.PANCAN12’
    ```

*   checking R code for possible problems ... NOTE
    ```
    ...
      (.../revdep/checks/RTCGA/new/RTCGA.Rcheck/00_pkg_src/RTCGA/R/ggbiplot.R:157-161)
    ggbiplot: no visible binding for global variable ‘xvar’
      (.../revdep/checks/RTCGA/new/RTCGA.Rcheck/00_pkg_src/RTCGA/R/ggbiplot.R:157-161)
    ggbiplot: no visible binding for global variable ‘yvar’
      (.../revdep/checks/RTCGA/new/RTCGA.Rcheck/00_pkg_src/RTCGA/R/ggbiplot.R:157-161)
    ggbiplot: no visible binding for global variable ‘angle’
      (.../revdep/checks/RTCGA/new/RTCGA.Rcheck/00_pkg_src/RTCGA/R/ggbiplot.R:157-161)
    ggbiplot: no visible binding for global variable ‘hjust’
      (.../revdep/checks/RTCGA/new/RTCGA.Rcheck/00_pkg_src/RTCGA/R/ggbiplot.R:157-161)
    read.mutations: no visible binding for global variable ‘.’
      (.../revdep/checks/RTCGA/new/RTCGA.Rcheck/00_pkg_src/RTCGA/R/readTCGA.R:383)
    read.mutations: no visible binding for global variable ‘.’
      (.../revdep/checks/RTCGA/new/RTCGA.Rcheck/00_pkg_src/RTCGA/R/readTCGA.R:386)
    read.rnaseq: no visible binding for global variable ‘.’
      (.../revdep/checks/RTCGA/new/RTCGA.Rcheck/00_pkg_src/RTCGA/R/readTCGA.R:372-375)
    survivalTCGA: no visible binding for global variable ‘times’
      (.../revdep/checks/RTCGA/new/RTCGA.Rcheck/00_pkg_src/RTCGA/R/survivalTCGA.R:101-137)
    whichDateToUse: no visible binding for global variable ‘.’
      (.../revdep/checks/RTCGA/new/RTCGA.Rcheck/00_pkg_src/RTCGA/R/downloadTCGA.R:167-168)
    Undefined global functions or variables:
      . angle hjust muted times varname xvar yvar
    ```

*   checking Rd cross-references ... NOTE
    ```
    Packages unavailable to check Rd xrefs: ‘RTCGA.rnaseq’, ‘RTCGA.clinical’, ‘RTCGA.mutations’, ‘RTCGA.CNV’, ‘RTCGA.RPPA’, ‘RTCGA.mRNA’, ‘RTCGA.miRNASeq’, ‘RTCGA.methylation’
    
    
    
    
    
    
    
    
    ```

# SanFranBeachWater

Version: 0.1.0

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘tibble’
      All declared Imports should be used.
    ```

# sejmRP

Version: 1.3.4

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespaces in Imports field not imported from:
      ‘cluster’ ‘factoextra’ ‘tidyr’
      All declared Imports should be used.
    ```

# sidrar

Version: 0.2.4

## In both

*   checking package dependencies ... ERROR
    ```
    Package required but not available: ‘RCurl’
    
    See section ‘The DESCRIPTION file’ in the ‘Writing R Extensions’
    manual.
    ```

# solrium

Version: 1.0.0

## In both

*   checking Rd cross-references ... NOTE
    ```
    Package unavailable to check Rd xrefs: ‘XML’
    
    ```

# sparklyr

Version: 0.6.4

## In both

*   checking package dependencies ... NOTE
    ```
    Package suggested but not available for checking: ‘RCurl’
    ```

# sss

Version: 0.1-0

## In both

*   checking Rd cross-references ... NOTE
    ```
    Package unavailable to check Rd xrefs: ‘XML’
    
    
    
    
    ```

# TCGAbiolinks

Version: 2.5.9

## In both

*   checking whether package ‘TCGAbiolinks’ can be installed ... ERROR
    ```
    Installation failed.
    See ‘.../revdep/checks/TCGAbiolinks/new/TCGAbiolinks.Rcheck/00install.out’ for details.
    ```

## Installation

### Devel

```
* installing *source* package ‘TCGAbiolinks’ ...
** R
** data
*** moving datasets to lazyload DB
Warning: namespace ‘GenomicRanges’ is not available and has been replaced
by .GlobalEnv when processing object ‘dataREAD’
Warning: namespace ‘GenomicRanges’ is not available and has been replaced
by .GlobalEnv when processing object ‘dataREAD’
** inst
** preparing package for lazy loading
Error in loadNamespace(j <- i[[1L]], c(lib.loc, .libPaths()), versionCheck = vI[[j]]) : 
  there is no package called ‘RCurl’
ERROR: lazy loading failed for package ‘TCGAbiolinks’
* removing ‘.../revdep/checks/TCGAbiolinks/new/TCGAbiolinks.Rcheck/TCGAbiolinks’

```
### CRAN

```
* installing *source* package ‘TCGAbiolinks’ ...
** R
** data
*** moving datasets to lazyload DB
Warning: namespace ‘GenomicRanges’ is not available and has been replaced
by .GlobalEnv when processing object ‘dataREAD’
Warning: namespace ‘GenomicRanges’ is not available and has been replaced
by .GlobalEnv when processing object ‘dataREAD’
** inst
** preparing package for lazy loading
Error in loadNamespace(j <- i[[1L]], c(lib.loc, .libPaths()), versionCheck = vI[[j]]) : 
  there is no package called ‘RCurl’
ERROR: lazy loading failed for package ‘TCGAbiolinks’
* removing ‘.../revdep/checks/TCGAbiolinks/old/TCGAbiolinks.Rcheck/TCGAbiolinks’

```
# TCGAbiolinksGUI

Version: 1.2.1

## In both

*   checking whether package ‘TCGAbiolinksGUI’ can be installed ... ERROR
    ```
    Installation failed.
    See ‘.../revdep/checks/TCGAbiolinksGUI/new/TCGAbiolinksGUI.Rcheck/00install.out’ for details.
    ```

## Installation

### Devel

```
* installing *source* package ‘TCGAbiolinksGUI’ ...
** R
** inst
** preparing package for lazy loading
Error in loadNamespace(j <- i[[1L]], c(lib.loc, .libPaths()), versionCheck = vI[[j]]) : 
  there is no package called ‘RCurl’
ERROR: lazy loading failed for package ‘TCGAbiolinksGUI’
* removing ‘.../revdep/checks/TCGAbiolinksGUI/new/TCGAbiolinksGUI.Rcheck/TCGAbiolinksGUI’

```
### CRAN

```
* installing *source* package ‘TCGAbiolinksGUI’ ...
** R
** inst
** preparing package for lazy loading
Error in loadNamespace(j <- i[[1L]], c(lib.loc, .libPaths()), versionCheck = vI[[j]]) : 
  there is no package called ‘RCurl’
ERROR: lazy loading failed for package ‘TCGAbiolinksGUI’
* removing ‘.../revdep/checks/TCGAbiolinksGUI/old/TCGAbiolinksGUI.Rcheck/TCGAbiolinksGUI’

```
# textreadr

Version: 0.7.0

## In both

*   checking Rd cross-references ... NOTE
    ```
    Package unavailable to check Rd xrefs: ‘tm’
    
    
    ```

# tidyquant

Version: 0.5.3

## In both

*   checking tests ...
    ```
    ...
    
    
    
     ERROR
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
         })
      9: expr_type_of(.x)
      10: typeof(x)
      11: duplicate(quo)
      
      ══ testthat results  ═══════════════════════════════════════════════════════════
      OK: 149 SKIPPED: 2 FAILED: 5
      1. Failure: Test returns tibble with correct rows and columns. (@test_tq_get_key_stats.R#15) 
      2. Failure: Test returns tibble with correct rows and columns. (@test_tq_get_key_stats.R#17) 
      3. Failure: Test returns tibble with correct rows and columns. (@test_tq_get_key_stats.R#19) 
      4. Error: Test error on invalid data inputs. (@test_tq_mutate.R#142) 
      5. Error: Test error on invalid data inputs. (@test_tq_transmute.R#121) 
      
      Error: testthat unit tests failed
      Execution halted
    ```

*   checking re-building of vignette outputs ... WARNING
    ```
    ...
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

*   checking dependencies in R code ... NOTE
    ```
    ...
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# tidyRSS

Version: 1.2.2

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘testthat’
      All declared Imports should be used.
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# tidyverse

Version: 1.2.1

## In both

*   checking dependencies in R code ... NOTE
    ```
    ...
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# tm

Version: 0.7-3

## In both

*   checking package dependencies ... NOTE
    ```
    Packages suggested but not available for checking:
      ‘Rcampdf’ ‘Rpoppler’ ‘tm.lexicon.GeneralInquirer’
    ```

*   checking Rd cross-references ... NOTE
    ```
    Packages unavailable to check Rd xrefs: ‘tm.plugin.dc’, ‘readtext’, ‘Rpoppler’, ‘tau’, ‘tokenizers’
    ```

# tropr

Version: 0.1.2

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    Error in re-building vignettes:
      ...
    --smart/-S has been removed.  Use +smart or -smart extension instead.
    For example: pandoc -f markdown+smart -t markdown-smart.
    Try pandoc --help for more information.
    Error: processing vignette 'quickstart.Rmd' failed with diagnostics:
    pandoc document conversion failed with error 2
    Execution halted
    
    
    ```

# units

Version: 0.4-6

## In both

*   checking re-building of vignette outputs ... WARNING
    ```
    ...
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

# W3CMarkupValidator

Version: 0.1-6

## In both

*   checking Rd cross-references ... NOTE
    ```
    Package unavailable to check Rd xrefs: ‘RCurl’
    
    
    ```

# waccR

Version: 0.1.0

## Newly fixed

*   checking re-building of vignette outputs ... WARNING
    ```
    ...
    Quitting from lines 40-44 (Calculate_WACC_in_R.Rmd) 
    Warning in findLocalsList1(e[-1], shadowed, cntxt) :
      closing unused connection 5 (http://people.stern.nyu.edu/adamodar/New_Home_Page/datafile/totalbeta.html)
    Error: processing vignette 'Calculate_WACC_in_R.Rmd' failed with diagnostics:
    Recv failure: Connection reset by peer
    Execution halted
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ```

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespaces in Imports field not imported from:
      ‘lubridate’ ‘tibble’
      All declared Imports should be used.
    
    
    
    
    
    
    
    
    
    
    
    ```

# webchem

Version: 0.3.0

## In both

*   checking package dependencies ... ERROR
    ```
    Package required but not available: ‘RCurl’
    
    See section ‘The DESCRIPTION file’ in the ‘Writing R Extensions’
    manual.
    ```

# wikilake

Version: 0.3

## In both

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 4 marked UTF-8 strings
    ```

# wikitaxa

Version: 0.2.0

## In both

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 166 marked UTF-8 strings
    
    ```

