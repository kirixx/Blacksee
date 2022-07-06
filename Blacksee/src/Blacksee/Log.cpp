#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include <spdlog/sinks/basic_file_sink.h>

namespace Blacksee
{
    std::shared_ptr<spdlog::logger> CLog::s_ClientLogger;
    std::shared_ptr<spdlog::logger> CLog::s_CoreLogger;

    void CLog::Init()
    {
        std::vector<spdlog::sink_ptr> logSinks;
        logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Blacksee.log", true));

        logSinks[0]->set_pattern("%^[%T] %n: %v%$");
        logSinks[1]->set_pattern("[%T] [%l] %n: %v");

        s_ClientLogger = std::make_shared<spdlog::logger>("Application", begin(logSinks), end(logSinks));
        spdlog::register_logger(s_ClientLogger);
        s_ClientLogger->set_level(spdlog::level::level_enum::trace);
        s_ClientLogger->flush_on(spdlog::level::trace);

        s_CoreLogger = std::make_shared<spdlog::logger>("Blacksee", begin(logSinks), end(logSinks));
        spdlog::register_logger(s_CoreLogger);
        s_CoreLogger->set_level(spdlog::level::level_enum::trace);
        s_CoreLogger->flush_on(spdlog::level::trace);
    }
}