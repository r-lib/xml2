#pragma once

#include <cpp11.hpp>

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <algorithm>
#include <cstring>

cpp11::sexp read_bin(cpp11::sexp con, size_t bytes = 64 * 1024);
cpp11::sexp write_bin(cpp11::sexp data, cpp11::sexp con);

inline size_t R_WriteConnection(cpp11::sexp con, void* buf, size_t n) {
  cpp11::writable::raws payload(n);
  cpp11::sexp payload_sexp = cpp11::sexp(payload);

  memcpy(RAW(payload_sexp), buf, n);

  write_bin(payload_sexp, con);

  return n;
}
