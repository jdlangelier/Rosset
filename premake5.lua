workspace "Rosset"
    architecture "x64"
    startproject "Sandbox"
    configurations { "Debug", "Release" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["glfw"] =  "Rosset/ThirdParties/glfw/glfw/include"
    IncludeDir["spdlog"] =  "Rosset/ThirdParties/spdlog/include"

    include "Rosset/ThirdParties/glfw"

project "Rosset"
    location "Rosset"
    kind "SharedLib"
    language "C++"

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
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines {
            "RS_PLATFORM_WINDOWS",
            "RS_BUILD_DLL"
        }

        postbuildcommands { ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") }

    filter "configurations:Debug"
        defines {
            "RS_DEBUG",
            "RS_ENABLE_ASSERTS"
        }
        symbols "On"

    filter "configurations:Release"
        defines "RS_RELEASE"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

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
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines "RS_PLATFORM_WINDOWS"
 
    filter "configurations:Debug"
        defines {
            "RS_DEBUG",
            "RS_ENABLE_ASSERTS"
        }
        symbols "On"

    filter "configurations:Release"
        defines "RS_RELEASE"
        optimize "On"
