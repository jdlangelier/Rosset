#pragma once

#include <string>
#include <sstream>

#ifdef RS_PLATFORM_WINDOWS
    #include <Windows.h>
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

#define BIT(x) (1 << x)
