/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.Listbox.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Unit tests for listbox.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

static MGuiListbox* listbox = NULL;

static void unit_test_listbox_event( const MGuiEvent* event )
{
	extern MGuiMemobox* output_memo;

	switch ( event->type )
	{
	case EVENT_LISTBOX_SELECT:
		mgui_memobox_add_line( output_memo, "[EVENT_LISTBOX_SELECT] Selected item: %s", mgui_listbox_get_item_text( event->list.item ) );
		break;
	}
}

void unit_test_create_listbox( void )
{
	extern MGuiCanvas* canvas_listbox;

	// Create a test listbox.
	listbox = mgui_create_listbox_ex( canvas_listbox, 425, 75, 100, 200, FLAG_LISTBOX_MULTISELECT|FLAG_TEXT_TAGS, COL_WINDOW, COL_LIST_SELECT );
	mgui_set_text_colour_i( listbox, COL_TEXT );
	mgui_set_event_handler( listbox, unit_test_listbox_event, NULL );

	// Add some tets items.
	mgui_listbox_add_item( listbox, _MTEXT("Orange") );
	mgui_listbox_add_item( listbox, _MTEXT("Apple") );
	mgui_listbox_add_item( listbox, _MTEXT("Banana") );
	mgui_listbox_add_item( listbox, _MTEXT("Bread") );
	mgui_listbox_add_item( listbox, _MTEXT("Pie") );
	mgui_listbox_add_item( listbox, _MTEXT("Cake") );
	mgui_listbox_add_item( listbox, _MTEXT("Butter") );
	mgui_listbox_add_item( listbox, _MTEXT("Ice cream") );
	mgui_listbox_add_item( listbox, _MTEXT("Milk") );
	mgui_listbox_add_item( listbox, _MTEXT("Running") );
	mgui_listbox_add_item( listbox, _MTEXT("Out") );
	mgui_listbox_add_item( listbox, _MTEXT("Of") );
	mgui_listbox_add_item( listbox, _MTEXT("Ideas") );
	mgui_listbox_add_item( listbox, "[#ff0000]C[#00ff00]o[#0000ff]l[#ff00ff]o[#ffff00]u[#00ffff]r[#ffffff]s[#d]" );
}

void unit_test_destroy_listbox( void )
{
	// This will destroy all items automatically.
	mgui_element_destroy( listbox );
}
