#ifndef DATE_H
#define DATE_H

class Date
{
public:
	explicit Date(int = 1, int = 1, int = 2000);
	void print() const;
private:
	unsigned int month;
	unsigned int day;
	unsigned int year;
};

#endif