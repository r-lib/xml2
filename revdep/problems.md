# GenomicDataCommons

<details>

* Version: 1.8.0
* Source code: https://github.com/cran/GenomicDataCommons
* URL: https://bioconductor.org/packages/GenomicDataCommons, http://github.com/Bioconductor/GenomicDataCommons
* BugReports: https://github.com/Bioconductor/GenomicDataCommons/issues/new
* Date/Publication: 2019-05-02
* Number of recursive dependencies: 103

Run `revdep_details(,"GenomicDataCommons")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    ...
    > # get some example file uuids
    > uuids <- files() %>%
    +     filter(~ access == 'open' & file_size < 100000) %>%
    +     results(size = 3) %>%
    +     ids()
    > 
    > # and get the data, placing it into the gdc_cache() directory
    > fpaths <- gdcdata(uuids, use_cached=TRUE)
    Error in .gdc_file_rename(destfile, to, overwrite) : 
      failed to rename downloaded file:
    
      from: '/Users/jhester/Library/Caches/GenomicDataCommons/f9c28d2c-d724-42df-9b63-1e0e28a52599/.partial_download'
      to: '/Users/jhester/Library/Caches/GenomicDataCommons/f9c28d2c-d724-42df-9b63-1e0e28a52599/nationwidechildrens.org_biospecimen.TCGA-2G-AAI6.xml'
      reason:
        cannot rename file
        '/Users/jhester/Library/Caches/GenomicDataCommons/f9c28d2c-d724-42df-9b63-1e0e28a52599/.partial_download'
        to
        '/Users/jhester/Library/Caches/GenomicDataCommons/f9c28d2c-d724-42df-9b63-1e0e28a52599/nationwidechildrens.org_biospecimen.TCGA-2G-AAI6.xml',
        reason 'No such file or directory'
    Calls: gdcdata -> mapply -> <Anonymous> -> .gdc_file_rename
    Execution halted
    ```

## In both

*   checking Rd \usage sections ... WARNING
    ```
    Undocumented arguments in documentation object '.htseq_importer'
      ‘fnames’
    
    Functions with \usage entries need to have the appropriate \alias
    entries, and all their arguments documented.
    The \usage entries must correspond to syntactically valid R code.
    See chapter ‘Writing R documentation files’ in the ‘Writing R
    Extensions’ manual.
    ```

*   checking R code for possible problems ... NOTE
    ```
    default_fields.character: no visible binding for global variable
      ‘defaults’
      (.../revdep/checks.noindex/GenomicDataCommons/new/GenomicDataCommons.Rcheck/00_pkg_src/GenomicDataCommons/R/fields.R:51)
    gdc_rnaseq: no visible binding for global variable ‘case_id’
      (.../revdep/checks.noindex/GenomicDataCommons/new/GenomicDataCommons.Rcheck/00_pkg_src/GenomicDataCommons/R/gdc_rnaseq.R:106-107)
    gdc_rnaseq: no visible binding for global variable ‘file_id’
      (.../revdep/checks.noindex/GenomicDataCommons/new/GenomicDataCommons.Rcheck/00_pkg_src/GenomicDataCommons/R/gdc_rnaseq.R:106-107)
    Undefined global functions or variables:
      case_id defaults file_id
    ```

# rpx

<details>

* Version: 1.20.0
* Source code: https://github.com/cran/rpx
* URL: https://github.com/lgatto/rpx
* BugReports: https://github.com/lgatto/rpx/issues
* Date/Publication: 2019-05-02
* Number of recursive dependencies: 90

Run `revdep_details(,"rpx")` for more info

</details>

## Newly broken

*   checking whether package ‘rpx’ can be installed ... ERROR
    ```
    Installation failed.
    See ‘.../revdep/checks.noindex/rpx/new/rpx.Rcheck/00install.out’ for details.
    ```

## Installation

### Devel

```
* installing *source* package ‘rpx’ ...
** using staged installation
** R
** inst
** byte-compile and prepare package for lazy loading
Error in setOldClass(c("xml_document", "xml_node")) : 
  inconsistent old-style class information for “xml_document”; the class is defined but does not extend “xml_node” and is not valid as the data part
Error: unable to load R code in package ‘rpx’
Execution halted
ERROR: lazy loading failed for package ‘rpx’
* removing ‘.../revdep/checks.noindex/rpx/new/rpx.Rcheck/rpx’

```
### CRAN

```
* installing *source* package ‘rpx’ ...
** using staged installation
** R
** inst
** byte-compile and prepare package for lazy loading
** help
*** installing help indices
** building package indices
** installing vignettes
** testing if installed package can be loaded from temporary location
** testing if installed package can be loaded from final location
** testing if installed package keeps a record of temporary installation path
* DONE (rpx)

```
# sos4R

<details>

* Version: 0.3.0
* Source code: https://github.com/cran/sos4R
* URL: https://github.com/52North/sos4R
* BugReports: https://github.com/52North/sos4R/issues
* Date/Publication: 2019-04-13 22:42:42 UTC
* Number of recursive dependencies: 61

Run `revdep_details(,"sos4R")` for more info

</details>

## Newly broken

*   checking whether package ‘sos4R’ can be installed ... ERROR
    ```
    Installation failed.
    See ‘.../revdep/checks.noindex/sos4R/new/sos4R.Rcheck/00install.out’ for details.
    ```

## Installation

### Devel

```
* installing *source* package ‘sos4R’ ...
** package ‘sos4R’ successfully unpacked and MD5 sums checked
** using staged installation
** R
** demo
** inst
** byte-compile and prepare package for lazy loading
Error in methods::setOldClass(Classes = c("xml_node", "xml_document")) : 
  inconsistent old-style class information for “xml_node”; the class is defined but does not extend “xml_document” and is not valid as the data part
Error: unable to load R code in package ‘sos4R’
Execution halted
ERROR: lazy loading failed for package ‘sos4R’
* removing ‘.../revdep/checks.noindex/sos4R/new/sos4R.Rcheck/sos4R’

```
### CRAN

```
* installing *source* package ‘sos4R’ ...
** package ‘sos4R’ successfully unpacked and MD5 sums checked
** using staged installation
** R
** demo
** inst
** byte-compile and prepare package for lazy loading
** help
*** installing help indices
** building package indices
** installing vignettes
** testing if installed package can be loaded from temporary location
** testing if installed package can be loaded from final location
** testing if installed package keeps a record of temporary installation path
* DONE (sos4R)

```
