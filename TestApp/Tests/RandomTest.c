/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		RandomTest.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Quick test for random elements.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "Input/Input.h"

// Default colour definitions
#define COL_TEXT			RGBCOL(255,255,255)
#define COL_TEXTBG			RGBCOL(20,20,20)
#define COL_SCROLL			RGBCOL(50,50,50)
#define COL_WINDOW			RGBCOL(75,75,75)
#define COL_TITLEBAR		RGBCOL(10,10,10)
#define CONSOLE_ALPHA		255

#ifdef _WIN32
#define CONSOLE_FONT		_MTEXT("Lucida Console")
#define WINDOW_FONT			_MTEXT("Verdana")
#define TITLEBAR_FONT		_MTEXT("Tahoma")
#else
#define CONSOLE_FONT		_MTEXT("*x13*")
#define WINDOW_FONT			_MTEXT("lucidasans-8")
#define TITLEBAR_FONT		_MTEXT("lucidasans-bold-8")
#endif

MGuiCanvas*			canvas	= NULL;
MGuiLabel*			label	= NULL;
MGuiProgressbar*	progbar	= NULL;
static float		progress = 0.0f;

static bool app_shutdown( uint32 key, void* data )
{
	extern bool running;

	(void)key; (void)data;
	running = false;

	return true;
}

void random_test_initialize( void )
{
	input_add_key_down_bind( MKEY_F10, app_shutdown, NULL );

	canvas = mgui_create_canvas( NULL );
	mgui_add_flags( canvas, FLAG_BACKGROUND );
	mgui_set_colour_i( canvas, 0xFFFFFFFF );

	label = mgui_create_label_ex( canvas, 50, 50, 125, 30, FLAG_BORDER|FLAG_CLIP, RGBCOL(0,0,0), "yeah" );
	mgui_set_alignment( label, ALIGN_RIGHT|ALIGN_TOP );
	mgui_set_font_size( label, 18 );
	mgui_set_text_colour_i( label, RGBCOL(0,255,0) );
	mgui_set_text_padding( label, 0, 0, 0, 0 );

	progbar = mgui_create_progressbar_ex( canvas, 50, 100, 100, 20, FLAG_NONE, RGBCOL(0,255,0), RGBCOL(255,0,0), 100.0f );
	mgui_progressbar_set_value( progbar, 0.0f );
	mgui_progressbar_set_bg_shade( progbar, 0.25f );
	mgui_progressbar_set_thickness( progbar, 2 );
}

void random_test_process( void )
{
	progress += 0.2f;
	mgui_progressbar_set_value( progbar, progress );
	mgui_force_redraw();
}

void random_test_shutdown( void )
{
	mgui_element_destroy( label );
	mgui_element_destroy( progbar );
}
