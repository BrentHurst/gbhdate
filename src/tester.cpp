#include <cstdio>
#include <iostream>
#include "gbhdate.hpp"

using namespace std;

int main()
{
	char c;

	GBH_Date D(20200708);

	D.Print();

	do
	{
		D.ReadInDate();
		D.Print();
		cout << "continue? [y/n]: ";
		cin >> c;
	}while(c == 'y');


	return 0;
}
