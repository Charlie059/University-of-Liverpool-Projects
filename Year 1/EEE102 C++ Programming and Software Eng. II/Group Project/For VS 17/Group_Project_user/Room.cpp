
#include "Room.h"


Room::Room(int RoomType, int RoomNumber, vector <movieTime> MovieTimeVec)
{
	roomType = RoomType;
	roomNumber = RoomNumber;
	movieTimeVec = MovieTimeVec;
}


Room::~Room()
{
}


int Room::RoomTypeGetter() {
	return roomType;
}

void Room::RoomTypeSetter(int type) {
	roomType = type;
}


movieTime Room::roomTimeTableSetter(int moviePrice, int movieId, string movieName, int movieStartTime, int seat[25][30]) {
	movieTime roomTimeTable;
	roomTimeTable.movieID = movieId;
	roomTimeTable.movieName = movieName;
	roomTimeTable.movieStartTime = movieStartTime;//Full time 0-24
	roomTimeTable.moviePrice = moviePrice;
	return roomTimeTable;
}

void Room::roomTimeTableSetterVec(movieTime MovieTime) {
	movieTimeVec.push_back(MovieTime);
}


vector <movieTime> Room::roomTimeTableGetterVec() {
	return movieTimeVec;
}

void Room::RoomTimeTableShown() {
	cout << setfill('=') << setw(70) << "=" << endl << setfill(' ');
	if (movieTimeVec.size()) {
		cout << "Number " << roomNumber << "'s room TimeTable" << endl;
		cout << setfill('-') << setw(70) << "-" << endl << setfill(' ');
	}
	else {
		cout << "Number " << roomNumber << "'s room has no movie arranged." << endl;
	}

	for (int i = 0; i < movieTimeVec.size(); i++)
	{
		cout << i + 1 << ". Movie Id  " << movieTimeVec[i].movieID << "  " << "  Movie Name  " << movieTimeVec[i].movieName << "  Movie Start  " << movieTimeVec[i].movieStartTime << ":00 " << "Price " << movieTimeVec[i].moviePrice << endl;
	}
	cout << endl ;
}


void Room::arrange_the_venue() {
	movie themovie = movie("Not Given", 0, 0);
	vector<movie> v_movie;
	vector <int>timeArr;//Collect the Time
	v_movie = read_movie();
	if (v_movie.size() == 0) {
		cout << "You have not added the movie yet." << endl;
	}
	else {
		cout << "The movie list:" << endl;
		for (int i = 0; i < v_movie.size(); i++) {
			cout << (i + 1) << " Movie name: " << v_movie[i].get_movie_name() << endl;
			cout << "  Movie duration: " << v_movie[i].get_movie_duration() << " minutes" << endl;
			cout << "  Movie ID: " << v_movie[i].get_movie_id() << endl;
		}

	}
	bool success = 0;
	bool successAdding = 1;//inline success
	do {
		cout << "Which movie would you want to add in room " << roomNumber << endl;
		cout << "Enter movie number to add" << endl;
		int number = 0;

		int time = 0;
		do
		{

			cin >> number;

			cout << endl << "What time do you want to arrange this movie" << endl;
			cout << "Only even integer time is support. Eg: 8" << endl;
			cin >> time;

			if (number > v_movie.size() || number <= 0 || time > 24 || time < 0 || time % 2 != 0)
			{
				cout << "Out of limition, enter again!" << endl;
				cout << "Enter movie number to add" << endl;
			}
			else
			{

				vector <int> vec;

				for (int i = 0; i < movieTimeVec.size(); i++)
				{
					vec.push_back(movieTimeVec[i].movieStartTime);
				}
				if (com_vec(time, vec))
				{
					cout << "This time is not support to add" << endl;
					successAdding = 0;
				}

				for (int i = 0; i < timeArr.size(); i++)
				{
					if (timeArr[i] == time)
					{
						cout << "This time is not support to add" << endl;
						successAdding = 0;
					}


				}

				if (successAdding == true)
				{
					timeArr.push_back(time);
				}



			}




		} while (number > v_movie.size() || number <= 0 || time > 24 || time < 0 || time % 2 != 0);
		int price = 0;
		if (successAdding == 1)
		{
			cout << endl << "What price do you want to set for one seat?" << endl;

			cin >> price;//Price Setter
		}


		movieTime roomTimeTable;


		if (successAdding == true)
		{
			roomTimeTable.movieID = v_movie[number - 1].get_movie_id();
			roomTimeTable.movieName = v_movie[number - 1].get_movie_name();
			roomTimeTable.movieStartTime = timeArr.back();//Full time 0-24
			roomTimeTable.moviePrice = price;
			movieTimeVec.push_back(roomTimeTable);
		}





		successAdding = 1;//recover the bool


		cout << endl<< "Are you finish adding? Yes for 1 No for 2" << endl;
		int selection = 0;
		cin >> selection;
		if (selection == 1)
		{
			success = 1;
		}
		else if (selection == 2)
		{
			success = 0;
		}
		else { success = 1; }

	} while (success == 0);


}



void Room::delete_the_venue() {

	cout << "Number " << roomNumber << "'s TimeTable" << endl;
	for (int i = 0; i < movieTimeVec.size(); i++)
	{
		cout << i + 1 << "Movie Id  " << movieTimeVec[i].movieID << "  " << "  Movie Name  " << movieTimeVec[i].movieName << "  Movie Start  " << movieTimeVec[i].movieStartTime << ":00 " << endl;
	}
	cout << "Which number do you want to delete" << endl;

	int selection;
	cin >> selection;

	//	movieTimeVec
	if (movieTimeVec.size()>selection)
	{
		movieTimeVec.erase(movieTimeVec.begin() + selection - 1);
	}
	else
	{
		cout << "CHECK VLUE" << endl;
	}


}


void Room::save_room_info(int room_num) {

	//save the data as a file
	string name = "Room_data.txt";

	char str[1];
	stringstream ss;
	ss << room_num;
	string s1 = ss.str();



	name = s1 + name;
	ofstream of_save(name);

	of_save << roomType << endl;
	of_save << 0 << endl;

	for (int i = 0; i < movieTimeVec.size(); i++) {
		of_save << movieTimeVec[i].movieID << endl;
		of_save << movieTimeVec[i].movieName << endl;
		of_save << movieTimeVec[i].movieStartTime << endl;
		of_save << movieTimeVec[i].moviePrice << endl;
		for (int j = 0; j < 25; j++)
		{
			for (int k = 0; k < 30; k++)
			{
				of_save << movieTimeVec[i].seat[j][k] << endl;
			}
		}

	}


	of_save.close();
}

int strToInt(string str) {
	return stoi(str);
}
void Room::read_room_info(int room_num) {
	ifstream text;
	string name = "Room_data.txt";

	char str[1];
	stringstream ss;
	ss << room_num;
	string s1 = ss.str();


	name = s1 + name;
	text.open(name, ios::in);
	vector<string> strVec;
	while (!text.eof()) {
		string inbuf;
		getline(text, inbuf, '\n');
		strVec.push_back(inbuf);
	}

	int movieTime_value = strVec.size();


	movieTime_value = (movieTime_value - 3) / 754;


	for (int i = 0; i < movieTime_value; i++)
	{
		movieTime mV;
		int seat[25][30] = {};
		mV.movieID = strToInt(strVec[2 + i * 754]);
		mV.movieName = strVec[3 + i * 754];
		mV.movieStartTime = strToInt(strVec[4 + i * 754]);
		mV.moviePrice = strToInt(strVec[5 + i * 754]);
		int counter = 0;

		for (int j = 0; j < 25; j++)
		{

			for (int k = 0; k < 30; k++)
			{
				seat[j][k] = strToInt(strVec[6 + counter + i * 754]);
				counter++;
			}

		}

		for (int i = 0; i < 25; i++)
		{

			for (int j = 0; j < 30; j++)
			{
				mV.seat[i][j] = seat[i][j];
			}
		}


		movieTimeVec.push_back(mV);

	}




}




//Read the data for the specified row

bool Room::write_seat_info(int number, int x, int y, int user_id) {

	if (roomType == 0)
	{

		if (x > 15 || y > 20)
		{
			cout << "Invaild Value" << endl;
			return false;
		}
		else if (movieTimeVec[number].seat[x][y] != 0)
		{
			cout << "Invaild Value, this seat has been bought" << endl;
			return false;
		}
		else
		{
			movieTimeVec[number].seat[x][y] = user_id;
			return true;
		}



	}
	else
	{
		if (x > 25 || y > 30)
		{
			cout << "Invaild Value" << endl;
			return false;
		}
		else if (movieTimeVec[number].seat[x][y] != 0)
		{
			cout << "Invaild Value, this seat has been bought" << endl;
			return false;
		}
		else
		{
			movieTimeVec[number].seat[x][y] = user_id;
			return true;
		}
	}


}


void Room::print_the_seat(int movieTime) {

	//This part was changed for better code format and output format
	int wordDistance = 3;	//The place left for print seat. Not printing user name now so it could be smaller (no need for 8)
	cout << "0 you can buy, 1 you can not buy" << endl;
	int imax, jmax;
	if (roomType) {
		imax = 25;
		jmax = 30;
	}
	else {
		imax = 15;
		jmax = 20;
	}
	//Print Horizental label
	cout << "    ";
	for (int j = 0; j < jmax; j++) {
		cout << setw(wordDistance) << j;
	}
	cout << endl;
	for (int j = 0; j < jmax+1; j++) {
		cout << setfill('-') << setw(wordDistance) << "-";
	}
	cout << setfill(' ') << endl;

	for (int i = 0; i < imax; i++)
	{
		cout << setw(2) << i << "| ";
		for (int j = 0; j < jmax; j++)
		{
			if (movieTimeVec[movieTime].seat[i][j] == 0)
			{
				 cout << setw(wordDistance) << "0";
			}
			else
			{
				cout << setw(wordDistance) << "1";
			}
	//		cout << setw(8)<<movieTimeVec[movieTime].seat[i][j];
		}
		cout << endl;
	}
}

bool com_vec(int a, vector<int> b) {


	for (int j = 0; j < b.size(); j++)
	{
		//Using two for loop to find each vector whether they have same compoment
		if (a == b[j])
		{
			return true;
			break;
			//If it find the same, then stop the one inner loop
		}


	}

	return false;

}


bool Room::ticket_limation(int venue,int user_id) {
    int seat_arr[750] = {};
	int counter = 0;
	for (int i = 0; i < 25; i++)
	{

		for (int j = 0; j < 30; j++)
		{
			int seat_id = movieTimeVec[venue].seat[i][j];

			seat_arr[counter] = seat_id;
			counter++;
		}
	}
	

	if (frequency(seat_arr, 750, user_id) >= 5)
	{

		return true;
	}
	else
	{
		return false;
	}

}


int frequency(int ar[], int n, int element)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (element == ar[i])
		{
			count++;
		}
	}
	return count;
}