/*************************************************
 *   G BRENT HURST
 *   ConstrDestr.cpp
 *   May 9, 2017 (original)
 *   August 12, 2019 (last edit)
 *
 *   Constructors and destructors
 *   (if any) for the Date class.
 *
 *   #include "gbhdate.h"
 *
 ************************************************/


#include "gbhdate.h"

using namespace std;


//Constructors if the date is known.
Date::Date(int y,int m,int d)
{
	setDate(y, m, d);
}
Date::Date(string date)
{
	setDate(date);
}


//Constructor if the date isn't known
Date::Date()
{
	day=0;
	month=0;
	year=0;
	totalDay=0;
}
