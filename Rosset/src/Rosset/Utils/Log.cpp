#include "Rosset/Config/RsConfig.h"

#include "Rosset/Utils/Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Rosset {
    std::shared_ptr<spdlog::logger> Log::s_engineLogger;
    std::shared_ptr<spdlog::logger> Log::s_appLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        s_engineLogger = spdlog::stdout_color_mt("Engine");
        s_engineLogger->set_level(spdlog::level::trace);

        s_appLogger = spdlog::stdout_color_mt("App");
        s_appLogger->set_level(spdlog::level::trace);
    }
}
