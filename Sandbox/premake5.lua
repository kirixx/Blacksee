project "Sandbox"
    kind "ConsoleApp"
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
        "%{wks.location}/Blacksee/vendor/spdlog/include",
        "%{wks.location}/Blacksee/src",
        "%{wks.location}/Blacksee/vendor",
    }

    links
    {
        "Blacksee"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "BS_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "BS_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "BS_DIST"
        runtime "Release"
        optimize "on"