/*************************************************
 *   G BRENT HURST
 *   gbhdate.h
 *   May 9, 2017 (original)
 *   August 12, 2019 (last edit)
 *
 *   A class that deals with dates of the
 *   modern Western Gregorian calendar.
 *
 *   This class currently doesn't support the
 *   Julian calendar and actually assumes it was
 *   never used. I might add support in the          TODO
 *   future. As of now, this doesn't support
 *   dates before January 1, AD 1 (Gregorian).       TODO
 *
 *   Method definitions in the file(s) indicated
 *   above each block of declarations.
 *
 ************************************************/

#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;


class Date
{
  protected:
	int year;
	int month;
	string monthName;
	string monthAbr;
	int day;

	int totalDay; //since an undefined epoch

	//setProtected.cpp
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	void setTotalDay();
	void setWithTotalDay(int i);

  public:
	//ConstrDestr.cpp
	Date(int y,int m,int d);
	Date(string date);
	Date();

	//operators.cpp
	Date operator+(const int days);
	Date operator-(const int days);
	Date operator++();
	Date operator--();
	Date operator+=(const int days);
	Date operator-=(const int days);
	Date operator=(const Date& d);
	int operator-(const Date& d);
	bool operator<(const Date& d);
	bool operator>(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	//print.cpp
	//pretty much just for error checking
	void print() const;

	//read.cpp
	void ReadInDate();

	//setPublic.cpp
	bool setDate(int y, int m, int d);
	bool setDate(string date);
	bool setDate(const Date& D);

	//get.cpp
	int getYear() const;
	int getMonth() const;
	string getMonthName() const;
	string getMonthAbr() const;
	int getDay() const;
	//default format: "yyyymmdd"
	string getDate() const;
};

#endif
