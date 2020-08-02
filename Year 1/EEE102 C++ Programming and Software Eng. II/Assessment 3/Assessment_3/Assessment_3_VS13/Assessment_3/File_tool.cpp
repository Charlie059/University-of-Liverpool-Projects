
#include "File_tool.h"

File_tool::File_tool()
{
	
	if (check_file()==true)
	{
		cout << "ERROR FILE" << endl;
	}

}
//Check that the file is complete

File_tool::~File_tool()
{
}

bool File_tool::check_file(){
	ifstream fin("data.txt");
	if (fin.bad() == true)
	{
		return true;
	}
	else
		return false;
}
//Check that the file is exist
void File_tool::write_file(string name, int balance,int balance_computer, int color, int position_player, int position_computer, int action_point_player, int action_point_computer, int OwnerPlayer[38], int OwnerComputer[38], int price[38]){

	const char* p = name.data();
	ofstream fout("data.txt");
	fout << p << endl;
	fout << balance << endl;
	fout << balance_computer << endl;
	fout << color << endl;
	fout << position_player << endl;
	fout << position_computer << endl;
	fout << action_point_player << endl;
	fout << action_point_computer << endl;
	for (int i = 0; i < 38; i++)
	{
		fout << OwnerPlayer[i] << endl;
	}
	for (int i = 0; i < 38; i++)
	{
		fout << OwnerComputer[i] << endl;
	}
	for (int i = 0; i < 38; i++)
	{
		fout << price[i] << endl;
	}
	fout.close();
}
//Write data method
string File_tool::read_name(){
	string name;
	char line[40];
	ifstream fin("data.txt");
	fin.getline(line, 20);
	fin.close();
	name = line;
	return name;
}

int File_tool::read_balance(){

	int m1;
	ifstream fin("balance.txt");

	fin >> m1;

	fin.close();
	return m1;

}
int File_tool::read_color(){



	int m1;
	ifstream fin("color.txt");

	fin >> m1;

	fin.close();
	return m1;
}
int File_tool::position(){
	int m1;
	ifstream fin("position.txt");

	fin >> m1;

	fin.close();
	return m1;

}
int* File_tool::read_own(){
	int m1;
	int arrary[38];
	ifstream fin("own.txt");
	for (int i = 0; i < 38; i++)
	{
		fin >> m1;
		arrary[i] = m1;
	}
	fin.close();
	return arrary;
}

string File_tool::readTxt(string filename, int line)
{
	ifstream text;
	text.open(filename, ios::in);
	vector<string> strVec;
	while (!text.eof()){
		string inbuf;
		getline(text, inbuf, '\n');

		strVec.push_back(inbuf);
	}

	return strVec[line - 1];

}
//Read the data for the specified row

int File_tool::CountLines(string filename)
{
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(filename, ios::in);
	if (ReadFile.fail())
	{
		return 0;
	}
	else
	{
		while (getline(ReadFile, tmp, '\n'))
		{
			n++;
		}
		ReadFile.close();
		return n;
	}
}
//Get the number of file rows