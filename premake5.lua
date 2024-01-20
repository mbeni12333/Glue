workspace "GluEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

startproject "Sandbox"
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GluEngine"
    location "GluEngine"
    kind "SharedLib"
    language "C++"
    -- create a directory build containing a foilder for binaries, and objs

    targetdir ("build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("build/bin-int/" .. outputdir .. "/%{prj.name}")



    pchheader "gepch.h"
	pchsource "GluEngine/src/gepch.cpp"


    -- Add all the files in the src folder
    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }



    filter "system:windows"
        cppdialect = "C++17"
        staticruntime = "On"
        systemversion = "latest"

        defines{
            "GLUE_PLATFORM_WINDOWS",
            "GLUE_BUILD_DLL"
        }

        postbuildcommands{
            ("{COPY} %{cfg.buildtarget.relpath} ../build/bin//" .. outputdir .. "/Sandbox")
        }

    
    filter "configurations:Debug"
        defines "GLUE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "GLUE_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "GLUE_DIST"
        optimize "On"





project "Sandbox"
    location "Sandbox"
    language "C++"
    kind "ConsoleApp"

    targetdir ("build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("build/bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }


    includedirs{
        "GluEngine/vendor/spdlog/include",
        "GluEngine/src"
    }
    links{
        "GluEngine"
    }

    filter "system:windows"
        cppdialect = "C++17"
        staticruntime = "On"
        systemversion = "latest"

        defines{
            "GLUE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "GLUE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GLUE_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "GLUE_DIST"
        optimize "On"