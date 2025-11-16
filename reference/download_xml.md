# Download a HTML or XML file

Libcurl implementation of `C_download` (the "internal" download method)
with added support for https, ftps, gzip, etc. Default behavior is
identical to
[`download.file()`](https://rdrr.io/r/utils/download.file.html), but
request can be fully configured by passing a custom
[`curl::handle()`](https://jeroen.r-universe.dev/curl/reference/handle.html).

## Usage

``` r
download_xml(
  url,
  file = basename(url),
  quiet = TRUE,
  mode = "wb",
  handle = curl::new_handle()
)

download_html(
  url,
  file = basename(url),
  quiet = TRUE,
  mode = "wb",
  handle = curl::new_handle()
)
```

## Arguments

- url:

  A character string naming the URL of a resource to be downloaded.

- file:

  A character string with the name where the downloaded file is saved.

- quiet:

  If `TRUE`, suppress status messages (if any), and the progress bar.

- mode:

  A character string specifying the mode with which to write the file.
  Useful values are `"w"`, `"wb"` (binary), `"a"` (append) and `"ab"`.

- handle:

  a curl handle object

## Value

Path of downloaded file (invisibly).

## Details

The main difference between `curl_download` and `curl_fetch_disk` is
that `curl_download` checks the http status code before starting the
download, and raises an error when status is non-successful. The
behavior of `curl_fetch_disk` on the other hand is to proceed as normal
and write the error page to disk in case of a non success response.

The `curl_download` function does support resuming and removes the
temporary file if the download did not complete successfully. For a more
advanced download interface which supports concurrent requests and
resuming large files, have a look at the
[multi_download](https://jeroen.r-universe.dev/curl/reference/multi_download.html)
function.

## See also

[curl_download](https://jeroen.r-universe.dev/curl/reference/curl_download.html)

## Examples

``` r
if (FALSE) { # \dontrun{
download_html("http://tidyverse.org/index.html")
} # }
```
