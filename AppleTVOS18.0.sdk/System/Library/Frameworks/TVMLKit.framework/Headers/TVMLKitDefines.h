//
//  TVMLKitDefines.h
//  TVMLKit
//
//  Copyright (c) 2014-2015 Apple. All rights reserved.
//

#ifndef _TVMLKit_TVMLKitDefines_
#define _TVMLKit_TVMLKitDefines_

#if !defined(TV_EXTERN)
#ifdef __cplusplus
#define TV_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define TV_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

#if !defined(TV_EXTERN_CLASS)
#ifdef __cplusplus
#define TV_EXTERN_CLASS   extern "C" __attribute__((visibility ("default")))
#else
#define TV_EXTERN_CLASS   extern __attribute__((visibility ("default")))
#endif
#endif

#if __BUILDING_TVMLKIT__
# define TVML_DEPRECATED_BEGIN(...)
# define TVML_DEPRECATED_END
# define TVML_DEPRECATED(...)
# define TVML_DEPRECATED_IOS(a, b)
#else
# define TVML_DEPRECATED_BEGIN(...) API_DEPRECATED_BEGIN(__VA_ARGS__)
# define TVML_DEPRECATED_END API_DEPRECATED_END
# define TVML_DEPRECATED(...) API_DEPRECATED(__VA_ARGS__)
# define TVML_DEPRECATED_IOS(a, b) NS_DEPRECATED_IOS(a,b)
#endif

#if !defined(TV_EXTERN_CLASS_AVAILABLE)
#define TV_EXTERN_CLASS_AVAILABLE(version) __attribute__((visibility("default"))) NS_CLASS_AVAILABLE(NA, version)
#endif

#endif /* defined(_TVMLKit_TVMLKitDefines_) */
