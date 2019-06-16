#include "PCH.h"
#include "Log.h"
#include <spdlog\sinks\stdout_color_sinks.h>
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging

namespace one
{
    std::shared_ptr<spdlog::logger> Log::s_EngineLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_EngineLogger = spdlog::stdout_color_mt("Engine");
        s_EngineLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("Game");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}