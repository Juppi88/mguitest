/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.DebugOutput.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Debug output window for unit test.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

MGuiWindow*		output_window	= NULL;
MGuiMemobox*	output_memo		= NULL;

void unit_test_create_output_window( void )
{
	extern MGuiCanvas* canvas;

	// Create the event window.
	output_window = mgui_create_window_ex( canvas, 170, 380, 610, 180, FLAG_NONE, COL_WINDOW, "Event Output" );
	mgui_window_set_title_colour_i( output_window, COL_TITLEBAR );
	mgui_remove_flags( output_window, FLAG_WINDOW_CLOSEBTN|FLAG_WINDOW_RESIZABLE );

	// Create a memobox on which to show the events.
	output_memo = mgui_create_memobox_ex( output_window, 5, 5, 600, 145, FLAG_MEMOBOX_TOPBOTTOM, COL_TEXTBG );
	mgui_set_font( output_memo, CONSOLE_FONT, 10, FFLAG_NONE, CHARSET_ANSI );
	mgui_set_text_colour_i( output_memo, COL_TEXT );
}

void unit_test_destroy_output_window( void )
{
	mgui_element_destroy( output_memo );
	mgui_element_destroy( output_window );
}
