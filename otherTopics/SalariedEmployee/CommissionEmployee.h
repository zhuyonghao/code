#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include "Employee.h"
#include <string>

class CommissionEmployee: public Employee
{
public:
	CommissionEmployee(const std::string&, const std::string&,
		const std::string&, double = 0, double = 0);
	virtual ~CommissionEmployee(){}

	void setCommissionRate(double);
	double getCommissionRate() const;

	void setCommissionSales(double);
	double getCommissionSales() const;

	virtual double earnings() const override;
	virtual void print() const override;

private:
	double grossSales;
	double commissionRate;
};


#endif
