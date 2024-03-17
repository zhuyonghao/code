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
#include <sstream>
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



//字串从第七位开始，数5个位置
int main()
{
    string string1("The airplane landed on time.");
    cout << string1.substr(7, 5) << endl;
}

//字符串交换
int main()
{
    string first("one");
    string second("two");

    cout << first << "  " << second << endl;

    first.swap(second);

    cout << first << "  " << second << endl;
}



// capacity: 15
// max size: 9223372036854775807
// 容量会不断变大
void printStatistics(const string &stringRef)
{
    cout << "capacity: " << stringRef.capacity() << "\nmax size: "
         << stringRef.max_size() << "\nsize: " << stringRef.size()
         << "\nlength: " << stringRef.length()
         << "\nempty: " << stringRef.empty();
}

int main()
{
    string string1;

    cout << "Statistics before input:\n"
         << boolalpha;
    printStatistics(string1);

    cout << "\n\nEnter a string: ";
    cin >> string1;
    cout << "The string entered was: " << string1;

    cout << "\nStatistics after input:\n";
    printStatistics(string1);

    cin >> string1;
    cout << "\n\nThe remaining string is: " << string1 << endl;
    printStatistics(string1);

    string1 += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
    cout << "\n\nstring1 is now: " << string1 << endl;
    printStatistics(string1);

    string1.resize(string1.size() + 10);
    cout << "\nStats after resizing by (length + 10):\n";
    printStatistics(string1);
    cout << endl;
}



int main()
{
    string string1("noon is 12 pm; midnight is not.");
    int location;

    cout << "Original string:\n"
         << string1
         << "\n\n(find) \"is\" was found at: " << string1.find("is")
         << "\n(rfind) \"is\" was found at: " << string1.rfind("is");
    // 从前查找第一个存在的字符的位置
    location = string1.find_first_of("misop");
    cout << "\n\n(find_first_of) found '" << string1[location]
         << "' from the group \"misop\" at: " << location;
    // 从后查找第一个存在的字符的位置
    location = string1.find_last_of("misop");
    cout << "\n\n(find_last_of) found '" << string1[location]
         << "' form the group \"misop\" at: " << location;
    // 查找第一个不存在字符的位置
    location = string1.find_first_not_of("noi spm");
    cout << "\n\n(find_first_not_of) '" << string1[location]
         << "' is not contained in \"noi spm\" and was found at: " << location;

    location = string1.find_first_not_of("12noi spm");
    cout << "\n\n(find_first_not_of) '" << string1[location]
         << "' is not contained in \"12noi spm\" and was "
         << "found at: " << location << endl;

    location = string1.find_first_not_of(
        "noon is 12 pm; midnight is not.");
    cout << "\nfind_first_not_of(\"noon is 12 pm; midnight is not.\")"
         << " returned: " << location << endl;
}



// 在字符串中替换字符
// 每个换行符在字符串中占用一个元素位置
int main()
{
    string string1("The values in any left subtree"
                   "\nare less than the value in the"
                   "\nparent node and the values in"
                   "\nany right subtree are greater"
                   "\nthan the value in the parent node");

    cout << "Original string :\n"
         << string1 << endl
         << endl;
    // 删除62位之后的元素
    string1.erase(62);

    cout << "Original string after erase:\n"
         << string1
         << "\nAfter first replacement:\n";

    size_t position = string1.find(" ");
    // 替换一位
    while (position != string::npos)
    {
        string1.replace(position, 1, ".");
        position = string1.find(" ", position + 1);
    }

    cout << string1 << "\nAfter second replacement:\n";

    position = string1.find(".");
    // 替换两位
    while (position != string::npos)
    {
        string1.replace(position, 2, "xxxxx;;yyy", 5, 2);
        position = string1.find(".", position + 1);
    }

    cout << string1 << endl;
}


// 在字符串中插入字符
// 从第0个元素开始
int main()
{
    string string1("beginning end");
    string string2("middle ");
    string string3("12345678");
    string string4("xx");

    cout << "Initial strings:\nstring1: " << string1
         << "\nstring2: " << string2 << "\nstring3: " << string3
         << "\nstring4: " << string4 << "\n\n";
    // 插入在第十个元素之前
    string1.insert(10, string2);

    string3.insert(3, string4, 0, string::npos);

    cout << "String after insert:\nstring1: " << string1
         << "\nstring2: " << string2 << "\nstring3: " << string3
         << "\nstring4: " << string4 << endl;
}



// 转换成C风格的基于指针的char*字符串
int main()
{
    string string1("STRINGS");
    const char *ptr1 = nullptr;
    size_t length = string1.size();
    char *ptr2 = new char[length + 1];

    string1.copy(ptr2, length, 0);
    ptr2[length] = '\0';

    cout << "string string1 is " << string1
         << "\nstring1 converted to a pointer-based string is "
         << string1.c_str() << "\nptr1 is ";
    // 返回一个不以空字符结束的、C字符的字符数组
    ptr1 = string1.data();

    for (size_t i = 0; i < length; ++i)
        cout << *(ptr1 + i);

    cout << "\nptr2 is " << ptr2 << endl;
    delete[] ptr2;
}


// 迭代器
int main()
{
    string string1("Testing iterators");
    string::const_iterator iterator1 = string1.begin();

    cout << "string1 = " << string1
         << "\n(Using iterator iterator1) string1 is: ";

    while (iterator1 != string1.end())
    {
        cout << *iterator1;
        ++iterator1;
    }

    cout << endl;
}


// 字符串流的处理
// 类istringstream支持从字符串中输入，类ostringstream支持输出到一个字符串
// 正则表达式用于辅助数据验证
int main()
{
    ostringstream outputString;

    string string1("Output of several data types ");
    string string2("to an ostringstream object:");
    string string3("\n         double: ");
    string string4("\n            int: ");
    string string5("\naddress of int: ");

    double double1 = 123.4567;
    int integer = 22;
    // 输出到一个字符串
    outputString << string1 << string2 << string3 << double1
                 << string4 << integer << string5 << &integer;
    // 输出到屏幕
    cout << "outputString contains:\n"
         << outputString.str();
    // 将更多数据输出到此字符串
    outputString << "\nmore characters added";
    cout << "\n\nafter additional stream insertions,\n"
         << "outputString contains:\n"
         << outputString.str() << endl;
}

*/

// 演示istringstream
// 此对象从内存的字符串将数据输入到程序的变量中
// 从字符串中读入输出到内存
int main()
{
    string input("Input test 123 4.7 A");
    istringstream inputString(input);
    string string1;
    string string2;
    int integer;
    double double1;
    char character;

    inputString >> string1 >> string2 >> integer >> double1 >> character;

    cout << "The following items were extracted\n"
         << "from the istringstream object:"
         << "\nstring: " << string1 << "\nstring: " << string2 << "\n   int: " << integer
         << "\ndouble: " << double1 << "\n  char: " << character;

    long value;
    inputString >> value;
    // 来测试是否还有数据剩余
    if (inputString.good())
        cout << "\n\nlong value is: " << value << endl;
    else
        cout << "\n\ninputString is empty" << endl;
}

// C++11 数值转化函数