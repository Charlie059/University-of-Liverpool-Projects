//=======================
//		user.h
//=======================

#ifndef _USER
#define _USER

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "movie.h"
#include "Room.h"
#include "conio.h"
using namespace std;

void operate_user();
void showUsers();
void searchUser(string Sname);
int userLogin();
int userIDsearch(int uID,bool &exist);
class user
{
	friend vector<user> read_user();     //read the data from user_data.txt
	friend void save_user(vector<user> v_user);     //save the data as a file(user_data.txt)
	friend vector<user> delete_user(vector<user> v_user);     //delete a user
protected:
	string user_name;
	string user_password;
	int user_id;
public:
	user(string User_name, string User_password, int User_id);     //normal constructor
	//getter and setter
	string get_user_name();
	string get_user_password();
	int get_user_id();
	void set_user_name(string u_name);
	void set_user_password(string u_password);
	void set_user_id(int u_id);
};

#endif