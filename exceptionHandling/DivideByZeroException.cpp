/*
 *try调用函数，如果出现异常，函数throw一个异常类
 *catch将会捕获异常类并输出内容
 */

#include <stdexcept>
#include <iostream>
using namespace std;

class DivideByZeroException : public std::runtime_error
{
public:
    DivideByZeroException() : std::runtime_error("attempted to divide by zero") {}
};

double quotient(int numerator, int denominator)
{
    if (denominator == 0)
        throw DivideByZeroException();

    return static_cast<double>(numerator) / denominator;
}

int main()
{
    int number1;
    int number2;

    cout << "Enter two integers (end-of-file to end): ";
    while (cin >> number1 >> number2)
    {
        try
        {
            double result = quotient(number1, number2);
            cout << "The quotient is: " << result << endl;
        }
        // 避免了对异常对象的复制
        // what属于虚函数
        catch (DivideByZeroException &divideByZeroException)
        {
            cout << "Exception occured: "
                 << divideByZeroException.what() << endl;
        }

        cout << endl;
    }
}