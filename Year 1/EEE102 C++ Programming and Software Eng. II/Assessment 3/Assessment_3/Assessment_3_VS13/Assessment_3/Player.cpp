#include "Player.h"

Player::Player(){
	name = "";
	balance = 0;
	position = 0;
	action_point = 0;
}

Player::Player(string Name, int Balance,int Color, int Position, int Action_point, int Owner[38])
{
	name = Name;
	balance = Balance;
	color = Color;
	position = Position;
	action_point = Action_point;
	for (int i = 0; i < 38; i++)
	{
		owner[i] = Owner[i];
	}
}


Player::~Player()
{
}

void Player::name_setter(string set_name){
	this->name = set_name;
}
string Player::name_getter(){
	return name;
}
void Player::balance_setter(int set_balance){
	this->balance = set_balance;
}
int Player::balance_getter(){
	return balance;
}
void Player::color_setter(int set_color){
	this->color = set_color;
}
int Player::color_getter(){
	return color;
}
void Player::position_setter(int set_position){
	this->position = set_position;
}
int Player::position_getter(){
	return position;
}
void Player::action_point_setter(int set_action_point){
	this->action_point = set_action_point;
}
int Player::action_point_getter(){
	return action_point;
}
void Player::Owner_setter(int set_owner[38]){

	for (int i = 0; i < 38; i++)
	{
		owner[i] = set_owner[i];
	}
}
int* Player::Owner_getter(){
	int *Owner = new int[38];
	Owner = owner;
	return Owner;
}
void Player::Initialization_settings(){
	this->balance = 1000;
	this->position = 0;
	this->owner[38] = { 0 };
}
//void* Player::Owner_upgrade_getter(){
//	return owner_upgrade;
//}
void Player::AI_battle(Player player){

	if (balance > 1000)
	{

	}

}

bool Player::buy_square(Player other, int square_price[], int type){

	if (owner[position] == 0 && other.owner[position] == 0 && position != 0 && position != 19 && type == 1)
	{
		if (balance >= square_price[position])
		{
			owner[position] = 1;
			balance = balance - square_price[position];
			cout << name << " Purchase Success in Number " << position << " and cost " << square_price[position]<<"$"<< endl;
			return true;
		}
		else
		{
			cout << name << " has No enough Money" << endl;
			return false;
		}
	}
	else if (owner[position] == 0 && other.owner[position] == 0 && position != 0 && position != 19 && type == 2)
	{
		if (balance >= 1.5*square_price[position])
		{
			owner[position] = 2;
			balance = balance - 1.5*square_price[position];
			cout << name << " Purchase Success and upgrate in Number " << position << " and cost " << 1.5*square_price[position] << "$" << endl;
			return true;
		}
		else
		{
			cout << name<<" has No enough Money" << endl;
			return false;
		}
	}
	else
	{
		cout << name << " has Purchased Failure in Number " << position << endl;
		return false;
	}

	
}


Player Player::determine_fine(Player other, int square_price[]){


	Player ret_player;
	if ((other.owner[position] == 1) && ((other.owner[position + 1] == 1 || other.owner[position + 1] == 2) || (other.owner[position - 1] == 1 || other.owner[position - 1] == 2)))
	{
		balance = balance - 0.2 * (square_price_getter(square_price, position));
		//other_p.balance_setter(other_p.balance_getter() + 0.2 * (square_price_getter(square_price, position))); 
		cout << "\r																						\r";
		cout << name << " has been fined double" << 0.2* (square_price_getter(square_price, position)) << "$" << endl;
		string name = other.name_getter();

		ret_player.name_setter(other.name_getter());
		ret_player.balance_setter(other.balance_getter() + 0.2 * (square_price_getter(square_price, position)));
		ret_player.color_setter(other.color_getter());
		ret_player.position_setter(other.position_getter());
		ret_player.action_point_setter(other.action_point_getter());
		ret_player.Owner_setter(other.Owner_getter());
		return ret_player;
	}
	else if ((other.owner[position] == 2) && ((other.owner[position + 1] == 1 || other.owner[position + 1] == 2) || (other.owner[position - 1] == 1 || other.owner[position - 1] == 2)))
	{
		balance = balance - 0.25 * (square_price_getter(square_price, position));
		//other_p.balance_setter(other_p.balance_getter() + 0.2 * (square_price_getter(square_price, position))); 
		cout << "\r																						\r";
		cout << name << " has been fined double" << 0.25* (square_price_getter(square_price, position)) << "$" << endl;
		string name = other.name_getter();

		ret_player.name_setter(other.name_getter());
		ret_player.balance_setter(other.balance_getter() + 0.25 * (square_price_getter(square_price, position)));
		ret_player.color_setter(other.color_getter());
		ret_player.position_setter(other.position_getter());
		ret_player.action_point_setter(other.action_point_getter());
		ret_player.Owner_setter(other.Owner_getter());
		return ret_player;
	}
	else if ((other.owner[position] == 1) && (other.owner[position + 1] == 0) && (other.owner[position - 1] == 0))
	{
		balance = balance - 0.1* (square_price_getter(square_price, position));
		cout << "\r																						\r";
		cout << name << " has been fined " << 0.1* (square_price_getter(square_price, position)) << "$" << endl;
		cout << "\r																						\r";
		cout << other.name_getter() << " earned " << 0.1* (square_price_getter(square_price, position)) << "$" << endl;
		string name = other.name_getter();
		Player ret_player;
		ret_player.name_setter(other.name_getter());
		ret_player.balance_setter(other.balance_getter() + 0.1 * (square_price_getter(square_price, position)));
		ret_player.color_setter(other.color_getter());
		ret_player.position_setter(other.position_getter());
		ret_player.action_point_setter(other.action_point_getter());
		ret_player.Owner_setter(other.Owner_getter());
		return ret_player;
	}
	else if ((other.owner[position] == 2) && (other.owner[position + 1] == 0) && (other.owner[position - 1] == 0))
	{
		balance = balance - 0.2* (square_price_getter(square_price, position));
		cout << "\r																						\r";
		cout << name << " has been fined double" << 0.2* (square_price_getter(square_price, position)) << "$" << endl;
		cout << "\r																						\r";
		cout << other.name_getter() << " earned " << 0.2* (square_price_getter(square_price, position)) << "$" << endl;
		string name = other.name_getter();
		Player ret_player;
		ret_player.name_setter(other.name_getter());
		ret_player.balance_setter(other.balance_getter() + 0.2 * (square_price_getter(square_price, position)));
		ret_player.color_setter(other.color_getter());
		ret_player.position_setter(other.position_getter());
		ret_player.action_point_setter(other.action_point_getter());
		ret_player.Owner_setter(other.Owner_getter());
		return ret_player;
	}
	else
	{
		string name = other.name_getter();
		Player ret_player;
		ret_player.name_setter(other.name_getter());
		ret_player.balance_setter(other.balance_getter());
		ret_player.color_setter(other.color_getter());
		ret_player.position_setter(other.position_getter());
		ret_player.action_point_setter(other.action_point_getter());
		ret_player.Owner_setter(other.Owner_getter());
		return ret_player;
	}



}


int square_price_getter(int square[],int i){
	
	return square[i];

}


void Player::roll_dice_and_move(){

	srand((unsigned)time(NULL));		// generating random seed based on system time
	action_point = (rand() % 6 + 1);
	position = position + action_point;
	if (position == 19)
	{
		cout << name<<" in Prison, stop one turn and cost 200$!" << endl;
		balance = balance - 200;
	}
	if (position > 37)
	{
		position = position - 38;
		balance = balance + 100;
		cout << name<<" Balance + 100" << endl;
	}
\

	cout << name << " moves " << action_point << " now in the " << position << endl;

}

