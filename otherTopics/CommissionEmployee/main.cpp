#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h"

using namespace std;

int main()
{
	CommissionEmployee employee(
		"Sue", "Jones", "222-22-2222", 10000, 0.06
	);
	cout << fixed << setprecision(2);
	cout << employee.getFirstName() << '\n'
		<< employee.getLastName() << '\n'
		<< employee.getSocialSecurityNumber() << '\n'
		<< employee.getGrossSales() << '\n'
		<< employee.getComissionRate() << '\n';
	employee.setCommissionRate(0.1);
	employee.setGrossSales(8000);
	employee.print();
	employee.earnings();
}