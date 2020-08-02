#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class File_tool
{
public:
	File_tool();
	~File_tool();
	bool File_tool::check_file();
	void File_tool::write_file(string name, int balance, int balance_computer, int color, int position_player, int position_computer, int action_point_player, int action_point_computer, int OwnerPlayer[38], int OwnerComputer[38], int price[38]);
	string File_tool::read_name();
	int File_tool::read_balance();
	int File_tool::read_color();
	int File_tool::position();
	int* File_tool::read_own();
	string readTxt(string filename, int line);
	int CountLines(string filename);
};

