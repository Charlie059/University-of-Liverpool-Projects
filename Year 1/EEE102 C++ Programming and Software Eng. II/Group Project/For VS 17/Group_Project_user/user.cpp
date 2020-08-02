//=======================
//		user.cpp
//=======================

#include "user.h"

user::user(string User_name, string User_password, int User_id)
{
	user_name = User_name;
	user_password = User_password;
	user_id = User_id;
}

string user::get_user_name()
{
	return user_name;
}

string user::get_user_password()
{
	return user_password;
}

int user::get_user_id()
{
	return user_id;
}

void user::set_user_name(string u_name)
{
	user_name = u_name;
}

void user::set_user_password(string u_password)
{
	user_password = u_password;
}

void user::set_user_id(int u_id)
{
	user_id = u_id;
}

vector<user> read_user()
{
	//read the data from movie_data.txt
	user theuser = user("Not Given", "Not Given", 0);
	vector<user> v_user;
	char read[50];
	string strread;
	int id;
	int counter = 0;
	ifstream if_read1("user_data.txt");
	ifstream if_read2("user_data.txt");
	//Because a user with four lines to record in file, the first three of the four lines corresponding to the user name, the user password and user ID, line 4 OOOOOO(6 capital letter O) is used for marking, the for loop is used to count how many lines of OOOOOO, how many rows OOOOOO, file record how many user's information, because here i < 40000, so it can record 10000 users of the information (4 * 100000 = 40000, you can change the 40000 older, so a little more).
	for (int i = 0; i < 40000; i++){
		if_read1.getline(read, 50);
		strread = read;
		if (strread == "OOOOOO"){
			counter++;
		}
	}
	if_read1.close();
	//read data from user_data.txt
	for (int i = 0; i < (4 * counter); i = i + 4){
		if_read2.getline(read, 50);
		strread = read;
		theuser.set_user_name(strread);

		if_read2.getline(read, 50);
		strread = read;
		theuser.set_user_password(strread);

		if_read2.getline(read, 50);
		strread = read;
		stringstream ss(strread);
		ss >> id;
		theuser.set_user_id(id);

		if_read2.getline(read, 50);

		v_user.push_back(theuser);
	}
	if_read2.close();
	return v_user;
}

void save_user(vector<user> v_user){
	//save the data as a file
	ofstream of_save("user_data.txt");
	for (int i = 0; i < v_user.size(); i++){
		of_save << v_user[i].get_user_name() << endl;
		of_save << v_user[i].get_user_password() << endl;
		of_save << v_user[i].get_user_id() << endl;
		of_save << "OOOOOO" << endl;
	}
	of_save.close();
}

vector<user> delete_user(vector<user> v_user)
{
	int input;
	int success = 0;
	vector<int> number;
	for (int i = 0; i < v_user.size(); i++){
		number.push_back(v_user[i].get_user_id());
	}
	if (v_user.size() == 0){
		cout << "You have not added the user yet." << endl;
	}
	else{
		cout << "The user list:" << endl;
		for (int i = 0; i < v_user.size(); i++){
			cout << (i + 1) << endl;
			cout << "  User name: " << v_user[i].get_user_name() << endl;
			cout << "  User password: " << v_user[i].get_user_password() << endl;
			cout << "  User ID: " << v_user[i].get_user_id() << endl;
			cout << endl;
		}
		cout << "If you want to delete a user from the user list, please input the number: ";
		cin >> input;
		do{
			if (input > v_user.size()){
				cout << "Please input again: ";
				cin >> input;
				success = 0;
			}
			else{
				success = 1;
			}
		} while (success != 1);
		int i = 0;
		for (auto it = v_user.begin(); it != v_user.end(); it++){
			if (v_user[i].get_user_id() == number[input - 1]){
				it = v_user.erase(it);
				cout << "The deletion is successful!" << endl;
				if (it == v_user.end()) break;
			}
			i++;
		}
	}
	return v_user;
}

void operate_user()
{
	user theuser = user("Not Given", "Not Given", 0);
	vector<user> v_user;
	v_user = read_user();
	int judge = 0;
	do{
		string input_name;
		string input_password;
		int input_id;
		cout << "Please input a number to select:" << endl;
		cout << "1. Add a user" << endl;
		cout << "2. Delete a user" << endl;
		cout << "3. View user list" << endl;
		cout << "4. Exit" << endl;
		int select;
		cin >> select;
		switch (select){
		//add a user
		case 1:
			system("pause");
			system("cls");
			cout << "Please input user name: ";
			getline(cin, input_name);
			getline(cin, input_name);
			cout << "Please input user password: ";
			getline(cin, input_password);
			//getline(cin, input_password);
			cout << "Please input user ID (Only integer number): ";
			cin >> input_id;
			theuser.set_user_name(input_name);
			theuser.set_user_password(input_password);
			theuser.set_user_id(input_id);
			v_user.push_back(theuser);
			save_user(v_user);     //save data into user_data.txt
			cout << "The add is successful!" << endl;
			system("pause");
			system("cls");
			break;
		//delete a user
		case 2:
			system("pause");
			system("cls");
			v_user = delete_user(v_user);
			save_user(v_user);     //save data into movie_data.txt
			system("pause");
			system("cls");
			break;
		//display user list
		case 3:
			system("pause");
			system("cls");
			if (v_user.size() == 0){
				cout << "You have not added the user yet." << endl;
			}
			else{
				cout << "The user list:" << endl;
				for (int i = 0; i < v_user.size(); i++){
					cout << (i + 1) << endl;
					cout << "  User name: " << v_user[i].get_user_name() << endl;
					cout << "  User password: " << v_user[i].get_user_password() << endl;
					cout << "  User ID: " << v_user[i].get_user_id() << endl;
					cout << endl;
				}
			}
			system("pause");
			system("cls");
		//exit
		case 4:
			judge = 1;
			system("pause");
			system("cls");
			break;
	    //when the input number is not 1~4, you can enter it again
		default:
			cout << "Please input again." << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (judge != 1);
}

void showUsers() {	//A loop to show all users
	vector<user> userList;
	userList = read_user();
	for (int i = 0; i < userList.size(); i++) {
		cout << "  User name: " << userList[i].get_user_name() <<"  User password: " << userList[i].get_user_password() <<"  User ID: " << userList[i].get_user_id() << endl;
	}
}

void searchUser(string Sname) {		//Search user by name. This function was for admin so it could show all information and all user in this name
	vector<user> userList;
	userList = read_user();
	bool searchFlag = false;
	for (int i = 0; i < userList.size(); i++) {
		if (userList[i].get_user_name() == Sname) {
			cout << "  User name: " << userList[i].get_user_name() << "  User password: " << userList[i].get_user_password() << "  User ID: " << userList[i].get_user_id() << endl;
			searchFlag = true;
		}
		if (!searchFlag)cout << "No result in this name." << endl;
	}
}

int userLogin() {			//Log in function, return user ID (unique) when success and -1 when failed, create a user if need.
	vector<user> userList;
	userList = read_user();	//The programmer of user class made this to read all info into the vector
	int vecPosition;
	int uID;
	string uPassWord;
	string uName;
	string sTemp;
	bool userExist = false;
	cout << "Input your accont ID: (Input unexist ID to create user)" << endl;
	bool inputValid = false;	//Flag to check if input were all digit
	while (!inputValid) {
		inputValid = true;
		getline(cin, sTemp);
		for (int i = 0; i < sTemp.length(); i++) {
			if (sTemp[i] < 48 || sTemp[i]>57) inputValid = false;
		}
		if (!inputValid) cout << "Input Invalid" << endl;
	}
	//Convert string input to integer
	stringstream ss;
	ss << sTemp;
	ss >> uID;
	ss.clear();
	//User this function to locate the user in the vector.
	vecPosition = userIDsearch(uID, userExist);
	if (userExist) {		//If the user exist, ask and check the password
		cout << "Input your password to Login:" << endl;
		getline(cin, uPassWord);
		if (userList[vecPosition].get_user_password() == uPassWord) {
			cout << "Login Success" << endl;
			system("PAUSE");
			return uID;
		}
		else {
			cout << "Login Failed" << endl;
			system("PAUSE");
			return -1;
		}
	}
	else {				//If ID does not exit, ask if the customer want to create a user
		cout << "ID does not exist, do you want to create one in this ID? [1 for YES or else for NO]" << endl;
		int cmd = _getch();
		string input_name;
		string input_password;
		if (cmd == '1') {
			//This part was from the user class's programmer. Maybe two times of get name was for prevent error
			system("pause");
			system("cls");
			cout << "Please input user name: ";
			getline(cin, input_name);
			getline(cin, input_name);
			cout << "Please input user password: ";
			getline(cin, input_password);
			//getline(cin, input_password);
			
			user newUser(input_name, input_password, uID);

			userList.push_back(newUser);
			save_user(userList);     //save data into user_data.txt
			cout << "The add is successful!" << endl;
			system("pause");
			system("cls");
			return uID;
		}
		else return -1;
	}
}

int userIDsearch(int uID,bool &exist) {		//Check user ID and locate the user in the vector
	vector<user> userList;
	userList = read_user();
	for (int i = 0; i < userList.size(); i++) {
		if (userList[i].get_user_id() == uID) {
			exist = true;
			return i;
		}
	}
	return -1;
}