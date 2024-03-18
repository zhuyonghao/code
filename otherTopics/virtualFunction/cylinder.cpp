#include"cylinder.h"

Cylinder::Cylinder(float a,float b,float r,float h):Circle(a,b,r),height(h){}

void Cylinder::setH(float h)
{
	height = h;
}

float Cylinder::getH() const{ return height; }

float Cylinder::area() const 
{ return 2 * Circle::area() + 2 * 3.14529 * radius * height; }

float Cylinder::volume()const 
{ return Circle::area() * height; }

ostream& operator<<(ostream& output, const Cylinder& cy)
{
	output <<cy.getX()<<" " << cy.getY() <<" " << cy.getR() <<
	cy.getH() << " " << cy.area() <<" "<<cy.volume() << endl;
	return output;
}