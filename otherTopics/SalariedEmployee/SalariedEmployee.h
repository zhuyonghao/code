#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "Employee.h"


class SalariedEmployee: public Employee
{
public:
	SalariedEmployee(const std::string&, const std::string&,
		const std::string&, double = 0.0);//defalutWeeklySalary
	virtual ~SalariedEmployee() {}

	void setWeeklySalary(double);
	double getWeeklySalary() const;

	virtual double earnings() const override;
	virtual void print() const override;

private:
	double weeklySalary;
};

#endif
