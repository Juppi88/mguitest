-- Mylly GUI test app (Xlib)

project "GuiTest-Xlib"
	kind "WindowedApp"
	language "C"
	files { "*.h", "*.c", "../../*", "../../Tests/UnitTest/*", "premake4.lua" }
	includedirs { ".", "../../", "../../../Libraries" }
	targetname "guitest-xlib"
	
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

	configuration "linux"
		targetextension ".bin"
		buildoptions { "-fms-extensions" } -- Unnamed struct/union fields within structs/unions
		links { "Lib-MGUI-Renderer-Xlib", "X11", "m", "pthread" }
