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
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

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

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
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
        systemversion "latest"

        defines
        {
            "KE_PLATFORM_WINDOWS",
            "KE_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }


    filter "configurations:Debug"
        defines "KE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "KE_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "KE_DIST"
        runtime "Release"
        symbols "on"



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
        systemversion "latest"

        defines
        {
            "KE_PLATFORM_WINDOWS"
        }


    filter "configurations:Debug"
        defines "KE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "KE_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "KE_DIST"
        runtime "Release"
        symbols "on"