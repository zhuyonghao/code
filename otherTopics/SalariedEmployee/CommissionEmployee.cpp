#include <iostream>
#include <stdexcept>
#include "CommissionEmployee.h"

using namespace std;

CommissionEmployee::CommissionEmployee(const string& first,
	const string& last, const string& ssn, double sales, double rate)
	:Employee(first, last, ssn)
{
	setCommissionRate(rate);
	setCommissionSales(sales);
}

void CommissionEmployee::setCommissionRate(double rate)
{
	if (rate > 0.0 && rate < 1.0)
		commissionRate = rate;
	else
		throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
}

double CommissionEmployee::getCommissionRate() const
{
	return commissionRate;
}

void CommissionEmployee::setCommissionSales(double sales)
{
	if (sales >= 0.0)
		grossSales = sales;
	else
		throw invalid_argument("Gross sales must be >= 0.0");
}

double CommissionEmployee::getCommissionSales() const
{
	return grossSales;
}

double CommissionEmployee::earnings() const
{
	return getCommissionRate() * getCommissionSales();
}

void CommissionEmployee::print() const
{
	cout << "commission employee: ";
	Employee::print();
	cout << "\ngross sales: " << getCommissionSales()
		<< "; commission rate: " << getCommissionRate();
}
