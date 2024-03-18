/*#include<iostream>
using namespace std;

class Date
{
public:
	//Date();
	//Date(int);
	//Date(int, int);
	Date(int month=4, int day=16, int year=2005);//函数重载与带有默认参数的构造函数出现歧义
	void display();
private:
	int year;
	int month;
	int day;
};

Date::Date()
{
	month = 4;
	day = 16;
	year = 2005;
 }
 
Date::Date(int m) :month(m) { day = 16; year = 2005; }

Date::Date(int m, int d) :month(m), day(d) { year = 2005; }

Date::Date(int m,int d,int y):month(m),day(d),year(y){}

void Date::display()
{
	cout << month << "/" << day << "/" << year << endl;
}

int main()
{
	Date date1, date2(1), date3(1,1), date4(11,25,2006);
	date1.display();
	date2.display();
	date3.display();
	date4.display();
}//只能按照参数顺序

#include<iostream>
using namespace std;

class Student
{
public:
	Student(int n, float s):num(n),score(s){}
	void display();
	int num;
	float score;
};

void Student::display()
{
	cout << num << " " << score << endl;
}

int main()
{
	void max(Student * p);
	Student stud[5] = { Student(101,78.5),Student(102,85.5),Student(103,98.5),Student(104,100.0),Student(105,98.5) };
	Student* p = stud;
	max(p);
}

void max(Student* p)
{
	Student* pmax = p;
	float max = p->score;
	for(int i=1;i<5;i++,p++)
		if (p->score > max)
		{
			max = p->score;
			pmax = p;
		}
	pmax->display();
}
#include<iostream>
using namespace std;
class Student
{
public:
	Student(int n,float s):num(n),score(s){}//初始化才可以使用这种写法
	void change(int n, float s) { num = n; score = s; }
	void display() const;
private:
	int num;
	float score;
};

void Student::display() const 
{
	cout << num << "\n";
	cout << score << "\n";
}

int main()
{
	void fun(Student & stud);
	Student stud(101, 78.5);
	fun(stud);
}

void fun(Student& stud)
{
	stud.display();
	stud.change(10,85);
	stud.display();
}

#include<iostream>
using namespace std;

class Product
{
public:
	Product(int n, int q, float p) :num(n), quantity(q), price(p) {}
	void total();
	static float average();
	static void display();//静态成员函数
private:
	int num;
	int quantity;
	float price;
	static float discount;
	static float sum;
	static int n;//静态变量数据共享
};

void Product::total()
{
	float rate = 1.0;
	if (quantity > 10) rate *= 0.98;
	sum += quantity * price * rate * (1 - discount);//普通成员函数可以访问静态成员
	n += quantity;
}

void Product::display()
{
	cout << sum << endl;
	cout << average() << endl;
}

float Product::average()
{
	return (sum / n);
}

float Product::discount = 0.05;
float Product::sum = 0;
int Product::n = 0;//静态数据成员可以进行初始化
//静态函数只能调用静态的数据和函数因为没有this指针

int main()
{
	Product Prod[3] = { Product(101,5,23.5),Product(102,12,24.56), Product(103,100,21.5) };
	for (int i = 0; i < 3; i++)
		Prod[i].total();
	Product::display();
}

#include<iostream>
using namespace std;

class Date;
class Time
{
public:
	Time(int h,int m,int s):hour(h),minute(m),second(s){}
	friend void display(const Date&, const Time&);
private:
	int hour;
	int minute;
	int second;
};
class Date
{
public:
	Date(int m, int d, int y);
	friend void display(const Date&, const Time&);//非成员函数因为没有this指针所以需要常引用
private:
	int month;//友元函数和友元成员函数
	int day;
	int year;
};

Date::Date(int m, int d, int y):month(m),day(d),year(y){}

void display(const Date&d, const Time&t)
{
	cout << d.month << " " << d.day << " " << d.year << endl;
	cout << t.hour << " " << t.minute << " " << t.second << endl;
}

int main()
{
	Time t1(10, 13, 56);
	Date d1(12, 25, 2004);
	display(d1, t1);
} 

#include<iostream>
using namespace std;

class Time;
class Date
{
public:
	Date(int, int, int);
	friend Time;//Time是友元类
private:
	int month;
	int day;
	int year;
};
Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

class Time
{
public:
	Time(int h, int m, int s) :hour(h), minute(m), second(s) {}
	void display(const Date&);//友元成员函数
private:
	int hour;
	int minute;
	int second;
};

void Time::display(const Date& d1)
{
	cout << d1.month << " " << d1.day << " " << d1.year << endl;
	cout << hour << " " << minute << " " << second << endl;
}

int main()
{
	Time t1(10, 13, 56);
	Date d1(12, 25, 2004);
	t1.display(d1);
}*/
#include<iostream>
using namespace std;

template<class numtype>//模板声明

class Compare
{
public:
	Compare(numtype a, numtype b);//构造函数声明
	numtype max();
	numtype min();//成员函数
private:
	numtype x, y;
};

template<class numtype>//声明
Compare<numtype>::Compare(numtype a, numtype b)//类中的构造函数
{
	x = a;
	y = b;
}

template<class numtype>
numtype Compare<numtype>::max()
{
	return (x > y) ? x: y;
}

template<class numtype>
numtype Compare<numtype>::min()
{
	return (x < y) ? x: y;
}

int main()
{
	Compare<int> cmp1(3, 7);
	cout << cmp1.max() << endl;
	cout << cmp1.min() << endl;
	Compare<float> cmp2(2.1, 5.3);
	cout << cmp2.max() << endl;
	cout << cmp2.min() << endl;
	return 0;
}