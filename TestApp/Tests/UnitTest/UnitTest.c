/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Proper unit test for MGUI elements.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "UnitTest.h"
#include "MGUI/MGUI.h"
#include "Input/Input.h"
#include "Platform/Window.h"

MGuiCanvas* canvas = NULL;

static bool keybind_shutdown( uint32 key, void* data )
{
	extern bool running;

	UNREFERENCED_PARAM( key );
	UNREFERENCED_PARAM( data );

	running = false;
	return true;
}

void unit_test_initialize( void )
{
	// Create the main canvas (this is really optional, we just want the cool background colour)
	canvas = mgui_create_canvas( NULL );
	mgui_add_flags( canvas, FLAG_BACKGROUND );
	mgui_set_colour_i( canvas, RGBCOL(125,175,175) );

	// Initialize the element list and output window.
	unit_test_create_element_list();
	unit_test_create_output_window();

	// Add a quick keybind to shut down the test app.
	input_add_key_down_bind( MKEY_F10, keybind_shutdown, NULL );

	// Initialize all tests.
	unit_test_create_button();
	unit_test_create_checkbox();
	unit_test_create_editbox();
	unit_test_create_label();
	unit_test_create_listbox();
	unit_test_create_memobox();
	unit_test_create_progressbar();
	unit_test_create_scrollbar();
	unit_test_create_sprite();
	unit_test_create_window();
}

void unit_test_process( void )
{
	// Nothing to do here.
}

void unit_test_shutdown( void )
{
	// Destroy all tests.
	unit_test_destroy_button();
	unit_test_destroy_checkbox();
	unit_test_destroy_editbox();
	unit_test_destroy_label();
	unit_test_destroy_listbox();
	unit_test_destroy_memobox();
	unit_test_destroy_progressbar();
	unit_test_destroy_scrollbar();
	unit_test_destroy_sprite();
	unit_test_destroy_window();

	unit_test_destroy_element_list();
	unit_test_destroy_output_window();

	mgui_element_destroy( canvas );
}
