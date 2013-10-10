/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.Editbox.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Unit tests for editbox.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

static MGuiEditbox* editbox1 = NULL;
static MGuiEditbox* editbox2 = NULL;
static MGuiEditbox* editbox3 = NULL;
static MGuiEditbox* editbox4 = NULL;

static void unit_test_editbox_event( const MGuiEvent* event )
{
	extern MGuiMemobox* output_memo;
	MGuiEditbox* editbox = event->any.element;

	switch ( event->type )
	{
	case EVENT_INPUT_RETURN:
		if ( mgui_get_text_len( editbox ) > 0 )
		{
			mgui_memobox_add_line( output_memo, "[EVENT_INPUT_RETURN] Text from editbox '%u': %s", (uint32)event->any.data, mgui_get_text( editbox ) );
			mgui_set_text_s( editbox, "" );
		}
		break;

	default:
		break;
	}
}

void unit_test_create_editbox( void )
{
	extern MGuiCanvas* canvas_editbox;

	// Create a normal editbox.
	editbox1 = mgui_create_editbox_ex( canvas_editbox, 375, 100, 225, 22, FLAG_NONE, COL_WINDOW, "A normal editbox" );
	mgui_set_text_colour_i( editbox1, COL_TEXT );
	mgui_set_font( editbox1, CONSOLE_FONT, 12, FFLAG_NONE, CHARSET_ANSI );
	mgui_set_event_handler( editbox1, unit_test_editbox_event, (void*)1 );

	// Create a normal editbox with different colours.
	editbox2 = mgui_create_editbox_ex( canvas_editbox, 375, 140, 225, 22, FLAG_NONE, RGBCOL(100,200,230), "Hello, Vice City" );
	mgui_set_text_colour_i( editbox2, RGBCOL(240,40,240) );
	mgui_set_font( editbox2, CONSOLE_FONT, 12, FFLAG_NONE, CHARSET_ANSI );
	mgui_set_event_handler( editbox2, unit_test_editbox_event, (void*)2 );

	// Create an editbox that masks user input.
	editbox3 = mgui_create_editbox_ex( canvas_editbox, 375, 180, 225, 22, FLAG_EDITBOX_MASKINPUT, COL_WINDOW, "A masked editbox" );
	mgui_set_text_colour_i( editbox3, COL_TEXT );
	mgui_set_font( editbox3, CONSOLE_FONT, 12, FFLAG_NONE, CHARSET_ANSI );
	mgui_set_event_handler( editbox3, unit_test_editbox_event, (void*)3 );

	// Create a disabled editbox.
	editbox4 = mgui_create_editbox_ex( canvas_editbox, 375, 220, 225, 22, FLAG_DISABLED, COL_WINDOW, "A disabled editbox" );
	mgui_set_text_colour_i( editbox4, COL_TEXT );
	mgui_set_font( editbox4, CONSOLE_FONT, 12, FFLAG_NONE, CHARSET_ANSI );
	mgui_set_event_handler( editbox4, unit_test_editbox_event, (void*)4 );
}

void unit_test_destroy_editbox( void )
{
	mgui_element_destroy( editbox1 );
	mgui_element_destroy( editbox2 );
	mgui_element_destroy( editbox3 );
}
