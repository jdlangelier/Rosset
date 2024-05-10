project "imgui"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/" .. outputdir .. "/%{prj.name}" .. "/obj")

    files
    {
        "%{prj.name}/*.h",
        "%{prj.name}/*.cpp",
        "%{prj.name}/backends/imgui_impl_glfw.cpp",
        "%{prj.name}/backends/imgui_impl_glfw.h",
        "%{prj.name}/backends/imgui_impl_opengl3.cpp",
        "%{prj.name}/backends/imgui_impl_opengl3.h"
    }

    includedirs {
        "%{prj.name}",
        "../glfw/glfw/include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
