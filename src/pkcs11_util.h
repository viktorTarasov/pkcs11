#ifndef PKCS11_UTIL_H
#define PKCS11_UTIL_H

/*
 * Copyright (C) 2011 Mathias Brossard <mathias@brossard.org>
 */

#ifndef WIN32
   /* Unix case */
#define CK_DEFINE_FUNCTION(returnType, name) \
   returnType name

#define CK_DECLARE_FUNCTION(returnType, name) \
   returnType name

#define CK_DECLARE_FUNCTION_POINTER(returnType, name) \
   returnType (* name)

#define CK_CALLBACK_FUNCTION(returnType, name) \
   returnType (* name)

#else
   /* Win32 case */
#define CK_DEFINE_FUNCTION(returnType, name) \
   returnType __declspec(dllexport) name

#define CK_DECLARE_FUNCTION(returnType, name) \
   returnType __declspec(dllexport) name

#ifdef __MINGW32__
#define CK_DECLARE_FUNCTION_POINTER(returnType, name) \
   returnType (* name)
#else
#define CK_DECLARE_FUNCTION_POINTER(returnType, name)    \
   returnType __declspec(dllimport) (* name)
#endif

#define CK_CALLBACK_FUNCTION(returnType, name) \
   returnType (* name)

#endif

#define CK_PTR *
#ifndef NULL_PTR
#define NULL_PTR 0
#endif

#include <pkcs11.h>
#include <getopt.h>

#ifdef __cplusplus
extern "C" {
#endif

CK_FUNCTION_LIST  *pkcs11_get_function_list( const char *param );
CK_RV pkcs11_initialize(CK_FUNCTION_LIST_PTR funcs);
CK_RV pkcs11_initialize_nss(CK_FUNCTION_LIST_PTR funcs, const char *path);
void print_usage_and_die(char *name, const struct option *opts, const char **help);

#ifdef __cplusplus
};
#endif

#endif
