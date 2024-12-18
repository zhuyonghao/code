// 固定大小的内存块和指向这些内存块的指针数组
#include <iostream>

template <typename T>
class deque
{
private:
    T **map;           // 指针数组
    size_t mapSize;    // 指针数组大小
    size_t blockSize;  // 每个内存块的大小
    size_t startBlock; // 起始块的索引
    size_t startIndex; // 起始块内的索引
    size_t endBlock;   // 结束块的索引
    size_t endIndex;   // 结束块内的索引

    // 动态扩展或缩小指针数组以适应更多或更少的内存块
    void allocateMap(size_t newMapSize)
    {
        // 创建一个新的指针数组newMap
        T **newMap = new T *[newMapSize];
        // 初始化
        for (size_t i = 0; i < newMapSize; ++i)
        {
            newMap[i] = nullptr;
        }

        // 计算偏移量
        // 原有的数据结构依然保持居中的位置，提供空间以便后续在两端增加或减少元素。
        size_t offset = (newMapSize - mapSize) / 2;

        // 复制旧的指针数组到新数组
        for (size_t i = 0; i < mapSize; ++i)
            newMap[i + offset] = map[i];

        // 删除旧的指针数组并更新指针
        delete[] map;
        map = newMap;
        mapSize = newMapSize;
        startBlock += offset;
        endBlock += offset;
    }

    // 按需分配一个新的内存块以便存储更多的元素
    void allocateBlock(size_t blockIndex)
    {
        // 如果没有分配
        if (!map[blockIndex])
        {
            map[blockIndex] = new T[blockSize];
        }
    }

public:
    deque(size_t initBlockSize = 4)
        : blockSize(initBlockSize), mapSize(8), startBlock(4), startIndex(0), endBlock(4), endIndex(0)
    {
        // 分配指针数组
        map = new T *[mapSize];
        // 初始化
        for (size_t i = 0; i < mapSize; ++i)
            map[i] = nullptr;
        // 分配块
        allocateBlock(startBlock);
    }

    ~deque()
    {
        // 释放每个块内的动态内存
        for (size_t i = 0; i < mapSize; ++i)
            delete[] map[i];
        // 释放指针数组
        delete[] map;
    }

    bool empty() const
    {
        return startBlock == endBlock && startIndex == endIndex;
    }

    void push_front(const T &value)
    {
        // 如果当前块已满，startIndex为0
        if (startIndex == 0)
        {
            // 如果当前在第一块，并且需要再向前扩展
            if (startBlock == 0)
            {
                // 扩展map的大小
                allocateMap(mapSize * 2);
            }
            // 移动到前一个块
            --startBlock;
            // 将索引设置到新块的末尾
            startIndex = blockSize;
            // 如果新块没有分配内存，分配它
            allocateBlock(startBlock);
        }
        // 在新的位置插入元素
        map[startBlock][--startIndex] = value;
    }

    void push_back(const T &value)
    {
        // 如果当前块已满
        if (endIndex == blockSize)
        {
            // 如果当前块是最后一块且需要扩展
            if (endBlock == mapSize - 1)
            {
                // 扩展map大小
                allocateMap(mapSize * 2);
            }
            // 移动到下一块
            ++endBlock;
            // 将索引设置到新块的起始位置
            endIndex = 0;
            // 如果新块没有分配内存，分配它
            allocateBlock(endBlock);
        }
        // 在新的位置插入元素
        map[endBlock][endIndex++] = value;
    }

    void pop_front()
    {
        if (!empty())
        {
            // 如果当前块中元素都被移除完了
            if (++startIndex == blockSize)
            {
                // 将索引重置为0
                startIndex = 0;
                // 移动到下一块
                ++startBlock;
            }
        }
        else
        {
            std::cerr << "Error: Deque is empty, cannot pop front." << std::endl;
        }
    }

    void pop_back()
    {
        if (!empty())
        {
            // 如果当前块中元素元素已经被移除完
            if (endIndex == 0)
            {
                // 将索引设置为前一个块的末尾
                endIndex = blockSize;
                // 移动到前一个块
                --endBlock;
            }
            // 从当前块的末尾移除元素
            --endIndex;
        }
        else
        {
            std::cerr << "Error: Deque is empty, cannot pop back." << std::endl;
        }
    }

    T &front()
    {
        if (!empty())
        {
            return map[startBlock][startIndex];
        }
        else
        {
            std::cerr << "Error: Deque is empty, no front element." << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    T &back()
    {
        if (!empty())
        {
            return map[endBlock][endIndex - 1];
        }
        else
        {
            std::cerr << "Error: Deque is empty, no back element." << std::endl;
            exit(EXIT_FAILURE);
        }
    }
};
int main()
{
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);

    std::cout << "Front: " << dq.front() << "\n";
    std::cout << "Back: " << dq.back() << "\n";

    dq.pop_front();
    dq.pop_back();

    std::cout << "Front after pop: " << dq.front() << "\n";
    std::cout << "Back after pop: " << dq.back() << "\n";

    return 0;
}