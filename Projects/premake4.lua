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
	include "../Libraries/MGUI/Renderer/OpenGL"
