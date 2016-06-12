FROM rocker/r-devel-san

RUN apt-get -qq update \
	&& apt-get -qq dist-upgrade -y \
	&& apt-get -qq install git pandoc pandoc-citeproc libssl-dev libcurl4-openssl-dev libxml2-dev -y \
	&& RD -e 'install.packages(c("Rcpp", "BH", "httr", "testthat", "magrittr", "knitr", "rmarkdown", "covr"), quiet = T)'

RUN git clone https://github.com/hadley/xml2 \
	&& RD CMD build xml2 --no-build-vignettes \
	&& RD CMD INSTALL xml2_*.tar.gz --install-tests

RUN RD -e 'testthat::test_package("xml2"); q("no");' || true

RUN RD CMD check xml2_*.tar.gz
