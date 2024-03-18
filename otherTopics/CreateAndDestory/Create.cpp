#include <iostream>
#include "Create.h"

using namespace std;

CreateAndDestory::CreateAndDestory(int ID, string messageString)
	:objectID(ID), message(messageString)
{
	cout << "Object " << objectID << "  constructor runs  "
		<< message << endl;
}

CreateAndDestory::~CreateAndDestory()
{
	cout << (objectID == 1 || objectID == 6 ? "\n" : "");
	cout << "Object " << objectID << "  destructor runs  "
		<< message << endl;
}