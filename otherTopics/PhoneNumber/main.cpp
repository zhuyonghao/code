#include <iostream>
#include "PhoneNumber.h"

using namespace std;

int main()
{
	PhoneNumber phone;
	cout << "Enter phone number in the form (123) 456-7890:" << endl;
	cin >> phone;//operator >> (cin,phone);
	cout << "The phone number entered was: ";
	cout << phone << endl;
}