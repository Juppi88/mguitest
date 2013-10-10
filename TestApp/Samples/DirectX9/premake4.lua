-- Mylly GUI test app (DirectX 9)

project "GuiTest-DirectX9"
	kind "WindowedApp"
	language "C"
	files { "*.h", "*.c", "../../*", "../../Tests/UnitTest/*", "premake4.lua" }
	includedirs { ".", "../../", "../../../Libraries" }
	targetname "guitest-dx9"
	
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
		links { "Lib-MGUI-Renderer-DirectX9", "d3d9", "d3dx9" }
