#ifndef __XML2_XMLDOC__
#define __XML2_XMLDOC__

#include <Rcpp.h>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <libxml/parser.h>
#include "xml-utils.h"

// convenience typedef for shared_ptr to XmlDoc
typedef boost::shared_ptr<xmlDoc> Xml2DocumentPtr;

#endif
