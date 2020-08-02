//=======================
//		movie.h
//=======================

#ifndef _MOVIE
#define _MOVIE

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void operate_movie();
void searchMovie(string Sname);

class movie
{
	friend vector<movie> read_movie();     //read the data from movie_data.txt
	friend void save_movie(vector<movie> v_movie);     //save the data as a file(movie_data.txt)
	friend vector<movie> delete_movie(vector<movie> v_movie);     //delete a movie
protected:
	string movie_name;
	int movie_duration;
	int movie_id;
public:
	movie(string Movie_name, int Movie_duration, int Movie_id);     //normal constructor
	//getter and setter
	string get_movie_name();
	double get_movie_duration();
	int get_movie_id();
	void set_movie_name(string m_name);
	void set_movie_duration(double m_duration);
	void set_movie_id(int m_id);
};

#endif