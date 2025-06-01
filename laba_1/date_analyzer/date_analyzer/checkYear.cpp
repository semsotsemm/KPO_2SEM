#include <iostream>
#include "getData.h"

using namespace std;

bool checkYear(int year, int lyear, int nday_bth, int nday)
{
	if (year > lyear || (year == lyear && nday_bth > nday))
	{
		return true;
	}
	else
	{
		return false;
	}
}