/*
 *编译器可以内联函数对象重载的operator()来提高性能
 *由于是类的对象，函数对象可以具有operator()用来执行任务的数据成员
 */

/*
#include <iostream>
#include <array>      //数组类模板
#include <algorithm>  //copy
#include <numeric>    //accumulate
#include <functional> //binary_function
#include <iterator>   //ostream_iterator

using namespace std;

int sumSquares(int total, int value)
{
    return total + value * value;
}

template <typename T>
class SumSquaresClass
{
public:
    T operator()(const T &total, const T &value)
    {
        return total + value * value;
    }
};

int main()
{
    const size_t SIZE = 10;
    array<int, SIZE> integers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ostream_iterator<int> output(cout, " ");

    cout << "array integers contains:\n";
    copy(integers.cbegin(), integers.cend(), output);

    int result = accumulate(integers.cbegin(), integers.cend(),
                            0, sumSquares);

    cout << "\n\nSum of suqares of elements in integers using"
         << "binary\nfunction sumSquare: " << result;

    result = accumulate(integers.cbegin(), integers.cend(),
                        0, SumSquaresClass<int>());
    cout << "\n\nSum of suqares of elements in integers using"
         << "binary\nfunction object: " << result;
}
*/

/*
 *lLambda表达式是匿名函数的一个用法，
 *可以用来创建小的、简单的函数。
 *Lambda表达式的一般形式为：lambdaIntroducer[] 参数列表 函数体
 */

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    const size_t SIZE = 4;
    array<int, SIZE> values = {1, 2, 3, 4};

    for_each(values.cbegin(), values.cend(),
             [](int i)
             { cout << i * 2 << endl; });
    int sum = 0;

    for_each(values.cbegin(), values.cend(), [&sum](int i)
             { sum += i; });
    cout << "sum is " << sum << endl;
}