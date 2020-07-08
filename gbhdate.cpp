#include "gbhdate.hpp"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define isLeapYear y%4==0 && ((y%100 != 0) || (y%400 == 0))


// TODO - Fix under this
















//Constructors if the date is known.
GBH_Date::GBH_Date(int y,int m,int d)
{
	setDate(y, m, d);
}
GBH_Date::GBH_Date(string date)
{
	setDate(date);
}


//Constructor if the date isn't known
GBH_Date::GBH_Date()
{
	day=0;
	month=0;
	year=0;
	totalDay=0;
}

int GBH_Date::getYear() const { return year; }
int GBH_Date::getMonth() const { return month; }
string GBH_Date::getMonthName() const { return monthName; }
string GBH_Date::getMonthAbr() const { return monthAbr; }
int GBH_Date::getDay() const { return day; }

//Assumes a year before AD 10,000
string GBH_Date::getDateStr() const
{
	char c[20];
	string s;

	sprintf(c,"%04d%02d%02d",year,month,day);

	s = c;

	return s;
}

unsigned int getDateInt() const
{
	return year * 10000 + month * 100 + day;
}

GBH_Date GBH_Date::operator+(const int days)
{
	this->setWithTotalDay(totalDay + days);
	return *this;
}
GBH_Date GBH_Date::operator-(const int days) { return *this + (-1*days); }
GBH_Date GBH_Date::operator++() { return *this + 1; }
GBH_Date GBH_Date::operator--() { return *this - 1; }
GBH_Date GBH_Date::operator+=(const int days) { return *this + days; }
GBH_Date GBH_Date::operator-=(const int days) { return *this - days; }
GBH_Date GBH_Date::operator=(const GBH_Date& d) { return d; }
int GBH_Date::operator-(const GBH_Date& d){return this->totalDay - d.totalDay;}
bool GBH_Date::operator<(const GBH_Date& d){return (this->totalDay < d.totalDay);}
bool GBH_Date::operator>(const GBH_Date& d){return (this->totalDay > d.totalDay);}
bool GBH_Date::operator<=(const GBH_Date& d){return (this->totalDay <= d.totalDay);}
bool GBH_Date::operator>=(const GBH_Date& d){return (this->totalDay >= d.totalDay);}
bool GBH_Date::operator==(const GBH_Date& d){return (this->totalDay == d.totalDay);}
bool GBH_Date::operator!=(const GBH_Date& d){return (this->totalDay != d.totalDay);}


//A basic print function that's
//pretty much only useful for
//error checking.
void GBH_Date::print() const
{
	cout << "day:   " << day << endl
		 << "       " << totalDay<< endl
		 << "month: " << month << endl
		 << "       " << monthName << endl
		 << "       " << monthAbr << endl
		 << "year:  " << year << endl;
}

//Read in an integer
int ReadInt(string s)
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
	unsigned int ui;
	bool beenThroughOnce;
	string junk;

	beenThroughOnce=false;
	do
	{
		if(beenThroughOnce)
			printf("There was an error in the date. Please retry.\n");

		ui = ReadInt("yyyymmdd");

		beenThroughOnce=true;

	}while(!setDate(y,m,d));


	//Literally the most important line of code in this method.
	//If you delete this, you will have significant problems
	//reading anything else. Cin is annoying.
	getline(cin,junk);
}

//self-explanatory. day,month,year initialized to 0.
void GBH_Date::setDay(int d)
{
	day=d;

	if(day && month && year)
		setTotalDay();
}

//self-explanatory. day,month,year initialized to 0.
void GBH_Date::setMonth(int m)
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
void GBH_Date::setYear(int y)
{
	year=y;

	if(day && month && year)
		setTotalDay();
}

//annoying but self-explanatory.
void GBH_Date::setTotalDay()
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
void GBH_Date::setWithTotalDay(int a)
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
//Returns false if passed an invalid date.
//Returns true if passed a valid date.
bool GBH_Date::setDate(int y, int m, int d)
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
bool GBH_Date::setDate(string date)
{
	int i;

	sscanf(date.c_str(),"%d",&i);

	return setDate(i / 10000, (i / 100) % 100, i % 100);
}

//Returns false if passed an invalid date.
//Returns true if passed a valid date.
bool GBH_Date::setDate(unsigned int date)
{
	return setDate(date / 10000, (date / 100) % 100, date % 100);
}

//Returns false if passed an invalid date.
//Returns true if passed a valid date.
bool GBH_Date::setDate(const GBH_Date& D)
{
	return this->setDate(D.getDate());
}
