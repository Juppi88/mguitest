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
	
	-- Test application
	include "../TestApp"
	
	-- Third party and in-house libraries
	include "../Libraries/Input"
	include "../Libraries/Math"
	include "../Libraries/Platform"
	include "../Libraries/Stringy"
	include "../Libraries/Types"
	include "../Libraries/MGUI"

	if _ACTION == "vs2005" or _ACTION == "vs2008" or _ACTION == "vs2010" or _ACTION == "vs2012" then
		include "../Libraries/MGUI/Renderer/OpenGL"
		include "../Libraries/MGUI/Renderer/DirectX9"
		include "../Libraries/MGUI/Renderer/GDIPlus"
	else
		include "../Libraries/MGUI/Renderer/X11"
	end
