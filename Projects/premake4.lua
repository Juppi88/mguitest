-- Mylly GUI test

solution ( "Mylly " .. string.upper( _ACTION ) )
	configurations { "Debug", "Release" }
	flags { "ExtraWarnings" }
	targetdir ( "../Builds/Lib/" .. os.get() .. "/" .. _ACTION )
	libdirs { "../Builds/Lib/" }
	includedirs { "../Libraries", "../Libraries/Types" }
	
	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize", "FloatFast" }
	
	configuration "Debug"
		defines { "DEBUG", "_DEBUG" }
		flags { "Symbols" }
		
	configuration "windows"
		defines { "_CRT_SECURE_NO_WARNINGS" } -- Ignore visual studio's bs security warnings
	
	-- Third party and in-house libraries
	include "../Libraries/Input"
	include "../Libraries/Math"
	include "../Libraries/Platform"
	include "../Libraries/Stringy"
	include "../Libraries/Types"
	include "../Libraries/MGUI"

	if _ACTION == "vs2005" or _ACTION == "vs2008" or _ACTION == "vs2010" or _ACTION == "vs2012" then
		-- Include Wndows renderers
		include "../Libraries/MGUI/Renderer/DirectX8"
		include "../Libraries/MGUI/Renderer/DirectX9"
		include "../Libraries/MGUI/Renderer/GDIPlus"
		include "../Libraries/MGUI/Renderer/OpenGL"
		
		-- Include Windows samples
		include "../TestApp/Samples/DirectX8"
		include "../TestApp/Samples/DirectX9"
		include "../TestApp/Samples/GDIPlus"
		include "../TestApp/Samples/OpenGL"
	else
		-- Include Linux renderers
		include "../Libraries/MGUI/Renderer/Xlib"
		
		-- Include Linux samples
		include "../TestApp/Samples/Xlib"
	end
