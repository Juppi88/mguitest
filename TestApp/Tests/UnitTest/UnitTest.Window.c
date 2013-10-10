/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.Window.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Unit tests for window.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

static MGuiWindow* window = NULL;

static void unit_test_window_event( const MGuiEvent* event )
{
	extern MGuiMemobox* output_memo;
	vectorscreen_t drag_offset;

	switch ( event->type )
	{
	case EVENT_WINDOW_CLOSE:
		mgui_memobox_add_line_s( output_memo, "[EVENT_WINDOW_CLOSE] Window closed." );
		break;

	case EVENT_DRAG:
		mgui_window_get_drag_offset( window, &drag_offset );
		mgui_memobox_add_line( output_memo, "[EVENT_DRAG] Window moved to (%d,%d).", event->mouse.cursor_x - drag_offset.x, event->mouse.cursor_y - drag_offset.y );
		break;

	case EVENT_WINDOW_RESIZE:
		mgui_memobox_add_line( output_memo, "[EVENT_WINDOW_RESIZE] Window resized to (%u,%u)", event->resize.width, event->resize.height );
		break;

	default:
		break;
	}
}

void unit_test_create_window( void )
{
	extern MGuiCanvas* canvas_window;

	// Create a closeable and scrollable window.
	window = mgui_create_window_ex( canvas_window, 325, 50, 300, 200, FLAG_NONE, COL_WINDOW, _MTEXT("MGuiWindow") );

	mgui_set_font_flags( window, FFLAG_BOLD );
	mgui_set_text_colour_i( window, COL_TEXT );
	mgui_window_set_title_colour_i( window, COL_TITLEBAR );
	mgui_set_event_handler( window, unit_test_window_event, NULL );
}

void unit_test_destroy_window( void )
{
	mgui_element_destroy( window );
}
