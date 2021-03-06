//==================================
//		Group_Project_user.cpp
//==================================
/*

==Problem Part==============================
1.When display room's timetable, it was better to add a notice instead of nothing after "timetable"		--Not fixed, i mean if No.4 room have no movie, the output was:
																										Room 4's Timetable:

																										Room 5's Timetalbe:
																										--I think it should be:
																										Room 4: No movie arranged
																										Room 5's Timetable:
																										OK, I fixed
2.Cretical format problem in user interface:
	a>When checking bought seats, no notice displayed and PAUSE used twice			--No matter who's code, I just list problem, fix or not was not on me.
	b>When selecting seat, screen should set to max size							--fixed, DO NOT USE STRANGE OPERATION PLEASE
	c>When selecting seat, user need to count rows by themselves, I think there should be labels	--Done, please check the code for further change
3.Please check the task sheet for manager's view. If you think "such as" does not count, that's OK.(I think may be could add functions like admin)		--No need for a menu, just print them all
4.Program crashed when trying to delete the venue does not exit, please add input verify	--Yes it worked, but please add a notice....

Updated 2019/05/19 16:57
*/


#include "movie.h"
#include "user.h"
#include "Room.h"
#include "conio.h"
#include "windows.h"

vector<user> customer;
using namespace std;

vector<vector<movieTime>> TimeTableVec;
vector<Room> roomVec;
void add_room(int room_type);
void delete_room(int arrary_number);
void buy(int user_id_sort);
void readAllRoom();
void saveRoomInfo();
int commandInput(int min, int max);
int readFlie_times();
int checkAllMoney();


void room_and_movieTime_itialization() {
	int time = readFlie_times();
	//Movie time itialization
	for (int i = 0; i < time; i++)
	{
		vector<movieTime> roomTimeTableVec;
		TimeTableVec.push_back(roomTimeTableVec);
	}
	//Room 
	for (int i = 0; i < time; i++)
	{
	
		
			Room room(0, i, TimeTableVec[i]);
			roomVec.push_back(room);
		
	}

	if (time == 0)
	{
		cout << "There are no rooms, system will auto create 8 rooms" << endl;
		for (int i = 0; i < 8; i++)
		{
			vector<movieTime> roomTimeTableVec;
			TimeTableVec.push_back(roomTimeTableVec);
		}
		//Room 
		for (int i = 0; i < 8; i++)
		{


			Room room(0, i, TimeTableVec[i]);
			roomVec.push_back(room);

		}
	}

}

int main()
{	
	HWND hwnd = GetForegroundWindow();	//Set handle to front window
	ShowWindow(hwnd, SW_MAXIMIZE);		//Maximum the window size

	room_and_movieTime_itialization();

	customer = read_user();
	
	readAllRoom();

	// This is the [1st LEVEL Menu], switching system mode to provide 3 different kind of user with specific functions.
	cout << "===========================" << endl;
	cout << "Movie system activating:" << endl << endl;
	cout << "Please set system mode:" << endl;

	cout << "1.\t Admain Login." << endl;
	cout << "2.\t Manager Login." << endl;
	cout << "3.\t Customer Mode." << endl;
	cout << "===========================" << endl;

	int Smode = commandInput(1, 3);
	system("cls");

	int command;
	string Sname;
	int command2;
	int userID;
	bool userSituation = true;
	string stTemp;

	//All the running code were in the while(1) that means the system will keep running until user chose to Exit
	while (1) {
		switch (Smode) {
		case 1:
			//This is the [2nd LEVEL Menu---For Admin],provide complex update and search function
			cout << "==============Administrator mode:===============" << endl;
			cout << "1.\t Complex Update." << endl;
			cout << "2.\t Search Movie." << endl;
			cout << "3.\t Search Rooms." << endl;
			cout << "4.\t Check Customers." << endl;
			cout << "5.\t Change System Mode." << endl;
			cout << "6.\t Exit." << endl;
			cout << "================================================" << endl;
			cout << "Please input your command:" << endl << endl;
			command = commandInput(1, 6);

			//[3rd LEVEL Menue---For Admin], provide complex update choices
			switch (command) {
			case 1:
				cout << "===============Complex Update=================" << endl;
				cout << "1. Update Movies." << endl;
				cout << "2. Update Room." << endl;
				cout << "3. Update Customer Informateion." << endl;
				cout << "4. Update Rooms' Movie Timetable" << endl;
				cout << "==============================================" << endl;
				command2 = commandInput(1, 4);
				switch (command2) {
				case 1:
					operate_movie();	//Other's function to complex update movie, include a 4th menu
					break;
				case 2:					//Choose a room from the list and do the operate
					cout << "Which room do you want to operate? (Input a 1 greater number to add room))" << endl;
					for (int i = 0; i<roomVec.size(); i++) {
						roomVec[i].RoomTimeTableShown();
					}
					cout << endl;
					command2 = commandInput(0, roomVec.size());
					if (command2 != roomVec.size()) {
						cout << "How do you want to modify?" << endl;
						cout << "1. Delete" << endl;
						cout << "2. Change room size" << endl;
						cout << "3. No change" << endl << endl;
						switch (commandInput(1, 3)) {
						case 1:
							delete_room(command2);
							cout << "Room deleted." << endl;
							break;
						case 2:
							if (roomVec[command2].RoomTypeGetter()) {
								cout << "Room size changed to SMALL" << endl;
								roomVec[command2].RoomTypeSetter(0);
							}
							else {
								cout << "Room size changed to LARGE" << endl;
								roomVec[command2].RoomTypeSetter(1);
							}
							break;
						case 3:			//This choice was added because sometimes the user may not want to change anything
							cout << "No change was made" << endl;
							break;
						}
						system("PAUSE");
					}
					else {
						cout << "What room size do you want?(0 for small and 1 for large)" << endl;
						add_room(commandInput(0,1));
						cout << "Room Added" << endl;
						system("PAUSE");
					}
					break;
				case 3:
					operate_user();		//Other's function to complex update users, include a 4th menu
					break;
				case 4:					//Arrange movie for a room. Functions were provided, this is only a interface
					for (int i = 0; i < roomVec.size(); i++) {
						roomVec[i].RoomTimeTableShown();
					}
					cout << "Choose the room you want to operate" << endl;
					command2 = commandInput(0, roomVec.size()-1);

					cout<<endl << "1. Arrange the venue" << endl;
					cout << "2. Delete the venue" << endl << endl;;

					switch (commandInput(1,2)) {
					case 1:
						roomVec[command2].arrange_the_venue();
						break;
					case 2:
						roomVec[command2].delete_the_venue();
						break;
					default:
						//This will not happen because "commandInput()" does not allow invalid input
						cout << "#ERROR Command invalid" << endl;
						break;
					}
				}
				break;
			case 2:		//Function of searching movie
				cout << "Input movie name you want to search:" << endl;
				getline(cin, Sname);
				cout << endl;
				searchMovie(Sname);
				system("PAUSE");
				break;
			case 3:		//Function of showing room timetable. Function provided.
				cout << "Input Room Number:" << endl;
				roomVec[commandInput(0,roomVec.size()-1)].RoomTimeTableShown();
				system("PAUSE");
				break;
			case 4:		//Function of searching customers
				cout << "===========================" << endl;
				cout << "1. Show all customers." << endl;
				cout << "2. Search specific customer." << endl;
				cout << "============================" << endl;
				command2 = commandInput(1, 2);
				switch (command2) {
				case 1:
					showUsers();
					break;
				case 2:
					cout << "Input the name for searching:" << endl;
					getline(cin, Sname);
					searchUser(Sname);
					break;
				default:
					cout << "#ERROR command invalid";
					break;
				}
				system("PAUSE");
				break;
			case 5:		//Reset [1st LEVEL Menu] to change system interface
				cout << "Please set system mode:" << endl;

				cout << "1.\t Admain Login." << endl;
				cout << "2.\t Manager Login." << endl;
				cout << "3.\t Customer Mode." << endl << endl;

				Smode = commandInput(1, 3);
				break;
			case 6:		//This is only correct way provided for exit the program
				exit(0);
			default:
				cout << "#ERROR: Command Invalid" << endl;
				break;
			}
			break;
		case 2:
			//Since manager only need to know how much he earned. System mode 2 for manager only display income and then turn to switch system mode
			cout << "============Manager mode==============" << endl;
			cout << "This is today's income:" << endl << endl;
			cout<< checkAllMoney()<<endl;

			cout << "=================================" << endl;
			cout << "Please set system mode:" << endl;

			cout << "1.\t Admain Login." << endl;
			cout << "2.\t Manager Login." << endl;
			cout << "3.\t Customer Mode." << endl << endl;

			Smode = commandInput(1, 3);
			break;
		case 3:
			//This is [2nd LEVEL Menu---For customers]
			cout << "=========User Mode Activating===========" << endl;
			userID = userLogin();		//Log in function. Return user ID when log in succeed, or return -1. Creating user also done here
			userSituation = true;		//Keep the loop running until user log out. Or the user will need to log in after each operation
			if (userID == -1) break;
			while (userSituation) {		//Keep in loop until log out
				system("cls");
				cout << "=========User Mode Activating===========" << endl;
				cout << "User: " << userID << " Logged in." << endl << endl;
				cout << "1. Show book list" << endl;
				cout << "2. Book seat" << endl;
				cout << "3. Log Out" << endl;
				cout << "4. Change System Mode" << endl << endl;;
				command2 = commandInput(1, 4);
				switch (command2) {
				case 1:
					for (int i = 0; i < roomVec.size(); i++)
					{

						for (int j = 0; j < roomVec[i].roomTimeTableGetterVec().size(); j++)
						{

							int seat_arr[750] = {};
							int counter = 0;
							for (int width = 0; width < 25; width++)
							{

								for (int length = 0; length < 30; length++)
								{
									int seat_id = roomVec[i].roomTimeTableGetterVec()[j].seat[width][length];
									seat_arr[counter] = seat_id;
									counter++;
								}
							}


							for (int w = 0; w < 750; w++)
							{
								if (seat_arr[w] == userID)
								{
									cout << "**************" << endl;
									cout << "User " << userID << "      Room " << i << "   The " << j + 1 << "'s movie" << endl;
									cout<<"The seat "<< "Row "<<(int)w / 30 + 1 <<" and" <<"Colum "<<  w % 30 + 1 <<endl;
								}

							}

						


						}
						

					}
						





					system("PAUSE");
					break;
				case 2:		//Provided functionn for buy ticket, require attribute of userID
					buy(userID);
					system("PAUSE");
					break;
				case 3:		//Change the situation to false to stop the loop
					userSituation = false;
					cout << "Log out success" << endl;
					break;
				case 4:		//If a customer want to change mode, a password was required
					cout << "Input System Password: (Default set as 741852963)" << endl;
					getline(cin, stTemp);
					if (stTemp == "741852963") {
						cout << "Please set system mode:" << endl;

						cout << "1.\t Admain Login." << endl;
						cout << "2.\t Manager Login." << endl;
						cout << "3.\t Customer Mode." << endl << endl;

						Smode = commandInput(1, 3);
						userSituation = false;
					}
					else {
						cout << "Wrong Password" << endl;
					}
					break;
				default:
					cout << "#ERROR Command invalid" << endl;
					break;
				}
				system("PAUSE");
			}
			break;
		}
		system("cls");
		saveRoomInfo();
	}
	

	return 0;
}

void buy(int user_id_sort)
{
	customer = read_user();
	int numOFroom;
	int row;
	int column;
	for (int i = 0; i < roomVec.size(); i++)
	{
		roomVec[i].RoomTimeTableShown();
	}

	cout<<endl << "Please input the number of Room: (Start form 0)";
	int room_num = commandInput(0, roomVec.size() - 1);
	cout <<endl<< "Please input the number of movie: " << endl;
	int venue_num = commandInput(1, roomVec[room_num].roomTimeTableGetterVec().size());
	bool exist;

	bool whether_limation = roomVec[room_num].ticket_limation(venue_num - 1, user_id_sort);
	if (whether_limation ==true)
	{
		cout << "****************************" << endl;
		cout << "Tickets out of limatation, you can not buy anymore" << endl;
	}
	else
	{
		roomVec[room_num].print_the_seat(venue_num - 1);
		bool success_flag = false;
		do
		{
			cout << "Please input row: " << endl;
			cin >> row;
			cout << endl << "Please input column: "<<endl;
			cin >> column;



		} while (roomVec[room_num].write_seat_info(venue_num - 1, row - 1, column - 1, customer[userIDsearch(user_id_sort, exist)].get_user_id()) == false);
		cout << "PURCHASE SUCCESS" << endl;
	}
	




}



int readFlie_times() {
	int room_num = 0;
	bool open_flag = true;
	do
	{
		string name = "Room_data.txt";

		char str[1];
		stringstream ss;
		ss << room_num;
		string s1 = ss.str();



		name = s1 + name;

		ifstream file;
		file.open(name);

	
		if (!file.is_open())
		{
			open_flag = false;
		}

			

		file.close();
		room_num++;
	} while (open_flag == true);
	
	return room_num-1;
}


void readAllRoom() {
	int times = readFlie_times();

	for (int i = 0; i < times; i++)
	{
		roomVec[i].read_room_info(i);
	}
}

void saveRoomInfo() {
	for (int i = 0; i < roomVec.size(); i++)
	{
		roomVec[i].save_room_info(i);
	}
}

//Delete the room yopu want, arrary number start from 0
void delete_room(int arrary_number) {

		TimeTableVec.erase(TimeTableVec.begin() + arrary_number);
		roomVec.erase(roomVec.begin() + arrary_number);
	

	
	
}
//Add room you want, however you need to add roomType
void add_room(int room_type) {
	vector<movieTime> roomTimeTableVec;
	TimeTableVec.push_back(roomTimeTableVec);
	Room room(room_type,roomVec.size(), TimeTableVec[TimeTableVec.size() - 1]);
	roomVec.push_back(room);
}

int commandInput(int min, int max) {
	char command = _getch();
	int result = command - 48;
	while (result<min || result > max) {
		cout << "Input invalid" << endl;
		command = _getch();
		result = command - 48;
	}
	return result;
}


int checkAllMoney() {
	int allMoney = 0;
	for (int i = 0; i < roomVec.size(); i++)
	{
		for (int j = 0; j < roomVec[i].roomTimeTableGetterVec().size(); j++)
		{
			int price = roomVec[i].roomTimeTableGetterVec()[j].moviePrice;
			int couter_people = 0;

			int seat_arr[750] = {};
			int counter = 0;
			for (int k = 0; k < 25; k++)
			{

				for (int w = 0; w < 30; w++)
				{
					int seat_id = roomVec[i].roomTimeTableGetterVec()[j].seat[k][w];

					seat_arr[counter] = seat_id;
					counter++;
				}
			}



			for (int k = 0; k < 750; k++)
			{
				if (seat_arr[k] !=0)
				{
					couter_people++;
				}

				
			}

			allMoney = allMoney + price * couter_people;

		}

	}
	return allMoney;
}