project "Blacksee"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src", 
        "vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW", 
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {

        }

     filter "configurations:Debug"
        defines 
        {
            "BS_DEBUG",
            "ASSERTIONS_ENABLED"
        }
        symbols "On"

     filter "configurations:Release"
        defines "BS_RELEASE"
        optimize "On"
     
     filter "configurations:Dist"
        defines "BS_DIST"
        optimize "On"