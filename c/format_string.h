/*
 *   zsync - client side rsync over http
 *   Copyright (C) 2004,2005 Colin Phipps <cph@moria.org.uk>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the Artistic License v2 (see the accompanying 
 *   file COPYING for the full license terms), or, at your option, any later 
 *   version of the same license.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   COPYING file for details.
 */

#include <inttypes.h>

#if defined(PRIu32) && !defined(HAVE_WINSOCK2_H)
# define SIZE_T_PF "%zd"
#else
# define SIZE_T_PF "%u"
#endif

#if SIZEOF_OFF_T == 8
# ifdef PRIu64
#  define OFF_T_PF "%" PRIu64
# else
#  define OFF_T_PF "%llu"
# endif
#else
# ifdef HAVE_WINSOCK2_H
#  define OFF_T_PF "%ld"
# else
# ifdef PRIu32
#  define OFF_T_PF "%" PRIu32
# else
#  define OFF_T_PF "%lu"
# endif
#endif
#endif

