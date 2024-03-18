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
		get_value();//��Ա��������
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
	stud1.get_value_1();//���û���ĺ���displayλ���õ�
	stud1.display_1();
}//˽�м̳�ʱ�޷��������û����еĹ��ú�����Ϊ�Ѿ���Ϊ��˽��
//������Ա��˽�г�Ա���ֻ�����������ܷ�ʹ��
//�����̳�ԭ��˽�н����Ϊ���ɷ���
//����ԭ���ı�����Ա���ú������Ե�������

//˽��  �������ַ�ʽ�����ɷ���
//���� �̳з�ʽ Ϊ��Ա��������
//���� ˽�У�˽�� ���ã����� ���� ������

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
	B(int i) :A(i) { c = 0; }//�����๹�캯��
	B(int i, int j) :A(i, j) { c = 0; }//�ȵ��û��๹�캯��
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
	C() { cout << "3" << endl; }//������Ĺ��캯���ȵ��û���Ĺ��캯��
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
	Teacher(string nam, int a, char s, string tit, string ad, string t);//���캯������
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
//���캯������
void Teacher::display()
{
	cout<< name<<" " << age <<" " << sex<<" " << title <<" " << addr <<" " << tel<<endl;
}

class Gadre
{
public:
	Gadre(string nam, int a, char s, string p, string ad, string t);//���캯������
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
//���캯������
void Gadre::display()
{
	cout << name << " " << age << " " << sex << " " <<post << " " << addr << " " << tel << endl;
}

class Person :public Teacher, public Gadre//���ؼ̳�
{
public:
	Person(string nam, int a, char s, string tit, string p, string ad, string t, float w);
	void show();//�������ʼ��
private:
	float wage;
};
//�����ȳ�ʼ��Ȼ���������ʼ��
Person::Person(string nam, int a, char s, string tit, string p, string ad, string t, float w):
	Teacher(nam, a, s, tit, ad, t), Gadre(nam, a, s, p, ad, t),wage(w){}
void Person::show()
{
	Teacher::display();//ָ��������Ȼ�����
	cout << Gadre::post << " " << wage;//���Grade�е�post
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
	Teacher(int, string, char);//���캯��
	void display();//���
private:
	int num;
	string name;
	char sex;
};

Teacher::Teacher(int n, string nam, char s):num(n),name(nam),sex(s){}
//���캯����ʼ���б�
void Teacher::display()
{
	cout << num << " " << name << " " << sex<<" ";
}

class BirthDate
{
public:
	BirthDate(int, int, int);
	void display();
	void change(int, int, int);//�޸ĺ���
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
{//���ü̳�Teacher
public:
	Professor(int, string, char, int, int, int, float);//�����๹�캯������
	void display();
	void change(int,int,int);//���ú�����Ա
private:
	float area;
	BirthDate birthday;//�����еĶ���
};
//�ȳ�ʼ���࣬�ڳ�ʼ���Ӷ�������ʼ��������
Professor::Professor(int n, string nam, char s, int y, int m, int d, float a):
	Teacher(n,nam,s),birthday(y,m,d),area(a){}

void Professor::display()//��Ա����
{
	Teacher::display();//���ü̳е�display������ָ����������
	birthday.display();//����˽�г�Ա�еĶ���ʹ����ú���
	cout << area<<endl;
	//cout << birthday.year����������Ϊֻ��ͨ��p��Ա����������b�ĳ�Ա�������ı�����˽�г�Ա
}

void Professor::change(int y, int m, int d)
{//ͨ�������������ú���
	birthday.change(y, m, d);//����˽�г�Ա�е��Ӷ���ʹ�����change����
}

int main()
{
	Professor prof(3012, "zhang", 'f', 1949, 10, 1, 125.4);
	prof.display();
	prof.change(1950, 6, 1);//���ù��ú�����change����Ȼ���ٵ����Ӷ�����ʹ��ı����ʾ
	prof.display();//�ö�������ʽ��������Ϊ�����Ǽ̳�����
}