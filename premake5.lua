workspace "Two"

     architecture "x86"
     architecture "x64"

     startproject "Game"

     filter "system:windows"
		disablewarnings { "4996", "4251" }
		--disablewarnings { "4996", "4251", "26451" }
                  
platforms {       -- Dropdown Solution Confg Platforms section in VS
    
     "Win32",
     "x64"
} 
    
configurations {   -- Dropdown Solution Configurations
     "Debug",
     "Release"  
}

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}

IncludeDir["GLFW"]     = "Mods/GLFW/include"
IncludeDir["Glad"]     = "Mods/Glad/include"
IncludeDir["ImGui"]    = "Mods/imgui"
IncludeDir["glm"]      = "Mods/glm"
IncludeDir["SOIL2"]    = "Mods/SOIL2/incs"
IncludeDir["GSL"]      = "Mods/GSL/include"
IncludeDir["spdlog"]   = "Mods/spdlog/include"


group "Dependencies"

include "Mods/GLFW"
include "Mods/Glad"
include "Mods/imgui"
include "Mods/SOIL2"

 group ""

--[[ GLOBAL Precompiled Header   
pchheader "PCH.h"
pchsource "Engine/Engine/PCH.cpp"
]]


project "Engine" 
    location "Engine"
    kind "StaticLib"
    language "C++"
	cppdialect "C++17"
	staticruntime "on"

    pchheader "PCH.h"
    pchsource "Engine/Engine/PCH.cpp"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("bint/" .. outputdir .. "/%{prj.name}")


    files {

        "%{prj.name}/Engine/**.h",
        "%{prj.name}/Engine/**.cpp",

    }

	defines {

	     --"_CRT_SECURE_NO_WARNINGS"
	}

    includedirs {
        --"%{prj.name}/",
		"%{prj.name}/Engine",
     
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.SOIL2}",
        "%{IncludeDir.GSL}",
        "%{IncludeDir.boost}",
     
        "$(BOOST)"
    }

    libdirs { 
        "$(BOOST)/stage/lib" 
    }

    links { 
        "GLFW",
		"Glad",
	    "ImGui",
        "SOIL2";
		"opengl32.lib"
	}

    filter"system:windows"
        systemversion "latest"

        defines {
             "ONE_ENGINE",
             "ONE_WINDOW",
             "GLFW_INCLUDE_NONE"
        }

        filter "configurations:Debug"
        defines "ONE_DEBUG"
		runtime "Debug"
        symbols "on"

        filter "configurations:Release"
        defines "ONE_RELEASE"
		runtime "Release"
        optimize "on"


-----------------------------------
-----     PROJECT # 1 BooErGame     -----
-----------------------------------

project "Game" 
    location "Game"
    kind "ConsoleApp"
    language "C++"
	cppdialect "C++17"
	staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bint/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/Game/**.h",
        "%{prj.name}/Game/**.cpp",
    }

    includedirs {

        "Engine/",
        "%{prj.name}/Game",
        
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.SOIL2}",
        "%{IncludeDir.GSL}",
     
        "$(BOOST)"
    }

    libdirs { 
        "$(BOOST)/stage/lib" 
    }
  
    links {
        "Engine",
		"opengl32.lib"
    }

    filter"system:windows"
        systemversion "latest"

    defines {

         "ONE_ENGINE",
         "ONE_WINDOW"
    }


    filter "configurations:Debug"
        defines "ONE_DEBUG"
		runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ONE_RELEASE"
		runtime "Release"
        optimize "on"
