#ifndef __XML2_XMLNODE__
#define __XML2_XMLNODE__

#include <Rcpp.h>
#include <boost/noncopyable.hpp>
#include "xml-utils.h"
#include <libxml/tree.h>

class XmlNode {
  Xml2DocumentPtr pDoc_;
  xmlNode* pNode_;

public:

  XmlNode(Xml2DocumentPtr pDoc, xmlNode* pNode): pDoc_(pDoc), pNode_(pNode) {
  }

  Rcpp::CharacterVector name() {
    return xmlCharToRChar(pNode_->name);
  }

};

#endif
