#include "point.h"

Point::Point(float a,float b):x(a),y(b){}

void Point::setPoint(float a, float b)
{
	x = a;
	y = b;
}

ostream& operator<<(ostream& output, const Point& p)
{
	output << p.x << " " << p.y << endl;
	return output;//ÖØÔØÔËËã·û
}