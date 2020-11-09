workspace "KainEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "KainEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "KainEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "KainEngine/vendor/imgui"
IncludeDir["glm"] = "KainEngine/vendor/glm"

group "Dependencies"
	include "KainEngine/vendor/GLFW"
	include "KainEngine/vendor/Glad"
	include "KainEngine/vendor/imgui"
group ""


project "KainEngine"
	location "KainEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "kepch.h"
	pchsource "KainEngine/src/kepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"KE_PLATFORM_WINDOWS",
			"KE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "KE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "KE_DIST"
		runtime "Release"
		symbols "On"



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
		"KainEngine/vendor/spdlog/include",
		"KainEngine/src",
		"KainEngine/vendor",
		"%{IncludeDir.glm}"

	}

	links
	{
		"KainEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"KE_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "KE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "KE_DIST"
		runtime "Release"
		symbols "On"