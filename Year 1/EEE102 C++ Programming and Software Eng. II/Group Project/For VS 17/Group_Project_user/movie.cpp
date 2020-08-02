//=======================
//		movie.cpp
//=======================

#include "movie.h"

movie::movie(string Movie_name, int Movie_duration, int Movie_id)
{
	movie_name = Movie_name;
	movie_duration = Movie_duration;
	movie_id = Movie_id;
}

string movie::get_movie_name()
{
	return movie_name;
}

double movie::get_movie_duration()
{
	return movie_duration;
}

int movie::get_movie_id()
{
	return movie_id;
}

void movie::set_movie_name(string m_name)
{
	movie_name = m_name;
}

void movie::set_movie_duration(double m_duration)
{
	movie_duration = m_duration;
}

void movie::set_movie_id(int m_id)
{
	movie_id = m_id;
}

vector<movie> read_movie()
{
	//read the data from movie_data.txt
	movie themovie = movie("Not Given", 0, 0);
	vector<movie> v_movie;
	char read[200];    //movie name cannot be longer than 200
	string strread;
	double duration;
	int id;
	int counter = 0;
	ifstream if_read1("movie_data.txt");
	ifstream if_read2("movie_data.txt");
	//As a movie file to record with 4 lines, the first three of the four lines corresponding to the name of the movie, movie time and film ID, line 4 OOOOOO (6 capital letter O) is used for marking, the for loop is used to count how many lines of OOOOOO, how many rows OOOOOO, file record how much of the movie, because here i < 400, so it can record 50 film (4 * 100 = 400, you can change the 400 a bit bigger, so it can record more data).
	for (int i = 0; i < 400; i++){
		if_read1.getline(read, 200);
		strread = read;
		if (strread == "OOOOOO"){
			counter++;
		}
	}
	if_read1.close();
	//This for loop is the one that really starts reading the contents of the file.
	for (int i = 0; i < (4 * counter); i = i + 4){
		if_read2.getline(read, 200);
		strread = read;
		themovie.set_movie_name(strread);

		if_read2.getline(read, 200);
		strread = read;
		stringstream ss1(strread);
		ss1 >> duration;
		themovie.set_movie_duration(duration);

		if_read2.getline(read, 200);
		strread = read;
		stringstream ss2(strread);
		ss2 >> id;
		themovie.set_movie_id(id);

		if_read2.getline(read, 200);

		v_movie.push_back(themovie);
	}
	if_read2.close();
	return v_movie;
}

void save_movie(vector<movie> v_movie)
{
	//save the data as a file
	ofstream of_save("movie_data.txt");
	for (int i = 0; i < v_movie.size(); i++){
		of_save << v_movie[i].get_movie_name() << endl;
		of_save << v_movie[i].get_movie_duration() << endl;
		of_save << v_movie[i].get_movie_id() << endl;
		of_save << "OOOOOO" << endl;
	}
	of_save.close();
}

vector<movie> delete_movie(vector<movie> v_movie)
{
	int input;
	int success = 0;
	vector<int> number;
	for (int i = 0; i < v_movie.size(); i++){
		number.push_back(v_movie[i].get_movie_id());
	}
	if (v_movie.size() == 0){
		cout << "You have not added the movie yet." << endl;
	}
	else{
		cout << "The movie list:" << endl;
		for (int i = 0; i < v_movie.size(); i++){
			cout << (i + 1) << endl;
			cout << "  Movie name: " << v_movie[i].get_movie_name() << endl;
			cout << "  Movie duration: " << v_movie[i].get_movie_duration() << " minutes" << endl;
			cout << "  Movie ID: " << v_movie[i].get_movie_id() << endl;
			cout << endl;
		}
		cout << "If you want to delete a movie from the movie list, please input the number: ";
		cin >> input;
		do{
			if (input > v_movie.size()){
				cout << "Please input again: ";
				cin >> input;
				success = 0;
			}
			else{
				success = 1;
			}
		} while (success != 1);
		int i = 0;
		for (auto it = v_movie.begin(); it != v_movie.end(); it++){
			if (v_movie[i].get_movie_id() == number[input - 1]){
				it = v_movie.erase(it);
				cout << "The deletion is successful!" << endl;
				if (it == v_movie.end()) break;
			}
			i++;
		}
	}
	return v_movie;
}

void operate_movie()
{
	movie themovie = movie("Not Given", 0, 0);
	vector<movie> v_movie;
	v_movie = read_movie();     //read data from movie_data.txt
	int judge = 0;
	do{
		string input_name;
		double input_duration;
		int input_id;
		cout << "Please input a number to select:" << endl;
		cout << "1. Add a movie" << endl;
		cout << "2. Delete a movie" << endl;
		cout << "3. View movie list" << endl;
		cout << "4. Return" << endl;
		int select;
		cin >> select;
		switch (select){
			//add a movie
		case 1:
			//system("pause");
			system("cls");
			cout << "Please input movie name: ";
			getline(cin, input_name);
			getline(cin, input_name);
			cout << "Please input movie duration (Unit: minute): ";
			cin >> input_duration;
			cout << "Please input movie ID (Only integer number): ";
			cin >> input_id;
			themovie.set_movie_name(input_name);
			themovie.set_movie_duration(input_duration);
			themovie.set_movie_id(input_id);
			v_movie.push_back(themovie);
			save_movie(v_movie);     //save data into movie_data.txt
			cout << "The add is successful!" << endl;
			//system("pause");
			system("cls");
			break;
			//delete a movie
		case 2:
			//system("pause");
			system("cls");
			v_movie = delete_movie(v_movie);
			save_movie(v_movie);     //save data into movie_data.txt
			//system("pause");
			system("cls");
			break;
			//display movie list
		case 3:
			//system("pause");
			system("cls");
			if (v_movie.size() == 0){
				cout << "You have not added the movie yet." << endl;
			}
			else{
				cout << "The movie list:" << endl;
				for (int i = 0; i < v_movie.size(); i++){
					cout << (i + 1) << endl;
					cout << "  Movie name: " << v_movie[i].get_movie_name() << endl;
					cout << "  Movie duration: " << v_movie[i].get_movie_duration() << " minutes" << endl;
					cout << "  Movie ID: " << v_movie[i].get_movie_id() << endl;
					cout << endl;
				}
			}
			system("pause");
			system("cls");
			break;
			//exit
		case 4:
			judge = 1;
			//system("pause");
			system("cls");
			break;
			//when the input number is not 1~4, you can enter it again
		default:
			cout << "Please input again." << endl;
			//system("pause");
			system("cls");
			break;
		}
	} while (judge != 1);
}
void searchMovie(string Sname) {
	vector<movie> v_movie;
	v_movie = read_movie();     //read data from movie_data.txt
	bool searchFlag = false;
	for (unsigned int i = 0; i < v_movie.size(); i++) {
		if (v_movie[i].get_movie_name() == Sname) {
			cout << "The movie have id " << v_movie[i].get_movie_id() << " with duration " << v_movie[i].get_movie_duration() << endl;
			searchFlag = true;
		}
	}
	if (!searchFlag) cout << "No movie found in this name" << endl;
 }