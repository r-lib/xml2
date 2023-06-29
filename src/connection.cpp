#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <iterator>
#include <vector>
#include "xml2_utils.h"

// Wrapper around R's read_bin function
SEXP read_bin(SEXP con, size_t bytes) {
  SEXP e;
  SEXP raw_sxp = PROTECT(Rf_mkString("raw"));
  SEXP bytes_sxp = PROTECT(Rf_ScalarInteger(bytes));
  PROTECT(e = Rf_lang4(Rf_install("readBin"), con, raw_sxp, bytes_sxp));
  SEXP res = Rf_eval(e, R_GlobalEnv);
  UNPROTECT(3);
  return res;
}

// Wrapper around R's write_bin function
SEXP write_bin(SEXP data, SEXP con) {
  SEXP e;
  PROTECT(e = Rf_lang3(Rf_install("writeBin"), data, con));
  SEXP res = Rf_eval(e, R_GlobalEnv);
  UNPROTECT(1);
  return res;
}

// Read data from a connection in chunks and then combine into a single
// raw vector.
//
// [[export]]
extern "C" SEXP read_connection_(SEXP con_sxp, SEXP read_size_sxp) {

  BEGIN_CPP
  std::vector<char> buffer;
  size_t read_size = REAL(read_size_sxp)[0];

  SEXP chunk = read_bin(con_sxp, read_size);
  R_xlen_t chunk_size = Rf_xlength(chunk);
  while(chunk_size > 0) {
    std::copy(RAW(chunk), RAW(chunk) + chunk_size, std::back_inserter(buffer));
    chunk = read_bin(con_sxp, read_size);
    chunk_size = Rf_xlength(chunk);
  }

  size_t size = buffer.size();

  SEXP out = PROTECT(Rf_allocVector(RAWSXP, size));
  std::copy(buffer.begin(), buffer.end(), RAW(out));

  UNPROTECT(1);

  return out;

  END_CPP
}
