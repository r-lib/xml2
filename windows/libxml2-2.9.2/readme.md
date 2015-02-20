Both versions were compiled with msys and gcc 4.6.3 from Rtools 3.1. 
Simply extract libxml2 dir and use:

```bash
CFLAGS="-m32" ./configure
make
```

Or for x64:

```bash
CFLAGS="-m64" ./configure
make 
```

**Important:** Some versions of mingw give this error when linking the static library:

```
undefined reference to `_imp__xmlFree'
```

To fix this, you need to pass `-DIN_LIBXML` when compiling your **client**. See this [comment](https://github.com/GNOME/libxml2/blob/v2.9.2/include/libxml/xmlexports.h#L111-L115).
Example `Makevars.win` file:

```Make
LIB_XML="../windows/libxml2-2.9.2"
PKG_CPPFLAGS= -I${LIB_XML}/include -DIN_LIBXML
PKG_LIBS= -L${LIB_XML}/lib${R_ARCH} -lxml2 -liconv -lz -lws2_32
```
