#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

void virtualViaPointer(const Employee* const);
void virtualViaReference(const Employee&);

int main()
{
	cout << fixed << setprecision(2);

	SalariedEmployee salariedEmployee(
		"John", "Smith", "111-11-1111", 800);
	CommissionEmployee commissionEmployee(
		"Sue", "Jones", "333-33-3333", 10000, 0.06);
	BasePlusCommissionEmployee basePlusCommissionEmployee(
		"Bob", "Lewis", "444-44-4444", 5000, 0.04, 300);

	cout << "Employees processed individually using static binding:\n\n";

	salariedEmployee.print();
	cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
	commissionEmployee.print();
	cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
	basePlusCommissionEmployee.print();
	cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

	vector<Employee*>employees(3);
	employees[0] = &salariedEmployee;
	employees[1] = &commissionEmployee;
	employees[2] = &basePlusCommissionEmployee;

	cout << "Employees processed polymorphically via dynamic binding:\n\n";
	cout << "Virtual function calls made off base- class pointers:\n\n";
	for (const Employee* employeePtr : employees)
		virtualViaPointer(employeePtr);
	cout << "Virtual function calls made off base- class references:\n\n";
	for (const Employee* employeePtr : employees)
		virtualViaReference(*employeePtr);

}

void virtualViaPointer(const Employee* const baseClassPtr)
{
	baseClassPtr->print();
	cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}

void virtualViaReference(const Employee& baseClass)
{
	baseClass.print();
	cout << "\nearned $" << baseClass.earnings() << "\n\n";
}