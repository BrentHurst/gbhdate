/*************************************************
 *   G BRENT HURST
 *   read.cpp
 *   May 9, 2017 (original)
 *   August 12, 2019 (last edit)
 *
 *   Methods of the Date class to read in a date.
 *
 *   #include "gbhdate.h"
 *
 ************************************************/


#include "gbhdate.h"
#include <iostream>
#include <cstdio>

using namespace std;


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
void Date::ReadInDate()
{
	int d,m,y;
	bool beenThroughOnce;
	string junk;

	beenThroughOnce=false;
	do
	{
		if(beenThroughOnce)
			printf("There was an error in the date. Please retry.\n");

		y=ReadInt("year");
		m=ReadInt("month");
		d=ReadInt("day");

		beenThroughOnce=true;

	}while(!setDate(y,m,d));


	//Literally the most important line of code in this method.
	//If you delete this, you will have significant problems
	//reading anything else. Cin is annoying.
	getline(cin,junk);
}
