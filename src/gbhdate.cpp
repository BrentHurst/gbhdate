#include "gbhdate.hpp"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

bool IsLeapYear(int y)
{
	// TODO - is this right?
	return (y%4==0 && ((y%100 != 0) || (y%400 == 0)));
}


//A basic print function that's
//pretty much only useful for
//error checking.
void GBH_Date::Print() const
{
	cout << "day:   " << GetDay() << endl
		 << "month: " << GetMonth() << endl
		 << "       " << GetMonthName() << endl
		 << "year:  " << GetYear() << endl
		 << "date:  " << GetDate() << endl;
}


int GBH_Date::GetYear() const { return year; }
int GBH_Date::GetMonth() const { return month; }
int GBH_Date::GetDay() const { return day; }
int GBH_Date::GetDate() const { return year * 10000 + month * 100 + day; }


string GBH_Date::GetMonthName() const
{
	switch(month)
	{
		case 1:  return "January";   break;
		case 2:  return "February";  break;
		case 3:  return "March";     break;
		case 4:  return "April";     break;
		case 5:  return "May";       break;
		case 6:  return "June";      break;
		case 7:  return "July";      break;
		case 8:  return "August";    break;
		case 9:  return "September"; break;
		case 10: return "October";   break;
		case 11: return "November";  break;
		case 12: return "December";  break;
		default: return "";          break;
	}
}


//Constructors
GBH_Date::GBH_Date(int y,int m,int d)
{
	SetDate(y,m,d);
}
GBH_Date::GBH_Date(int i)
{
	SetDate(i);
}
GBH_Date::GBH_Date()
{
	ZeroOut();
}

bool GBH_Date::ZeroOut()
{
	year = 0;
	month = 0;
	day = 0;
	return false;
}

bool GBH_Date::SetDate(int y, int m, int d)
{
	if(!SetDate_Protected(y, m, d))
		return ZeroOut();
	else
		return true;
}
bool GBH_Date::SetDate(int i)
{
	if(!SetDate_Protected(i / 10000, (i / 100) % 100, i % 100))
		return ZeroOut();
	else
		return true;
}
bool GBH_Date::SetDate_Protected(int y, int m, int d)
{
	int monthtype;

	year = y;
	month = m;
	day = d;

	if(month == 1
			|| month == 3
			|| month == 5
			|| month == 7
			|| month == 8
			|| month == 10
			|| month == 12
	  )
		monthtype = 1;
	else if(month == 4
			|| month == 6
			|| month == 9
			|| month == 11
		   )
		monthtype = 2;
	else
		monthtype = 3;

	if(year < 0)
		return false;
	if(month < 1 || month > 12)
		return false;
	if(day < 1
			|| day > 31
			|| (monthtype == 2 && day > 30)
			|| (monthtype == 3 && IsLeapYear(year) && day > 29)
			|| (monthtype == 3 && !IsLeapYear(year) && day > 28)
	  )
		return false;

	return true;
}


//Read in an integer
static int ReadInt(string s)
{
	int i;
	string junk;

	printf("%s (integer): ",s.c_str());
	while(!(cin >> i))
	{
		cin.clear();
		cin >> junk;
		printf("Please enter the %s as an integer: ",s.c_str());
	}

	return i;
}


//Interactive with a user.
//Fairly self-explanatory.
void GBH_Date::ReadInDate()
{
	int ui;
	bool beenThroughOnce;
	string junk;

	beenThroughOnce=false;
	do
	{
		if(beenThroughOnce)
			printf("There was an error in the date. Please retry.\n");

		ui = ReadInt("yyyymmdd");

		beenThroughOnce=true;

	}while(!SetDate(ui));

	//Literally the most important line of code in this method.
	//If you delete this, you will have significant problems
	//reading anything else. Cin is annoying.
	getline(cin,junk);
}


bool GBH_Date::operator<(const GBH_Date& d){return (this->GetDate() < d.GetDate());}
bool GBH_Date::operator>(const GBH_Date& d){return (this->GetDate() > d.GetDate());}
bool GBH_Date::operator<=(const GBH_Date& d){return (this->GetDate() <= d.GetDate());}
bool GBH_Date::operator>=(const GBH_Date& d){return (this->GetDate() >= d.GetDate());}
bool GBH_Date::operator==(const GBH_Date& d){return (this->GetDate() == d.GetDate());}
bool GBH_Date::operator!=(const GBH_Date& d){return (this->GetDate() != d.GetDate());}


/* GBH_Date GBH_Date::operator+(const int days)
{
	this->setWithTotalDay(totalDay + days);
	return *this;
} */
/* GBH_Date GBH_Date::operator-(const int days) { return *this + (-1*days); } */
/* GBH_Date GBH_Date::operator++() { return *this + 1; } */
/* GBH_Date GBH_Date::operator--() { return *this - 1; } */
/* GBH_Date GBH_Date::operator+=(const int days) { return *this + days; } */
/* GBH_Date GBH_Date::operator-=(const int days) { return *this - days; } */
/* GBH_Date GBH_Date::operator=(const GBH_Date& d) { return d; } */
/* int GBH_Date::operator-(const GBH_Date& d){return this->totalDay - d.totalDay;} */
