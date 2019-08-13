/*************************************************
 *   G BRENT HURST
 *   get.cpp
 *   May 9, 2017 (original)
 *   August 12, 2019 (last edit)
 *
 *   Get methods for the Date class.
 *
 *   #include "gbhdate.h"
 *
 ************************************************/


#include "gbhdate.h"

using namespace std;


int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
string Date::getMonthName() const { return monthName; }
string Date::getMonthAbr() const { return monthAbr; }
int Date::getDay() const { return day; }

//Assumes a year before AD 10,000
string Date::getDate() const
{
	char c[20];
	string s;

	sprintf(c,"%04d%02d%02d",year,month,day);

	s = c;

	return s;
}
