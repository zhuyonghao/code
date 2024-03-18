/*#include <iostream>

using namespace std;

class Point
{
public:
	Point(float a,float b):x(a),y(b){}//���캯���Ĳ����б�
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
	//Circle* pt = new Circle(2.5, 1.8, 4.5);//�������ำֵ
	delete p;//�����࣬����
	//ֻɾ������������Ϊû��ָ��
}//�麯������ָ��ӻ��಻��ָ�������࣬����ɾ��ʱ������ɾ����������ɾ������

*/

#include <iostream>

using namespace std;

class Shape
{
public:
	virtual double area() const = 0;//��������д��麯��
};

class Circle : public Shape
{
public:
	Circle(double r):radius(r){}//���캯��
	virtual double area() const { return 3.14159 * radius * radius; }
private:
	double radius;
};

class Square :public Shape
{
public:Square(double s):side(s) {}//���캯��
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
private://���崿�麯��
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

//void printArea(const Shape& s)//���������
//{//��������Ļ��ಿ�ִ��ݸ���������ã��麯���滻��ԭ�����麯��
	//cout << s.area();//��̬����}

int main()
{
	Circle c(12.6);
	Square s(3.5);
	Rectangle re(4.5, 8.4);
	Trapezoid tx(2.0, 4.5, 3.2);
	Triangle t(4.5, 8.4);
	Shape* pt[5] = { &c,&s,&re,&tx,&t };//ָ������ָ�������������Ļ����ַ��ֵ
	double area = 0.0;//��������ֱ���û����ָ��������������麯��������Ҫ����ָ�������������ʵ���˶�̬
	for (int i = 0; i < 5; i++)
	{
		area += pt[i]->area();
	}
	cout << area;
}
