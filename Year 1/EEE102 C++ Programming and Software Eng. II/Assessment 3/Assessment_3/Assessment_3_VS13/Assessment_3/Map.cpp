
#include "Map.h"


using namespace std;
Map::Map()
{

	HWND hwnd;
	hwnd = GetConsoleWindow();
	
	Screen this_screen;
	int x = this_screen.get_screen_x();//1920
	int y = this_screen.get_screen_y();//1080
	HDC hDC = GetDC(hwnd);


	


	for (int i = 0; i <= 660; i = i + 60)
	{
		for (int j = 0; j < 600; j = j + 60)
		{
			if (i == 0 || i == 600)
			{
				HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
				//RECT rect{ y / 2, y / 2 + x / 33, x / 3+i, x / 3 + x / 33+i };
				RECT rect = { x / 20 + i, y / 20 + j, x / 20 + 50 + i, y / 20 + 50 + j };//left, top, right,bottom
				FillRect(hDC, &rect, hBrush);

			}

		}

	}

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	for (size_t i = 0; i <= 600; i = i + 60)
	{
		RECT rect_right = { x / 20 + i, y / 20, x / 20 + 50 + i, y / 20 + 50 };//left, top, right,bottom
		FillRect(hDC, &rect_right, hBrush);
	}

	for (size_t i = 0; i < 600; i = i + 60)
	{
		RECT rect_right = { x / 20 + i, y / 20 + 540, x / 20 + 50 + i, y / 20 + 590 };//left, top, right,bottom
		FillRect(hDC, &rect_right, hBrush);
	}




	
	LPCWSTR text1 = TEXT("BEGIN");
	TextOut(hDC, x / 20 + 4, y/20+15, text1, 5);
	LPCWSTR text2 = TEXT("JAIL");
	TextOut(hDC, x / 20 + 610, y / 20 + 555, text2, 4);



	DeleteObject(hBrush);
	//DeleteObject(hBrush1);
	ReleaseDC(hwnd, hDC);

}


Map::~Map()
{
}


void Map::set_color(int number,int RGB_R,int RGB_G, int RGB_B){
	HWND hwnd;
	hwnd = GetConsoleWindow();
	Screen this_screen;
	int x = this_screen.get_screen_x();//1920
	int y = this_screen.get_screen_y();//1080
	HDC hDC = GetDC(hwnd);
	
	switch (number)
	{
	case 0:{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB( RGB_R,  RGB_G,  RGB_B));
			   RECT rect2{ x / 20 , y / 20, x / 20 + 50, y / 20 + 50 };
			   FillRect(hDC, &rect2, hBrush1);
			   LPCWSTR text1 = TEXT("BEGIN");
			   TextOut(hDC, x / 20 + 4, y / 20 + 15, text1, 5);
			   break; }

	case 1:{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x/20 +60,y/20, x/20 +110, y/20 +50 };
			   FillRect(hDC, &rect2, hBrush1);
			   break; }
	case 2:{  
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
		RECT rect2{ x / 20 + 120, y / 20, x / 20 + 170, y / 20 + 50 };
		FillRect(hDC, &rect2, hBrush1); }
		break;
	case 3:{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 180, y / 20, x / 20 + 230, y / 20 + 50 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 4:
	{
			  HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			  RECT rect2{ x / 20 + 240, y / 20, x / 20 + 290, y / 20 + 50 };
			  FillRect(hDC, &rect2, hBrush1); }
		break;
	case 5:
	{
			  HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			  RECT rect2{ x / 20 + 300, y / 20, x / 20 + 350, y / 20 + 50 };
			  FillRect(hDC, &rect2, hBrush1); }
		break;
	case 6:
	{
			  HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			  RECT rect2{ x / 20 + 360, y / 20, x / 20 + 410, y / 20 + 50 };
			  FillRect(hDC, &rect2, hBrush1); }
		break;
	case 7:
	{
			  HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			  RECT rect2{ x / 20 + 420, y / 20, x / 20 + 470, y / 20 + 50 };
			  FillRect(hDC, &rect2, hBrush1); }
		break;
	case 8:
	{
			  HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			  RECT rect2{ x / 20 + 480, y / 20, x / 20 + 530, y / 20 + 50 };
			  FillRect(hDC, &rect2, hBrush1); }
		break;
	case 9:
	{
			  HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			  RECT rect2{ x / 20 + 540, y / 20, x / 20 + 590, y / 20 + 50 };
			  FillRect(hDC, &rect2, hBrush1); }
		break;
	case 10:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 600, y / 20, x / 20 + 650, y / 20 + 50 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 11:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 600, y / 20 +60, x / 20 + 650, y / 20 + 110 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 12:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 600, y / 20 +120, x / 20 + 650, y / 20 + 170 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 13:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 600, y / 20 +180, x / 20 + 650, y / 20 + 230 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 14:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 600, y / 20 +240, x / 20 + 650, y / 20 + 290 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 15:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 600, y / 20 + 300, x / 20 + 650, y / 20 + 350 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 16:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 600, y / 20 + 360, x / 20 + 650, y / 20 + 410 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 17:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 600, y / 20 + 420, x / 20 + 650, y / 20 + 470 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 18:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 600, y / 20 + 480, x / 20 + 650, y / 20 + 530 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 19://JAIL
	{
				HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 600, y / 20 + 540, x / 20 + 650, y / 20 + 590 };
			   FillRect(hDC, &rect2, hBrush1);
			   LPCWSTR text2 = TEXT("JAIL");
			   TextOut(hDC, x / 20 + 610, y / 20 + 555, text2, 4);
	}
		break;
	case 20:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 540, y / 20 + 540, x / 20 + 590, y / 20 + 590 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 21:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 480, y / 20 + 540, x / 20 + 530, y / 20 + 590 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 22:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 420, y / 20 + 540, x / 20 + 470, y / 20 + 590 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 23:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 360, y / 20 + 540, x / 20 + 410, y / 20 + 590 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 24:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 300, y / 20 + 540, x / 20 + 350, y / 20 + 590 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 25:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 240, y / 20 + 540, x / 20 + 290, y / 20 + 590 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 26:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 180, y / 20 + 540, x / 20 + 230, y / 20 + 590 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 27:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 120, y / 20 + 540, x / 20 + 170, y / 20 + 590 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 28:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 + 60, y / 20 + 540, x / 20 + 110, y / 20 + 590 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 29:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20 , y / 20 + 540, x / 20 + 50, y / 20 + 590 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 30:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20, y / 20 + 480, x / 20 + 50, y / 20 + 530 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 31:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20, y / 20 + 420, x / 20 + 50, y / 20 + 470 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 32:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20, y / 20 + 360, x / 20 + 50, y / 20 + 410 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 33:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20, y / 20 + 300, x / 20 + 50, y / 20 + 350 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 34:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20, y / 20 + 240, x / 20 + 50, y / 20 + 290 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 35:{
				HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
				RECT rect2{ x / 20, y / 20 + 180, x / 20 + 50, y / 20 + 230 };
				FillRect(hDC, &rect2, hBrush1); }
		break;
	case 36:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20, y / 20 + 120, x / 20 + 50, y / 20 + 170 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	case 37:
	{
			   HBRUSH hBrush1 = CreateSolidBrush(RGB(RGB_R, RGB_G, RGB_B));
			   RECT rect2{ x / 20, y / 20 + 60, x / 20 + 50, y / 20 + 110 };
			   FillRect(hDC, &rect2, hBrush1); }
		break;
	default:

		break;
	}

	//Drawing method

}
void Map::refresh_map(bool Clean_the_screen){

	HWND hwnd;
	hwnd = GetConsoleWindow();
	Screen this_screen;
	int x = this_screen.get_screen_x();//1920
	int y = this_screen.get_screen_y();//1080
	HDC hDC = GetDC(hwnd);
	HBRUSH hBrush1 = CreateSolidBrush(RGB(58, 150, 221));
	RECT rect2{ 0, 0, x, y };
	FillRect(hDC, &rect2, hBrush1);

	if (Clean_the_screen == true)
	{

		system("cls");
		Screen this_screen;
		this_screen.SetPosition(1, 30);
		Map newMap;
	}
	else
	{
		
		Screen this_screen;
		Map newMap;
	}

}

