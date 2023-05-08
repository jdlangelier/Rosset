#include "Rosset/Config/RsConfig.h"

#include "Rosset/Utils/Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

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
