#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Peak {
	
	class PEAK_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define PEAK_CORE_TRACE(...) :: Peak::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PEAK_CORE_INFO(...) :: Peak::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PEAK_CORE_WARN(...) :: Peak::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PEAK_CORE_ERROR(...) :: Peak::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PEAK_CORE_FATAL(...) :: Peak::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define PEAK_TRACE(...) :: Peak::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PEAK_INFO(...) :: Peak::Log::GetClientLogger()->info(__VA_ARGS__)
#define PEAK_WARN(...) :: Peak::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PEAK_ERROR(...) :: Peak::Log::GetClientLogger()->error(__VA_ARGS__)
#define PEAK_FATAL(...) :: Peak::Log::GetClientLogger()->fatal(__VA_ARGS__)