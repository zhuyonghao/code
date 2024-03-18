/*#include <iostream>

using namespace std;

class Point
{
public:
	Point(float a,float b):x(a),y(b){}//构造函数的参数列表
	virtual ~Point()
	{
		cout << "point destruct";
	}
private:
	float x, y;
};

class Circle :public Point
{
public:
	Circle(float a,float b,float r):Point(a,b),radius(r){}
	virtual ~Circle()
	{
		cout << "circle destructor";
	}
private:
	float radius;
};

int main()
{
	Point* p = new Circle(2.5, 1.8, 4.5);
	//Circle* pt = new Circle(2.5, 1.8, 4.5);//用派生类赋值
	delete p;//派生类，基类
	//只删除了派生类因为没有指针
}//虚函数中有指针从基类不断指向派生类，所以删除时可以先删除派生类再删除基类

*/

#include <iostream>

using namespace std;

class Shape
{
public:
	virtual double area() const = 0;//抽象基类有纯虚函数
};

class Circle : public Shape
{
public:
	Circle(double r):radius(r){}//构造函数
	virtual double area() const { return 3.14159 * radius * radius; }
private:
	double radius;
};

class Square :public Shape
{
public:Square(double s):side(s) {}//构造函数
	virtual double area() const { return side*side; }
private:
	double side;
};

class Trapezoid :public Shape
{
public:
	Trapezoid(double t, double b, double h):top(t),bottom(b),height(h){}
	virtual double area() const {return 0.5*(top+bottom)*height;
	}
private:
	double top, bottom, height;
};

class Rectangle :public Shape
{
public:
	Rectangle(double w,double h):width(w),height(h){}
	virtual double area() const { return width * height; }
private://定义纯虚函数
	double width, height;
};

class Triangle :public Shape
{
public:
	Triangle(double w,double h):width(w),height(h) {}
	virtual double area() const { return 0.5*width * height; }
private:
	double width, height;
};

//void printArea(const Shape& s)//基类的引用
//{//将派生类的基类部分传递给基类的引用，虚函数替换了原基类虚函数
	//cout << s.area();//动态关联}

int main()
{
	Circle c(12.6);
	Square s(3.5);
	Rectangle re(4.5, 8.4);
	Trapezoid tx(2.0, 4.5, 3.2);
	Triangle t(4.5, 8.4);
	Shape* pt[5] = { &c,&s,&re,&tx,&t };//指向基类的指针可以用派生类的基类地址赋值
	double area = 0.0;//这样可以直接用基类的指针引用派生类的虚函数，不需要单独指出派生类的名字实现了多态
	for (int i = 0; i < 5; i++)
	{
		area += pt[i]->area();
	}
	cout << area;
}
