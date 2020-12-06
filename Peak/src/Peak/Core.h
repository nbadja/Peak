#pragma once

#include "SDL.h"

#ifdef PEAK_PLATFORM_WINDOWS
#if PEAK_DYNAMIC_LINK
	#ifdef PEAK_BUILD_DLL
		#define PEAK_API __declspec(dllexport)
	#else
		#define PEAK_API __declspec(dllimport)
	#endif
#else
	#define PEAK_API
#endif
#else
	#error Peak only supports Windows!
#endif

#define BIT(x) (1 << x)