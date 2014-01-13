/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.FpsLabel.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Shows the current FPS rate of the application on a label.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "Platform/Timer.h"
#include "UnitTest.h"

static MGuiLabel* fpslabel = NULL;
static uint32 last_updated = 0;
static uint32 frames = 0;

void unit_test_create_fps_label( void )
{
	extern MGuiCanvas* canvas;

	fpslabel = mgui_create_label_ex( canvas, 725, 0, FLAG_NONE, RGBCOL(255,255,255), "0 FPS" );
	mgui_set_alignment( fpslabel, ALIGN_RIGHT );
}

void unit_test_destroy_fps_label( void )
{
	mgui_element_destroy( fpslabel );
	fpslabel = NULL;
}

void unit_test_update_fps_label( void )
{
	uint32 ticks = get_tick_count();
	uint32 diff = ticks - last_updated;

	if ( diff >= 1000 )
	{
		// Update the FPS display, then reset the counters.
		mgui_set_text( fpslabel, "%.1f FPS", 1000.0f * frames / diff );

		last_updated = ticks;
		frames = 0;
	}

	++frames;
}
