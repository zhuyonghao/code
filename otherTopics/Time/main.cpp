#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
	Time t;
	t.setHour(18).setMinute(30).setSecond(22);
	t.printStandard();
	cout << endl;
	t.printUniversal();
	cout << endl;
	t.setTime(20, 20, 20).printStandard();
}