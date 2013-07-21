-- Mylly GUI tester

project "GuiTest"
	kind "WindowedApp"
	language "C"
	files { "*.h", "*.c", "premake4.lua" }
	includedirs { ".", "../Libraries" }
	vpaths { [""] = { "../Test" } }
	targetname "guitest"
	links { "Lib-MGUI", "Lib-Platform", "Lib-Math", "Lib-Platform", "Lib-Stringy", "Lib-Input", "Lib-Types" }
	
	location ( "../Projects/" .. os.get() .. "/" .. _ACTION )
	
	configuration "Debug"
		targetdir "../Builds/Debug"
	
	configuration "Release"
		targetdir "../Builds/Release"
	
	-- Linux specific stuff
	configuration "linux"
		buildoptions { "-fms-extensions" } -- Unnamed struct/union fields within structs/unions
		targetextension ".bin"
		links { "Lib-MGUI-Renderer-X11", "X11", "pthread" }
	
	-- Windows specific stuff
	configuration "windows"
		flags { "WinMain" }
		targetextension ".exe"
		buildoptions { "/wd4201" } -- C4201: nameless struct/union
		--links { "Lib-MGUI-Renderer-OpenGL", "opengl32", "glu32" } -- Enable if you want to use OpenGL
		links { "Lib-MGUI-Renderer-GDIPlus", "gdiplus" } -- Enable if you want to use GDI+
