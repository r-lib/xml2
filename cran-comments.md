## Test environments
* local OS X install, R 3.2.0.
* ubuntu 12.04 (on travis-ci), R 3.2.0.
* win-builder (devel and release)

## R CMD check results
There were no ERRORs or WARNINGs. 

There was 1 NOTE:

* The installed package size is large because of the large `libs/` directory,
  due to the large size of `libxml2`. I don't think there's anything I can
  do about this.

## Downstream dependencies
None. This package was archived.
