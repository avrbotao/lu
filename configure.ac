#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(lu, 1.0.53, alexandre at botao dot org)
AC_MSG_NOTICE([lu 1.0.53 alexandre at botao dot org])
AM_INIT_AUTOMAKE([subdir-objects])
AC_CANONICAL_HOST
OE_CFLAGS=""
AS_CASE([$host_os],
        [aix*],
        [
           OE_CFLAGS="$OE_CFLAGS -DAIX"
        ],
        [hpux*],
        [
           OE_CFLAGS="$OE_CFLAGS -DHPUX"
        ],
        [linux*],
        [
           OE_CFLAGS="$OE_CFLAGS -DLINUX"
        ],
        [darwin*],
        [
           OE_CFLAGS="$OE_CFLAGS -DOSX"
	],
        [solaris*],
        [
           OE_CFLAGS="$OE_CFLAGS -DSOLARIS"
        ],
	[*],
	[
		AC_MSG_ERROR(["OS $host_os not supported"])
        ])
AS_CASE([$host_cpu],
	[hppa*],
	[
		OE_CFLAGS="$OE_CFLAGS -DHPPA"
	],
	[ia64],
	[
		OE_CFLAGS="$OE_CFLAGS -DIA64"
	],
	[i?86],
	[
		OE_CFLAGS="$OE_CFLAGS -DIX86"
	],
	[powerpc],
	[
		OE_CFLAGS="$OE_CFLAGS -DPOWERPC"
	],
	[sparc],
	[
		OE_CFLAGS="$OE_CFLAGS -DSPARC"
	],
	[x86_64],
	[
		OE_CFLAGS="$OE_CFLAGS -DAMD64"
	],
	[*],
	[
		AC_MSG_ERROR(["CPU $host_cpu not supported"])
	])
AC_SUBST([OE_CFLAGS])
AC_CONFIG_SRCDIR([include/tohuman.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_RANLIB
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB(crypt,crypt,[LIBS="$LIBS -lcrypt"])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT64_T
AC_TYPE_OFF_T

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
