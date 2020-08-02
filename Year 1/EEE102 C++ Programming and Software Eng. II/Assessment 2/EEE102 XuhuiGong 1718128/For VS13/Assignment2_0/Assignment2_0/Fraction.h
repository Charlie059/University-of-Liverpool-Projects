#pragma once

int get_maximum_common_divisor(int top, int bottom);
//Fraction fraction_setter(int top,int bottom);
class iFraction;
class Fraction
{
	friend iFraction convertF(Fraction Frac);
public:
	Fraction(int Top, int Bottom);
	Fraction();
	Fraction(int Top);
	~Fraction();
	//Four types of Fractions
	Fraction operator + (Fraction Frac);
	Fraction operator - (Fraction Frac);
	Fraction operator * (Fraction Frac);
	Fraction operator / (Fraction Frac);
	//Four types of method
	void print();
	int get_top();
	int get_bottom();
	//Getter
	void set_top(int Top);
	void set_bottom(int Bottom);
	//Setter
	void get_convert_negative();
	double convert_decimal();
	//Other 

	void operator = (Fraction frac);



protected:
	int top;
	int bottom;
};

