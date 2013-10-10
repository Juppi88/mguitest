/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.Sprite.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		Unit tests for sprite.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#include "MGUI/MGUI.h"
#include "UnitTest.h"

static MGuiSprite* sprite1 = NULL;
static MGuiSprite* sprite2 = NULL;

void unit_test_create_sprite( void )
{
	extern MGuiCanvas* canvas_sprite;

	// We have to use a different sprite format for OpenGL and the rest because our reference OpenGL renderer can only load
	// 32bit windows bitmaps (and apparently D3DX can't).
	extern const char_t* sprite_path;

	// Create a sprite directly from the file.
	sprite1 = mgui_create_sprite_ex( canvas_sprite, 325, 100, FLAG_NONE, RGBCOL(255,255,255), sprite_path );

	// Ditto, but change the colour and scale a bit.
	sprite2 = mgui_create_sprite_ex( canvas_sprite, 450, 125, FLAG_NONE, RGBCOL(255,0,0), sprite_path );
	mgui_set_abs_size_i( sprite2, 250, 250 );
}

void unit_test_destroy_sprite( void )
{
	mgui_element_destroy( sprite1 );
	mgui_element_destroy( sprite2 );
}
