workspace "Blacksee"
    architecture "x86_64"
    startproject "Sandbox"

    IncludeDir = {}
    IncludeDir["GLFW"] = "%{wks.location}/Blacksee/vendor/GLFW/include"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    flags
    {
        "MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
    include "Blacksee/vendor/GLFW"
group ""

group "Core"
    include "Blacksee"
group ""

group "Tools"

group ""

group "Misc"
    include "Sandbox"
group ""