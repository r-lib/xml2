#pragma once

#include <cpp11.hpp>

#define R_NO_REMAP
#include <Rinternals.h>
#undef R_NO_REMAP

#include <algorithm>
#include <cstring>

cpp11::sexp write_bin(cpp11::sexp data, cpp11::sexp con);

inline size_t R_WriteConnection(cpp11::sexp con, void* buf, size_t n) {
  cpp11::writable::raws payload(n);
  memcpy(RAW(payload), buf, n);
  write_bin(payload, con);

  return n;
}
