#pragma once

#include "utils.h"

#include <windows.h>


struct
{
	// platform non-specific.
	int width;
	int height;
	u32* pixels;
	// platform specific.
	BITMAPINFO bitmap_info;

} typedef Render_Buffer;

/* struct { */
/* 	int width; */
/* 	int height; */
/* 	u32 *pixels; */
/* 	BITMAPINFO bitmap_info; */
/* } typedef Game_Render_Buffer; */

global_variable Render_Buffer render_buffer;


internal LRESULT window_callback(HWND window, UINT message, WPARAM w_param, LPARAM l_param);

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

