# codemetar

<details>

* Version: 0.1.8
* Source code: https://github.com/cran/codemetar
* URL: https://github.com/ropensci/codemetar, https://ropensci.github.io/codemetar
* BugReports: https://github.com/ropensci/codemetar/issues
* Date/Publication: 2019-04-22 04:20:03 UTC
* Number of recursive dependencies: 80

Run `revdep_details(,"codemetar")` for more info

</details>

## In both

*   R CMD check timed out
    

*   checking dependencies in R code ... NOTE
    ```
    Namespace in Imports field not imported from: ‘memoise’
      All declared Imports should be used.
    ```

# cola

<details>

* Version: 
* Source code: ???
* URL: https://xml2.r-lib.org/, https://github.com/r-lib/xml2
* BugReports: https://github.com/r-lib/xml2/issues
* Number of recursive dependencies: 0

Run `revdep_details(,"")` for more info

</details>

## Error before installation

### Devel

```

  There are binary versions available but the source versions are later:
           binary source needs_compilation
reticulate   1.13   1.14              TRUE
tibble      2.1.3  3.0.0              TRUE

  Binaries will be installed
  These will not be installed


Package which is only available in source form, and may need
  compilation of C/C++/Fortran: ‘WGCNA’
installing the source packages ‘DO.db’, ‘GO.db’, ‘hu6800.db’, ‘org.Hs.eg.db’, ‘reactome.db’



```
### CRAN

```

  There are binary versions available but the source versions are later:
           binary source needs_compilation
reticulate   1.13   1.14              TRUE
tibble      2.1.3  3.0.0              TRUE

  Binaries will be installed
  These will not be installed


Package which is only available in source form, and may need
  compilation of C/C++/Fortran: ‘WGCNA’
installing the source packages ‘DO.db’, ‘GO.db’, ‘hu6800.db’, ‘org.Hs.eg.db’, ‘reactome.db’



```
# ELMER

<details>

* Version: 2.10.0
* Source code: https://github.com/cran/ELMER
* Date/Publication: 2019-11-06
* Number of recursive dependencies: 212

Run `revdep_details(,"ELMER")` for more info

</details>

## In both

*   R CMD check timed out
    

*   checking Rd \usage sections ... WARNING
    ```
    Undocumented arguments in documentation object 'heatmapGene'
      ‘correlation.method’ ‘scatter.plot.width’ ‘scatter.plot.height’
    
    Functions with \usage entries need to have the appropriate \alias
    entries, and all their arguments documented.
    The \usage entries must correspond to syntactically valid R code.
    See chapter ‘Writing R documentation files’ in the ‘Writing R
    Extensions’ manual.
    ```

*   checking installed package size ... NOTE
    ```
      installed size is 75.8Mb
      sub-directories of 1Mb or more:
        doc  75.1Mb
    ```

*   checking R code for possible problems ... NOTE
    ```
    ...
      (.../revdep/checks.noindex/ELMER/new/ELMER.Rcheck/00_pkg_src/ELMER/R/GetNearbyGenes.R:538-539)
    getRegionNearGenes: no visible binding for global variable 'ID'
      (.../revdep/checks.noindex/ELMER/new/ELMER.Rcheck/00_pkg_src/ELMER/R/GetNearbyGenes.R:551)
    getTFtargets: no visible binding for global variable 'TF'
      (.../revdep/checks.noindex/ELMER/new/ELMER.Rcheck/00_pkg_src/ELMER/R/Main_function.R:1634)
    getTFtargets: no visible binding for global variable 'TF'
      (.../revdep/checks.noindex/ELMER/new/ELMER.Rcheck/00_pkg_src/ELMER/R/Main_function.R:1636)
    heatmapGene: no visible global function definition for 'melt'
      (.../revdep/checks.noindex/ELMER/new/ELMER.Rcheck/00_pkg_src/ELMER/R/plots.R:590)
    heatmapGene: no visible binding for global variable 'mae'
      (.../revdep/checks.noindex/ELMER/new/ELMER.Rcheck/00_pkg_src/ELMER/R/plots.R:590)
    heatmapGene: no visible binding for global variable 'mae'
      (.../revdep/checks.noindex/ELMER/new/ELMER.Rcheck/00_pkg_src/ELMER/R/plots.R:592)
    heatmapGene: no visible global function definition for 'melt'
      (.../revdep/checks.noindex/ELMER/new/ELMER.Rcheck/00_pkg_src/ELMER/R/plots.R:593)
    heatmapGene: no visible binding for global variable 'mae'
      (.../revdep/checks.noindex/ELMER/new/ELMER.Rcheck/00_pkg_src/ELMER/R/plots.R:593)
    heatmapGene: no visible global function definition for 'stat_cor'
      (.../revdep/checks.noindex/ELMER/new/ELMER.Rcheck/00_pkg_src/ELMER/R/plots.R:597-613)
    Undefined global functions or variables:
      DistanceTSS Hugo_Symbol ID Side TF mae melt stat_cor
    ```

# move

<details>

* Version: 3.3.0
* Source code: https://github.com/cran/move
* URL: https://bartk.gitlab.io/move/
* BugReports: https://gitlab.com/bartk/move/issues
* Date/Publication: 2020-03-19 13:40:02 UTC
* Number of recursive dependencies: 123

Run `revdep_details(,"move")` for more info

</details>

## In both

*   R CMD check timed out
    

# RMixtCompIO

<details>

* Version: 4.0.2
* Source code: https://github.com/cran/RMixtCompIO
* URL: https://github.com/modal-inria/MixtComp, https://massiccc.lille.inria.fr/
* BugReports: https://github.com/modal-inria/MixtComp/issues
* Date/Publication: 2019-12-16 10:30:06 UTC
* Number of recursive dependencies: 39

Run `revdep_details(,"RMixtCompIO")` for more info

</details>

## In both

*   checking whether package ‘RMixtCompIO’ can be installed ... ERROR
    ```
    Installation failed.
    See ‘.../revdep/checks.noindex/RMixtCompIO/new/RMixtCompIO.Rcheck/00install.out’ for details.
    ```

## Installation

### Devel

```
* installing *source* package ‘RMixtCompIO’ ...
** package ‘RMixtCompIO’ successfully unpacked and MD5 sums checked
** using staged installation
** libs
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c RGraph.cpp -o RGraph.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c RcppExports.cpp -o RcppExports.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c UTest.cpp -o UTest.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c rmc.cpp -o rmc.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Various/Constants.cpp -o lib/Various/Constants.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Various/Timer.cpp -o lib/Various/Timer.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Various/Various.cpp -o lib/Various/Various.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/IO/SpecialStr.cpp -o lib/IO/SpecialStr.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/IO/IOFunctions.cpp -o lib/IO/IOFunctions.o
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/RNG.cpp -o lib/Statistic/RNG.o
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/NormalStatistic.cpp -o lib/Statistic/NormalStatistic.o
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/MultinomialStatistic.cpp -o lib/Statistic/MultinomialStatistic.o
lib/Various/Timer.cpp:56:8: warning: unused variable 'timePerIt' [-Wunused-variable]
                Real timePerIt = dt.total_milliseconds() / 1000. / Real(iteration);
                     ^
lib/Various/Timer.cpp:71:7: warning: unused variable 'sinceCreation' [-Wunused-variable]
        Real sinceCreation = dtCreation.total_milliseconds() / 1000.;
             ^
2 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/UniformIntStatistic.cpp -o lib/Statistic/UniformIntStatistic.o
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/UniformStatistic.cpp -o lib/Statistic/UniformStatistic.o
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/ExponentialStatistic.cpp -o lib/Statistic/ExponentialStatistic.o
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/RMixtCompIO/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/LinAlg/Typedef.cpp -o lib/LinAlg/Typedef.o
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:31:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:31:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:31:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:31:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:31:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
8 warnings and 5 errors generated.
make: *** [RGraph.o] Error 1
make: *** Waiting for unfinished jobs....
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:31:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Sparse:26:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SparseCore:66:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:31:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Sparse:27:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/OrderingMethods:71:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:31:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Sparse:29:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SparseCholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:31:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Sparse:32:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SparseQR:35:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:31:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Sparse:33:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/IterativeLinearSolvers:46:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:32:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/CholmodSupport:45:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:35:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/KroneckerProduct:34:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/../../Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:39:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/Polynomials:135:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/../../Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:40:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/SparseExtra:51:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/../../Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
17 warnings generated.
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:36:
In file included from lib/Mixture/Functional/Function.h:27:
In file included from lib/Statistic/Statistic.h:26:
In file included from lib/Statistic/MultinomialStatistic.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random.hpp:36:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/additive_combine.hpp:22:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:36:
In file included from lib/Mixture/Functional/Function.h:27:
In file included from lib/Statistic/Statistic.h:26:
In file included from lib/Statistic/MultinomialStatistic.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random.hpp:36:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/additive_combine.hpp:22:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:36:
In file included from lib/Mixture/Functional/Function.h:27:
In file included from lib/Statistic/Statistic.h:26:
In file included from lib/Statistic/MultinomialStatistic.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random.hpp:36:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/additive_combine.hpp:22:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:36:
In file included from lib/Mixture/Functional/Function.h:27:
In file included from lib/Statistic/Statistic.h:26:
In file included from lib/Statistic/MultinomialStatistic.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random.hpp:36:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/additive_combine.hpp:22:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:36:
In file included from lib/Mixture/Functional/Function.h:27:
In file included from lib/Statistic/Statistic.h:26:
In file included from lib/Statistic/MultinomialStatistic.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random.hpp:36:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/additive_combine.hpp:22:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:45:
In file included from lib/Manager/createAllMixtures.h:27:
lib/Composer/MixtureComposer.h:308:9: warning: unused variable 'nObs' [-Wunused-variable]
                Index nObs = paramStat_.getStatStorage().cols();
                      ^
9 warnings and 5 errors generated.
make: *** [UTest.o] Error 1
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
lib/Composer/MixtureComposer.h:308:9: warning: unused variable 'nObs' [-Wunused-variable]
                Index nObs = paramStat_.getStatStorage().cols();
                      ^
9 warnings and 5 errors generated.
make: *** [rmc.o] Error 1
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
ERROR: compilation failed for package ‘RMixtCompIO’
* removing ‘.../revdep/checks.noindex/RMixtCompIO/new/RMixtCompIO.Rcheck/RMixtCompIO’

```
### CRAN

```
* installing *source* package ‘RMixtCompIO’ ...
** package ‘RMixtCompIO’ successfully unpacked and MD5 sums checked
** using staged installation
** libs
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c RGraph.cpp -o RGraph.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c RcppExports.cpp -o RcppExports.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c UTest.cpp -o UTest.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c rmc.cpp -o rmc.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Various/Constants.cpp -o lib/Various/Constants.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Various/Timer.cpp -o lib/Various/Timer.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Various/Various.cpp -o lib/Various/Various.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/IO/SpecialStr.cpp -o lib/IO/SpecialStr.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/IO/IOFunctions.cpp -o lib/IO/IOFunctions.o
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Constants.cpp:27:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/RNG.cpp -o lib/Statistic/RNG.o
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Various/Various.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/NormalStatistic.cpp -o lib/Statistic/NormalStatistic.o
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/RNG.cpp:23:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/MultinomialStatistic.cpp -o lib/Statistic/MultinomialStatistic.o
lib/Various/Timer.cpp:56:8: warning: unused variable 'timePerIt' [-Wunused-variable]
                Real timePerIt = dt.total_milliseconds() / 1000. / Real(iteration);
                     ^
lib/Various/Timer.cpp:71:7: warning: unused variable 'sinceCreation' [-Wunused-variable]
        Real sinceCreation = dtCreation.total_milliseconds() / 1000.;
             ^
2 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/UniformIntStatistic.cpp -o lib/Statistic/UniformIntStatistic.o
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/IO/IOFunctions.cpp:23:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/UniformStatistic.cpp -o lib/Statistic/UniformStatistic.o
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformIntStatistic.cpp:24:
In file included from lib/Statistic/UniformIntStatistic.h:29:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/xml2/old/Rcpp/include" -I".../revdep/library.noindex/RMixtCompIO/RcppEigen/include" -I".../revdep/library.noindex/RMixtCompIO/BH/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Ilib -Ilib/LinAlg -DEIGEN_MATRIXBASE_PLUGIN=\"EigenMatrixBaseAddons.h\" -Ioptim/include -fPIC  -Wall -g -O2  -c lib/Statistic/ExponentialStatistic.cpp -o lib/Statistic/ExponentialStatistic.o
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:30:
In file included from lib/IO/NamedAlgebra.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:31:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:31:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:31:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:31:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from RGraph.cpp:23:
In file included from ./RGraph.h:31:
In file included from lib/IO/IOFunctions.h:26:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
8 warnings and 5 errors generated.
make: *** [RGraph.o] Error 1
make: *** Waiting for unfinished jobs....
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/MultinomialStatistic.cpp:23:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:30:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:31:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Sparse:26:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SparseCore:66:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:31:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Sparse:27:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/OrderingMethods:71:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:31:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Sparse:29:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SparseCholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:31:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Sparse:32:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SparseQR:35:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:31:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Sparse:33:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/IterativeLinearSolvers:46:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:32:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/CholmodSupport:45:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:35:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/KroneckerProduct:34:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/../../Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:39:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/Polynomials:135:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/../../Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from RcppExports.cpp:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigen.h:25:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/RcppEigenForward.h:40:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/SparseExtra:51:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/unsupported/Eigen/../../Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
17 warnings generated.
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/UniformStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/NormalStatistic.cpp:27:
In file included from lib/Statistic/RNG.h:29:
In file included from lib/Various/Constants.h:26:
In file included from lib/Various/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:33:
In file included from lib/LinAlg/Maths.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:36:
In file included from lib/Mixture/Functional/Function.h:27:
In file included from lib/Statistic/Statistic.h:26:
In file included from lib/Statistic/MultinomialStatistic.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random.hpp:36:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/additive_combine.hpp:22:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:36:
In file included from lib/Mixture/Functional/Function.h:27:
In file included from lib/Statistic/Statistic.h:26:
In file included from lib/Statistic/MultinomialStatistic.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random.hpp:36:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/additive_combine.hpp:22:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:36:
In file included from lib/Mixture/Functional/Function.h:27:
In file included from lib/Statistic/Statistic.h:26:
In file included from lib/Statistic/MultinomialStatistic.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random.hpp:36:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/additive_combine.hpp:22:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:36:
In file included from lib/Mixture/Functional/Function.h:27:
In file included from lib/Statistic/Statistic.h:26:
In file included from lib/Statistic/MultinomialStatistic.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random.hpp:36:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/additive_combine.hpp:22:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:36:
In file included from lib/Mixture/Functional/Function.h:27:
In file included from lib/Statistic/Statistic.h:26:
In file included from lib/Statistic/MultinomialStatistic.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random.hpp:36:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/additive_combine.hpp:22:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from UTest.cpp:25:
In file included from lib/MixtComp.h:45:
In file included from lib/Manager/createAllMixtures.h:27:
lib/Composer/MixtureComposer.h:308:9: warning: unused variable 'nObs' [-Wunused-variable]
                Index nObs = paramStat_.getStatStorage().cols();
                      ^
9 warnings and 5 errors generated.
make: *** [UTest.o] Error 1
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:26:
In file included from lib/LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
In file included from lib/Composer/MixtureComposer.h:28:
In file included from lib/Composer/ClassDataStat.h:26:
In file included from lib/Composer/ZClassInd.h:27:
In file included from lib/Data/AugmentedData.h:31:
In file included from lib/Data/../Statistic/UniformStatistic.h:27:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/random/mersenne_twister.hpp:24:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/RMixtCompIO/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from rmc.cpp:26:
In file included from lib/Run/Learn.h:26:
lib/Composer/MixtureComposer.h:308:9: warning: unused variable 'nObs' [-Wunused-variable]
                Index nObs = paramStat_.getStatStorage().cols();
                      ^
9 warnings and 5 errors generated.
make: *** [rmc.o] Error 1
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:1:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Core:535:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:2:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/LU:47:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:12:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Jacobi:29:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:3:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Cholesky:43:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:4:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/QR:17:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Householder:27:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:5:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/SVD:48:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:6:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Geometry:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
In file included from lib/Statistic/ExponentialStatistic.cpp:27:
In file included from lib/Statistic/ExponentialStatistic.h:26:
In file included from lib/Statistic/../LinAlg/LinAlg.h:28:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Dense:7:
In file included from .../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/Eigenvalues:58:
.../revdep/library.noindex/RMixtCompIO/RcppEigen/include/Eigen/src/Core/util/ReenableStupidWarnings.h:10:30: warning: pragma diagnostic pop could not pop, no matching push [-Wunknown-pragmas]
    #pragma clang diagnostic pop
                             ^
8 warnings generated.
ERROR: compilation failed for package ‘RMixtCompIO’
* removing ‘.../revdep/checks.noindex/RMixtCompIO/old/RMixtCompIO.Rcheck/RMixtCompIO’

```
# TCGAbiolinks

<details>

* Version: 2.14.1
* Source code: https://github.com/cran/TCGAbiolinks
* URL: https://github.com/BioinformaticsFMRP/TCGAbiolinks
* BugReports: https://github.com/BioinformaticsFMRP/TCGAbiolinks/issues
* Date/Publication: 2020-02-27
* Number of recursive dependencies: 264

Run `revdep_details(,"TCGAbiolinks")` for more info

</details>

## Newly fixed

*   checking examples ... ERROR
    ```
    ...
    > query <- GDCquery(project = "TCGA-GBM",
    +                   data.category = "Transcriptome Profiling",
    +                   data.type = "Gene Expression Quantification",
    +                   workflow.type = "HTSeq - Counts",
    +                   barcode = c("TCGA-14-0736-02A-01R-2005-01", "TCGA-06-0211-02A-02R-2005-01"))
    --------------------------------------
    o GDCquery: Searching in GDC database
    --------------------------------------
    Genome of reference: hg38
    --------------------------------------------
    oo Accessing GDC. This might take a while...
    --------------------------------------------
    ooo Project: TCGA-GBM
    --------------------
    oo Filtering results
    --------------------
    ooo By data.type
    Error in GDCquery(project = "TCGA-GBM", data.category = "Transcriptome Profiling",  : 
      Please set a valid workflow.type argument from the list below:
      => 
    Execution halted
    ```

## In both

*   R CMD check timed out
    

*   checking installed package size ... NOTE
    ```
      installed size is 104.0Mb
      sub-directories of 1Mb or more:
        R      2.7Mb
        data   4.0Mb
        doc   97.0Mb
    ```

*   checking R code for possible problems ... NOTE
    ```
    ...
      (.../revdep/checks.noindex/TCGAbiolinks/new/TCGAbiolinks.Rcheck/00_pkg_src/TCGAbiolinks/R/visualize.R:942)
    TCGAvisualize_starburst: no visible global function definition for
      ‘values’
      (.../revdep/checks.noindex/TCGAbiolinks/new/TCGAbiolinks.Rcheck/00_pkg_src/TCGAbiolinks/R/methylation.R:1193)
    TCGAvisualize_starburst: no visible global function definition for
      ‘values’
      (.../revdep/checks.noindex/TCGAbiolinks/new/TCGAbiolinks.Rcheck/00_pkg_src/TCGAbiolinks/R/methylation.R:1257)
    readExonQuantification: no visible binding for global variable ‘exon’
      (.../revdep/checks.noindex/TCGAbiolinks/new/TCGAbiolinks.Rcheck/00_pkg_src/TCGAbiolinks/R/prepare.R:269-270)
    readExonQuantification: no visible binding for global variable
      ‘coordinates’
      (.../revdep/checks.noindex/TCGAbiolinks/new/TCGAbiolinks.Rcheck/00_pkg_src/TCGAbiolinks/R/prepare.R:269-270)
    readGeneExpressionQuantification : <anonymous>: no visible binding for
      '<<-' assignment to ‘assay.list’
      (.../revdep/checks.noindex/TCGAbiolinks/new/TCGAbiolinks.Rcheck/00_pkg_src/TCGAbiolinks/R/prepare.R:396)
    readGeneExpressionQuantification: no visible binding for global
      variable ‘assay.list’
      (.../revdep/checks.noindex/TCGAbiolinks/new/TCGAbiolinks.Rcheck/00_pkg_src/TCGAbiolinks/R/prepare.R:413)
    Undefined global functions or variables:
      Tumor.purity assay.list barcode clinical coordinates exon is_ffpe
      rse_gene submitter_id value values
    ```

# tm

<details>

* Version: 0.7-7
* Source code: https://github.com/cran/tm
* URL: http://tm.r-forge.r-project.org/
* Date/Publication: 2019-12-12 10:06:26 UTC
* Number of recursive dependencies: 43

Run `revdep_details(,"tm")` for more info

</details>

## In both

*   checking whether package ‘tm’ can be installed ... ERROR
    ```
    Installation failed.
    See ‘.../revdep/checks.noindex/tm/new/tm.Rcheck/00install.out’ for details.
    ```

*   checking package dependencies ... NOTE
    ```
    Packages suggested but not available for checking:
      'Rcampdf', 'Rpoppler', 'tm.lexicon.GeneralInquirer'
    ```

## Installation

### Devel

```
* installing *source* package ‘tm’ ...
** package ‘tm’ successfully unpacked and MD5 sums checked
** using staged installation
** libs
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/tm/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c RcppExports.cpp -o RcppExports.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/tm/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c copy.c -o copy.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/tm/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c init.c -o init.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/tm/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c remove.c -o remove.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/tm/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c scan.c -o scan.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/tm/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c tdm.cpp -o tdm.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/tm/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c tokenizer.cpp -o tokenizer.o
In file included from tokenizer.cpp:4:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from tokenizer.cpp:4:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tokenizer.cpp:4:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tokenizer.cpp:4:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tokenizer.cpp:4:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
5 errors generated.
make: *** [tokenizer.o] Error 1
make: *** Waiting for unfinished jobs....
In file included from tdm.cpp:5:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from tdm.cpp:5:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tdm.cpp:5:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tdm.cpp:5:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tdm.cpp:5:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
5 errors generated.
make: *** [tdm.o] Error 1
ERROR: compilation failed for package ‘tm’
* removing ‘.../revdep/checks.noindex/tm/new/tm.Rcheck/tm’

```
### CRAN

```
* installing *source* package ‘tm’ ...
** package ‘tm’ successfully unpacked and MD5 sums checked
** using staged installation
** libs
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c RcppExports.cpp -o RcppExports.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c copy.c -o copy.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c init.c -o init.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c remove.c -o remove.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c scan.c -o scan.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c tdm.cpp -o tdm.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/tm/BH/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c tokenizer.cpp -o tokenizer.o
In file included from tokenizer.cpp:4:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from tokenizer.cpp:4:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tokenizer.cpp:4:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tokenizer.cpp:4:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tokenizer.cpp:4:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
5 errors generated.
make: *** [tokenizer.o] Error 1
make: *** Waiting for unfinished jobs....
In file included from tdm.cpp:5:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from tdm.cpp:5:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tdm.cpp:5:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tdm.cpp:5:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from tdm.cpp:5:
In file included from .../revdep/library.noindex/tm/BH/include/boost/tokenizer.hpp:20:
In file included from .../revdep/library.noindex/tm/BH/include/boost/token_iterator.hpp:22:
In file included from .../revdep/library.noindex/tm/BH/include/boost/iterator/iterator_adaptor.hpp:10:
In file included from .../revdep/library.noindex/tm/BH/include/boost/static_assert.hpp:17:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config.hpp:57:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/platform/macos.hpp:28:
In file included from .../revdep/library.noindex/tm/BH/include/boost/config/detail/posix_features.hpp:18:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
5 errors generated.
make: *** [tdm.o] Error 1
ERROR: compilation failed for package ‘tm’
* removing ‘.../revdep/checks.noindex/tm/old/tm.Rcheck/tm’

```
# units

<details>

* Version: 0.6-6
* Source code: https://github.com/cran/units
* URL: https://github.com/r-quantities/units/
* BugReports: https://github.com/r-quantities/units/issues/
* Date/Publication: 2020-03-16 17:30:02 UTC
* Number of recursive dependencies: 69

Run `revdep_details(,"units")` for more info

</details>

## In both

*   checking whether package ‘units’ can be installed ... ERROR
    ```
    Installation failed.
    See ‘.../revdep/checks.noindex/units/new/units.Rcheck/00install.out’ for details.
    ```

## Installation

### Devel

```
* installing *source* package ‘units’ ...
** package ‘units’ successfully unpacked and MD5 sums checked
** using staged installation
configure: units: 0.6-6
checking whether the C++ compiler works... yes
checking for C++ compiler default output file name... a.out
checking for suffix of executables... 
checking whether we are cross compiling... no
checking for suffix of object files... o
checking whether we are using the GNU C++ compiler... yes
checking whether clang++ -std=gnu++11 accepts -g... yes
checking how to run the C++ preprocessor... clang++ -std=gnu++11 -E
checking for grep that handles long lines and -e... /usr/local/bin/ggrep
checking for egrep... /usr/local/bin/ggrep -E
checking for ANSI C header files... rm: cannot remove 'conftest.dSYM': Is a directory
rm: cannot remove 'conftest.dSYM': Is a directory
yes
checking for sys/types.h... yes
checking for sys/stat.h... yes
checking for stdlib.h... yes
checking for string.h... yes
checking for memory.h... yes
checking for strings.h... yes
checking for inttypes.h... yes
checking for stdint.h... yes
checking for unistd.h... yes
checking for stdbool.h that conforms to C99... no
checking for _Bool... no
checking for error_at_line... no
checking for gcc... clang
checking whether we are using the GNU C compiler... yes
checking whether clang accepts -g... yes
checking for clang option to accept ISO C89... none needed
checking for XML_ParserCreate in -lexpat... yes
checking udunits2.h usability... no
checking udunits2.h presence... no
checking for udunits2.h... no
checking udunits2/udunits2.h usability... no
checking udunits2/udunits2.h presence... no
checking for udunits2/udunits2.h... no
checking for ut_read_xml in -ludunits2... no
configure: error: in `.../revdep/checks.noindex/units/new/units.Rcheck/00_pkg_src/units':
configure: error: 
--------------------------------------------------------------------------------
  Configuration failed because libudunits2.so was not found. Try installing:
    * deb: libudunits2-dev (Debian, Ubuntu, ...)
    * rpm: udunits2-devel (Fedora, EPEL, ...)
    * brew: udunits (OSX)
  If udunits2 is already installed in a non-standard location, use:
    --configure-args='--with-udunits2-lib=/usr/local/lib'
  if the library was not found, and/or:
    --configure-args='--with-udunits2-include=/usr/include/udunits2'
  if the header was not found, replacing paths with appropriate values.
  You can alternatively set UDUNITS2_INCLUDE and UDUNITS2_LIBS manually.
--------------------------------------------------------------------------------

See `config.log' for more details
ERROR: configuration failed for package ‘units’
* removing ‘.../revdep/checks.noindex/units/new/units.Rcheck/units’

```
### CRAN

```
* installing *source* package ‘units’ ...
** package ‘units’ successfully unpacked and MD5 sums checked
** using staged installation
configure: units: 0.6-6
checking whether the C++ compiler works... yes
checking for C++ compiler default output file name... a.out
checking for suffix of executables... 
checking whether we are cross compiling... no
checking for suffix of object files... o
checking whether we are using the GNU C++ compiler... yes
checking whether clang++ -std=gnu++11 accepts -g... yes
checking how to run the C++ preprocessor... clang++ -std=gnu++11 -E
checking for grep that handles long lines and -e... /usr/local/bin/ggrep
checking for egrep... /usr/local/bin/ggrep -E
checking for ANSI C header files... rm: cannot remove 'conftest.dSYM': Is a directory
rm: cannot remove 'conftest.dSYM': Is a directory
yes
checking for sys/types.h... yes
checking for sys/stat.h... yes
checking for stdlib.h... yes
checking for string.h... yes
checking for memory.h... yes
checking for strings.h... yes
checking for inttypes.h... yes
checking for stdint.h... yes
checking for unistd.h... yes
checking for stdbool.h that conforms to C99... no
checking for _Bool... no
checking for error_at_line... no
checking for gcc... clang
checking whether we are using the GNU C compiler... yes
checking whether clang accepts -g... yes
checking for clang option to accept ISO C89... none needed
checking for XML_ParserCreate in -lexpat... yes
checking udunits2.h usability... no
checking udunits2.h presence... no
checking for udunits2.h... no
checking udunits2/udunits2.h usability... no
checking udunits2/udunits2.h presence... no
checking for udunits2/udunits2.h... no
checking for ut_read_xml in -ludunits2... no
configure: error: in `.../revdep/checks.noindex/units/old/units.Rcheck/00_pkg_src/units':
configure: error: 
--------------------------------------------------------------------------------
  Configuration failed because libudunits2.so was not found. Try installing:
    * deb: libudunits2-dev (Debian, Ubuntu, ...)
    * rpm: udunits2-devel (Fedora, EPEL, ...)
    * brew: udunits (OSX)
  If udunits2 is already installed in a non-standard location, use:
    --configure-args='--with-udunits2-lib=/usr/local/lib'
  if the library was not found, and/or:
    --configure-args='--with-udunits2-include=/usr/include/udunits2'
  if the header was not found, replacing paths with appropriate values.
  You can alternatively set UDUNITS2_INCLUDE and UDUNITS2_LIBS manually.
--------------------------------------------------------------------------------

See `config.log' for more details
ERROR: configuration failed for package ‘units’
* removing ‘.../revdep/checks.noindex/units/old/units.Rcheck/units’

```
# vroom

<details>

* Version: 1.2.0
* Source code: https://github.com/cran/vroom
* URL: https://github.com/r-lib/vroom
* BugReports: https://github.com/r-lib/vroom/issues
* Date/Publication: 2020-01-13 22:40:02 UTC
* Number of recursive dependencies: 88

Run `revdep_details(,"vroom")` for more info

</details>

## In both

*   checking whether package ‘vroom’ can be installed ... ERROR
    ```
    Installation failed.
    See ‘.../revdep/checks.noindex/vroom/new/vroom.Rcheck/00install.out’ for details.
    ```

## Installation

### Devel

```
* installing *source* package ‘vroom’ ...
** package ‘vroom’ successfully unpacked and MD5 sums checked
** using staged installation
** libs
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c Iconv.cpp -o Iconv.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c LocaleInfo.cpp -o LocaleInfo.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c RcppExports.cpp -o RcppExports.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c altrep.cc -o altrep.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c delimited_index.cc -o delimited_index.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c delimited_index_connection.cc -o delimited_index_connection.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c fixed_width_index_connection.cc -o fixed_width_index_connection.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c gen.cc -o gen.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c grisu3.c -o grisu3.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c guess_type.cc -o guess_type.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c index_collection.cc -o index_collection.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c localtime.c -o localtime.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom.cc -o vroom.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom_big_int.cc -o vroom_big_int.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom_chr.cc -o vroom_chr.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom_date.cc -o vroom_date.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom_dbl.cc -o vroom_dbl.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/vroom/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom_dttm.cc -o vroom_dttm.o
In file included from index_collection.cc:2:
In file included from ./delimited_index_connection.h:1:
In file included from ./delimited_index.h:9:
In file included from mio/include/mio/shared_mmap.hpp:24:
In file included from mio/include/mio/mmap.hpp:24:
In file included from mio/include/mio/page.hpp:27:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from index_collection.cc:2:
In file included from ./delimited_index_connection.h:1:
In file included from ./delimited_index.h:9:
In file included from mio/include/mio/shared_mmap.hpp:24:
In file included from mio/include/mio/mmap.hpp:24:
In file included from mio/include/mio/page.hpp:27:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from index_collection.cc:2:
In file included from ./delimited_index_connection.h:1:
In file included from ./delimited_index.h:9:
In file included from mio/include/mio/shared_mmap.hpp:24:
In file included from mio/include/mio/mmap.hpp:24:
In file included from mio/include/mio/page.hpp:27:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from index_collection.cc:2:
In file included from ./delimited_index_connection.h:1:
In file included from ./delimited_index.h:9:
In file included from mio/include/mio/shared_mmap.hpp:24:
In file included from mio/include/mio/mmap.hpp:24:
In file included from mio/include/mio/page.hpp:27:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from index_collection.cc:2:
In file included from ./delimited_index_connection.h:1:
In file included from ./delimited_index.h:9:
In file included from mio/include/mio/shared_mmap.hpp:24:
In file included from mio/include/mio/mmap.hpp:24:
In file included from mio/include/mio/page.hpp:27:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
5 errors generated.
make: *** [index_collection.o] Error 1
make: *** Waiting for unfinished jobs....
ERROR: compilation failed for package ‘vroom’
* removing ‘.../revdep/checks.noindex/vroom/new/vroom.Rcheck/vroom’

```
### CRAN

```
* installing *source* package ‘vroom’ ...
** package ‘vroom’ successfully unpacked and MD5 sums checked
** using staged installation
** libs
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c Iconv.cpp -o Iconv.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c LocaleInfo.cpp -o LocaleInfo.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c RcppExports.cpp -o RcppExports.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c altrep.cc -o altrep.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c delimited_index.cc -o delimited_index.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c delimited_index_connection.cc -o delimited_index_connection.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c fixed_width_index_connection.cc -o fixed_width_index_connection.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c gen.cc -o gen.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c grisu3.c -o grisu3.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c guess_type.cc -o guess_type.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c index_collection.cc -o index_collection.o
clang -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include  -fPIC  -Wall -g -O2  -c localtime.c -o localtime.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom.cc -o vroom.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom_big_int.cc -o vroom_big_int.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom_chr.cc -o vroom_chr.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom_date.cc -o vroom_date.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom_dbl.cc -o vroom_dbl.o
clang++ -std=gnu++11 -I"/Library/Frameworks/R.framework/Resources/include" -DNDEBUG  -I".../revdep/library.noindex/vroom/progress/include" -I".../revdep/library.noindex/xml2/old/Rcpp/include" -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk -I/usr/local/include -Imio/include -DWIN32_LEAN_AND_MEAN -Ispdlog/include -fPIC  -Wall -g -O2  -c vroom_dttm.cc -o vroom_dttm.o
In file included from index_collection.cc:2:
In file included from ./delimited_index_connection.h:1:
In file included from ./delimited_index.h:9:
In file included from mio/include/mio/shared_mmap.hpp:24:
In file included from mio/include/mio/mmap.hpp:24:
In file included from mio/include/mio/page.hpp:27:
In file included from /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:655:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h:39:17: error: unknown type name 'uuid_t'
int gethostuuid(uuid_t, const struct timespec *) __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
                ^
In file included from index_collection.cc:2:
In file included from ./delimited_index_connection.h:1:
In file included from ./delimited_index.h:9:
In file included from mio/include/mio/shared_mmap.hpp:24:
In file included from mio/include/mio/mmap.hpp:24:
In file included from mio/include/mio/page.hpp:27:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:662:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getsgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from index_collection.cc:2:
In file included from ./delimited_index_connection.h:1:
In file included from ./delimited_index.h:9:
In file included from mio/include/mio/shared_mmap.hpp:24:
In file included from mio/include/mio/mmap.hpp:24:
In file included from mio/include/mio/page.hpp:27:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:664:27: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      getwgroups_np(int *, uuid_t);
                              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from index_collection.cc:2:
In file included from ./delimited_index_connection.h:1:
In file included from ./delimited_index.h:9:
In file included from mio/include/mio/shared_mmap.hpp:24:
In file included from mio/include/mio/mmap.hpp:24:
In file included from mio/include/mio/page.hpp:27:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:727:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setsgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
In file included from index_collection.cc:2:
In file included from ./delimited_index_connection.h:1:
In file included from ./delimited_index.h:9:
In file included from mio/include/mio/shared_mmap.hpp:24:
In file included from mio/include/mio/mmap.hpp:24:
In file included from mio/include/mio/page.hpp:27:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:729:31: error: unknown type name 'uuid_t'; did you mean 'uid_t'?
int      setwgroups_np(int, const uuid_t);
                                  ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h:31:31: note: 'uid_t' declared here
typedef __darwin_uid_t        uid_t;
                              ^
5 errors generated.
make: *** [index_collection.o] Error 1
make: *** Waiting for unfinished jobs....
ERROR: compilation failed for package ‘vroom’
* removing ‘.../revdep/checks.noindex/vroom/old/vroom.Rcheck/vroom’

```
# xslt

<details>

* Version: 1.3
* Source code: https://github.com/cran/xslt
* URL: https://github.com/ropensci/xslt
* BugReports: https://github.com/ropensci/xslt/issues
* Date/Publication: 2017-11-18 22:28:07 UTC
* Number of recursive dependencies: 26

Run `revdep_details(,"xslt")` for more info

</details>

## In both

*   checking whether package ‘xslt’ can be installed ... ERROR
    ```
    Installation failed.
    See ‘.../revdep/checks.noindex/xslt/new/xslt.Rcheck/00install.out’ for details.
    ```

## Installation

### Devel

```
* installing *source* package ‘xslt’ ...
** package ‘xslt’ successfully unpacked and MD5 sums checked
** using staged installation
Found pkg-config cflags and libs!
Using PKG_CFLAGS=-I/usr/include/libxml2
Using PKG_LIBS=-lexslt -lxslt -lxml2 -lz -lpthread -licucore -lm -lxml2
------------------------- ANTICONF ERROR ---------------------------
Configuration failed because libexslt was not found. Try installing:
 * deb: libxslt1-dev (Debian, Ubuntu, etc)
 * rpm: libxslt-devel (Fedora, CentOS, RHEL)
 * csw: libxslt_dev (Solaris)
If libexslt is already installed, check that 'pkg-config' is in your
PATH and PKG_CONFIG_PATH contains a libexslt.pc file. If pkg-config
is unavailable you can set INCLUDE_DIR and LIB_DIR manually via:
R CMD INSTALL --configure-vars='INCLUDE_DIR=... LIB_DIR=...'
--------------------------------------------------------------------
ERROR: configuration failed for package ‘xslt’
* removing ‘.../revdep/checks.noindex/xslt/new/xslt.Rcheck/xslt’

```
### CRAN

```
* installing *source* package ‘xslt’ ...
** package ‘xslt’ successfully unpacked and MD5 sums checked
** using staged installation
Found pkg-config cflags and libs!
Using PKG_CFLAGS=-I/usr/include/libxml2
Using PKG_LIBS=-lexslt -lxslt -lxml2 -lz -lpthread -licucore -lm -lxml2
------------------------- ANTICONF ERROR ---------------------------
Configuration failed because libexslt was not found. Try installing:
 * deb: libxslt1-dev (Debian, Ubuntu, etc)
 * rpm: libxslt-devel (Fedora, CentOS, RHEL)
 * csw: libxslt_dev (Solaris)
If libexslt is already installed, check that 'pkg-config' is in your
PATH and PKG_CONFIG_PATH contains a libexslt.pc file. If pkg-config
is unavailable you can set INCLUDE_DIR and LIB_DIR manually via:
R CMD INSTALL --configure-vars='INCLUDE_DIR=... LIB_DIR=...'
--------------------------------------------------------------------
ERROR: configuration failed for package ‘xslt’
* removing ‘.../revdep/checks.noindex/xslt/old/xslt.Rcheck/xslt’

```
