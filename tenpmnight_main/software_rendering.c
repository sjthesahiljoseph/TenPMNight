
#include "win32_platform.h"
#include "software_rendering.h"

internal void
clear_screen(u32 color, Render_Buffer r_buffer) {
	u32 *pixel = r_buffer.pixels;

	for (int y = 0; y < r_buffer.height; y++) {
		for (int x = 0; x < r_buffer.width; x++) {
			*pixel++ = color;
		}	
	}
}

internal void
draw_rect_in_pixels(int x0, int y0, int x1, int y1, u32 color, Render_Buffer r_buffer) {

	for (int y = y0; y < y1; y++) {
		u32 *pixel = r_buffer.pixels + x0 + r_buffer.width * y;
		for (int x = x0; x < x1; x++) {
			*pixel++ = color;
		}	
	}
}


