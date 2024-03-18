#include <iostream>
#include "Create.h"

using namespace std;

void create(void);

CreateAndDestory first(1, "global before main");//global object

int main()
{
	cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
	
	CreateAndDestory second(2, "(local automatic in main)");
	static CreateAndDestory third(3, "(local static in main)");

	create();

	cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << endl;
	CreateAndDestory fourth(4, "local automatic in main");
	cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;
}

void create(void)
{
	cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
	CreateAndDestory fifth(5, "(local automatic in create)");
	static CreateAndDestory sixth(6, "local static in create");
	CreateAndDestory seventh(7, "(local automatic in create)");
	cout << "\nCREATE FUNCTION: EXECUTION ENDS;" << endl;
}