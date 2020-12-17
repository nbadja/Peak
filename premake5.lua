workspace "Peak"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SDL2"] = "Peak/vendor/SDL2/include"
IncludeDir["Glad"] = "Peak/vendor/Glad/include"
IncludeDir["ImGui"] = "Peak/vendor/imgui"
IncludeDir["glm"] = "Peak/vendor/glm"
IncludeDir["zep"] = "Peak/vendor/zep/include"

group "Dependencies"
include "Peak/vendor/SDL2/SDL2.lua"
include "Peak/vendor/SDL2/SDL2main.lua"
include "Peak/vendor/Glad"
include "Peak/vendor/imgui"
group ""

project "Peak"
	location "Peak"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "peakpch.h"
	pchsource "Peak/src/peakpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/zep/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.SDL2}",
		"GL",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.zep}"
	}

	links
	{
		"SDL2",
		"SDL2main",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
				"PEAK_PLATFORM_WINDOWS",
				"PEAK_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "PEAK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PEAK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PEAK_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Peak/vendor/spdlog/include",
		"Peak/src",
		"%{IncludeDir.SDL2}",
		"GL",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Peak",
		"SDL2",
		"SDL2main",
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PEAK_PLATFORM_WINDOWS"	
		}

	filter "configurations:Debug"
		defines "PEAK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PEAK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PEAK_DIST"
		runtime "Release"
		optimize "on"