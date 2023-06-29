#pragma once

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <algorithm>
#include <cstring>

SEXP read_bin(SEXP con, size_t bytes = 64 * 1024);
SEXP write_bin(SEXP data, SEXP con);

inline SEXP R_GetConnection(SEXP con) { return con; }

inline size_t R_ReadConnection(SEXP con, void* buf, size_t n) {
  SEXP res = PROTECT(read_bin(con, n));

  R_xlen_t size = Rf_xlength(res);

  memcpy(buf, RAW(res), size);

  UNPROTECT(1);

  return Rf_xlength(res);
}

inline size_t R_WriteConnection(SEXP con, void* buf, size_t n) {
  SEXP payload = PROTECT(Rf_allocVector(RAWSXP, n));

  memcpy(RAW(payload), buf, n);

  write_bin(payload, con);

  UNPROTECT(1);

  return n;
}
