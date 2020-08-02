//#include "Fraction.h"
#include "iFraction.h"




iFraction::iFraction()
{
	whole_number = NULL;
	bottom = 0;
	top = 0;
}

iFraction::iFraction(int w_number, int Top, int Bottom)
{
	whole_number = w_number;
	bottom = Bottom;
	top = Top;
}


void iFraction::print()
{
	if (whole_number == 0)
	{
		std::cout << "The result is ";
		std::cout << top << "/" << bottom;
	}
	else
	{
		std::cout << "The result is ";
		std::cout << whole_number << " and " << top << "/" << bottom;

	}

}


iFraction::~iFraction()
{
}


