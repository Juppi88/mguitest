/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.Scrollbar.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Unit tests for scrollbar.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

static MGuiScrollbar* scrollbar1 = NULL;
static MGuiScrollbar* scrollbar2 = NULL;

static void unit_test_scrollbar_event( const MGuiEvent* event )
{
	extern MGuiMemobox* output_memo;

	switch ( event->type )
	{
	case EVENT_SCROLL:
		mgui_memobox_add_line( output_memo, "[EVENT_SCROLL] %s scrollbar movement from %.2f to %.2f",
							   event->scroll.element == scrollbar1 ? "Vertical" : "Horizontal",
							   event->scroll.position + event->scroll.change, event->scroll.position );
		break;

	default:
		break;
	}
}

void unit_test_create_scrollbar( void )
{
	extern MGuiCanvas* canvas_scrollbar;

	// Create a vertical scrollbar.
	scrollbar1 = mgui_create_scrollbar_ex( canvas_scrollbar, 350, 50, 16, 200, FLAG_NONE, COL_WINDOW );
	mgui_set_event_handler( scrollbar1, unit_test_scrollbar_event, NULL );

	// Create a horizontal scrollbar.
	scrollbar2 = mgui_create_scrollbar_ex( canvas_scrollbar, 375, 234, 200, 16, FLAG_SCROLLBAR_HORIZ, COL_WINDOW );
	mgui_set_event_handler( scrollbar2, unit_test_scrollbar_event, NULL );
}

void unit_test_destroy_scrollbar( void )
{
	mgui_element_destroy( scrollbar1 );
	mgui_element_destroy( scrollbar2 );
}
