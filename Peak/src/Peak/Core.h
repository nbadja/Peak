#pragma once

#ifdef PEAK_PLATFORM_WINDOWS
	#ifdef PEAK_BUILD_DLL
		#define PEAK_API __declspec(dllexport)
	#else
		#define PEAK_API __declspec(dllimport)
	#endif
#else
	#error Peak only supports Windows!
#endif

#define BIT(x) (1 << x)