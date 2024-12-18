// queue是一种容器适配器
// queue默认使用deque作为底层容器
#include <iostream>
#include <deque>

template <typename T>
class queue
{
public:
private:
    std::deque<T> container;

public:
    void enqueue(const T &value)
    {
        container.push_back(value);
    }

    void dequeue()
    {
        if (!container.empty())
            container.pop_front();
        else
        {
            std::cerr << "队列为空，无法移除元素。" << std::endl;
        }
    }

    T &front()
    {
        return container.front();
    }

    bool empty() const
    {
        return container.empty();
    }

    size_t size() const
    {
        return container.size();
    }
};

int main()
{
    queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    while (!q.empty())
    {
        std::cout << "队头元素: " << q.front() << std::endl;
        q.dequeue();
    }

    return 0;
}