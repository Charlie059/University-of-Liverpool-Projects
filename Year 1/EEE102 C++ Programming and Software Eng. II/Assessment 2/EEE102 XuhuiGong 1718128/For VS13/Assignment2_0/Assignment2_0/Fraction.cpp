#include "Fraction.h"
#include <cstdlib> 
#include <iostream>

Fraction::Fraction(int Top, int Bottom)
{
	top = Top;
	bottom = Bottom;
}
/*Constractor*/
Fraction::~Fraction()
{}

Fraction::Fraction() {
	top = 0;
	bottom = 1;
}
//default if creat Fraction()
Fraction::Fraction(int Top) {
	top = Top;
	bottom = 1;
}
//default if creat Fraction(top)

void Fraction::print() {
	std::cout << "The result is ";
	std::cout << top << "/" << bottom;
}
//Print method



Fraction Fraction::operator+(Fraction Frac)
{
	Frac.get_convert_negative();
	//convert to the standard eg:3/-4 to -3/4

	int top_two = Frac.get_top();
	//get second fraction of top
	int bottom_two = Frac.get_bottom();
	//get second fraction of bottom
	int bottom_result = bottom * bottom_two;
	//get the bottom of result
	int top_result = top * bottom_two + top_two * bottom;
	//get the top of result
	int top_result_new = 0;
	int bottom_result_new = 0;
	//Set a new variable to prevent changes to old variables

	top_result_new = top_result / (get_maximum_common_divisor(top_result, bottom_result));
	bottom_result_new = bottom_result / (get_maximum_common_divisor(top_result, bottom_result));
	//The result is not approximate, so div maximum_common_divisor

	Fraction add_result;
	//Create a new Fraction of result
	add_result.bottom = bottom_result_new;
	add_result.top = top_result_new;
	//input the value of result
	add_result.get_convert_negative();
	//To get frction convert negative if "3/-4" to transfer to "-3/4"
	return add_result;

}

Fraction Fraction::operator-(Fraction Frac)
{
	Frac.get_convert_negative();
	int top_two = Frac.get_top();
	int bottom_two = Frac.get_bottom();
	int bottom_result = bottom * bottom_two;
	int top_result = top * bottom_two - top_two * bottom;
	//The different between add and sub is this func is negative
	int top_result_new = 0;
	int bottom_result_new = 0;
	top_result_new = top_result / (get_maximum_common_divisor(top_result, bottom_result));
	bottom_result_new = bottom_result / (get_maximum_common_divisor(top_result, bottom_result));
	Fraction sub_result;
	sub_result.bottom = bottom_result_new;
	sub_result.top = top_result_new;
	sub_result.get_convert_negative();
	return sub_result;
}

Fraction Fraction::operator*(Fraction Frac)
{
	Frac.get_convert_negative();
	int top_two = Frac.get_top();
	int bottom_two = Frac.get_bottom();
	int bottom_result = bottom * bottom_two;
	int top_result = top * top_two;
	//To get the top result as top * top_two
	int top_result_new = 0;
	int bottom_result_new = 0;
	top_result_new = top_result / (get_maximum_common_divisor(top_result, bottom_result));
	bottom_result_new = bottom_result / (get_maximum_common_divisor(top_result, bottom_result));
	Fraction mul_result;
	mul_result.bottom = bottom_result_new;
	mul_result.top = top_result_new;
	mul_result.get_convert_negative();
	return mul_result;
}

Fraction Fraction::operator/(Fraction Frac)
{
	Frac.get_convert_negative();
	int bottom_two = Frac.get_top();
	int top_two = Frac.get_bottom();
	//Because division is equal to the reciprocal of multiplication
	int bottom_result = bottom * bottom_two;
	int top_result = top * top_two;
	int top_result_new = 0;
	int bottom_result_new = 0;
	top_result_new = top_result / (get_maximum_common_divisor(top_result, bottom_result));
	bottom_result_new = bottom_result / (get_maximum_common_divisor(top_result, bottom_result));
	Fraction mul_result;
	if ((bottom_result_new == 0) && (top_result_new == 0))
	{
		mul_result.top = 0;
		mul_result.bottom = 1;
		return mul_result;
	}
	mul_result.bottom = bottom_result_new;
	mul_result.top = top_result_new;
	mul_result.get_convert_negative();
	return mul_result;
}

/*Div func*/
int Fraction::get_top() {
	return top;
}
/*top getter*/
int Fraction::get_bottom() {
	return bottom;
}
/*bottom getter*/

void Fraction::set_top(int Top) {
	this->top = Top;
}
/*top setter*/

void Fraction::set_bottom(int Bottom) {
	this->bottom = Bottom;
}
/*bottom setter*/

double Fraction::convert_decimal() {
	double result_decimal = (double)top / bottom;
	//Convert it to decimal
	std::cout << std::endl;
	std::cout << "Convert to decimals, the result is " << result_decimal << std::endl;
	return result_decimal;
}

void Fraction::operator=(Fraction frac)
{
	top = frac.top;
	bottom = frac.bottom;
}

//Covert to decimal func
int get_maximum_common_divisor(int top, int bottom) {
	//Split phase division
	int r = top;
	while (r != 0)
	{
		r = top % bottom;
		top = bottom;
		bottom = r;
	}

	if (top == 0)
	{
		return 1;
	}
	else
	{
		return abs(top);
		//Because we could meet negitive number, so we get absolute number
	}
}





void Fraction::get_convert_negative() {
	if ((bottom < 0) && (top < 0))
	{
		bottom = (-bottom);
		top = (-top);
	}
	else if ((bottom < 0) && (top > 0))
	{
		bottom = (-bottom);
		top = (-top);
	}
}
//Convert Fraction to the standard eg "1/-3" to "-1/3", and "-1/-3" to "1/3"

