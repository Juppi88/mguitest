-- Mylly GUI tester

project "GuiTest"
	kind "WindowedApp"
	language "C"
	files { "*.h", "*.c", "premake4.lua" }
	includedirs { ".", "../Libraries" }
	vpaths { [""] = { "../Test" } }
	targetname "guitest"
	links { "Lib-MGUI", "Lib-MGUI-Renderer-X11", "Lib-Platform", "Lib-Math",
			"Lib-Platform", "Lib-Stringy", "Lib-Input",  "X11", "pthread", "Lib-Types" }
	
	location ( "../Projects/" .. os.get() .. "/" .. _ACTION )
	
	configuration "Debug"
		targetdir "../Builds/Debug"
	
	configuration "Release"
		targetdir "../Builds/Release"
	
	-- Linux specific stuff
	configuration "linux"
		buildoptions { "-fms-extensions" } -- Unnamed struct/union fields within structs/unions
		targetextension ".bin"
	
	-- Windows specific stuff
	configuration "windows"
		flags { "WinMain" }
		targetextension ".exe"
		buildoptions { "/wd4201" } -- C4201: nameless struct/union
