/*
 *类模板
 *使用函数模板类操作类模板特化的对象
 *非类型形参
 *模板类型形参的默认实参
 *重载函数模板
 */

#include <deque>
#include <iostream>
#include <string>
using namespace std;

// 类模板
template <typename T>
class Stack
{
public:
    T &top()
    {
        return stack.front();
    }

    void push(const T &pushValue)
    {
        stack.push_front(pushValue);
    }

    void pop();

    bool isEmpty() const
    {
        return stack.empty();
    }

    size_t size() const
    {
        return stack.size();
    }

private:
    deque<T> stack;
};

// 如果在类外定义
template <typename T>
inline void Stack<T>::pop()
{
    return stack.pop_front();
}
/*
int main()
{
    Stack<double> doubleStack;
    const size_t doubleStackSize = 5;
    double doubleValue = 1.1;

    cout << "Pushing elements onto doubleStack\n";

    for (size_t i = 0; i < doubleStackSize; ++i)
    {
        doubleStack.push(doubleValue);
        cout << doubleValue << " ";
        doubleValue += 1.1;
    }

    cout << "\n\nPoping elements from doubleStack\n";

    while (!doubleStack.isEmpty())
    {
        cout << doubleStack.top() << ' ';
        doubleStack.pop();
    }

    cout << "\nStack is empty, cannot pop.\n";

    Stack<int> intStack;
    const size_t intStackSize = 10;
    int intValue = 1;

    cout << "\nPushing elements onto intStack\n";

    for (size_t i = 0; i < intStackSize; ++i)
    {
        intStack.push(intValue);
        cout << intValue++ << ' ';
    }

    cout << "\n\nPoping elements from intStack\n";

    while (!intStack.isEmpty())
    {
        cout << intStack.top() << ' ';
        intStack.pop();
    }

    cout << "Stack is empty, cannot pop." << endl;
}


*/

// 使用函数模板来操作类模板特化的对象
template <typename T>
void testStack(
    Stack<T> &theStack, // 类模板的引用
    const T &value,     // 赋值的值
    const T &increment, // 增加多少
    size_t size,
    const string &stackName)
{
    cout << "\nPushing elements onto " << stackName << '\n';
    T pushValue = value;

    for (size_t i = 0; i < size; ++i)
    {
        theStack.push(pushValue);
        cout << pushValue << ' ';
        pushValue += increment;
    }

    cout << "\n\nPopping elements from " << stackName << '\n';

    while (!theStack.isEmpty())
    {
        cout << theStack.top() << ' ';
        theStack.pop();
    }

    cout << "\nStack is empty. cannot pop." << endl;
}

int main()
{
    Stack<double> doubleStacck;
    const size_t doubleStackSize = 5;
    testStack(doubleStacck, 1.1, 1.1, doubleStackSize, "doubleStack");

    Stack<int> intStack;
    const size_t intStackSize = 10;
    testStack(intStack, 1, 1, intStackSize, "intStack");
}
