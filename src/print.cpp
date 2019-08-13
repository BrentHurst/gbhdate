/*************************************************
 *   G BRENT HURST
 *   print.cpp
 *   May 9, 2017 (original)
 *   August 12, 2019 (last edit)
 *
 *   Error print method for the Date class.
 *
 *   #include "gbhdate.h"
 *
 ************************************************/


#include "gbhdate.h"
#include <iostream>

using namespace std;


//A basic print function that's
//pretty much only useful for
//error checking.
void Date::print() const
{
	cout << "day:   " << day << endl
		 << "       " << totalDay<< endl
		 << "month: " << month << endl
		 << "       " << monthName << endl
		 << "       " << monthAbr << endl
		 << "year:  " << year << endl;
}
