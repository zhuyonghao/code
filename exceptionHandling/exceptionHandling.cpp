/*
 *异常处理使程序员能够创建应用程序来解决异常，使程序更加健壮
 *try catch throw
 *重新抛出异常：
 *捕获到一个异常后，你可能想先执行一些操作
 *例如，释放某些资源或记录错误日志等）
 *然后继续将这个异常抛出，使得外层代码能够知道这个错误并处理。
 *********************************************************
 *堆栈展开：
 *程序的控制流会跳过所有的未执行代码，
 *直到找到一个能接受该异常类型的catch块。
 *如果在调用堆栈中没有找到这样的catch块，程序会终止。
 *********************************************************
 *什么时候使用异常处理
 *构造函数、析构函数和异常处理
 *异常和继承：利用多态以简洁的方式捕获相关的错误
 *********************************************************
 *new动态分配空间失败：抛出bad_alloc异常
 *使用函数set_new_handle处理new失败
 *********************************************************
 *unique_ptr阻止内存泄漏
 */
/*
// 重新抛出异常来处理异常
#include <iostream>
#include <stdexcept>
using namespace std;

void throwException()
{
    try
    {
        cout << "   Function throwException throws an Exception\n";
        throw exception(); // 抛出异常
    }
    catch (exception &)
    {
        cout << "   Exception handled in function throwException"
             << "Function throwException rethrow exception";
        throw; // 处理异常后重新抛出
    }

    cout << "This also should not be print\n";
}

int main()
{
    try
    {
        cout << "\nmain invoke function throwException\n";
        throwException();
        cout << "This should not be print\n";
    }
    // 没有用到异常参数，所以忽略了名字
    catch (exception &)
    {
        cout << "\nException handled in main\n";
    }

    cout << "Program control continues after catch in main\n";
}


// 堆栈展开
// 当异常被抛出但没有在一个特定的作用域内被捕获时，函数调用堆栈堆栈
// 并试图在下一个外部的try...catch语句块内捕获这个异常
// 展开函数调用堆栈意味着在其中异常没有被捕获到的函数将会结束
// 此函数中完成初始化的所有变量将被销毁，并且控制将返回到最初调用该函数的语句

#include <iostream>
#include <stdexcept>
using namespace std;

void function3()
{
    cout << "in function 3" << endl;

    throw runtime_error("runtime_error in funciton3");
}

void function2()
{
    cout << "funciton3 is called inside function2" << endl;
    function3();
}

void function1()
{
    cout << "function2 is called inside function1" << endl;
    function2();
}

int main()
{
    try
    {
        cout << "function1 is called inside main" << endl;
        function1();
    }
    catch (runtime_error &error)
    {
        cout << "Exception occured: " << error.what() << endl;
        cout << "Exception handled in main" << endl;
    }
}
*/

// unique_ptr
#include <memory>
#include <iostream>

using namespace std;

class Integer
{
private:
    int value;

public:
    Integer(int i = 0);
    ~Integer();
    void setInteger(int i);
    int getInteger() const;
};

Integer::Integer(int i)
    : value(i)
{
    cout << "Constructor for integer" << value << endl;
}

Integer::~Integer()
{
    cout << "Destructor for integer" << value << endl;
}

void Integer::setInteger(int i)
{
    value = i;
}

int Integer::getInteger() const
{
    return value;
}

// unique<className> ptrName(new className());

int main()
{
    cout << "Creating a unique_ptr object that point to an Integer\n";
    unique_ptr<Integer> ptrToInteger(new Integer(7));

    ptrToInteger->setInteger(99);

    cout << (*ptrToInteger).getInteger() << endl;
}

// 指向内置数组的unique_ptr
// unique_ptr<string[]> ptr(new string[10]);