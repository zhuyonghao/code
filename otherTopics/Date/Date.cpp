#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int m, int d, int y)
	:month(m), day(d), year(y)
{
}

void Date::print() const
{
	cout << month << "/" << day << "/" << year << endl;
}