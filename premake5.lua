workspace "2DPlatformer"
	architecture "x64"
	
	configurations {
		"Debug",
		"Release"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
--IncludeDir["GLFW"] = "vendor/glfw/include"
--IncludeDir["GLAD"] = "vendor/glad/include"

-- Includes GLFW premake5.lua --
--include "vendor/glfw"
--include "vendor/glad"

project "2DPlatformer"
	location "2DPlatformer"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files {
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**.hpp"
	}
	
	includedirs {
		"%{prj.name}"
	}
	
	links {
		
	}
	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"