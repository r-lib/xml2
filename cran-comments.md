## Release summary

## Test environments

* local macOS install, R 3.6.2.
* Ubuntu 14.04 (on travis-ci), R-oldrel, R-release, R-devel
* Windows Server 2012 R2 (x64), R 3.6.2
* Rhub

## R CMD check results
There were no ERRORs or WARNINGs.

There were 1 NOTEs:

* checking installed package size ... NOTE
  installed size is  6.7Mb
  sub-directories of 1Mb or more:
    libs   6.4Mb
  * The installed package size is large because of the large `libs/` directory,
  due to the large size of `libxml2`. I don't think there's anything I can
  do about this.


## Downstream dependencies
I ran `R CMD check` on all reverse dependencies (https://github.com/r-lib/xml2/tree/master/revdep#readme).

There were no breaking changes with this release.
