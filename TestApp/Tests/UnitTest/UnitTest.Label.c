/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.Label.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Unit tests for label.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

static MGuiLabel* label1 = NULL;
static MGuiLabel* label2 = NULL;
static MGuiLabel* label3 = NULL;
static MGuiLabel* label4 = NULL;
static MGuiLabel* label5 = NULL;
static MGuiLabel* label6 = NULL;

void unit_test_create_label( void )
{
	extern MGuiCanvas* canvas_label;

	// Create a basic label with some text.
	label1 = mgui_create_label_ex( canvas_label, 350, 75, FLAG_NONE, COL_TEXTBG, "This is a label." );

	// Create a label which supports format tags.
	label2 = mgui_create_label_ex( canvas_label, 350, 100, FLAG_TEXT_TAGS, COL_TEXTBG, "This is another label [#ff00ff]that [#ffff00]supports [#ff0000]format[#d] [#uline]tags[#u]." );

	// Create a bigger label with a different font.
	label3 = mgui_create_label_ex( canvas_label, 350, 130, FLAG_TEXT_TAGS, RGBCOL(255,255,0), "This one uses an [#ff0000]outlined font.[#d]" );
	mgui_set_font( label3, WINDOW_FONT, 16, FFLAG_BOLD|FFLAG_OUTLINE, CHARSET_ANSI );

	// Show different alignments.
	label4 = mgui_create_label_ex( canvas_label, 365, 170, FLAG_BORDER|FLAG_BACKGROUND, COL_TEXT, "Top left align" );
	mgui_set_alignment( label4, ALIGN_TOP|ALIGN_LEFT );
	mgui_set_abs_size_i( label4, 150, 25 );
	mgui_set_colour_i( label4, COL_WINDOW );

	label5 = mgui_create_label_ex( canvas_label, 365, 200, FLAG_BORDER|FLAG_BACKGROUND, COL_TEXT, "Centre align" );
	mgui_set_alignment( label5, ALIGN_CENTER );
	mgui_set_abs_size_i( label5, 150, 25 );
	mgui_set_colour_i( label5, COL_WINDOW );

	label6 = mgui_create_label_ex( canvas_label, 365, 230, FLAG_BORDER|FLAG_BACKGROUND, COL_TEXT, "Bottom right align" );
	mgui_set_alignment( label6, ALIGN_BOTTOM|ALIGN_RIGHT );
	mgui_set_abs_size_i( label6, 150, 25 );
	mgui_set_colour_i( label6, COL_WINDOW );
}

void unit_test_destroy_label( void )
{
	mgui_element_destroy( label1 );
	mgui_element_destroy( label2 );
	mgui_element_destroy( label3 );
	mgui_element_destroy( label4 );
	mgui_element_destroy( label5 );
}
