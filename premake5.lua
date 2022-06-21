workspace "Blacksee"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Blacksee"
    location "Blacksee"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BS_PLATFORM_WINDOWS", 
            "BS_BUILD_DLL"
        }

        postbuildcommand
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

     filter "configuration:Debug"
        defines "BS_DEBUG"
        symbols "On"

     filter "configuration:Release"
        defines "BS_RELEASE"
        optimize "On"
     
     filter "configuration:Dist"
        defines "BS_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Blacksee/vendor/spdlog/include",
        "Blacksee/src"
    }

    links
    {
        "Blacksee"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BS_PLATFORM_WINDOWS"
        }

     filter "configuration:Debug"
        defines "BS_DEBUG"
        symbols "On"

     filter "configuration:Release"
        defines "BS_RELEASE"
        optimize "On"
     
     filter "configuration:Dist"
        defines "BS_DIST"
        optimize "On"