#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace KainEngine
{
	class KAINENGINE_API Log
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
#define KE_CORE_TRACE(...) ::KainEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KE_CORE_INFO(...)  ::KainEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KE_CORE_WARN(...)  ::KainEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KE_CORE_ERROR(...) ::KainEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KE_CORE_FATAL(...) ::KainEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define KE_TRACE(...)      ::KainEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KE_INFO(...)       ::KainEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define KE_WARN(...)       ::KainEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KE_ERROR(...)      ::KainEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define KE_FATAL(...)      ::KainEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)