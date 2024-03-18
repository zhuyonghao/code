#include "Date.h"

int main()
{
	Date date1(7, 4, 2004);
	Date date2;
	date1.print();
	date2.print();
	date2 = date1;
	date2.print();
}