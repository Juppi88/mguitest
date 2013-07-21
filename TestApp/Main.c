/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		Main.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A test app for Mylly GUI (Win32).
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
#include "ConsoleTest.h"

#ifdef _WIN32
#include "MGUI/Renderer/GDIPlus/GDI.h"
//#include "MGUI/Renderer/OpenGL/OpenGL.h"
#else
#include "MGUI/Renderer/X11/X11.h"
#endif // _WIN32

bool			running		= true;
syswindow_t*	wnd			= NULL;

#ifdef _WIN32
static bool		active		= true;
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
	MGuiRenderer* renderer;

	wnd = create_system_window( 240, 160, 400, 450, _MTEXT("Mylly GUI Test"), false, message_hook );

	input_initialize( wnd );
	mgui_initialize( wnd, MGUI_USE_DRAW_EVENT );

#ifdef _WIN32
	renderer = mgui_gdiplus_initialize( wnd );
	//renderer = mgui_opengl_initialize( wnd );
#else
	renderer = mgui_x11_initialize( wnd );
#endif // _WIN32

	mgui_set_renderer( renderer );
	mgui_set_skin( NULL );

	// Run the console test
	console_test_initialize();
}

void guitest_execute( void )
{
	while ( running )
	{
		if ( !is_window_visible( wnd ) ) break;

		console_test_process();

		process_window_messages( wnd, message_hook );
		mgui_process();

		thread_sleep( 10 );
	}
}

void guitest_cleanup( void )
{
	console_test_shutdown();

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
