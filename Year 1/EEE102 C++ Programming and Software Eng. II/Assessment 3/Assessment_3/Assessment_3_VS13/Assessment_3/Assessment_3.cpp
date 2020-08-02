// Assessment_3.cpp : Defines the entry point for the console application.
// Xuhui Gong

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Map.h"
#include <string>
#include "Screen.h"
#include "File_tool.h"
#include "Player.h"
//Import files
using namespace std;
HWND WINAPI GetConsoleWindow();
Player player;
Player computer;
Screen this_screen;
File_tool file;
void print_color(int color);//Parsing colors
int square_price[38];//Define house price
int square_price_getter(int);// house price getter
void random_square_price_setter();// random house price getter method
Map map_recovery;//Image Construction Statement
//Declaration in main function
void battle();//Battle method

int strToint(string str){
	stringstream ss;
	ss << str;
	int value;
	ss >> value;
	return value;
}
//String to int method

void recover_map_in_battle(Player,Player);//Image refresh

void userinterface(){
	HWND hwnd;//Statement brush
	hwnd = GetConsoleWindow();//Getting Command Desk Functions
	HDC hDC = GetDC(hwnd);//Get HDC
	system("color 37");//Setting Command Desk Colors
	cout << "Please do not Scroll bar, otherwise, the image function will be affected." << endl;
	cout << "Please do not drag the command desk or use the mouse box to select text at CMD, otherwise it will cause abnormal map function." << endl;
	cout << "The recommended resolution is 1920*1080. The program will automatically set the resolution. If not, the picture will not be displayed." << endl;
	cout << "Wait 6s and read to Continue" << endl;
	Sleep(6000);
	system("cls");//Clear the screen
	int x = this_screen.get_screen_x();
	int y = this_screen.get_screen_y();//Get screen parameters
	LPCWSTR text1 = TEXT("Welcome to the Monopoly GAME");
	LPCWSTR text2 = TEXT("PRODUCED BY XUHUI GONG");
	LPCWSTR text3 = TEXT("Please wait to continue");//Setting Output Print Statement
	TextOut(hDC, (5*x) / 12, (3*y)/4, text1, 28);
	TextOut(hDC, (5 * x) / 12, (3 * y) / 4 +20, text2, 22);
	TextOut(hDC, (5 * x) / 12, (3 * y) / 4 + 40, text3, 23);//Print bu text
	Ellipse(hDC, 200, 200, 400, 400);
	Ellipse(hDC, 500, 200, 700, 400);
	Ellipse(hDC, 100, 200, 800, 800);//Drawing ellipse

	ReleaseDC(hwnd, hDC);//Free memory

	Sleep(3000);

	Map map;//Initialization image
	random_square_price_setter();//Setting Price Random Number
	computer.Initialization_settings();//Computer Hand Content Initialization
	computer.name_setter("Peter");
	computer.color_setter(4);//Blue
	map.refresh_map(false);//Refresh the map
	this_screen.SetPosition(0, 45);//Setting Output Text Location
	cout << "_____________________________________________________" << endl;
	bool success = 0;
	do{
		cout << "Please select Play a new game or continue the game..." << endl;
		cout << "1. New Game			 2. Continue the Game" << endl;
		int select_num ;
		cin.clear();//Clear the Flag
		cin.sync();//Delete the wrong input
		cin >> select_num;
		map.refresh_map(false);
		Sleep(100);
		switch (select_num)
		{
		case 1:{
				   cout << "Create your account:" << endl;
				   cout << "What is your name?" << endl;
				   string name;
				   cin >> name;
				   player.name_setter(name);
				   enter_color:
				   cout << "Which color do you want to use in the game to represent your hourse?" << endl;
				   cout << "1. Red 2.Green 3.Yellow" << endl;
				   int color_selection;
				   cin.clear();//Clear the Flag of error
				   cin.sync();//Delete the wrong input
				   cin >> color_selection;
				  

				   switch (color_selection)
				   {
				   case 1:{
							  player.color_setter(1);
							  success = 1;
				   break;
				   }
				   case 2:{
							  player.color_setter(2);
							  success = 1;
							  break;
				   }
				   case 3:{
							  player.color_setter(3);
							  success = 1;
							  break;
				   }
				
				   default:
					   cout << "Wrong input of color, please enter again!" << endl;
					   goto enter_color;
					   break;
				   }
				   player.Initialization_settings();
				   break;
		}//Users select specific information
		case 2:{//If the user chooses to continue the game, the program will read the text document.
				   cout << "Recovering your account..." << endl;
				   cout << "Please wait..." << endl;
				//   string name=file.read_file(1);
				//   cout << name << endl;
				   int line = file.CountLines("data.txt");
				   cout << line << endl;
				   player.name_setter(file.readTxt("data.txt", 1));
				   string playerBalance = file.readTxt("data.txt", 2);				   
				   player.balance_setter(strToint(playerBalance));
				   string computerBalance = file.readTxt("data.txt", 3);
				   computer.balance_setter(strToint(computerBalance));

				   string colorOfPlayer = file.readTxt("data.txt", 4);
				   player.color_setter(strToint(colorOfPlayer));

				   string PositionOfPlayer = file.readTxt("data.txt", 5);
				   player.position_setter(strToint(PositionOfPlayer));

				   string PositionOfComputer = file.readTxt("data.txt", 6);
				   computer.position_setter(strToint(PositionOfComputer));

				   string actionOfPlayer = file.readTxt("data.txt", 7);
				   player.action_point_setter(strToint(actionOfPlayer));

				   string actionOfComputer = file.readTxt("data.txt", 8);
				   computer.action_point_setter(strToint(actionOfComputer));

				   int owner_player[38];
				   int owner_computer[38];
				   int price[38];
				   int n = 0;
				   for (int i = 9; i < 9+38; i++)
				   {
					   string own = file.readTxt("data.txt", i);
					   owner_player[n] = strToint(own);
					   n++;
				   }

				   player.Owner_setter(owner_player);
				   n = 0;
				   for (int i = 47; i < 38 + 47; i++)
				   {
					   string own = file.readTxt("data.txt", i);
					   owner_computer[n] = strToint(own);
					   n++;
				   }
			
				   computer.Owner_setter(owner_computer);
				   n = 0;
				   for (int i = 85; i < 38 + 85; i++)
				   {
					   string own = file.readTxt("data.txt", i);
					   price[n] = strToint(own);
					   square_price[n] = price[n];
					   n++;
				   }

				   success = 1;
				   break;//Restore file content
		}
		default:
			success = 0;
			cout << "Wrong input, please enter again!" << endl;

			break;
		}

	} while (success == 0);
	



	cout << "OK, everthing are finished." << endl;
	cout << "__________________________________________________________________________________________________________" << endl;
	Sleep(1000);
	map.refresh_map(true);
}

//UserInterface


int main()
{

	
	
	this_screen.full_screen();
	system("mode con cols=400 lines=400");//Set the number of command lines
	userinterface();

	Map map;
	int round = 0;
	while (player.balance_getter() >= 0 && computer.balance_getter() >= 0)
	{
		system("cls");
		this_screen.SetPosition(0, 45);
		cout << "________________________________________" << endl;
		cout << "# Player" << setw(10) << player.name_getter() << "  # Opponent" << setw(10) << computer.name_getter()<<endl;
		cout << "# Balance" << setw(10) << player.balance_getter() << setw(10) << "# Balance" << setw(10) << computer.balance_getter() << endl;
		cout << "# Color Owner" << setw(5); print_color(player.color_getter()); cout << setw(15) << "# Color Owner" << setw(5); print_color(computer.color_getter()); cout<< endl;
		cout << "# ColorPosition Pink" << setw(5) << "# ColorPosition Black" << endl;
		//Game parameter display
		player.roll_dice_and_move();//Players roll dice
		if (player.position_getter() == 19)
		{
			computer.roll_dice_and_move();
			player = computer.determine_fine(player, square_price);
			bool Whether_buy_computer = computer.buy_square(player, square_price, 1);
		}
		//Detect whether players are in prison or not
		computer = player.determine_fine(computer, square_price);
		//Check whether players are fined
		int *owner_player = player.Owner_getter();
		int *owner_computer = computer.Owner_getter();
		recover_map_in_battle(player,computer);
		if (owner_player[player.position_getter()] == 0 && owner_computer[player.position_getter()] == 0 && player.position_getter() != 0 && player.position_getter() != 19)
		{
			bool success = 0;
			do{
				cout << "Do you want to buy or upgrade Plot? "<<square_price[player.position_getter()]<<"$" << endl;
				cout << "1. Buy 2. Buy and Upgrade 3.Do nothing 4.Save and Exit" << endl;
				int select_num;
				cin.clear();//Clear the Flag
				cin.sync();//Delete the wrong input
				cin >> select_num;

				switch (select_num)
				{
				case 1:{
						   bool Whether_buy_player = player.buy_square(computer, square_price,1);
						   //Purchase method
						   Sleep(2000);
						   success = 1;
						   break;
				}
			
				case 2:{
						   bool Whether_buy_player = player.buy_square(computer, square_price, 2);
						   //Purchase method
						   Sleep(2000);
						   success = 1;
						   break;



				}

				case 3:{
						   success = 1;
						   break;
				}
				case 4:{
						   cout << "Saving" << endl;
						   file.write_file(player.name_getter(), player.balance_getter(), computer.balance_getter(),player.color_getter(), player.position_getter(),computer.position_getter() ,player.action_point_getter(), computer.action_point_getter(),owner_player, owner_computer,square_price);
						   exit(0);
						   break;
						   //Save the game
				}

				default:success = 0;
					cout << "Error Number" << endl;
					break;
				}



			} while (success == 0);

		}
	
		

		



		Sleep(2000);
		computer.roll_dice_and_move();
		//Computer round
		if (computer.position_getter() == 19)
		{
			player.roll_dice_and_move();
			computer = player.determine_fine(computer, square_price);
			if (owner_player[player.position_getter()] == 0 && owner_computer[player.position_getter()] == 0 && player.position_getter() != 0 && player.position_getter() != 19)
			{
				bool success = 0;
				do{
					cout << "Do you want to buy or upgrade Plot?" << endl;
					cout << "1. Buy 2. Buy and Upgrade 3.Do nothing" << endl;
					int select_num;
					cin.clear();//Clear the Flag
					cin.sync();//Delete the wrong input
					cin >> select_num;

					switch (select_num)
					{
					case 1:{
							   bool Whether_buy_player = player.buy_square(computer, square_price, 1);

							   Sleep(2000);
							   success = 1;
							   break;
					}

					case 2:{
							   bool Whether_buy_player = player.buy_square(computer, square_price, 2);

							   Sleep(2000);
							   success = 1;
							   break;



					}

					case 3:{
							   success = 1;
							   break;
					}

					default:success = 0;
						cout << "Error Number" << endl;
						break;
					}



				} while (success == 0);

			}


		}

		player = computer.determine_fine(player, square_price);
		bool Whether_buy_computer = computer.buy_square(player, square_price,1);
		round++;
		cout << "The reound " << round << endl;
		Sleep(3000);

	}
	//Tell the player that the game is over and get the result
	Sleep(1000);
	if (player.balance_getter()>0)
	{
		cout << "YOU WIN" << endl;
	}
	else{
		cout << "GAME OVER" << endl;
	}


	system("PAUSE");
	return 0;
}

void random_square_price_setter(){

	srand((unsigned)time(NULL));		// generating random seed based on system time

	for (int i = 0; i < 38; i++)
	{
		square_price[i] = (rand() % (291)) + 10;
	}

}

int square_price_getter(int square){

	return square_price[square];

}

void recover_map_in_battle(Player player_1,Player player_2){

	HWND hwnd;
	hwnd = GetConsoleWindow();
	Screen this_screen;
	int x = this_screen.get_screen_x();//1920
	int y = this_screen.get_screen_y();//1080
	HDC hDC = GetDC(hwnd);
	HBRUSH hBrush1 = CreateSolidBrush(RGB(58, 150, 221));


	int RGB_R_1;
	int RGB_G_1;
	int RGB_B_1;

	int RGB_R_2;
	int RGB_G_2;
	int RGB_B_2;


	switch (player_1.color_getter())
	{
		case 1:{
				 //  cout << "Red";
				   RGB_R_1 = 255;
				   RGB_G_1 = 0;
				   RGB_B_1 = 0;
				   break;
		}
		case 2:{
				//   cout << "Green";
				   RGB_R_1 = 0;
				   RGB_G_1 = 255;
				   RGB_B_1 = 127;
				   break;
		}
		case 3:{
				   RGB_R_1 = 245;
				   RGB_G_1 = 222;
				   RGB_B_1 = 179;
				//   cout << "Yellow";
				   break;
		}
		case 4:{
				   RGB_R_1 = 65;
				   RGB_G_1 = 105;
				   RGB_B_1 = 225;
				   cout << "Blue";
				   break;
		}
		default:
			break;
	}


	switch (player_2.color_getter())
	{
	case 1:{
			   //  cout << "Red";
			   RGB_R_2 = 255;
			   RGB_G_2 = 0;
			   RGB_B_2 = 0;
			   break;
	}
	case 2:{
			   //   cout << "Green";
			   RGB_R_2 = 0;
			   RGB_G_2 = 255;
			   RGB_B_2 = 127;
			   break;
	}
	case 3:{
			   RGB_R_2 = 245;
			   RGB_G_2 = 222;
			   RGB_B_2 = 179;
			   //   cout << "Yellow";
			   break;
	}
	case 4:{
			   RGB_R_2 = 65;
			   RGB_G_2 = 105;
			   RGB_B_2 = 225;
			//   cout << "Blue";
			   break;
	}
	default:
		break;
	}

	int *result_1 = player.Owner_getter();
	int *result_2 = computer.Owner_getter();

	for (int i = 0; i < 38; i++)
	{
		if (result_1[i]==1 || result_1[i] == 2)
		{
			map_recovery.set_color(i, RGB_R_1, RGB_G_1, RGB_B_1);

		}
		else if (result_2[i]==1 || result_2[i] == 2)
		{
			map_recovery.set_color(i, RGB_R_2, RGB_G_2, RGB_B_2);

		}
		else
		{
			map_recovery.set_color(i, 255, 255, 255);

		}
	
	}
	
	map_recovery.set_color(player.position_getter(), 155, 10, 220);
	map_recovery.set_color(computer.position_getter(), 5, 10, 20);


}//Print redrawing method


void print_color(int color){

	switch (color)
	{
	case 1:{
			   cout << "Red";
			   break;
	}
	case 2:{
			   cout << "Green";
			   break;
	}
	case 3:{
			   cout << "Yellow";
			   break;
	}
	case 4:{
			   cout << "Blue";
			   break;
	}
	default:
		break;
	}
}



