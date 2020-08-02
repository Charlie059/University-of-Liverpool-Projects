
#include <iostream>
#include "Fraction.h"
#include "iFraction.h"
#include <string>
#include <sstream>
//Convert string to int
#include <cmath>
//To get the pow function
#include <stdlib.h>
#include <time.h>
//To create a random float that could convert it to fraction

/**********************************************/
void ask_input_fraction(int number_select);
void comparison_size();
void user_interface();
int input_func();
Fraction convert_fraction(double);
//Convert decimal to fraction method, the Convert fraction to decimal method is in the Fraction class
using namespace std;
bool isinput_all_digital(string);
/*Main page method*/
Fraction first_fraction;
Fraction second_fraction;
Fraction result;
iFraction iResult;



//Main page var

int main()
{

	user_interface();
	//Running the main interface
}
/*Main**************************************************************/

void user_interface() {
start_interface:
	system("cls");
	cout << "***********************************************" << endl;
	cout << "* This program let user to input two fraction *" << endl;
	cout << "* User could select which method could be used*" << endl;
	cout << "*Then,the result will be make a simplification*" << endl;
	cout << "* Also, the conversion will be list in result *" << endl;
	cout << "***********************************************" << endl << endl;
	cout << "Please set up first fraction" << endl;
	ask_input_fraction(1);
	//Let user input first fraction
	cout << "*******************************************" << endl;
	cout << "Please set up second fraction" << endl;
	ask_input_fraction(2);
	//Let user input second fraction
	cout << "Please select which method you want to use" << endl;
	cout << "1.Add  2.Subtract  3.Multiple  4.Divide  5.Comparison of size" << endl;
	cout << "*******************************************" << endl;
	//Let user to select method to manipulate
selection:
	int number_of_selection = input_func();
	//Input user selection
	first_fraction.get_convert_negative();
	second_fraction.get_convert_negative();
	//To get frction convert negative if "3/-4" to transfer to "-3/4"
	switch (number_of_selection)
	{//In order to make to clear to select, so uses switch
	case 1:

		result = first_fraction + second_fraction;
		//Using adding method
		iResult = convertF(result);
		iResult.print();

		//Call printer to print
		result.convert_decimal();
		//Convert it to decimal
		break;
	case 2:
		result = first_fraction - second_fraction;
		//Using subing method
		iResult = convertF(result);
		iResult.print();
		result.convert_decimal();
		break;
	case 3:
		result = first_fraction * second_fraction;
		//Using muling method
		iResult = convertF(result);
		iResult.print();
		result.convert_decimal();
		break;
	case 4:
		result = first_fraction / second_fraction;
		//Using diving method
		iResult = convertF(result);
		iResult.print();
		result.convert_decimal();
		break;
	case 5:
		comparison_size();
		//Using Comparing method
		break;

	default:
		cout << "Please select again!" << endl;
		//If user enter others, print warning
		goto selection;
		//Jump to selection, however goto is not good, i will change it to do while loop
	}
	cout << "******************************************************************************" << endl;
	cout << "Just now, you have enter a fraction convert to the decimal, then, i will give a random decimal to convert it to the fraction" << endl;

	srand((unsigned)time(NULL));
	double rand_number = 2 * (rand() / double(RAND_MAX));
	//Get a random from 0-2
	cout << "The random number is " << rand_number << endl;
	//Get the random double
	Fraction convert_fraction_result = convert_fraction(rand_number);
	cout << "The convert result of random is " << convert_fraction_result.get_top() << "/" << convert_fraction_result.get_bottom() << endl;
	cout << "*********************************************************************" << endl;

start_selection:
	cout << "Do you want to calculate again? Press 1 for Yes or 2 for No " << endl;
	//Tell user if want to calculate again
	int number_of_selection_again = input_func();
	//Reenter user selection
	switch (number_of_selection_again) {
	case 1:
		cout << "You select Yes!" << endl;
		goto start_interface;
		//If user enter 1, goto interface again
	case 2:
		cout << "You select No! Program will exit" << endl;
		//If user enter 2, goto stop(Not good, it will be changed to dowhile)
		break;
	default:
		cout << "Wrong number! Please select again!" << endl;
		//Wrong number warning
		goto start_selection;
	}
}

/*Userinterface*****************************************************/

void ask_input_fraction(int number_select) {
	cout << "Firstly, please enter the top of fraction" << endl;
	int top_first = input_func();
	//Enter the first fraction
	cout << "Secondly, please enter the bottom of fraction" << endl;
	int bottom_first = input_func();
	//Enter the second fraction
	do
	{
		if (bottom_first == 0)
		{
			cout << "Sory, bottom does not allow to set 0!" << endl << "Please enter again!" << endl;
			//Avoid the bootom is 0
			bottom_first = input_func();
		}
	} while (bottom_first == 0);

	if (number_select == 1)//Parameter settings, 1 for first_fraction setting up, 2 for second_fraction setting up
	{
		first_fraction.set_top(top_first);
		first_fraction.set_bottom(bottom_first);
		//Setting top and bottom of first fraction
		first_fraction.get_convert_negative();
		//To get frction convert negative if "3/-4" to transfer to "-3/4"
	}
	else if (number_select == 2)
	{
		second_fraction.set_top(top_first);
		second_fraction.set_bottom(bottom_first);
		second_fraction.get_convert_negative();
	}
}

/*Asking input_fraction method**************************************/

bool isinput_all_digital(string user_input) {
	int counter_neg = 0;
	for (int i = 0; i < user_input.length(); i++)
	{
		if (((user_input[i] < 48) && (user_input[i] != 45)) || (58 < user_input[i]))
		{
			return false;
		}
		if ((user_input[i] == 45))
		{
			counter_neg++;
		}
	}
	if (counter_neg > 1)
	{
		cout << "Please enter only one negative sign!" << endl;
		return false;

	}

	return true;
}

/*Consider the input is digital*************************************/

int input_func() {
	string user_input;
	//Use string to save the user_input firstly
	getline(cin, user_input);
	//geline from cin
	bool result = isinput_all_digital(user_input);
	//Consider that all input is digital
	do
	{
		if (result == false)
		{
			cout << "Please enter the number again!" << endl;
			getline(cin, user_input);
			result = isinput_all_digital(user_input);
		}
	} while (result == false);
	//If user enter other char, let user to input again
	if (user_input.length() == 0)
	{
		cout << "You select fraction which 0/x (x!=0)" << endl;
		return 0;
	}
	//if user enter nothing, system default set 0/x
	stringstream stream(user_input);
	//Convert string to int
	int input;
	stream >> input;
	return input;
}

/*Fundational input function****************************************/
void comparison_size() {
	double first_dec = first_fraction.convert_decimal();
	double second_dec = second_fraction.convert_decimal();
	//Create two double to store the result and compare them
	cout << endl;
	cout << "*************************************" << endl;

	if (first_dec > second_dec)//If first > second, get cout
	{
		cout << "So first_dec > second_dec" << endl;
	}
	else if (first_dec < second_dec)
	{
		cout << "So first_dec < second_dec" << endl;
	}
	else
	{
		cout << "So first_dec is approximately equal second_dec" << endl;
	}

}

/*Comparison method*************************************************/

Fraction convert_fraction(double dec) {
	int top = (dec * pow(10, 4));
	int bottom = 1 * pow(10, 4);
	//Get the top and bottom *10^16
	int maximum_common_divisor = get_maximum_common_divisor(top, bottom);
	Fraction convert_fraction_result(top / maximum_common_divisor, bottom / maximum_common_divisor);
	return convert_fraction_result;
}

iFraction convertF(Fraction Frac)
{
	int new_top = (Frac.top) % (Frac.bottom);//Use a var to store the top
	if ((new_top == 0) && (Frac.top != 0))//Special sitation eg. -2/1 + -3/1
	{
		new_top = 1;
	}
	return iFraction(((Frac.top) / (Frac.bottom)), (new_top), (Frac.bottom));//Return iFraction
}
