#include <iostream>
#include "Employee.h"

using namespace std;

int main()
{
	cout << Employee::getCount() << '\n';
	{
		Employee e1("susan", "baker");
		Employee e2("Robert", "jones");
		cout << Employee::getCount() << endl;
		cout << e1.getFirstName() << " " << e1.getLastName() << endl;
		cout << e2.getFirstName() << " " << e2.getLastName() << endl;
	}
	cout << Employee::getCount();
}