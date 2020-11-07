#pragma once

#ifdef KE_PLATFORM_WINDOWS
	#ifdef 	KE_BUILD_DLL
		#define KAINENGINE_API __declspec(dllexport)
	#else
		#define KAINENGINE_API __declspec(dllimport)
	#endif
#else
	#error KainEngine only supports Windows
#endif

#define BIT(x) (1 << x)