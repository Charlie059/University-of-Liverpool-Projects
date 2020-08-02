#pragma once
#include <windows.h>
class Screen
{
public:
	Screen();
	~Screen();
	void Screen::full_screen();
	int Screen::get_screen_x();
	int Screen::get_screen_y();
	void Screen::SetPosition(int x, int y);

};

