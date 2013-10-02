/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		GDIPlus.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A test app for Mylly GUI (GDI+).
 *
 *				(c) Tuomo Jauhiainen 2012-13
 *
 **********************************************************************/

#include "MGUI/Renderer/GDIPlus/WinGDIPlus.h"
#include "Platform/Window.h"
#include <stdio.h>

void test_initialize( void )
{
	FILE* skin;
	MGuiRenderer* renderer;
	extern syswindow_t* wnd;

	renderer = mgui_gdiplus_initialize( wnd );
	mgui_set_renderer( renderer );

	// If a test skin file exists, load it.
	skin = fopen( "./mguiskin.png", "r" );
	if ( skin != NULL )
	{
		fclose( skin );
		mgui_set_skin( "./mguiskin.png" );
	}
}

void test_shutdown( void )
{
	mgui_gdiplus_shutdown();
}

void test_begin_frame( void )
{
	mgui_gdiplus_begin_scene();
}

void test_end_frame( void )
{
	mgui_gdiplus_end_scene();
}
