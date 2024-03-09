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


// remove、remove_if、remove_copy、remove_copy_if

 //remove和remove_if
 //并不修改这个容器中的元素数目，而是把那些没有被删除的元素移动到容器的前部
 //remove_copy和remove_copy_if
 //那些没有被删除的元素将其复制到另一个容器中

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
     // predicate"指的是返回布尔值（true或false）的函数或“函数对象”
     // greater9是一个函数对象用来断言
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


// replace、replace_if、replace_copy和replace_copy_if
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
     cout << "a1 before replacing all 10s:\n";
     copy(a1.cbegin(), a1.cend(), output);

     replace(a1.begin(), a1.end(), 10, 100);
     cout << "\na1 after replacing all 10s:\n";
     copy(a1.cbegin(), a1.cend(), output);

     array<int, SIZE> a2(init);
     array<int, SIZE> c1;
     cout << "\n\na2 before replacing all 10s and copying:\n";
     copy(a2.cbegin(), a2.cend(), output);

     replace_copy(a2.cbegin(), a2.cend(), c1.begin(), 10, 100);
     cout << "\na2 after replacing all 10s in c1:\n";
     copy(c1.cbegin(), c1.cend(), output);

     array<int, SIZE> a3(init);
     cout << "\n\na3 before replacing values greater9:\n";
     copy(a3.cbegin(), a3.cend(), output);

     replace_if(a3.begin(), a3.end(), greater9, 100);
     cout << "\na3 after replacing values greater9:\n";
     copy(a3.cbegin(), a3.cend(), output);

     array<int, SIZE> a4(init);
     array<int, SIZE> c2;
     cout << "\n\na4 before replacing values greater9 and copying:\n";
     copy(a4.cbegin(), a4.cend(), output);

     replace_copy_if(a4.cbegin(), a4.cend(), c2.begin(), greater9, 100);
     cout << "\na4 after replacing values greater9 and coping:\n";
     copy(c2.cbegin(), c2.cend(), output);
}

bool greater9(int x)
{
     return x > 9;
}


// math algorithm
// random_shuffle(洗牌) count count_if min_element(返回迭代器) max_element minmax_element
// accumulate(求和) for_each transform
#include <algorithm>
#include <iostream>
#include <numeric>
#include <array>
#include <iterator>

using namespace std;

bool greater9(int);
void outputSquare(int);
int calculateCube(int);

int main()
{
     const size_t SIZE = 10;
     array<int, SIZE> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     ostream_iterator<int> output(cout, " ");

     cout << "a1 before random_shuffle: ";
     copy(a1.cbegin(), a1.cend(), output);

     random_shuffle(a1.begin(), a1.end());
     cout << "\na1 after random_shuffle: ";
     copy(a1.cbegin(), a1.cend(), output);

     array<int, SIZE> a2 = {100, 2, 8, 1, 50, 3, 8, 8, 9, 10};
     cout << "\n\na2 contains: ";
     copy(a2.cbegin(), a2.cend(), output);

     int result = count(a2.cbegin(), a2.cend(), 8);
     cout << "\nNumber of elements matching 8: " << result;

     result = count_if(a2.cbegin(), a2.cend(), greater9);
     cout << "\nNumber of elements graeter 9: " << result;

     cout << "\n\nMinimum element in a2 is: "
          << *(min_element(a2.cbegin(), a2.cend()));

     auto minAndMax = minmax_element(a2.cbegin(), a2.cend());
     cout << "\nThe minimum and maximum elements in a2 are "
          << *minAndMax.first << " and " << *minAndMax.second
          << ", repectively";

     cout << "\n\nThe total of the elements in a1 is: "
          << accumulate(a1.cbegin(), a1.cend(), 0);

     cout << "\n\nThe square of every integer in a1 is:\n";
     for_each(a1.cbegin(), a1.cend(), outputSquare);
     array<int, SIZE> cubes;

     transform(a1.cbegin(), a1.cend(), cubes.begin(), calculateCube);
     cout << "\n\nThe cube of every integer in a1 is:\n";
     copy(cubes.cbegin(), cubes.cend(), output);
     cout << endl;
}

bool greater9(int value)
{
     return value > 9;
}

void outputSquare(int value)
{
     cout << value * value << ' ';
}

int calculateCube(int value)
{
     return value * value * value;
}


// 基本查找和排序算法
// find find_if  sort binary_search
// all_of any_of none_of find_if_not

#include <algorithm>
#include <iostream>
#include <array>
#include <iterator>
using namespace std;

bool greater10(int);

int main()
{
     const size_t SIZE = 10;
     array<int, SIZE> a = {10, 2, 17, 5, 16, 8, 13, 11, 20, 7};
     ostream_iterator<int> output(cout, " ");

     cout << "array contains: ";
     copy(a.cbegin(), a.cend(), output);

     auto location = find(a.cbegin(), a.cend(), 16);

     if (location != a.cend())
          cout << "\n\nFound 16 at location " << (location - a.cbegin());
     else
          cout << "\n\n16 not found";

     location = find(a.cbegin(), a.cend(), 100);

     if (location != a.cend())
          cout << "\n\nFound 100 at location " << (location - a.cbegin());
     else
          cout << "\n\n100 not found";

     location = find_if(a.cbegin(), a.cend(), greater10);

     if (location != a.cend())
          cout << "\n\nThe first value greater than 10 is " << *location
               << "\n found at location " << (location - a.cbegin());
     else
          cout << "\n\nvalues greater10 not found";

     sort(a.begin(), a.end());
     cout << "\n\narray after sort: ";
     copy(a.cbegin(), a.cend(), output);

     if (binary_search(a.cbegin(), a.cend(), 13))
          cout << "\n\n13 was found in a";
     else
          cout << "\n\n13 was not found in a";

     if (binary_search(a.cbegin(), a.cend(), 100))
          cout << "\n\n100 was found in a";
     else
          cout << "\n\n100 was not found in a";
     // 检测是不是全部大于
     if (all_of(a.cbegin(), a.cend(), greater10))
          cout << "\n\nall the elements in a are greater than 10";
     else
          cout << "\n\nSome elements in a are not greater than 10";
     // 检测是不是有一些大于
     if (any_of(a.cbegin(), a.cend(), greater10))
          cout << "\n\nSome of the elements in a greater than 10";
     else
          cout << "\n\nNone of elements in a are greater than 10";
     // 检测是不是没有
     if (none_of(a.cbegin(), a.cend(), greater10))
          cout << "\n\nNone of the elements in a greater than 10";
     else
          cout << "\n\nsome of elements in a are greater than 10";

     location = find_if_not(a.cbegin(), a.cend(), greater10);

     if (location != a.cend())
          cout << "\n\nThe first value not greater than 10 is " << *location
               << "\nfound at location " << (location - a.cbegin());
     else
          cout << "\n only value greater than 10 were found";

     cout << endl;
}

bool greater10(int value)
{
     return value > 10;
}


// swap iter_swap swap_ranges
#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
     const size_t SIZE = 10;
     array<int, SIZE> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     ostream_iterator<int> output(cout, " ");

     cout << "Array contains: \n";
     copy(a.cbegin(), a.cend(), output);

     swap(a[0], a[1]);

     cout << "\nAfter swapping, Array contains: \n";
     copy(a.cbegin(), a.cend(), output);
     // 交换迭代器值没变
     iter_swap(a.begin(), a.begin() + 1);
     cout << "\nAfter swapping iterator, Array contains: \n";
     copy(a.cbegin(), a.cend(), output);
     // 用从第五位开始的值赋值给前五位
     swap_ranges(a.begin(), a.begin() + 5, a.begin() + 5);

     cout << "\nAfter swapping range, Array contains: \n";
     copy(a.cbegin(), a.cend(), output);
     cout << endl;
}


// copy_backward merge unique reverse
#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>

using namespace std;

int main()
{
     const size_t SIZE = 5;
     array<int, SIZE> a1 = {1, 2, 3, 4, 5};
     array<int, SIZE> a2 = {6, 7, 8, 9, 10};
     ostream_iterator<int> output(cout, " ");

     cout << "a1 contains: \n";
     copy(a1.cbegin(), a1.cend(), output);
     cout << "\na2 contains: \n";
     copy(a2.cbegin(), a2.cend(), output);

     array<int, SIZE> result;
     // 将容器a1中的元素逆序复制到result容器中
     // result容器从后往前返回一个迭代器
     copy_backward(a1.cbegin(), a1.cend(), result.end());
     cout << "\n\nAfter copy_backward, results contains: ";
     copy(result.cbegin(), result.cend(), output);

     array<int, SIZE + SIZE> result2;

     merge(a1.cbegin(), a1.cend(), a2.cbegin(), a2.cend(), result2.begin());

     cout << "\n\nAfter merge: ";
     copy(result2.cbegin(), result2.cend(), output);
     // 上将每个重复的元素移至范围的尾部
     auto endLocation = unique(result2.begin(), result2.end());

     cout << "\n\nAfter unique contains: ";
     copy(result2.begin(), endLocation, output);

     cout << "\nAfter reverse: ";
     reverse(a1.begin(), a1.end());
     copy(a1.cbegin(), a1.cend(), output);

     cout << endl;
}


// inplace_merge unique_copy reverse_copy

#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <vector>

using namespace std;

int main()
{
     const size_t SIZE = 10;
     array<int, SIZE> a1 = {1, 3, 5, 7, 9, 1, 3, 5, 7, 9};
     ostream_iterator<int> output(cout, " ");

     cout << "array a1 contains: ";
     copy(a1.cbegin(), a1.cend(), output);
     //合并同一容器中的两个有序的元素序列
     inplace_merge(a1.begin(), a1.begin() + 5, a1.end());

     cout << "\nAfter inplace_merge, all contains: ";
     copy(a1.cbegin(), a1.cend(), output);

     vector<int> results1;
     //back_inserter函数使用vector的push_back成员函数
     //在这个vector对象的末端插入元素
     unique_copy(a1.cbegin(), a1.cend(), back_inserter(results1));
     cout << "After unique_copy results1 contains: ";
     copy(results1.cbegin(), results1.cend(), output);

     vector<int> results2;

     reverse_copy(a1.cbegin(), a1.cend(), back_inserter(results2));
     cout << "\nAfter reverse_copy, results2 contains: ";
     copy(results2.cbegin(), results2.cend(), output);
     cout << endl;
}
*/

// include set_difference set_intersection
// set_symmetric(对称)_difference set_union(联合)

#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>

using namespace std;

int main()
{
     const size_t SIZE1 = 10, SIZE2 = 5, SIZE3 = 20;
     array<int, SIZE1> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     array<int, SIZE2> a2 = {4, 5, 6, 7, 8};
     array<int, SIZE3> a3 = {4, 5, 6, 11, 15};
     ostream_iterator<int> output(cout, " ");

     cout << "a1 contains: ";
     copy(a1.cbegin(), a1.cend(), output);
     cout << "\na2 contains: ";
     copy(a2.cbegin(), a2.cend(), output);
     cout << "a3 contains: ";
     copy(a3.cbegin(), a3.cend(), output);
     // 集合A是否包含集合B
     if (includes(a1.cbegin(), a1.cend(), a2.cbegin(), a2.cend()))
          cout << "\n\na1 includes a2";
     else
          cout << "\n\na1 does not include a2";

     if (includes(a1.cbegin(), a1.cend(), a3.cbegin(), a3.cend()))
          cout << "\n\na1 includes a3";
     else
          cout << "\n\na1 does not include a3";
     // 找两集合不同
     array<int, SIZE1> difference;
     auto result1 = set_difference(a1.cbegin(), a1.cend(), a2.cbegin(),
                                   a2.cend(), difference.begin());
     cout << "\n\nset_difference of a1 and a2 is: ";
     copy(difference.begin(), result1, output);
     // 集合交叉
     array<int, SIZE1> intersection;
     auto result2 = set_intersection(a1.cbegin(), a1.cend(), a2.cbegin(),
                                     a2.cend(), intersection.begin());
     cout << "\n\nset_intersection of a1 and a2 is: ";
     copy(intersection.begin(), result2, output);

     array<int, SIZE1 + SIZE2> symmetric_difference;

     auto result3 = set_symmetric_difference(a1.cbegin(), a1.cend(),
                                             a3.cbegin(), a3.cend(), symmetric_difference.begin());
     cout << "\n\nset_symmetric_difference of a1 and a3 is: ";
     copy(symmetric_difference.begin(), result3, output);

     array<int, SIZE3> unionSet;
}