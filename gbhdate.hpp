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

#ifndef GBHDATE_H
#define GBHDATE_H

#include <string>
using namespace std;


class GBH_Date
{
  protected:
	int year;
	int month;
	string monthName;
	string monthAbr;
	int day;

	int totalDay; //since an undefined epoch

	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	void setTotalDay();

  public:
	GBH_Date(int y,int m,int d);
	GBH_Date(string date);
	GBH_Date();

	GBH_Date operator+(const int days);
	GBH_Date operator-(const int days);
	GBH_Date operator++();
	GBH_Date operator--();
	GBH_Date operator+=(const int days);
	GBH_Date operator-=(const int days);
	GBH_Date operator=(const GBH_Date& d);
	int operator-(const GBH_Date& d);
	bool operator<(const GBH_Date& d);
	bool operator>(const GBH_Date& d);
	bool operator<=(const GBH_Date& d);
	bool operator>=(const GBH_Date& d);
	bool operator==(const GBH_Date& d);
	bool operator!=(const GBH_Date& d);

	//pretty much just for error checking
	void print() const;

	void ReadInDate();

	bool setDate(int y, int m, int d);
	bool setDate(string date);
	bool setDate(unsigned int date);
	bool setDate(const GBH_Date& D);

	int getYear() const;
	int getMonth() const;
	string getMonthName() const;
	string getMonthAbr() const;
	int getDay() const;
	//format: "yyyymmdd"
	string getDateStr() const;
	unsigned int getDateInt() const;

	int getTotalDay();
	void setWithTotalDay(int i);
};

#endif
