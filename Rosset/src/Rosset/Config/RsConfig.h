#pragma once

#include <string>
#include <sstream>

#ifdef RS_PLATFORM_WINDOWS
    #include <Windows.h>
#endif

#ifdef RS_DEBUG
    #define RS_ENABLE_ASSERTS
#endif

#ifdef RS_PLATFORM_WINDOWS
    #ifdef RS_BUILD_DLL
        #define RS_API __declspec(dllexport)
    #else
        #define RS_API __declspec(dllimport)
    #endif
#else
    #error "Rosset only supports Windows!"
#endif

#ifdef RS_ENABLE_ASSERTS
    #define RS_ASSERT(x, ...) { if (!(x)) { RS_APP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define RS_ENGINE_ASSERT(x, ...) { if (!(x)) { RS_ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define RS_ASSERT(x, ...)
    #define RS_ENGINE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#include "Rosset/Utils/Log.h"
