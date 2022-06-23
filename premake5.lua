workspace "Blacksee"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
binDir = "bin/" .. outputdir
intermidiate = "bin-int/" .. outputdir
intermidiateBlackSee = intermidiate .. "/Blacksee"
intermidiateSandbox = intermidiate .. "/Sandbox"
blackseeBinDir = binDir .. "/Blacksee"
sandboxBinDir = binDir .. "/Sandbox"

project "Blacksee"
    location "Blacksee"
    kind "SharedLib"
    language "C++"

    targetdir (blackseeBinDir)
    objdir (intermidiateBlackSee)

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
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

     filter "configurations:Debug"
        defines "BS_DEBUG"
        symbols "On"

     filter "configurations:Release"
        defines "BS_RELEASE"
        optimize "On"
     
     filter "configurations:Dist"
        defines "BS_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"

    targetdir (sandboxBinDir)
    objdir (intermidiateSandbox)

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

    postbuildcommands
    {
        ("{COPY} ../" .. blackseeBinDir .. "/*.dll ../" .. sandboxBinDir)
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

     filter "configurations:Debug"
        defines "BS_DEBUG"
        symbols "On"

     filter "configurations:Release"
        defines "BS_RELEASE"
        optimize "On"
     
     filter "configurations:Dist"
        defines "BS_DIST"
        optimize "On"