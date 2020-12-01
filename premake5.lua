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
IncludeDir["SDL2"] = "Peak/vendor/SDL2/include"
IncludeDir["Glad"] = "Peak/vendor/Glad/include"
IncludeDir["ImGui"] = "Peak/vendor/imgui"

group "Dependencies"
include "Peak/vendor/SDL2/SDL2.lua"
include "Peak/vendor/SDL2/SDL2main.lua"
include "Peak/vendor/Glad"
include "Peak/vendor/imgui"
group ""

project "Peak"
	location "Peak"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{prj.name}/src",
		"%{IncludeDir.SDL2}",
		"GL",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
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
		cppdialect "C++17"
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
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PEAK_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PEAK_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"Peak/src",
		"%{IncludeDir.SDL2}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"Peak",
		"SDL2",
		"SDL2main",
		"Glad"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"PEAK_PLATFORM_WINDOWS"	
		}

	filter "configurations:Debug"
		defines "PEAK_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PEAK_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PEAK_DIST"
		runtime "Release"
		optimize "On"