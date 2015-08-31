## Release summary

This release fixes configure problems on windows (it may also fix on solaris, but we haven't been able to recreate the problem locally).

## Test environments
* local OS X install, R 3.2.1.
* ubuntu 12.04 (on travis-ci), R 3.2.2.
* win-builder (devel and release)

## R CMD check results
There were no ERRORs or WARNINGs. 

There was 1 NOTE:

* The installed package size is large because of the large `libs/` directory,
  due to the large size of `libxml2`. I don't think there's anything I can
  do about this.

## Downstream dependencies
I ran `R CMD check` on all 6 reverse dependencies (https://github.com/hadley/xml2/tree/master/revdep/summary.md).  As far as I can tell, there are no new problems related to xml2.
