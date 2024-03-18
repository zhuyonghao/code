#include<iostream>

using namespace std;

class Point
{
public:
	Point(float a = 0, float b = 0);//构造函数
	void setPoint(float, float);//设置新的值
	float getX() const{ return x; }
	float getY() const { return y; }//获得xy
	friend ostream& operator <<(ostream&, const Point&);
protected:
	float x, y;
};
