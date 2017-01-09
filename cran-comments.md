## Release summary

This is a resubmission. Compared to the last version:

The vignettes should now be properly updated.

## Test environments

* local OS X install, R 3.3.0.
* Ubuntu 12.04 (on travis-ci), R-oldrel, R-release, R-devel
* Windows Server 2012 R2 (x64), R 3.3.0
* Rhub
  * Windows Server 2008 R2 SP1, R-devel, 32/64 bit
  * Debian Linux, R-devel, GCC ASAN/UBSAN
  * Fedora Linux, R-devel, clang, gfortran
  * Ubuntu Linux 16.04 LTS, R-release, GCC

## R CMD check results
There were no ERRORs or WARNINGs.

There was 1 NOTE:

* The installed package size is large because of the large `libs/` directory,
  due to the large size of `libxml2`. I don't think there's anything I can
  do about this.

## Downstream dependencies
I ran `R CMD check` on all 86 reverse dependencies (https://github.com/hadley/xml2/tree/master/revdep).

There were no issues found related to xml2.
