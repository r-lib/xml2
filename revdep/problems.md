# fhircrackr

<details>

* Version: 2.1.1
* GitHub: https://github.com/POLAR-fhiR/fhircrackr
* Source code: https://github.com/cran/fhircrackr
* Date/Publication: 2023-02-10 09:30:07 UTC
* Number of recursive dependencies: 38

Run `revdepcheck::cloud_details(, "fhircrackr")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘fhircrackr-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: transaction_bundle_example
    > ### Title: Toy examples to POST/PUT on a server
    > ### Aliases: transaction_bundle_example example_resource1 example_resource2
    > ###   example_resource3
    > ### Keywords: datasets
    > 
    > ### ** Examples
    > 
    > #unserialize xml objects before doing anything else with them!
    > fhir_unserialize(bundles = transaction_bundle_example)
    Error in xml2::xml_name(x = object) : Unexpected node type
    Calls: fhir_unserialize ... anyStrings -> isTRUE -> validityMethod -> <Anonymous>
    Execution halted
    ```

*   checking re-building of vignette outputs ... ERROR
    ```
    Error(s) in re-building vignettes:
    --- re-building ‘downloadResources.Rmd’ using rmarkdown
    
    Quitting from lines 128-129 [unnamed-chunk-7] (downloadResources.Rmd)
    Error: processing vignette 'downloadResources.Rmd' failed with diagnostics:
    Unexpected node type
    --- failed re-building ‘downloadResources.Rmd’
    
    --- re-building ‘fhircrackr_intro.Rmd’ using rmarkdown
    
    ...
    Error: processing vignette 'recreateResources.Rmd' failed with diagnostics:
    Unexpected node type
    --- failed re-building ‘recreateResources.Rmd’
    
    SUMMARY: processing the following files failed:
      ‘downloadResources.Rmd’ ‘fhircrackr_intro.Rmd’ ‘flattenResources.Rmd’
      ‘recreateResources.Rmd’
    
    Error: Vignette re-building failed.
    Execution halted
    ```

# pmparser

<details>

* Version: 1.0.17
* GitHub: https://github.com/hugheylab/pmparser
* Source code: https://github.com/cran/pmparser
* Date/Publication: 2023-05-23 23:32:04 UTC
* Number of recursive dependencies: 87

Run `revdepcheck::cloud_details(, "pmparser")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘pmparser-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: parseElement
    > ### Title: Parse elements from a PubMed XML file
    > ### Aliases: parseElement parsePmidStatus parseArticleId parseArticle
    > ###   parsePubHistory parseJournal parsePubType parseMesh parseKeyword
    > ###   parseGrant parseChemical parseDataBank parseComment parseAbstract
    > ###   parseOther parseAuthor parseInvestigator
    > 
    ...
    > dPmidRaw = pmidStatusList[[2L]]
    > dPmid = dPmidRaw[status != 'Deleted', !'status']
    > 
    > dArticleId = parseArticleId(pmXml, dPmid)
    > dArticle = parseArticle(pmXml, dPmid)
    > dJournal = parseJournal(pmXml, dPmid)
    Error in xml_attr(xml_find_first(x1[idx], "CitedMedium")) : 
      argument "attr" is missing, with no default
    Calls: parseJournal -> data.table -> xml_attr
    Execution halted
    ```

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Complete output:
      > library(testthat)
      > library(pmparser)
      > 
      > test_check('pmparser')
      [ FAIL 4 | WARN 0 | SKIP 4 | PASS 158 ]
      
      ══ Skipped tests (4) ═══════════════════════════════════════════════════════════
    ...
          ▆
       1. └─parseFuncs[[i]](pmXml, dPmid) at test_parse_element_no_rows.R:14:5
       2.   ├─data.table::data.table(...)
       3.   └─xml2::xml_attr(xml_find_first(x1[idx], "CitedMedium"))
      
      [ FAIL 4 | WARN 0 | SKIP 4 | PASS 158 ]
      Error: Test failures
      In addition: Warning message:
      call dbDisconnect() when finished working with a connection 
      Execution halted
    ```

