#include<iostream>

using namespace std;

class Point
{
public:
	Point(float a = 0, float b = 0);//���캯��
	void setPoint(float, float);//�����µ�ֵ
	float getX() const{ return x; }
	float getY() const { return y; }//���xy
	friend ostream& operator <<(ostream&, const Point&);
protected:
	float x, y;
};
