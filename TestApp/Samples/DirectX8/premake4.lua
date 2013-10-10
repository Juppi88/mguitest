-- Mylly GUI test app (DirectX 8)

project "GuiTest-DirectX8"
	kind "WindowedApp"
	language "C"
	files { "*.h", "*.c", "../../*", "../../Tests/UnitTest/*", "premake4.lua" }
	includedirs { ".", "../../", "../../../Libraries" }
	targetname "guitest-dx8"
	
	vpaths {
			["Tests"] = { "../../Tests/UnitTest/*" },
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
		links { "Lib-MGUI-Renderer-DirectX8", "d3d8", "d3dx8" }
