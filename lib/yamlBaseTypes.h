/*
 * yamlBaseTypes
 * Simplified YAML interface for C/Fortran
 *
 * Basic types used by all component APIs.
 *
 */

#ifndef __YAMLBASETYPES_H__
#define __YAMLBASETYPES_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <errno.h>
#include <ctype.h>
#include <yaml.h>

/*!
    @typedef yamlErrorCode
    Type of error codes used in this library.
*/
typedef unsigned int yamlErrorCode;

/*!
    @enum yamlError
    Basic error codes for all components of the API.
*/
enum {
    yamlError_none = 0
};


/*!
    @typedef yamlOptions
    Type of bitwise-enumerated options used in this library.
*/
typedef unsigned int yamlOptionsBitvec;

/*!
    @enum yamlOptions
    Basic options for all components of the API.
*/
enum {
    yamlOptions_none = 0
};


/*!
    @define yamlCStringFullLength
    Special value used to indicate a NUL-terminated C string whose
    full length should be used by a function. 
*/
#define yamlCStringFullLength   ((size_t)-1)


/* #undef FORTRAN_INTEGER8 */
/* #undef FORTRAN_LOGICAL8 */
#define FORTRAN_REAL8 TRUE

#ifdef FORTRAN_INTEGER8
#define YAMLFORTRANINTERFACE_INT_MAX	LONG_MAX
#define YAMLFORTRANINTERFACE_INT_MIN	LONG_MIN
typedef long int    yamlFortranInterfaceInteger;
#else
#define YAMLFORTRANINTERFACE_INT_MAX	INT_MAX
#define YAMLFORTRANINTERFACE_INT_MIN	INT_MIN
typedef int         yamlFortranInterfaceInteger;
#endif

#ifdef FORTRAN_LOGICAL8
typedef long int    yamlFortranInterfaceLogical;
#else
typedef int         yamlFortranInterfaceLogical;
#endif

#ifdef FORTRAN_REAL8
typedef double      yamlFortranInterfaceReal;
#else
typedef float       yamlFortranInterfaceReal;
#endif

#define HAVE_STRNCPY 1
#ifndef HAVE_STRNCPY
char *strncpy(char *dest, const char *src, size_t n);
#endif

#define HAVE_STRNCASECMP 1
#ifndef HAVE_STRNCASECMP
int strncasecmp(const char *s1, const char *s2, size_t n);
#endif

#endif /* __YAMLBASETYPES_H__ */
