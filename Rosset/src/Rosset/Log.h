#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Rosset {
    class RS_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_engineLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetAppLogger() { return s_appLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_engineLogger;
        static std::shared_ptr<spdlog::logger> s_appLogger;
    };
}

#define RS_ENGINE_TRACE(...) ::Rosset::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define RS_ENGINE_INFO(...)  ::Rosset::Log::GetEngineLogger()->info(__VA_ARGS__)
#define RS_ENGINE_WARN(...)  ::Rosset::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define RS_ENGINE_ERROR(...) ::Rosset::Log::GetEngineLogger()->error(__VA_ARGS__)
#define RS_ENGINE_FATAL(...) ::Rosset::Log::GetEngineLogger()->fatal(__VA_ARGS__)

#define RS_APP_TRACE(...)  ::Rosset::Log::GetAppLogger()->trace(__VA_ARGS__)
#define RS_APP_INFO(...)   ::Rosset::Log::GetAppLogger()->info(__VA_ARGS__)
#define RS_APP_WARN(...)   ::Rosset::Log::GetAppLogger()->warn(__VA_ARGS__)
#define RS_APP_ERROR(...)  ::Rosset::Log::GetAppLogger()->error(__VA_ARGS__)
#define RS_APP_FATAL(...)  ::Rosset::Log::GetAppLogger()->fatal(__VA_ARGS__)
