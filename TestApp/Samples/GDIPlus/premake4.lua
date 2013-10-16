-- Mylly GUI test app (GDI+)

project "GuiTest-GDIPlus"
	kind "WindowedApp"
	language "C"
	--files { "*.h", "*.c", "../../*", "../../Tests/UnitTest/*", "premake4.lua" }
	files { "*.h", "*.c", "../../*", "../../Tests/ConsoleTest/*", "premake4.lua" }
	includedirs { ".", "../../", "../../../Libraries" }
	targetname "guitest-gdiplus"
	
	vpaths {
			--["Tests"] = { "../../Tests/UnitTest/*" },
			["Tests"] = { "../../Tests/ConsoleTest/*" },
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
		defines { "MYLLY_WINDOWS_EXTRAS" }
		buildoptions { "/wd4201" } -- C4201: nameless struct/union
		linkoptions { "/NODEFAULTLIB:libci.lib" }
		links { "Lib-MGUI-Renderer-GDIPlus", "gdiplus" }
