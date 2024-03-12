/*
 *异常处理使程序员能够创建应用程序来解决异常，使程序更加健壮
 *try catch throw
 *堆栈展开
 *new动态分配空间失败
 *unique_ptr阻止内存泄漏
 */

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