/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.Progressbar.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Unit tests for progressbar.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

static MGuiProgressbar* progbar1 = NULL;
static MGuiProgressbar* progbar2 = NULL;
static MGuiProgressbar* progbar3 = NULL;

void unit_test_create_progressbar( void )
{
	extern MGuiCanvas* canvas_progressbar;

	// Create a 10% progressbar.
	progbar1 = mgui_create_progressbar_ex( canvas_progressbar, 400, 100, 200, 20, FLAG_NONE, RGBCOL(255,0,0), RGBCOL(0,255,0), 100.0f );
	mgui_progressbar_set_value( progbar1, 10.0f );

	// Create a 50% progressbar.
	progbar2 = mgui_create_progressbar_ex( canvas_progressbar, 400, 150, 200, 20, FLAG_NONE, RGBCOL(255,0,0), RGBCOL(0,255,0), 100.0f );
	mgui_progressbar_set_value( progbar2, 50.0f );

	// Create a 90% progressbar.
	progbar3 = mgui_create_progressbar_ex( canvas_progressbar, 400, 200, 200, 20, FLAG_NONE, RGBCOL(255,0,0), RGBCOL(0,255,0), 100.0f );
	mgui_progressbar_set_value( progbar3, 90.0f );
}

void unit_test_destroy_progressbar( void )
{
	mgui_element_destroy( progbar1 );
	mgui_element_destroy( progbar2 );
	mgui_element_destroy( progbar3 );
}
