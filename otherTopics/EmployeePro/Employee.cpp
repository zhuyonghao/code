#include <iostream>
#include "Employee.h"

using namespace std;

unsigned int Employee::count = 0;
//��������ǰ���static����Ȼ���������ļ����ò���

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

