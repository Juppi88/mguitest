/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		ConsoleTest.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A basic console window unit test for MGUI.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "Input/Input.h"
#include "Platform/Window.h"
#include "Math/MathUtils.h"

// Default colour definitions
#define COL_TEXT			RGBCOL(255,255,255)
#define COL_TEXTBG			RGBCOL(20,20,20)
#define COL_SCROLL			RGBCOL(50,50,50)
#define COL_WINDOW			RGBCOL(75,75,75)
#define COL_TITLEBAR		RGBCOL(10,10,10)
#define CONSOLE_ALPHA		255

static MGuiWindow*		window		= NULL;
static MGuiButton*		button		= NULL;
static MGuiEditbox*		editbox		= NULL;
static MGuiMemobox*		memobox		= NULL;

extern bool	running;
extern syswindow_t* wnd;

static void console_window_event( MGuiEvent* event )
{
	vectorscreen_t pos;
	vectorscreen_t size;
	int16 x, y;

	switch ( event->type )
	{
	case EVENT_WINDOW_CLOSE:
		running = false;
		break;

	case EVENT_DRAG:
		mgui_window_get_drag_offset( event->element, &pos );
		mgui_get_abs_size( event->element, &size );

		x = event->mouse.x;
		y = event->mouse.y;

		window_pos_to_screen( wnd, &x, &y );

		pos.x = x - pos.x;
		pos.y = y - pos.y;

		// Move the system window, don't let the GUI window move
		set_window_pos( wnd, pos.x, pos.y );
		mgui_set_abs_pos_i( window, 0, 0 );

		break;

	default:
		break;
	}
}

static void console_button_event( MGuiEvent* event )
{
	switch ( event->type )
	{
	case EVENT_RELEASE:
		if ( mgui_get_text_len( editbox ) != 0 )
		{
			mgui_memobox_add_line( memobox, "] %s", mgui_get_text( editbox ) );

			mgui_set_text_s( editbox, "" );
			mgui_set_focus( editbox );
		}
		break;

	default:
		break;
	}
}

static void console_editbox_event( MGuiEvent* event )
{
	switch ( event->type )
	{
	case EVENT_INPUT_RETURN:
		if ( mgui_get_text_len( editbox ) != 0 )
		{
			mgui_memobox_add_line_s( memobox, mgui_get_text( editbox ) );

			mgui_set_text_s( editbox, "" );
			mgui_set_focus( editbox );
		}
		break;

	case EVENT_HOVER_ENTER:
		set_mouse_cursor( CURSOR_TEXT );
		break;

	case EVENT_HOVER_LEAVE:
		set_mouse_cursor( CURSOR_ARROW );
		break;

	default:
		break;
	}
}

static bool console_shutdown( uint32 key, void* data )
{
	UNREFERENCED_PARAM( key );
	UNREFERENCED_PARAM( data );

	running = false;
	return true;
}

void console_test_initialize( void )
{
	uint16 w = 400, h = 450;

	// Main console window
	window = mgui_create_window_ex( NULL, 0, 0, w, h, FLAG_NONE, COL_WINDOW, NULL );
	mgui_set_text_s( window, _MTEXT("MGUI Test Console") );
	mgui_window_set_title_col_i( window, COL_TITLEBAR );
	mgui_set_event_handler( window, console_window_event, NULL );

	// Submit button
	button = mgui_create_button_ex( window, w - 65, h - 56, 50, 22, FLAG_BORDER, COL_WINDOW, _MTEXT("Submit") );
	mgui_set_text_colour_i( button, COL_TEXT );
	mgui_set_font( button, _MTEXT("Verdana"), 11, 0, 0 );
	mgui_set_event_handler( button, console_button_event, NULL );

	// Editbox
	editbox = mgui_create_editbox_ex( window, 12, h - 56, w - 86, 22, FLAG_NONE, COL_TEXTBG, NULL );
	mgui_set_text_colour_i( editbox, COL_TEXT );
	mgui_set_font( editbox, _MTEXT("Lucida Console"), 11, 0, 0 );
	mgui_set_event_handler( editbox, console_editbox_event, NULL );

	// Memobox (actual console part)
	memobox = mgui_create_memobox_ex( window, 12, 10, w - 24, h - 74, FLAG_MEMO_TOPBOTTOM, COL_TEXTBG );
	mgui_set_text_colour_i( memobox, COL_TEXT );
	mgui_set_font( memobox, _MTEXT("Lucida Console"), 10, 0, 0 );
	mgui_set_text_padding( memobox, 10, 4, 10, 10 );

	mgui_set_alpha( window, CONSOLE_ALPHA );

	// Add a keybind to open the console
	input_add_key_down_bind( MKEY_F10, console_shutdown, NULL );

	mgui_memobox_add_line_s( memobox, "MGUI test console loaded!" );
	mgui_memobox_add_line_s( memobox, "Press F10 to forcibly kill the app." );

	set_mouse_cursor( CURSOR_ARROW );
}

void console_test_process( void )
{
	// Nothing to do here. The main app loop will handle window event processing etc.
}

void console_test_shutdown( void )
{
	set_mouse_cursor( CURSOR_ARROW );
}
