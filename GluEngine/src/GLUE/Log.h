#pragma once


#include "GLUE/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GLUE {
	class GLUE_API Log {
		public:
			static void Init();
			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}




#define GLUE_CORE_TRACE(...) ::GLUE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GLUE_CORE_INFO(...)  ::GLUE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GLUE_CORE_WARN(...)  ::GLUE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GLUE_CORE_ERROR(...) ::GLUE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GLUE_CORE_FATAL(...) ::GLUE::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define GLUE_TRACE(...) ::GLUE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GLUE_INFO(...)  ::GLUE::Log::GetClientLogger()->info(__VA_ARGS__)
#define GLUE_WARN(...)  ::GLUE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GLUE_ERROR(...) ::GLUE::Log::GetClientLogger()->error(__VA_ARGS__)
#define GLUE_FATAL(...) ::GLUE::Log::GetClientLogger()->fatal(__VA_ARGS__)


#ifdef GLUE_DIST
	#define GLUE_CORE_TRACE(...) 
	#define GLUE_CORE_INFO(...)  
	#define GLUE_CORE_WARN(...)  
	#define GLUE_CORE_ERROR(...) 
	#define GLUE_CORE_FATAL(...) 


	#define GLUE_TRACE(...) 
	#define GLUE_INFO(...)  
	#define GLUE_WARN(...)  
	#define GLUE_ERROR(...) 
	#define GLUE_FATAL(...)
#endif