/*
#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	void get_value()
	{cin >> num >> name >> sex; }
	void display()
	{
		cout << num << " " << name << " " << sex << endl;
	}
protected:
	int num;
	string name;
	char sex;
};

class Student1 :protected Student
{
public:
	void get_value_1()
	{
		get_value();//成员函数公用
		cin >> age >> addr;
	}
	void display_1()
	{
		display();
		cout << age << " " << addr;
	}
private:
	int age;
	string addr;
};

int main()
{
	Student1 stud1;
	stud1.get_value_1();//调用基类的函数display位公用的
	stud1.display_1();
}//私有继承时无法在外界调用基类中的公用函数因为已经成为了私有
//保护成员和私有成员差不多只是在派生类能否使用
//保护继承原来私有将会变为不可访问
//但是原来的保护成员公用函数可以调用他们

//私有  无论哪种方式都不可访问
//公用 继承方式 为成员访问属性
//保护 私有：私有 公用：保护 保护 ：保护

#include<iostream>
using namespace std;

class A
{
public:
	A() { a = 0; b = 0; }
	A(int i) { a = i; b = 0; }
	A(int i, int j) { a = i; b = j; }
	void display() { cout << a << " " << b; }
private:
	int a, b;
};

class B :public A
{
public:
	B() { c = 0; }
	B(int i) :A(i) { c = 0; }//派生类构造函数
	B(int i, int j) :A(i, j) { c = 0; }//先调用基类构造函数
	B(int i, int j, int k) :A(i, j) { c = k; }
	void display1()
	{
		display();
		cout << c << endl;
	}
private:
	int c;
};

int main()
{
	B b1, b2(1), b3(1, 1), b4(1, 1, 1);
	b1.display1();
	b2.display1();
	b3.display1();
	b4.display1();
}
#include<iostream>
using namespace std;

class A
{
public:
	A() { cout << "1" << endl; }
	~A() { cout << "A" << endl; }
};

class B:public A
{
public:
	B() { cout << "2" << endl; }
	~B() { cout << "B" << endl; }
};

class C:public B
{
public:
	C() { cout << "3" << endl; }//派生类的构造函数先调用基类的构造函数
	~C() { cout << "C" << endl; }
};

int main()
{
	C c;
}

#include<iostream>
#include<string>
using namespace std;

class Teacher
{
public:
	Teacher(string nam, int a, char s, string tit, string ad, string t);//构造函数声明
	void display();
protected:
	string name;
	int age;
	char sex;
	string title;
	string addr;
	string tel;
};
Teacher::Teacher(string nam, int a, char s, string tit, string ad, string t):name(nam),age(a), sex(s),title(tit), addr(ad), tel(t){}
//构造函数定义
void Teacher::display()
{
	cout<< name<<" " << age <<" " << sex<<" " << title <<" " << addr <<" " << tel<<endl;
}

class Gadre
{
public:
	Gadre(string nam, int a, char s, string p, string ad, string t);//构造函数声明
	void display();
protected:
	string name;
	int age;
	char sex;
	string post;
	string addr;
	string tel;
};

Gadre::Gadre(string nam, int a, char s, string p, string ad, string t) :name(nam), age(a), sex(s), post(p), addr(ad), tel(t) {}
//构造函数定义
void Gadre::display()
{
	cout << name << " " << age << " " << sex << " " <<post << " " << addr << " " << tel << endl;
}

class Person :public Teacher, public Gadre//多重继承
{
public:
	Person(string nam, int a, char s, string tit, string p, string ad, string t, float w);
	void show();//派生类初始化
private:
	float wage;
};
//基类先初始化然后派生类初始化
Person::Person(string nam, int a, char s, string tit, string p, string ad, string t, float w):
	Teacher(nam, a, s, tit, ad, t), Gadre(nam, a, s, p, ad, t),wage(w){}
void Person::show()
{
	Teacher::display();//指定作用域然后输出
	cout << Gadre::post << " " << wage;//输出Grade中的post
}

int main()
{
	Person person1("wangli", 50, 'f', "prof", "president", "shanghai", "110", 131.4);
	person1.show();
}*/
#include<iostream>
using namespace std;

class Teacher
{
public:
	Teacher(int, string, char);//构造函数
	void display();//输出
private:
	int num;
	string name;
	char sex;
};

Teacher::Teacher(int n, string nam, char s):num(n),name(nam),sex(s){}
//构造函数初始化列表
void Teacher::display()
{
	cout << num << " " << name << " " << sex<<" ";
}

class BirthDate
{
public:
	BirthDate(int, int, int);
	void display();
	void change(int, int, int);//修改函数
private:
	int year;
	int month;
	int day;
};

BirthDate::BirthDate(int y, int m, int d) :year(y), month(m), day(d){}

void BirthDate::display()
{
	cout << month << "/" << day << "/" << year<<" ";
}

void BirthDate::change(int y,int m,int d)
{
	year = y;
	month = m;
	day = d;
}

class Professor :public Teacher
{//公用继承Teacher
public:
	Professor(int, string, char, int, int, int, float);//派生类构造函数声明
	void display();
	void change(int,int,int);//公用函数成员
private:
	float area;
	BirthDate birthday;//对象中的对象
};
//先初始基类，在初始化子对象，最后初始化派生类
Professor::Professor(int n, string nam, char s, int y, int m, int d, float a):
	Teacher(n,nam,s),birthday(y,m,d),area(a){}

void Professor::display()//成员函数
{
	Teacher::display();//调用继承的display函数，指出其作用域
	birthday.display();//调用私有成员中的对象使其调用函数
	cout << area<<endl;
	//cout << birthday.year不可以是因为只能通过p成员函数来调用b的成员函数来改变他的私有成员
}

void Professor::change(int y, int m, int d)
{//通过对象名来调用函数
	birthday.change(y, m, d);//调用私有成员中的子对象使其调用change函数
}

int main()
{
	Professor prof(3012, "zhang", 'f', 1949, 10, 1, 125.4);
	prof.display();
	prof.change(1950, 6, 1);//调用公用函数的change函数然后再调用子对象函数使其改变后显示
	prof.display();//用对象名方式调用是因为它不是继承来的
}