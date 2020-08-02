
#include "Screen.h"


Screen::Screen()
{
}


Screen::~Screen()
{
}

void Screen::full_screen()
{
	HWND hwnd = GetForegroundWindow();
	int x = get_screen_x();
	int y = get_screen_y();
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* Getting window information*/
	/* Set window information to maximize the removal of title bar and border*/
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE));

	SetWindowPos(hwnd, HWND_TOP, 0, 0, x, y, 0);
}

int Screen::get_screen_x(){
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);         /* Screen width pixels*/  
	return cx;
}

int Screen::get_screen_y(){
	HWND hwnd = GetForegroundWindow();
	int cy = GetSystemMetrics(SM_CYSCREEN);        /* Screen Height Pixel*/
	return cy;
}

void Screen::SetPosition(int x, int y)
{
	HANDLE winHandle;
	COORD pos = { x, y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	// Setting cursor position
	SetConsoleCursorPosition(winHandle, pos);
}