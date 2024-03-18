#include "circle.h"

class Cylinder :public Circle
{
public:
	Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);
	void setH(float);
	float getH() const;
	float area() const;
	float volume() const;
	friend ostream& operator<<(ostream&, const Circle&);
protected:
	float height;
};