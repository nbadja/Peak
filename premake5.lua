workspace "Peak"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}


project "Peak"
	location "Peak"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "peakpch.h"
	pchsource "Peak/src/peakpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	links
	{
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
				"PEAK_PLATFORM_WINDOWS",
				"PEAK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PEAK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PEAK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PEAK_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Peak/vendor/spdlog/include",
		"Peak/src"
	}

	links
	{
		"Peak"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PEAK_PLATFORM_WINDOWS"	
		}

	filter "configurations:Debug"
		defines "PEAK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PEAK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PEAK_DIST"
		optimize "On"