### autoconf configure.ac && autoreconf -if

AC_INIT(DESCRIPTION)


PKGCONFIG=`command -v pkg-config`
ISMAC=`uname | grep "[Dd]arwin"`


# Custom libxml2 path for compatibility with old XML package
if test -n "${LIBXML_INCDIR}"; then
  echo "User specified xml2 headers in $LIBXML_INCDIR."
  LIBXML_CFLAGS="-I$LIBXML_INCDIR"
elif test -n "$PKGCONFIG" ; then
  LIBXML_CFLAGS=`pkg-config --cflags libxml-2.0`
  LIBXML_LIBS=`pkg-config --libs libxml-2.0`
elif test -r "/usr/include/libxml2/libxml/parser.h" ; then
  LIBXML_CFLAGS="-I/usr/include/libxml2/"
elif test -r "/usr/local/include/libxml2/libxml/parser.h" ; then
  LIBXML_CFLAGS="-I/usr/local/include/libxml2/"
elif test -r "/opt/csw/include/libxml2/libxml/parser.h" ; then
  LIBXML_CFLAGS="-I/opt/csw/include/libxml2/"
  LIBXML_LIBS="-L/opt/csw/lib/ -lxml2"
elif test -n $ISMAC ; then
  DYNLIB=`xcodebuild -find-library xml2`
  XCODE=`dirname $DYNLIB`
  LIBXML_CFLAGS="-I$XCODE/include/libxml2"
fi

if test -n  "${LIBXML_CFLAGS}" ; then
  echo "Found libxml2 in ${LIBXML_CFLAGS}"
else
  AC_MSG_ERROR(["Could not find libxml2. Please install libxml2-devel (rpm) or libxml2-dev (deb)."])
fi


dnl Start to substitute templates
AC_SUBST(LIBXML_LIBS)
AC_SUBST(LIBXML_CFLAGS)
AC_OUTPUT(src/Makevars)


