/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.Button.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Unit tests for button.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

static MGuiButton* button1 = NULL;
static MGuiButton* button2 = NULL;
static MGuiButton* button3 = NULL;
static MGuiButton* button4 = NULL;

static void unit_test_button_event( const MGuiEvent* event )
{
	extern MGuiMemobox* output_memo;

	switch ( event->type )
	{
	case EVENT_CLICK:
		mgui_memobox_add_line( output_memo, "[EVENT_CLICK] Button '%s' pressed", mgui_get_text( event->mouse.element ) );
		break;

	case EVENT_RELEASE:
		mgui_memobox_add_line( output_memo, "[EVENT_RELEASE] Button '%s' released", mgui_get_text( event->mouse.element ) );
		break;

	default:
		break;
	}
}

void unit_test_create_button( void )
{
	// Canvas for this test
	extern MGuiCanvas* canvas_button;

	// Create a button with text 'A big button'
	button1 = mgui_create_button_ex( canvas_button, 325, 100, 150, 100, FLAG_NONE, RGBCOL(100,100,100), "A big button"  );
	mgui_set_text_colour_i( button1, COL_TEXT );
	mgui_set_font_flags( button1, FFLAG_BOLD );
	mgui_set_event_handler( button1, unit_test_button_event, NULL );

	// Create another button which supports text tags and uses an outlined font
	button2 = mgui_create_button_ex( canvas_button, 500, 100, 100, 25, FLAG_TEXT_TAGS, RGBCOL(100,200,255), "[#ff0000]C[#00ff00]O[#0000ff]L[#ff00ff]O[#ffff00]U[#00ffff]R[#ffffff]S[#d]" );
	mgui_set_text_colour_i( button2, COL_TEXT );
	mgui_set_font( button2, WINDOW_FONT, 11, FFLAG_BOLD|FFLAG_OUTLINE, CHARSET_ANSI );
	mgui_set_event_handler( button2, unit_test_button_event, NULL );

	// Create a normal button
	button3 = mgui_create_button_ex( canvas_button, 500, 137, 100, 25, FLAG_NONE, COL_WINDOW, "Enabled button"  );
	mgui_set_text_colour_i( button3, COL_TEXT );
	mgui_set_event_handler( button3, unit_test_button_event, NULL );

	// Create a disabled button
	button4 = mgui_create_button_ex( canvas_button, 500, 175, 100, 25, FLAG_DISABLED, COL_WINDOW, "Disabled button"  );
	mgui_set_text_colour_i( button4, COL_TEXT );
	mgui_set_event_handler( button4, unit_test_button_event, NULL );
}

void unit_test_destroy_button( void )
{
	mgui_element_destroy( button1 );
	mgui_element_destroy( button2 );
	mgui_element_destroy( button3 );
	mgui_element_destroy( button4 );
}
