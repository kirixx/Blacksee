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


