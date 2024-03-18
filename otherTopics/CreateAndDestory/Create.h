#include <iostream>

using namespace std;

#ifndef CREATE_H
#define CREATE_H

class CreateAndDestory
{
public:
	CreateAndDestory(int, string);
	~CreateAndDestory();
private:
	string message;
	int objectID;
};

#endif