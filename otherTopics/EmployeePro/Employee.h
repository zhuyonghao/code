#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
public:
	Employee(const std::string&, const std::string&);
	~Employee();
	std::string getFirstName() const;
	std::string getLastName() const;

	static unsigned int getCount();
private:
	std::string firstName;
	std::string lastName;

	static unsigned int count;
};

#endif