#include <cpp11.hpp>

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <iterator>
#include <vector>
#include "xml2_utils.h"

using namespace cpp11::literals; // so we can use ""_nm syntax

// Wrapper around R's read_bin function
SEXP read_bin(SEXP con, cpp11::doubles bytes_sxp) {
  cpp11::strings raw_sxp({"raw"});

  auto readBin = cpp11::package("base")["readBin"];
  cpp11::sexp res = readBin("con"_nm = con, "what"_nm = raw_sxp, "n"_nm = bytes_sxp);
  return res;
}

// Wrapper around R's write_bin function
cpp11::sexp write_bin(cpp11::sexp data, cpp11::sexp con) {
  cpp11::function write_bin = cpp11::package("base")["writeBin"];
  return write_bin(data, con);
}

// Read data from a connection in chunks and then combine into a single
// raw vector.
//
[[cpp11::register]]
cpp11::sexp read_connection_(cpp11::sexp con_sxp, cpp11::doubles read_size_sxp) {

  BEGIN_CPP
  std::vector<char> buffer;

  cpp11::sexp chunk = read_bin(con_sxp, read_size_sxp);
  R_xlen_t chunk_size = Rf_xlength(chunk);
  while(chunk_size > 0) {
    std::copy(RAW(chunk), RAW(chunk) + chunk_size, std::back_inserter(buffer));
    chunk = read_bin(con_sxp, read_size_sxp);
    chunk_size = Rf_xlength(chunk);
  }

  cpp11::raws out(buffer);

  return out;

  END_CPP
}
