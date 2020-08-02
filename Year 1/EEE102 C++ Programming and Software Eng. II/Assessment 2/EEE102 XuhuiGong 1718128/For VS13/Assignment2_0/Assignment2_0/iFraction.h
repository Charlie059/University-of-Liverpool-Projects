#pragma once
#include "Fraction.h"
#include <iostream>
class iFraction : public Fraction
{
	friend iFraction convertF(Fraction Frac);
protected:

	int whole_number;

public:
	iFraction();
	iFraction(int w_number, int top, int bottom);

	void print();
	~iFraction();
};

