/*************************************************
 *   G BRENT HURST
 *   setProtected.cpp
 *   May 9, 2017 (original)
 *   August 12, 2019 (last edit)
 *
 *   Protected methods of the Date class
 *   to set member variables.
 *
 *   At the end of the first three functions,
 *   setTotalDay() if day, month, and year
 *   are set.
 *
 *   Using epoch 1 = January 1, AD 1.
 *   Thus,       2 = January 2, AD 2,
 *               0 doesn't exist
 *              -1 = December 31, 1 BC.
 *
 *   Currently only works for AD dates. (TODO)
 *
 *   #include "Date.h"
 *
 ************************************************/


#include "gbhdate.h"

using namespace std;

#define isLeapYear y%4==0 && ((y%100 != 0) || (y%400 == 0))

//self-explanatory. day,month,year initialized to 0.
void Date::setDay(int d)
{
	day=d;

	if(day && month && year)
		setTotalDay();
}

//self-explanatory. day,month,year initialized to 0.
void Date::setMonth(int m)
{
	month=m;

	switch(month)
	{
		case 1:  monthName="January";	monthAbr="Jan"; break;
		case 2:  monthName="February";	monthAbr="Feb"; break;
		case 3:  monthName="March";		monthAbr="Mar"; break;
		case 4:  monthName="April";		monthAbr="Apr"; break;
		case 5:  monthName="May";		monthAbr="May"; break;
		case 6:  monthName="June";		monthAbr="Jun"; break;
		case 7:  monthName="July";		monthAbr="Jul"; break;
		case 8:  monthName="August";	monthAbr="Aug"; break;
		case 9:  monthName="September"; monthAbr="Sep"; break;
		case 10: monthName="October";	monthAbr="Oct"; break;
		case 11: monthName="November";	monthAbr="Nov"; break;
		case 12: monthName="December";	monthAbr="Dec"; break;
	}

	if(day && month && year)
		setTotalDay();
}

//self-explanatory. day,month,year initialized to 0.
void Date::setYear(int y)
{
	year=y;

	if(day && month && year)
		setTotalDay();
}

//annoying but self-explanatory.
void Date::setTotalDay()
{
	int y=year; //must be y for the #define

	totalDay=day;
	if(month>1)
		totalDay+=31;
	if(month>2)
	{
		totalDay+=28;
		if(isLeapYear)
			totalDay++;
	}
	if(month>3)
		totalDay+=31;
	if(month>4)
		totalDay+=30;
	if(month>5)
		totalDay+=31;
	if(month>6)
		totalDay+=30;
	if(month>7)
		totalDay+=31;
	if(month>8)
		totalDay+=31;
	if(month>9)
		totalDay+=30;
	if(month>10)
		totalDay+=31;
	if(month>11)
		totalDay+=30;

	for(y=1; y<year; y++)
	{
		totalDay+=365;
		if(isLeapYear)
			totalDay++;
	}
}

//Used in setWithTotalDay().
//Advance the month if necessary.
int nextMonth(int& td, int& m, int numDays)
{
	if(td>numDays)
	{
		td-=numDays;
		m++;
		return 1;
	}
	else
		return 0;
}

//given a totalDay, set the date.
void Date::setWithTotalDay(int a)
{
	int i,y,m,d,td,numDays;

	td = a;

	//set year
	for(y=1; ; y++) //must use y for #define
	{
		numDays = 365;
		if(isLeapYear) numDays++;

		if(td > numDays) td-=numDays;
		else break;
	}

	//set month
	m=1;
	numDays=28;
	if(isLeapYear) numDays++;
	for(i=1; i<=12; i++)
	{
		//months with 31 days
		if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
		{
			if(!nextMonth(td,m,31)) break;
		}
		//months with 30 days
		else if(i==4 || i==6 || i==9 || i==11)
		{
			if(!nextMonth(td,m,30)) break;
		}
		//February
		else
		{
			if(!nextMonth(td,m,numDays)) break;
		}
	}

	//set day
	d = td;

	setDate(y,m,d);
}
