#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Blacksee
{
    class BLACKSEE_API Log
    {
    public:
        Log() = default;
        ~Log() = default;
        inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; }
        inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }

        static void Init();

    private:
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
    };
}

#define BS_CORE_TRACE(...) Blacksee::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BS_CORE_INFO(...) Blacksee::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BS_CORE_WARN(...) Blacksee::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BS_CORE_ERROR(...) Blacksee::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BS_CORE_FATAL(...) Blacksee::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define BS_TRACE(...) Blacksee::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BS_INFO(...) Blacksee::Log::GetClientLogger()->info(__VA_ARGS__)
#define BS_WARN(...) Blacksee::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BS_ERROR(...) Blacksee::Log::GetClientLogger()->error(__VA_ARGS__)
#define BS_FATAL(...) Blacksee::Log::GetClientLogger()->fatal(__VA_ARGS__)
