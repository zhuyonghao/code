// typedef basic_string<char> string;

// 初始化string对象
// string text("Hello");一个参数的构造函数
// string name(8, 'x');两个参数的构造函数
// string month = "March";构造函数的隐式调用

// 字符串的输入和输出
// string stringObject;
// getline(cin, string1);可以读取空格

#include <iostream>
#include <string>
using namespace std;

/*
//字符串的赋值和连接
int main()
{
    // 初始化
    string string1("cat");
    string string2;
    string string3;

    string2 = string1;
    string3.assign(string1);

    cout << "string1: " << string1 << "\nstring2: " << string2
         << "\nstring3: " << string3 << endl;

    string2[0] = string3[2] = 'r';

    cout << "After modification\n";
    cout << "string1: " << string1 << "\nstring2: " << string2
         << "\nstring3: " << string3 << endl;

    for (size_t i = 0; i < string3.size(); ++i)
        // at可进行越界访问检测
        cout << string3.at(i) << ' ';
    cout << endl;

    string string4(string1 + "apult");
    string string5;

    string3 += "pet";
    string1.append("acomb");

    string5.append(string1, 4, string1.size() - 4);
    cout << string1 << ' ' << string2 << ' ' << string3 << ' '
         << string4 << ' ' << string5 << endl;
}
*/

// 字符串的比较
int main()
{
    string string1("Testing the comparison functions.");
    string string2("Hello");
    string string3("stinger");
    string string4(string2);

    cout << "string1: " << string1 << "\nstring2: " << string2
         << "\nstring3: " << string3 << "\nstring4: " << string4 << endl;

    if (string1 == string4)
        cout << "string1 == string4\n";
    else if (string1 > string4)
        cout << "string1 > string4\n";
    else
        cout << "string1 < string4\n";

    int result = string1.compare(string2);

    if (result == 0)
        cout << "string1.compare(string2) == 0\n";
    else if (result > 0)
        cout << "string1.compare(string2) > 0\n";
    else
        cout << "string1.compare(string2) < 0\n";
    // 比较string1 2-5 和 string3 0-5
    result = string1.compare(2, 5, string3, 0, 5);

    if (result == 0)
        cout << "string1.compare(2, 5, string3, 0, 5) == 0\n";
    else if (result > 0)
        cout << "string1.compare(2, 5, string3, 0, 5) > 0\n";
    else
        cout << "string1.compare(2, 5, string3, 0, 5) < 0\n";
    // string2从0-size和string4比较
    result = string4.compare(0, string2.size(), string2);

    if (result == 0)
        cout << "string4.compare(0, string2.size(), string2) == 0\n";
    else if (result > 0)
        cout << "string4.compare(0, string2.size(), string2) > 0\n";
    else
        cout << "string4.compare(0, string2.size(), string2) < 0\n";
    // 用string2的0-3与string4比较
    result = string2.compare(0, 3, string4);

    if (result == 0)
        cout << "string2.compare(0, 3, string4) == 0\n";
    else if (result > 0)
        cout << "string2.compare(0, 3, string4) > 0\n";
    else
        cout << "string2.compare(0, 3, string4) < 0\n";
}