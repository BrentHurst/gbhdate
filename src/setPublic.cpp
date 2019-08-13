/*************************************************
 *   G BRENT HURST
 *   setPublic.cpp
 *   May 9, 2017 (original)
 *   August 12, 2019 (last edit)
 *
 *   Public methods of the Date class
 *   to set member variables.
 *
 *   Functions are self-explanatory.
 *
 *   #include "Date.h"
 *
 ************************************************/


#include "gbhdate.h"

using namespace std;

#define isLeapYear y%4==0 && ((y%100 != 0) || (y%400 == 0))


//Returns false if passed an invalid date.
//Returns true if passed a valid date.
bool Date::setDate(int y, int m, int d)
{
	if(d<1 || m<1 || y<1 || d>31 || m>12 || y>9999)
		return false;
	else if((m==4 || m==6 || m==9 || m==11) && d>30)
		return false;
	else if((m==2 && d>29) || (m==2 && y%4 != 0 && d>28))
		return false;

	setDay(d);
	setMonth(m);
	setYear(y);

	return true;
}

//Returns false if passed an invalid date.
//Returns true if passed a valid date.
bool Date::setDate(string date)
{
	int i;

	sscanf(date.c_str(),"%d",&i);

	return setDate(i / 10000, (i / 100) % 100, i % 100);
}

//Returns false if passed an invalid date.
//Returns true if passed a valid date.
bool Date::setDate(const Date& D)
{
	return this->setDate(D.getDate());
}
