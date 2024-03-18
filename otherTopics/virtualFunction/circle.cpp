#include"circle.h"

Circle::Circle(float a, float b, float r):Point(a,b),radius(r){}

void Circle::setR(float r)
{
	radius = r;
}

float Circle::getR() const { return radius; }

float Circle::area() const { return 3.14159 * radius * radius; }

ostream& operator<< (ostream & output, const Circle & c)
{
	output << c.x << "," << c.y << " " << c.radius << " " << c.area() << endl;
	return output;
}

