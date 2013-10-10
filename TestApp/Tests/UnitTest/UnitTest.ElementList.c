/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.ElementList.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A window with a list of elements to test.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

static void unit_test_element_list_event( const MGuiEvent* event );

// Window for element tests
static MGuiWindow*		element_window		= NULL;
static MGuiListbox*		element_list		= NULL;

// Listbox items for each test
static MGuiListboxItem*	item_button			= NULL;
static MGuiListboxItem*	item_checkbox		= NULL;
static MGuiListboxItem*	item_editbox		= NULL;
static MGuiListboxItem*	item_label			= NULL;
static MGuiListboxItem*	item_listbox		= NULL;
static MGuiListboxItem*	item_memobox		= NULL;
static MGuiListboxItem*	item_progressbar	= NULL;
static MGuiListboxItem*	item_scrollbar		= NULL;
static MGuiListboxItem*	item_sprite			= NULL;
static MGuiListboxItem*	item_window			= NULL;

// Canvases for each test
MGuiCanvas*				canvas_button		= NULL;
MGuiCanvas*				canvas_checkbox		= NULL;
MGuiCanvas*				canvas_editbox		= NULL;
MGuiCanvas*				canvas_label		= NULL;
MGuiCanvas*				canvas_listbox		= NULL;
MGuiCanvas*				canvas_memobox		= NULL;
MGuiCanvas*				canvas_progressbar	= NULL;
MGuiCanvas*				canvas_scrollbar	= NULL;
MGuiCanvas*				canvas_sprite		= NULL;
MGuiCanvas*				canvas_window		= NULL;
MGuiCanvas*				current_test		= NULL;

extern MGuiCanvas* canvas;

void unit_test_create_element_list( void )
{
	// Create the window.
	element_window = mgui_create_window_ex( canvas, 10, 10, 150, 550, FLAG_NONE, COL_WINDOW, _MTEXT("Elements") );
	mgui_window_set_title_colour_i( element_window, COL_TITLEBAR );
	mgui_remove_flags( element_window, FLAG_WINDOW_CLOSEBTN|FLAG_WINDOW_RESIZABLE );

	// Create the listbox for elements...
	element_list = mgui_create_listbox_ex( element_window, 5, 5, 140, 515, FLAG_NONE, COL_TEXTBG, COL_LIST_SELECT );
	mgui_set_text_colour_i( element_list, COL_TEXT );
	mgui_set_event_handler( element_list, unit_test_element_list_event, NULL );

	// ...then add all the tests to it.
	item_button =		mgui_listbox_add_item( element_list, _MTEXT("Button") );
	item_checkbox =		mgui_listbox_add_item( element_list, _MTEXT("Checkbox") );
	item_editbox =		mgui_listbox_add_item( element_list, _MTEXT("Editbox") );
	item_label =		mgui_listbox_add_item( element_list, _MTEXT("Label") );
	item_listbox =		mgui_listbox_add_item( element_list, _MTEXT("Listbox") );
	item_memobox =		mgui_listbox_add_item( element_list, _MTEXT("Memobox") );
	item_progressbar =	mgui_listbox_add_item( element_list, _MTEXT("Progressbar") );
	item_scrollbar =	mgui_listbox_add_item( element_list, _MTEXT("Scrollbar") );
	item_sprite =		mgui_listbox_add_item( element_list, _MTEXT("Sprite") );
	item_window =		mgui_listbox_add_item( element_list, _MTEXT("Window") );

	// Create canvases for each unit test so we have an easy way to switch between tests.
	canvas_button =		mgui_create_canvas( NULL );
	canvas_checkbox =	mgui_create_canvas( NULL );
	canvas_editbox =	mgui_create_canvas( NULL );
	canvas_label =		mgui_create_canvas( NULL );
	canvas_listbox =	mgui_create_canvas( NULL );
	canvas_memobox =	mgui_create_canvas( NULL );
	canvas_progressbar = mgui_create_canvas( NULL );
	canvas_scrollbar =	mgui_create_canvas( NULL );
	canvas_sprite =		mgui_create_canvas( NULL );
	canvas_window =		mgui_create_canvas( NULL );

	mgui_remove_flags( canvas_button, FLAG_VISIBLE );
	mgui_remove_flags( canvas_checkbox, FLAG_VISIBLE );
	mgui_remove_flags( canvas_editbox, FLAG_VISIBLE );
	mgui_remove_flags( canvas_label, FLAG_VISIBLE );
	mgui_remove_flags( canvas_listbox, FLAG_VISIBLE );
	mgui_remove_flags( canvas_memobox, FLAG_VISIBLE );
	mgui_remove_flags( canvas_progressbar, FLAG_VISIBLE );
	mgui_remove_flags( canvas_scrollbar, FLAG_VISIBLE );
	mgui_remove_flags( canvas_sprite, FLAG_VISIBLE );
	mgui_remove_flags( canvas_window, FLAG_VISIBLE );
}

void unit_test_destroy_element_list( void )
{
	// Destroy everything. Technically we wouldn't have to do this,
	// because the library will free everything, but it's a good habit anyway.
	mgui_element_destroy( element_list );
	mgui_element_destroy( element_window );

	// Destroy unit test canvases.
	mgui_element_destroy( canvas_button );
	mgui_element_destroy( canvas_checkbox );
	mgui_element_destroy( canvas_editbox );
	mgui_element_destroy( canvas_label );
	mgui_element_destroy( canvas_listbox );
	mgui_element_destroy( canvas_memobox );
	mgui_element_destroy( canvas_progressbar );
	mgui_element_destroy( canvas_scrollbar );
	mgui_element_destroy( canvas_sprite );
	mgui_element_destroy( canvas_window );
}

static void unit_test_element_list_event( const MGuiEvent* event )
{
	MGuiListboxItem* item;

	if ( event->type != EVENT_LISTBOX_SELECT ) return;

	// Hide the currently selected test.
	if ( current_test != NULL )
	{
		mgui_remove_flags( current_test, FLAG_VISIBLE );
		current_test = NULL;
	}

	item = event->list.item;

	// Find out which test the user selected.
	if ( item == item_button )
		current_test = canvas_button;

	else if ( item == item_checkbox )
		current_test = canvas_checkbox;

	else if ( item == item_editbox )
		current_test = canvas_editbox;

	else if ( item == item_label )
		current_test = canvas_label;

	else if ( item == item_listbox )
		current_test = canvas_listbox;

	else if ( item == item_memobox )
		current_test = canvas_memobox;

	else if ( item == item_progressbar )
		current_test = canvas_progressbar;

	else if ( item == item_scrollbar )
		current_test = canvas_scrollbar;

	else if ( item == item_sprite )
		current_test = canvas_sprite;

	else if ( item == item_window )
		current_test = canvas_window;

	// Make the selected test visible.
	if ( current_test != NULL )
		mgui_add_flags( current_test, FLAG_VISIBLE );
}
