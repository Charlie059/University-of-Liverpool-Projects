#pragma once
#include <iostream>
#include "movie.h"
#include "user.h"
#include <vector>

#include <iomanip>
using namespace std;


struct movieTime {
	int moviePrice;
	int movieID;
	string movieName;
	int movieStartTime;

	int seat[25][30] = {};
};
bool com_vec(int a, vector<int> b);
int frequency(int ar[], int n, int element);
class Room
{
private:
	int roomType;
	// smallroom == 0, bigroom == 1

	enum roomType
	{
		smallroom,
		bigRoom
	};
	int roomNumber;



	vector <movieTime> movieTimeVec;

public:
	Room(int RoomType, int RoomNumber, vector <movieTime> MovieTimeVec);
	~Room();

	//Room type Setter and Getter
	int RoomTypeGetter();
	void RoomTypeSetter(int);

	//Print room's timeTable ofa movie
	void RoomTimeTableShown();

	//Set room's timeTable
	movieTime roomTimeTableSetter(int moviePrice, int movieId, string movieName, int movieStartTime, int seat[25][30]);//Single timetable setter for one room

	//Put the movieTime(struct) into the vector which stores the movieTime
	void roomTimeTableSetterVec(movieTime);

	//Return the vector which stores the movieTime
	vector <movieTime> roomTimeTableGetterVec();

	//One step to arrange or delete room's venue 
	void arrange_the_venue();// Arrange the venue
	void delete_the_venue();//motify the venue

	//Set the seat to the room(user.buy may use it)
	bool write_seat_info(int number, int x, int y, int user_id);

	//Print one venue of all the seats(0 for nobody brought, id for someone has bought)
	void print_the_seat(int);

	//Save and Read
	void save_room_info(int room_num);
	void read_room_info(int room_num);

	//Consider whether user has brought 5 ticket
	bool ticket_limation(int venue,  int user_id);

};

