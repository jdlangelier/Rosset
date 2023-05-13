#pragma once

#include <string>
#include <sstream>

#ifdef RS_PLATFORM_WINDOWS
    #include <Windows.h>
#endif

#ifdef RS_DEBUG
    #define RS_ENABLE_ASSERTS
#endif

#ifdef RS_ENABLE_ASSERTS
    #define RS_ASSERT(x, ...) { if (!(x)) { RS_APP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define RS_ENGINE_ASSERT(x, ...) { if (!(x)) { RS_ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define RS_ASSERT(x, ...)
    #define RS_ENGINE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define RS_BIND_EVENT_FUNCTION(function) std::bind(&function, this, std::placeholders::_1)

#include "Rosset/Config/KeyCodes.h"
#include "Rosset/Config/MouseButtonCodes.h"
#include "Rosset/Utils/Log.h"
