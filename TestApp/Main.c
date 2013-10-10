/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		Main.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A test app for Mylly GUI.
 *
 *				(c) Tuomo Jauhiainen 2012-13
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "Platform/Thread.h"
#include "Platform/Window.h"
#include "Platform/Timer.h"
#include "Stringy/Stringy.h"
#include "Input/Input.h"
#include "Math/Colour.h"
#include "Tests/UnitTest/UnitTest.h"
#include "Main.h"

bool running = true;
syswindow_t* wnd = NULL;

#ifdef _WIN32
static bool active = true;
#endif

#ifdef _WIN32

bool message_hook( void* data )
{
	MSG* msg;
	msg = (MSG*)data;

	switch ( msg->message )
	{
	case WM_ACTIVATE:
		if ( !HIWORD( msg->wParam ) ) active = true;
		else active = false;
		break;

	case WM_PAINT:
		mgui_force_redraw();
		break;
	}

	// Relay the packet to the input hook library
	return input_process( data );
}

#else

bool message_hook( void* data )
{
	XEvent* event = (XEvent*)data;

	switch ( event->type )
	{
	case Expose:
		mgui_force_redraw();
		break;

	case SelectionNotify:
	case SelectionRequest:
		clipboard_handle_event( wnd, data );
		break;
	}

	return input_process( data );
}

#endif /* _WIN32 */

void guitest_init( void )
{
	char_t title[64];
	extern char_t* renderer_name;

	sprintf( title, "Mylly GUI %s Test", renderer_name );

	wnd = create_system_window( 240, 160, 800, 600, title, true, message_hook );

	input_initialize( wnd );
	mgui_initialize( wnd, MGUI_USE_DRAW_EVENT ); // Only update the window when there's something to update.

	// Create a test renderer.
	test_initialize();
		
	// Run the actual test code
	unit_test_initialize();

	set_mouse_cursor( wnd, CURSOR_ARROW );
}

void guitest_execute( void )
{
	while ( running )
	{
		if ( !is_window_visible( wnd ) ) break;

		unit_test_process();

		process_window_messages( wnd, message_hook );

		// Tell the renderer to begin a new scene.
		test_begin_frame();

		// Let MGUI do pre-processing (re-draw render caches) and processing.
		mgui_pre_process();
		mgui_process();

		// End the scene.
		test_end_frame();

		thread_sleep( 15 );
	}
}

void guitest_cleanup( void )
{
	unit_test_shutdown();

	mgui_shutdown();
	input_shutdown();

	// Shutdown the test renderer and do cleanup.
	test_shutdown();
	
	destroy_system_window( wnd );
}

#ifdef _WIN32

int WINAPI WinMain(	HINSTANCE instance, HINSTANCE prev_instance, char* args, int cmd_show )
{
	UNREFERENCED_PARAM( instance );
	UNREFERENCED_PARAM( prev_instance );
	UNREFERENCED_PARAM( args );
	UNREFERENCED_PARAM( cmd_show );

	guitest_init();
	guitest_execute();
	guitest_cleanup();

	return 0;
}

#else

int main( void )
{
	guitest_init();
	guitest_execute();
	guitest_cleanup();

	return 0;
}

#endif /* _WIN32 */
