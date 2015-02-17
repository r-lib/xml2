#ifndef __XML2_XML2_TYPES__
#define __XML2_XML2_TYPES__

#include <boost/shared_ptr.hpp>
#include <libxml/parser.h>

// convenience typedef for shared_ptr to XmlDoc - this should always
// be construted with a custom deleter to ensure that the memory allocated
// by libxml2 is cleaned up.
typedef boost::shared_ptr<xmlDoc> Xml2DocumentPtr;

#include "XmlNode.h"

#endif
