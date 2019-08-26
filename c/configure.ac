# Process this file with autoconf to produce a configure script.

AC_INIT([zsync],[0.6.3],[http://zsync.moria.org.uk/])

AC_CONFIG_SRCDIR([client.c])
AC_CONFIG_AUX_DIR([autotools])
AC_CONFIG_MACRO_DIR([autotools])

AC_CANONICAL_HOST

AM_INIT_AUTOMAKE([dist-bzip2 no-dist-gzip foreign check-news -Woverride -Wobsolete -Wportability -Wsyntax -Wunsupported])
AM_MAINTAINER_MODE

dnl --- Check for programs
AC_PROG_CC
AC_PROG_LN_S
AC_PROG_RANLIB

AC_ARG_ENABLE([profile],
   AS_HELP_STRING([--enable-profile],[Turns on profiling]))

AC_ARG_ENABLE([debug],AS_HELP_STRING([--enable-debug], [turns on some debugging features]),
AC_DEFINE([DEBUG], [], [Turn on some debugging features]))

AS_IF([test "x$enable_profile" = "xyes"], [
   ZS_CFLAGS="${ZS_CFLAGS} -pg" ])

dnl --- Header files, typedefs, structures, libraries
AC_C_CONST
AC_HEADER_STDC
# string.h, memory.h, stdlib.h both included in the default header checks
# but we do need to give at least one .h to test, or Solaris sh errors
AC_CHECK_HEADERS([string.h])
AC_TYPE_SIZE_T
AC_CHECK_FUNCS(memcpy pwrite pread mkstemp gmtime_r strptime)

case $host_os in
   mingw32)
       host_os_mingw32=yes
       AC_CHECK_HEADERS([winsock2.h])
       AC_CHECK_LIB(ws2_32, main, LIBS="${LIBS} -lws2_32")
       AC_DEFINE(popen, _popen, [mingw32 version of popen])
       AC_DEFINE(pclose, _pclose, [mingw32 version of pclose])
       AC_DEFINE(snprintf, _snprintf, [mingw32 version of snprintf])
       AC_DEFINE(ftruncate, _chsize, [mingw32 does not have ftruncate])
       AC_DEFINE(_WIN32_WINNT, 0x0501, [Force getaddrinfo declaration])
       ;;
   *)
       AC_DEFINE([_XOPEN_SOURCE], 600, [Enable POSIX extensions if present])
       AC_DEFINE([_BSD_SOURCE],1, [Enable BSD extensions if present])
       AC_REPLACE_FUNCS(getaddrinfo)
       ;;
esac
AM_CONDITIONAL([MINGW32], test "x$host_os_mingw32" = "xyes")

AC_CHECK_DECL(BYTE_ORDER, [], [
   AC_DEFINE(LITTLE_ENDIAN, 1234, [Little endian])
   AC_DEFINE(BIG_ENDIAN, 4321, [Big endian])
   AC_C_BIGENDIAN(
      AC_DEFINE(BYTE_ORDER, BIG_ENDIAN, [Byte order]),
      AC_DEFINE(BYTE_ORDER, LITTLE_ENDIAN, [Byte order]))
   ])

X_TYPE_SOCKLEN_T
X_TYPE_IN_PORT_T
X_DECL_H_ERRNO

dnl Solaris needs -lsocket - and we need this for the getaddrinfo test
AC_CHECK_LIB(socket,socket)

dnl - Large file support if available
AC_SYS_LARGEFILE
AC_FUNC_FSEEKO
AC_CHECK_SIZEOF(size_t)
AC_CHECK_SIZEOF(off_t)
AC_CHECK_TYPE(uint, unsigned int)

AM_WITH_DMALLOC
AH_BOTTOM([
#ifdef HAVE_WINSOCK2_H
# include <winsock2.h>
# include <ws2tcpip.h>
#else
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
#endif
])

X_C_COMPILE_FLAGS($ZS_CFLAGS -g -Wall -Wwrite-strings -Winline -Wextra -Winline -Wmissing-noreturn -Wredundant-decls -Wnested-externs -Wundef -Wbad-function-cast -Wcast-align -Wvolatile-register-var -ffast-math)

dnl --- output
AC_SUBST(ac_aux_dir)
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile librcksum/Makefile zlib/Makefile libzsync/Makefile doc/Makefile])
AC_OUTPUT

