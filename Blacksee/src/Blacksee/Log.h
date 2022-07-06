#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Blacksee
{
    class BLACKSEE_API CLog
    {
    public:
        CLog() = default;
        ~CLog() = default;
        inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; }
        inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }

        static void Init();

    private:
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
    };
}

#define BS_CORE_TRACE(...) Blacksee::CLog::GetCoreLogger()->trace(__VA_ARGS__)
#define BS_CORE_INFO(...) Blacksee::CLog::GetCoreLogger()->info(__VA_ARGS__)
#define BS_CORE_WARN(...) Blacksee::CLog::GetCoreLogger()->warn(__VA_ARGS__)
#define BS_CORE_ERROR(...) Blacksee::CLog::GetCoreLogger()->error(__VA_ARGS__)
#define BS_CORE_FATAL(...) Blacksee::CLog::GetCoreLogger()->fatal(__VA_ARGS__)

#define BS_TRACE(...) Blacksee::CLog::GetClientLogger()->trace(__VA_ARGS__)
#define BS_INFO(...) Blacksee::CLog::GetClientLogger()->info(__VA_ARGS__)
#define BS_WARN(...) Blacksee::CLog::GetClientLogger()->warn(__VA_ARGS__)
#define BS_ERROR(...) Blacksee::CLog::GetClientLogger()->error(__VA_ARGS__)
#define BS_FATAL(...) Blacksee::CLog::GetClientLogger()->fatal(__VA_ARGS__)
