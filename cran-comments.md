I originally submitted this requested update of xml2 to CRAN on Fri, Jan 5,
2018 at 2:32 PM EST, it failed the pre-check due to the Connections API NOTE
detailed below (which I cannot remove). I sent a reply as instructed to CRAN at
Fri, Jan 5, 2018 at 3:32 PM EST explaining this. The package submission was
never moved from the 'archive' directory in the CRAN ftp, and presumably
automatically cleaned at some point; as it no longer exists in that directory.
I am resubmitting this in the hope it will be accepted.

## Release summary

This is a release to address a failing example on CRAN.

## Test environments

* local OS X install, R 3.4.3.
* Ubuntu 12.04 (on travis-ci), R-oldrel, R-release, R-devel
* Windows Server 2012 R2 (x64), R 3.4.3
* Rhub
  * Windows Server 2008 R2 SP1, R-devel, 32/64 bit
  * Debian Linux, R-devel, GCC ASAN/UBSAN
  * Fedora Linux, R-devel, clang, gfortran
  * Ubuntu Linux 16.04 LTS, R-release, GCC

## R CMD check results
There were no ERRORs or WARNINGs.

There were 2 NOTEs:

* checking installed package size ... NOTE
  installed size is  6.7Mb
  sub-directories of 1Mb or more:
    libs   6.4Mb
  * The installed package size is large because of the large `libs/` directory,
  due to the large size of `libxml2`. I don't think there's anything I can
  do about this.

* checking compiled code ... NOTE
  File 'xml2/libs/i386/xml2.dll':
    Found non-API calls to R: 'R_GetConnection', 'R_WriteConnection'
  File 'xml2/libs/x64/xml2.dll':
    Found non-API calls to R: 'R_GetConnection', 'R_WriteConnection'

  Compiled code should not call non-API entry points in R.
  * The xml2 package uses the connections API to read and write XML files to R
    connections. I don't believe there is an alternative other than using the
    connections API, and the connections code in xml2 has existed on CRAN since
    version 1.1.0, release on January 7th, 2017.


## Downstream dependencies
I ran `R CMD check` on all 202 reverse dependencies (https://github.com/hadley/xml2/tree/master/revdep#readme).

There were two breaking changes with this release.

|package                        |version |error  |warning |note |
|:------------------------------|:-------|:------|:-------|:----|
|[icesSAG](problems.md#icessag) |1.3-2   |__+2__ |        |     |
|[rio](problems.md#rio)         |0.5.5   |__+1__ |1       |     |

In both cases I sent fixes to the relevant repositories, they should have CRAN
releases incorporating the fixes in the short term.
- https://github.com/leeper/rio/pull/168
- https://github.com/ices-tools-prod/icesSAG/pull/146
