/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		Xlib.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A test app for Mylly GUI (Xlib).
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/Renderer/Xlib/Xlib.h"
#include "Platform/Window.h"

const char_t* renderer_name = _MTEXT( "Xlib" );
const char_t* sprite_path = _MTEXT( "" );

void test_initialize( void )
{
	MGuiRenderer* renderer;
	extern syswindow_t* wnd;

	renderer = mgui_xlib_initialize( wnd );
	mgui_set_renderer( renderer );
}

void test_shutdown( void )
{
	mgui_xlib_shutdown();
}

void test_begin_frame( void )
{
	mgui_xlib_begin_scene();
}

void test_end_frame( void )
{
	mgui_xlib_end_scene();
}
