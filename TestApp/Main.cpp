/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		Main.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A test app for Mylly GUI (Win32).
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "MGUI/Renderer/OpenGL/OpenGL.h"
#include "Platform/Thread.h"
#include "Platform/Window.h"
#include "Platform/Timer.h"
#include "Stringy/Stringy.h"
#include "Input/Input.h"
#include "Math/Colour.h"

static bool		running		= true;
static bool		active		= true;
static void*	wnd			= NULL;

MGuiWindow*		tr_window	= NULL;
MGuiWindow*		ps_window	= NULL;
MGuiLabel*		tr_label	= NULL;
MGuiLabel*		ps_label	= NULL;

static uint32	start_ticks	= 0;

#define COL_BACKGROUND	RGBCOL( 100, 100, 0 )
#define COL_WHITE		RGBCOL( 255, 255, 255 )

bool message_hook( void* data )
{
	MSG* msg;
	msg = (MSG*)data;

	switch ( msg->message )
	{
	case WM_ACTIVATE:
		if ( !HIWORD( msg->wParam ) ) active = true;
		else active = false;
		return true;

	case WM_PAINT:
		break;
	}

	// Relay the packet to the input hook library
	return input_process( data );
}

void CUIManager_TimeRemaining( void )
{
	tr_window = mgui_create_window_ex( NULL, -75, 190, 190, 50, FLAG_DISABLED, COL_BACKGROUND, NULL );
	mgui_remove_flags( tr_window, FLAG_WINDOW_CLOSEBTN|FLAG_WINDOW_TITLEBAR|FLAG_BORDER|FLAG_SHADOW );

	tr_label = mgui_create_label_ex( tr_window, 0, 0, 190, 50, FLAG_NONE, COL_WHITE, "--:--" );
	mgui_set_font_flags( tr_label, FFLAG_BOLD );
	mgui_set_font_size( tr_label, 25 );
	mgui_label_make_text_fit( tr_label );

	mgui_set_text_colour_i( tr_label, COL_WHITE );
}

void CUIManager_PositionScroller( void )
{
	ps_window = mgui_create_window_ex( NULL, 40, 90, 175, 95, FLAG_DISABLED, COL_BACKGROUND, NULL );
	mgui_remove_flags( ps_window, FLAG_WINDOW_CLOSEBTN|FLAG_WINDOW_TITLEBAR|FLAG_BORDER|FLAG_SHADOW );

	ps_label = mgui_create_label_ex( ps_window, 0, 0, 175, 95, FLAG_NONE, COL_WHITE, "POS" );
	mgui_set_font_size( ps_label, 12 );
	mgui_set_text_colour_i( ps_label, COL_WHITE );

	mgui_set_font_flags( ps_label, FFLAG_ITALIC );
}

void guitest_init( void )
{
	MGuiRenderer* renderer;

	wnd = create_system_window( 240, 160, 420, 440, _MTEXT("Mylly GUI Test"), true );

	input_initialize( wnd );
	mgui_initialize( wnd );

	renderer = mgui_opengl_initialize( wnd );

	mgui_set_renderer( renderer );
	mgui_set_skin( NULL );

	CUIManager_TimeRemaining();
	CUIManager_PositionScroller();
}

void guitest_execute( void )
{
	uint32 ticks, sec, csec;

	while ( running )
	{
		if ( !is_window_visible( wnd ) ) break;

		process_window_messages( NULL, message_hook );
		mgui_process();

		thread_sleep( 8 );

		ticks = get_tick_count() - start_ticks;
		sec = ticks / 1000;
		csec = ( ticks - 1000*sec ) / 10;

		mgui_set_text( tr_label, "%02u:%02u", sec, csec );
	}
}

void guitest_cleanup( void )
{
	mgui_shutdown();
	input_shutdown();
	destroy_system_window( wnd );
}

#ifdef _WIN32

int WINAPI WinMain(	HINSTANCE instance, HINSTANCE prev_instance, char* args, int cmd_show )
{
	UNREFERENCED_PARAM( instance );
	UNREFERENCED_PARAM( prev_instance );
	UNREFERENCED_PARAM( args );
	UNREFERENCED_PARAM( cmd_show );

	start_ticks = get_tick_count();

	guitest_init();
	guitest_execute();
	guitest_cleanup();
	
	return 0;
}

#endif /* _WIN32 */
