

#include <windows.h>

typedef int b32;

#define global_variable static
#define internal static

#define true 1
#define false 0

global_variable b32 running = true;

internal LRESULT
WindowCallback(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	
	switch (Msg)
	{

	case WM_QUIT:
	case WM_DESTROY:
	{
		running = false;
	}
	break;

	default:
	{
		result = DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	break;
	
	}
	
	return result;
}

int
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

	WNDCLASSA windowClass = {0};

	windowClass.style = CS_HREDRAW|CS_VREDRAW;
	windowClass.lpfnWndProc = WindowCallback;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = 0;
	windowClass.hIcon = 0;
	windowClass.hCursor = 0;
	windowClass.hbrBackground = 0;
	windowClass.lpszMenuName = 0;
	windowClass.lpszClassName = "TenPMNight";
	
	RegisterClassA(&windowClass);
	
	HWND window = CreateWindowExA(0, windowClass.lpszClassName, windowClass.lpszClassName,
								  WS_VISIBLE|WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
								  CW_USEDEFAULT, 1280, 720, 0, 0, 0, 0);

	HDC hdc = GetDC(window);
	
	while (running)
	{
		// Input
		MSG message;

		while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		// Simulation

		int width, height;
		void* memory;
		BITMAPINFO bitmapInfo;

		// Render
		StretchDIBits(hdc, 0, 0, width, height, 0, 0, width, height, memory, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY);
	}
	
}



