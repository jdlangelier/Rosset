workspace "Rosset"
    architecture "x64"
    startproject "Sandbox"
    configurations { "Debug", "Release" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["glfw"] =  "Rosset/ThirdParties/glfw/glfw/include"
    IncludeDir["spdlog"] =  "Rosset/ThirdParties/spdlog/include"

    group "Dependencies"
        include "Rosset/ThirdParties/glfw"
    group ""

project "Rosset"
    location "Rosset"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/" .. outputdir .. "/%{prj.name}" .. "/obj")

    pchheader "Rosset/Config/RsConfig.h"
    pchsource "%{prj.name}/src/Rosset/Config/RsConfig.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.spdlog}"
    }

    links {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines "RS_PLATFORM_WINDOWS"

    filter "configurations:Debug"
        defines "RS_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "RS_RELEASE"
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/" .. outputdir .. "/%{prj.name}" .. "/obj")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Rosset/src",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.spdlog}"
    }

    links "Rosset"

    filter "system:windows"
        systemversion "latest"

        defines "RS_PLATFORM_WINDOWS"
 
    filter "configurations:Debug"
        defines "RS_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "RS_RELEASE"
        runtime "Release"
        optimize "On"
