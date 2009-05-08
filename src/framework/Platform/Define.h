/*
 * Copyright (C) 2005-2009 QuadCore <http://getQuadCore.com/>
 *
 * Copyright (C) 2008-2009 Quad <http://www.quadcore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef QUAD_DEFINE_H
#define QUAD_DEFINE_H

#include <sys/types.h>

#include <ace/Basic_Types.h>
#include <ace/ACE_export.h>

#include "Platform/CompilerDefs.h"

#define QUAD_LITTLEENDIAN 0
#define QUAD_BIGENDIAN    1

#if !defined(QUAD_ENDIAN)
#  if defined (ACE_BIG_ENDIAN)
#    define QUAD_ENDIAN QUAD_BIGENDIAN
#  else //ACE_BYTE_ORDER != ACE_BIG_ENDIAN
#    define QUAD_ENDIAN QUAD_LITTLEENDIAN
#  endif //ACE_BYTE_ORDER
#endif //QUAD_ENDIAN

#if PLATFORM == PLATFORM_WINDOWS
#  define QUAD_EXPORT __declspec(dllexport)
#  define QUAD_LIBRARY_HANDLE HMODULE
#  define QUAD_LOAD_LIBRARY(a) LoadLibrary(a)
#  define QUAD_CLOSE_LIBRARY FreeLibrary
#  define QUAD_GET_PROC_ADDR GetProcAddress
#  define QUAD_IMPORT __cdecl
#  define QUAD_SCRIPT_EXT ".dll"
#  define QUAD_SCRIPT_NAME "QuadScript"
#  define QUAD_PATH_MAX MAX_PATH
#else //PLATFORM != PLATFORM_WINDOWS
#  define QUAD_LIBRARY_HANDLE void*
#  define QUAD_EXPORT export
#  define QUAD_LOAD_LIBRARY(a) dlopen(a,RTLD_NOW)
#  define QUAD_CLOSE_LIBRARY dlclose
#  define QUAD_GET_PROC_ADDR dlsym
#  if defined(__APPLE_CC__) && defined(BIG_ENDIAN)
#    define QUAD_IMPORT __attribute__ ((longcall))
#  elif defined(__x86_64__)
#    define QUAD_IMPORT
#  else
#    define QUAD_IMPORT __attribute__ ((cdecl))
#  endif //__APPLE_CC__ && BIG_ENDIAN
#  if defined(__APPLE_CC__)
#    define QUAD_SCRIPT_EXT ".dylib"
#    define QUAD_SCRIPT_NAME "../lib/libquadscript"
#  else
#    define QUAD_SCRIPT_EXT ".so"
#    define QUAD_SCRIPT_NAME "libquadscript"
#  endif //__APPLE_CC__
#  define QUAD_PATH_MAX PATH_MAX
#endif //PLATFORM

#if PLATFORM == PLATFORM_WINDOWS
#  ifdef QUAD_WIN32_DLL_IMPORT
#    define QUAD_DLL_DECL __declspec(dllimport)
#  else //!QUAD_WIN32_DLL_IMPORT
#    ifdef QUAD_WIND_DLL_EXPORT
#      define QUAD_DLL_DECL __declspec(dllexport)
#    else //!QUAD_WIND_DLL_EXPORT
#      define QUAD_DLL_DECL
#    endif //QUAD_WIND_DLL_EXPORT
#  endif //QUAD_WIN32_DLL_IMPORT
#else //PLATFORM != PLATFORM_WINDOWS
#  define QUAD_DLL_DECL
#endif //PLATFORM

#if PLATFORM == PLATFORM_WINDOWS
#  define QUAD_DLL_SPEC __declspec(dllexport)
#  ifndef DECLSPEC_NORETURN
#    define DECLSPEC_NORETURN __declspec(noreturn)
#  endif //DECLSPEC_NORETURN
#else //PLATFORM != PLATFORM_WINDOWS
#  define QUAD_DLL_SPEC
#  define DECLSPEC_NORETURN
#endif //PLATFORM

#if !defined(DEBUG)
#  define QUAD_INLINE inline
#else //DEBUG
#  if !defined(QUAD_DEBUG)
#    define QUAD_DEBUG
#  endif //QUAD_DEBUG
#  define QUAD_INLINE
#endif //!DEBUG

#if COMPILER == COMPILER_GNU
#  define ATTR_NORETURN __attribute__((noreturn))
#  define ATTR_PRINTF(F,V) __attribute__ ((format (printf, F, V)))
#else //COMPILER != COMPILER_GNU
#  define ATTR_NORETURN
#  define ATTR_PRINTF(F,V)
#endif //COMPILER == COMPILER_GNU

typedef ACE_INT64 int64;
typedef ACE_INT32 int32;
typedef ACE_INT16 int16;
typedef ACE_INT8 int8;
typedef ACE_UINT64 uint64;
typedef ACE_UINT32 uint32;
typedef ACE_UINT16 uint16;
typedef ACE_UINT8 uint8;

#if COMPILER != COMPILER_MICROSOFT
typedef uint16      WORD;
typedef uint32      DWORD;
#endif //COMPILER

typedef uint64 OBJECT_HANDLE;

#endif //QUAD_DEFINE_H

