-- Mylly GUI test app (OpenGL)

project "GuiTest-OpenGL"
	kind "WindowedApp"
	language "C"
	files { "*.h", "*.c", "../../*", "../../Tests/*", "premake4.lua" }
	includedirs { ".", "../../", "../../../Libraries" }
	targetname "guitest-opengl"
	
	vpaths {
			["Tests"] = { "../../Tests/*" },
			[""] = { ".", "../../*" }
		}
	
	links {
		"Lib-MGUI",
		"Lib-Platform",
		"Lib-Math",
		"Lib-Platform",
		"Lib-Stringy",
		"Lib-Input",
		"Lib-Types"
	}
	
	location ( "../../../Projects/" .. os.get() .. "/" .. _ACTION )
	
	configuration "Debug"
		targetdir "../../../Builds/Debug"
	
	configuration "Release"
		targetdir "../../../Builds/Release"

	configuration "windows"
		flags { "WinMain" }
		targetextension ".exe"
		buildoptions { "/wd4201" } -- C4201: nameless struct/union
		linkoptions { "/NODEFAULTLIB:libci.lib" }
		links { "Lib-MGUI-Renderer-OpenGL", "opengl32", "glu32" }
