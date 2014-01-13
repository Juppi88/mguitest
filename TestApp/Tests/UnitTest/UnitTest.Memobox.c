/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.Memobox.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Unit tests for memobox.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

static MGuiMemobox* memobox = NULL;

void unit_test_create_memobox( void )
{
	extern MGuiCanvas* canvas_memobox;
	colour_t col;

	// Create a memobox and add a few test lines to it.
	memobox = mgui_create_memobox_ex( canvas_memobox, 350, 100, 300, 200, FLAG_TEXT_TAGS|FLAG_MEMOBOX_TOPBOTTOM, COL_WINDOW );
	mgui_set_text_colour_i( memobox, COL_TEXT );
	mgui_set_font( memobox, TITLEBAR_FONT, 11, FFLAG_NONE, CHARSET_ANSI );

	mgui_memobox_add_line_s( memobox, "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, "
		"quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum "
		"dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum." );

	mgui_memobox_add_line_s( memobox, "" );

	mgui_memobox_add_line_s( memobox, "Memoboxes are multiline textboxes specifically designed to work as chatboxes and other output windows. One of their default properties is automatic word wrapping." );
	mgui_memobox_add_line_s( memobox, "" );

	mgui_memobox_add_line_s( memobox, "Memoboxes support most common element and font flags, including [#ff00ff][#uline]format tags[#u]." );
	mgui_memobox_add_line_s( memobox, "" );

	mgui_memobox_add_line( memobox, "You can also output formatted text: Pi is %f, pointer to this memobox is 0x%X.", 3.1415926535f, (void*)memobox );
	mgui_memobox_add_line_s( memobox, "" );

	col.hex = RGBCOL(0,255,255);
	mgui_memobox_add_line_col_s( memobox, "Colour can also be set separately for each line.", &col );
}

void unit_test_destroy_memobox( void )
{
	mgui_element_destroy( memobox );
}
