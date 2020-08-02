#pragma once
#include <string>
#include <iostream>
#include "Map.h"
using namespace std;
int square_price_getter(int square[], int i);
class Player
{

	
public:
	Player();
	Player(string, int balance, int color,int position, int action_point,int Owner[38]);
	~Player();
	void name_setter(string);
	string name_getter();
	void balance_setter(int);
	int balance_getter();
	void color_setter(int);
	int color_getter();
	void position_setter(int);
	int position_getter();
	void action_point_setter(int);
	int action_point_getter();
	void Owner_setter(int[]);
	int* Owner_getter();
	void Initialization_settings();

	void AI_battle(Player);
	bool buy_square(Player, int square[],int type);
	Player determine_fine(Player other, int square_price[]);

	void roll_dice_and_move();



	
private:
	string name;
	int balance;
	int color;
	int position;
	int action_point;
	int owner[38];//0 and 19 is not allowed to own

	
};

