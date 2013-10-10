/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.Checkbox.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Unit tests for checkbox.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

static MGuiCheckbox* checkbox1 = NULL;
static MGuiCheckbox* checkbox2 = NULL;
static MGuiCheckbox* checkbox3 = NULL;

static void unit_test_checkbox_event( const MGuiEvent* event )
{
	extern MGuiMemobox* output_memo;
	MGuiCheckbox* checkbox = event->any.element;

	switch ( event->type )
	{
	case EVENT_CHECKBOX_TOGGLE:
		if ( mgui_get_flags( checkbox ) & FLAG_CHECKBOX_CHECKED )
		{
			// This checkbox was just selected.
			mgui_memobox_add_line( output_memo, "[EVENT_CHECKBOX_TOGGLE] Checkbox '%u' selected", (uint32)event->any.data );
		}
		else
		{
			// This checkbox was just deselected.
			mgui_memobox_add_line( output_memo, "[EVENT_CHECKBOX_TOGGLE] Checkbox '%u' deselected", (uint32)event->any.data );
		}
		break;

	default:
		break;
	}
}

void unit_test_create_checkbox( void )
{
	extern MGuiCanvas* canvas_checkbox;

	// Create a selected checkbox.
	checkbox1 = mgui_create_checkbox_ex( canvas_checkbox, 475, 50, FLAG_CHECKBOX_CHECKED, COL_TEXT );
	mgui_set_event_handler( checkbox1, unit_test_checkbox_event, (void*)1 );

	// Create a deselected checkbox.
	checkbox2 = mgui_create_checkbox_ex( canvas_checkbox, 475, 100, FLAG_NONE, COL_TEXT );
	mgui_set_event_handler( checkbox2, unit_test_checkbox_event, (void*)2 );

	// Create an inactive checkbox.
	checkbox3 = mgui_create_checkbox_ex( canvas_checkbox, 475, 150, FLAG_DISABLED|FLAG_CHECKBOX_CHECKED, COL_TEXT );
	mgui_set_event_handler( checkbox3, unit_test_checkbox_event, (void*)3 );
}

void unit_test_destroy_checkbox( void )
{
	mgui_element_destroy( checkbox1 );
	mgui_element_destroy( checkbox2 );
	mgui_element_destroy( checkbox3 );
}
