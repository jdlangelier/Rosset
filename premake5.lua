workspace "Rosset"
    architecture "x64"
    startproject "Sandbox"
    configurations { "Debug", "Release" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["glad"] =  "Rosset/ThirdParties/glad/include"
    IncludeDir["glfw"] =  "Rosset/ThirdParties/glfw/glfw/include"
    IncludeDir["glm"] =  "Rosset/ThirdParties/glm"
    IncludeDir["imgui"] =  "Rosset/ThirdParties/imgui/imgui"
    IncludeDir["spdlog"] =  "Rosset/ThirdParties/spdlog/include"

    group "Dependencies"
        include "Rosset/ThirdParties/glad"    
        include "Rosset/ThirdParties/glfw"
        include "Rosset/ThirdParties/imgui"
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
        "%{IncludeDir.glad}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.imgui}",
        "%{IncludeDir.spdlog}"
    }

    links {
        "glad",
        "GLFW",
        "imgui",
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
        "%{IncludeDir.glad}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.imgui}",
        "%{IncludeDir.spdlog}"
    }

    links "Rosset"

    filter "system:windows"
        systemversion "latest"

        defines "RS_PLATFORM_WINDOWS"
 
    filter "configurations:Debug"
        defines "RS_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "RS_RELEASE"
        runtime "Release"
        optimize "on"
