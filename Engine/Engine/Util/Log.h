#pragma once
#include <memory>

#pragma warning( push )
#pragma warning( disable : 26451 )
#pragma warning( pop )

#include <spdlog\spdlog.h>
#include <spdlog\fmt\ostr.h>

namespace one
{
    class Log
    {
    private:
        static std::shared_ptr<spdlog::logger> s_EngineLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    };
}

/*Engine System Logger*/
#define ENGINE_TRACE(...)       ::one::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define ENGINE_INFO(...)        ::one::Log::GetEngineLogger()->info(__VA_ARGS__)
#define ENGINE_WARN(...)        ::one::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define ENGINE_ERROR(...)       ::one::Log::GetEngineLogger()->error(__VA_ARGS__)
#define ENGINE_CRITICAL(...)    ::one::Log::GetEngineLogger()->critical(__VA_ARGS__)

/*Client System Logger*/
#define CLIENT_TRACE(...)       ::one::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_INFO(...)        ::one::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_WARN(...)        ::one::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_ERROR(...)       ::one::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_CRITICAL(...)    ::one::Log::GetClientLogger()->critical(__VA_ARGS__)