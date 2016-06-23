## Release summary

This release allows for mutating XML nodes.

## Test environments
* local OS X install, R 3.3.0.
* ubuntu 12.04 (on travis-ci), R 3.3.0.
* win-builder (devel and release)

## R CMD check results
There were no ERRORs or WARNINGs.

There was 1 NOTE:

* The installed package size is large because of the large `libs/` directory,
  due to the large size of `libxml2`. I don't think there's anything I can
  do about this.

## Downstream dependencies
I ran `R CMD check` on all 51 reverse dependencies (https://github.com/hadley/xml2/tree/master/revdep/summary.md). 

There were 2 Warnings in rversions and docxtractr due to deprecated functions,
these maintainers have been alerted to the changes and will release new
versions of their packages soon.

There was 1 Error in rvest, a new version of that package has now been released
to address the issues.
