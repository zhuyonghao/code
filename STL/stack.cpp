// stack是一种容器适配器
// stack默认使用deque作为底层容器
#include <iostream>
#include <vector>

template <typename T>
class Stack
{
public:
    void push(const T &item)
    {
        elements.push_back(item);
    }

    void pop()
    {
        if (!elements.empty())
        {
            elements.pop_back();
        }
        else
        {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
    }

    T &top()
    {
        if (!elements.empty())
        {
            return elements.back();
        }
        else
        {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
    }

    bool empty() const
    {
        return elements.empty();
    }

    size_t size() const
    {
        return elements.size();
    }

private:
    std::vector<T> elements;
};

int main()
{
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack top: " << stack.top() << std::endl; // 输出 30

    stack.pop();
    std::cout << "Stack top after pop: " << stack.top() << std::endl; // 输出 20

    return 0;
}