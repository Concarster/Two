project "SOIL2"
    kind "StaticLib"
    language "C++"
	cppdialect "C++17"
    staticruntime "on"
    
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bint/" .. outputdir .. "/%{prj.name}")

	files {

        "srcs/etc1_utils.c",
        "srcs/image_DXT.c",
        "srcs/image_helper.c",
        "srcs/SOIL2.c"
    }
   
    includedirs {
         "incs"
    }

	filter "system:windows"
        systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
        symbols "on"

    filter "configurations:Release"
		runtime "Release"
        optimize "on"