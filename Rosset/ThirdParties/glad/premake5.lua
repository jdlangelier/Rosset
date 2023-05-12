project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin/" .. outputdir .. "/%{prj.name}" .. "/obj")

    files
    {
        "include/**.h",
        "src/**.c"
    }

    includedirs "include"

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
