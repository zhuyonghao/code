#include <iostream>
#include "Employee.h"

using namespace std;

unsigned int Employee::count = 0;
//不可以在前面加static，不然其他其他文件引用不到

unsigned int Employee::getCount()
{
	return count;
}

Employee::Employee(const string& first, const string& last)
	: firstName(first), lastName(last)
{
	++count;
	cout << "Employee constructor for " << firstName
		<< ' ' << lastName << " called." << endl;
}

Employee::~Employee()
{
	cout << "~Employee() called for " << firstName
		<< ' ' << lastName << endl;
	--count;
}

string Employee::getFirstName() const
{
	return firstName;
}

string Employee::getLastName() const
{
	return lastName;
}

