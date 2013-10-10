/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		OpenGL.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A test app for Mylly GUI (OpenGL).
 *
 *				(c) Tuomo Jauhiainen 2012-13
 *
 **********************************************************************/

#include "MGUI/Renderer/OpenGL/OpenGL.h"
#include "Platform/Window.h"
#include <stdio.h>

const char_t* renderer_name = _MTEXT( "OpenGL" );
const char_t* sprite_path = _MTEXT( "sprite.bmp" );

void test_initialize( void )
{
	FILE* skin;
	MGuiRenderer* renderer;
	extern syswindow_t* wnd;

	renderer = mgui_opengl_initialize( wnd );
	mgui_set_renderer( renderer );

	// If a test skin file exists, load it.
	// Note: The reference OpenGL renderer only supports 32bit bitmaps!
	skin = fopen( "./mguiskin.bmp", "r" );
	if ( skin != NULL )
	{
		fclose( skin );
		mgui_set_skin( "./mguiskin.bmp" );
	}
}

void test_shutdown( void )
{
	mgui_opengl_shutdown();
}

void test_begin_frame( void )
{
	mgui_opengl_begin_scene();
}

void test_end_frame( void )
{
	mgui_opengl_end_scene();
}
