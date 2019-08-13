/*************************************************
 *   G BRENT HURST
 *   operators.cpp
 *   December 26, 2017 (original)
 *   August 12, 2019 (last edit)
 *
 *   Operator overloads for the Date class.
 *   Everything works as you would expect.
 *
 *   #include "Date.h"
 *
 ************************************************/


#include "gbhdate.h"
#include <set>

using namespace std;


Date Date::operator+(const int days)
{
	this->setWithTotalDay(totalDay + days);
	return *this;
}
Date Date::operator-(const int days) { return *this + (-1*days); }
Date Date::operator++() { return *this + 1; }
Date Date::operator--() { return *this - 1; }
Date Date::operator+=(const int days) { return *this + days; }
Date Date::operator-=(const int days) { return *this - days; }
Date Date::operator=(const Date& d) { return d; }
int Date::operator-(const Date& d){return this->totalDay - d.totalDay;}
bool Date::operator<(const Date& d){return (this->totalDay < d.totalDay);}
bool Date::operator>(const Date& d){return (this->totalDay > d.totalDay);}
bool Date::operator<=(const Date& d){return (this->totalDay <= d.totalDay);}
bool Date::operator>=(const Date& d){return (this->totalDay >= d.totalDay);}
bool Date::operator==(const Date& d){return (this->totalDay == d.totalDay);}
bool Date::operator!=(const Date& d){return (this->totalDay != d.totalDay);}
