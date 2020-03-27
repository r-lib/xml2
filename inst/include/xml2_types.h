#ifndef __XML2_XML2_TYPES__
#define __XML2_XML2_TYPES__

#include <libxml/tree.h>
#include <Rcpp.h>

inline void finaliseNode(xmlNodePtr node) {
  // do nothing
}

inline void finaliseNs(xmlNsPtr ns) {
  // do nothing
}

template <typename T> class XPtr {
  SEXP data_;

  public:
  XPtr(SEXP x) : data_(x) {
    if (TYPEOF(data_) != EXTPTRSXP) {
      Rf_error("Expecting an external pointer: [type=%s]", Rf_type2char(TYPEOF(data_)));
    }
    R_PreserveObject(data_);
  }

  XPtr(T* p) {
    data_ = R_MakeExternalPtr((void *) p, R_NilValue, R_NilValue);
  }

  operator SEXP() const { return data_; }

  T* get() const {
    return (T*)(R_ExternalPtrAddr(data_));
  }

  T* checked_get() const {
    T* ptr = get();
    if (ptr == NULL) {
      Rf_error("external pointer is not valid");
    }
    return ptr;
  }

  operator T*() {
    return checked_get();
  }

  T* operator->() const {
    return checked_get();
  }

  ~XPtr() {
    R_ReleaseObject(data_);
  }
};

typedef Rcpp::XPtr<xmlDoc,Rcpp::PreserveStorage,xmlFreeDoc> XPtrDoc;
typedef ::XPtr<xmlNode> XPtrNode;
typedef Rcpp::XPtr<xmlNs,Rcpp::PreserveStorage,finaliseNs> XPtrNs;

#endif
