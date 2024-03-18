#include "point.h"

class Circle :public Point
{
public:
	Circle(float x = 0, float y = 0, float r = 0);
	void setR(float);
	float getR() const;
	float area() const;
	friend ostream& operator<<(ostream&, const Circle&);
protected:
	float radius;
};