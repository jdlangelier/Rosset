#pragma once

#include "Rosset/Config/RsConfig.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Rosset {
    class RS_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return ms_spEngineLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetAppLogger() { return ms_spAppLogger; }

    private:
        static std::shared_ptr<spdlog::logger> ms_spEngineLogger;
        static std::shared_ptr<spdlog::logger> ms_spAppLogger;
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
