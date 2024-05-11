#include "Rosset/Config/RsConfig.h"

#include "Rosset/Utils/Log.h"

#if defined(_MSC_VER)
    #pragma warning( push )
    #pragma warning( disable : 4996 )
    #pragma warning( disable : 6285 )
    #pragma warning( disable : 26437 )
    #pragma warning( disable : 26450 )
    #pragma warning( disable : 26495 )
    #pragma warning( disable : 26498 )
    #pragma warning( disable : 26800 )
#endif

#include <spdlog/sinks/stdout_color_sinks.h>

#if defined(_MSC_VER)
    #pragma warning( pop )
#endif

namespace Rosset {
    std::shared_ptr<spdlog::logger> Log::ms_spEngineLogger;
    std::shared_ptr<spdlog::logger> Log::ms_spAppLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        ms_spEngineLogger = spdlog::stdout_color_mt("Engine");
        ms_spEngineLogger->set_level(spdlog::level::trace);

        ms_spAppLogger = spdlog::stdout_color_mt("App");
        ms_spAppLogger->set_level(spdlog::level::trace);
    }
}
