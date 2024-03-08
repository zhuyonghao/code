/*
 *算法使用迭代器访问容器的元素，接收函数指针，算法利用指针来调用函数
 *函数指针类似于函数对象，具有重载的函数调用符()，像函数名一样来使用函数对象
 *C++11标准：lambda表达式创建匿名函数对象(没有名称函数对象)的速记机制
 **************************************************************************
 *每个容器的一个重要部分就是它所支持的迭代器类型，这决定了哪个算法可以应用到容器上，
 *每个以迭代器作为参数的标准库算法，都要求迭代器提供最低限度功能。
 *迭代器：前向迭代器，双向迭代器，随机访问迭代器
 */

/*

// fill、fill_n、generate和generate_n

#include <algorithm>
#include <iostream>
#include <array>
#include <iterator>

using namespace std;

char nextLetter();

int main()
{
    array<char, 10> chars;
    ostream_iterator<char> output(cout, " ");
    // 用5填充
    fill(chars.begin(), chars.end(), '5');

    cout << "\n\nchars after filling 5s:\n";
    copy(chars.cbegin(), chars.cend(), output);
    // 前五个用'A'填充
    fill_n(chars.begin(), 5, 'A');

    cout << "chars After filling five elements with As:\n";
    copy(chars.cbegin(), chars.cend(), output);
    // 用生成函数生成
    generate(chars.begin(), chars.end(), nextLetter);

    cout << "\n\nchars after generating letters A-J:\n";
    copy(chars.cbegin(), chars.cend(), output);
    // 用生成函数生成前五个
    generate_n(chars.begin(), 5, nextLetter);

    cout << "\n\nchars after generating K-O for the"
         << " first five elements:\n";
    copy(chars.cbegin(), chars.cend(), output);
    cout << endl;
}

char nextLetter()
{
    static char letter = 'A';
    return letter++;
}





// equal、mismatch、lexicographical_compare(词典)
// 比较两个值的序列是否相等
#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>

using namespace std;

int main()
{
    const size_t SIZE = 10;
    array<int, SIZE> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array<int, SIZE> a2(a1);
    array<int, SIZE> a3 = {1, 2, 3, 4, 1000, 6, 7, 8, 9, 10};
    ostream_iterator<int> output(cout, " ");

    cout << "a1 contains: ";
    copy(a1.cbegin(), a1.cend(), output);
    cout << "\na2 contains: ";
    copy(a2.cbegin(), a2.cend(), output);
    cout << "\na3 contains: ";
    copy(a3.cbegin(), a3.cend(), output);

    bool result = equal(a1.cbegin(), a1.cend(), a2.cbegin());
    cout << "\na1" << (result ? "is" : "is not")
         << " equal to a2.\n";

    result = equal(a1.cbegin(), a1.cend(), a3.cbegin());
    cout << "\na1" << (result ? "is" : "is not")
         << " equal to a3.\n";

    auto location = mismatch(a1.cbegin(), a1.cend(), a3.cbegin());
    cout << "\nThere is a mismatch between a1 and a3 at location"
         << (location.first - a1.cbegin()) << "\nwhere a1 contains "
         << *location.first << " and a3 contains" << *location.second
         << "\n\n";

    char c1[] = "HELLO";
    char c2[] = "BYE BYE";
    // 如果小,算法返回true;
    // 如果第一个序列中的元素比第二个序列大或者相等，则返回false
    result = lexicographical_compare(begin(c1), end(c1), begin(c2), end(c2));
    cout << c1 << (result ? "is less than" : "is greater than or equal to ")
         << c2 << endl;
}
*/

// remove、remove_if、remove_copy、remove_copy_if
// remove删除所有x元素
// remove_copy删除所有x元素将其复制到另一个容器中
// remove_if删除所有满足函数的元素
// remove_if删除所有满足函数的元素将其复制到另一个容器中
#include <algorithm>
#include <iostream>
#include <array>
#include <iterator>

using namespace std;

bool greater9(int);

int main()
{
    const size_t SIZE = 10;
    array<int, SIZE> init = {10, 2, 10, 4, 16, 6, 14, 8, 12, 10};
    ostream_iterator<int> output(cout, " ");

    array<int, SIZE> a1(init);
    cout << "a1 before removing all 10s\n";
    copy(a1.cbegin(), a1.cend(), output);

    auto newLastElement = remove(a1.begin(), a1.end(), 10);
    cout << "\na1 after removing all 10s:\n";
    copy(a1.begin(), newLastElement, output);

    array<int, SIZE> a2(init);
    array<int, SIZE> c = {0};
    cout << "\na2 before removing all 10s and copying:\n";
    copy(a2.cbegin(), a2.cend(), output);

    remove_copy(a2.cbegin(), a2.cend(), c.begin(), 10);
    cout << "\nc after removing all 10s from a2:\n";
    copy(c.cbegin(), c.cend(), output);

    array<int, SIZE> a3(init);
    cout << "\na3 before removing all elements greater than 9:\n   ";
    copy(a3.begin(), a3.end(), output);

    newLastElement = remove_if(a3.begin(), a3.end(), greater9);
    cout << "\na3 after removing all elements greater than 9:\n";
    copy(a3.begin(), newLastElement, output);

    array<int, SIZE> a4(init);
    array<int, SIZE> c2 = {0};
    cout << "\n\na4 before all elements"
         << "\ngreater than 9 and copying:\n";
    copy(a4.cbegin(), a4.cend(), output);

    remove_copy_if(a4.cbegin(), a4.cend(), c2.begin(), greater9);
    cout << "\nc2 after removing all elements"
         << "\ngreater than 9 from a4:\n";
    copy(c2.cbegin(), c2.cend(), output);
    cout << endl;
}

bool greater9(int x)
{
    return x > 9;
}