/**********************************************************************
 *
 * PROJECT:		Mylly GUI Test App
 * FILE:		UnitTest.h
 * LICENCE:		See Licence.txt
 * PURPOSE:		Proper unit test for MGUI elements.
 *
 *				(c) Tuomo Jauhiainen 2013
 *
 **********************************************************************/

#pragma once
#ifndef __MGUI_UNIT_TEST_H
#define __MGUI_UNIT_TEST_H

// Default colour and font definitions
#define COL_TEXT			RGBCOL(225,225,225)
#define COL_TEXTBG			RGBCOL(20,20,20)
#define COL_SCROLL			RGBCOL(50,50,50)
#define COL_WINDOW			RGBCOL(75,75,75)
#define COL_TITLEBAR		RGBCOL(40,80,20)
#define COL_LIST_SELECT		RGBCOL(50,50,50)

#ifdef _WIN32
#define CONSOLE_FONT		_MTEXT("Lucida Console")
#define WINDOW_FONT			_MTEXT("Verdana")
#define TITLEBAR_FONT		_MTEXT("Tahoma")
#else
#define CONSOLE_FONT		_MTEXT("*x13*")
#define WINDOW_FONT			_MTEXT("lucidasans-8")
#define TITLEBAR_FONT		_MTEXT("lucidasans-bold-8")
#endif

void	unit_test_initialize			( void );
void	unit_test_process				( void );
void	unit_test_shutdown				( void );

void	unit_test_create_element_list	( void );
void	unit_test_destroy_element_list	( void );

void	unit_test_create_output_window	( void );
void	unit_test_destroy_output_window	( void );

void	unit_test_create_fps_label		( void );
void	unit_test_destroy_fps_label		( void );
void	unit_test_update_fps_label		( void );

// Button test
void	unit_test_create_button			( void );
void	unit_test_destroy_button		( void );

// Checkbox test
void	unit_test_create_checkbox		( void );
void	unit_test_destroy_checkbox		( void );

// Editbox test
void	unit_test_create_editbox		( void );
void	unit_test_destroy_editbox		( void );

// Label test
void	unit_test_create_label			( void );
void	unit_test_destroy_label			( void );

// Listbox test
void	unit_test_create_listbox		( void );
void	unit_test_destroy_listbox		( void );

// Memobox test
void	unit_test_create_memobox		( void );
void	unit_test_destroy_memobox		( void );

// Progressbar test
void	unit_test_create_progressbar	( void );
void	unit_test_destroy_progressbar	( void );

// Scrollbar test
void	unit_test_create_scrollbar		( void );
void	unit_test_destroy_scrollbar		( void );

// Sprite test
void	unit_test_create_sprite			( void );
void	unit_test_destroy_sprite		( void );

// Window test
void	unit_test_create_window			( void );
void	unit_test_destroy_window		( void );

#endif // __MGUI_UNIT_TEST_H
