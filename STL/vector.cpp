// vector基于动态数组

#include <iostream>
#include <exception> // 异常处理防止数组越界
#include <utility>   // std::move

template <typename T> // 声明一个模板，T是类型参数
class vector
{
public:
    // 为类型为T大小为1的数组分配空间将首元素的指针赋值给data
    vector() : m_size(0), m_capacity(1), data(new T[1]) {}

    ~vector()
    {
        clear();       // 将数组大小置为0
        delete[] data; // 使用delete[]释放数组的内存
    }

    void push_back(const T &value)
    {
        // 大小是否大于容量
        if (m_size >= m_capacity)
        {
            resize(); // 扩容
        }

        data[m_size] = value; // 赋值

        ++m_size;
    }

    void pop_back()
    {
        if (m_size > 0)
            --m_size;
    }

    // vec[0] = 10;  修改 vector 的第一个元素
    T &operator[](size_t index)
    {
        // 防止越界
        if (index >= m_size)
        {
            // out_of_range是std中的异常类
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    // int value = vec[0];  只能读取元素，不能修改
    const T &operator[](size_t index) const
    {
        if (index >= m_size)
            throw std::out_of_range("Index out of range");

        return data[index];
    }

    // 声明为常函数无法修改对象成员
    size_t size() const
    {
        return m_size;
    }

    size_t capacity() const
    {
        return m_capacity;
    }

    void clear()
    {
        // 大小为0，后期使用直接赋值覆盖原先的值
        m_size = 0;
    }

private:
    // 扩容
    void resize()
    {
        // 容量变为两倍
        m_capacity *= 2;

        // 开辟空间
        T *new_data = new T[m_capacity];

        // 将原先的值移动新开辟的空间
        for (size_t i = 0; i < m_size; ++i)
        {
            // move将其参数转换为一个右值引用
            // 右值引用允许资源的所有权被转移，而不是复制资源, 避免了不必要的深拷贝操作
            new_data[i] = data[i]; // 移动构造
        }

        // 释放旧数组内存
        delete[] data;

        data = new_data; // 赋值
    }

    // size_t无符号整型，可以表示更大的数，无负数
    size_t m_size; // 实际存储元素的数量

    size_t m_capacity; // 可以存储元素的数量

    T *data; // 数组名也是指向数组首元素的指针
};

int main()
{
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    // 输出: 10 20 30

    vec.pop_back();
    std::cout << "\nSize after pop_back: " << vec.size() << std::endl;
    // 输出: Size after pop_back: 2

    return 0;
}
