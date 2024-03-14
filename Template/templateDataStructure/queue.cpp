// 基于List实现类模板Queue
#include <iostream>
#include <string>
using namespace std;

// List声明过才可以被友元函数使用
// 前置说明(forward declaration)
template <typename NODETYPE>
class List;

template <typename NODETYPE>
class ListNode
{
    // 友元类
    friend class List<NODETYPE>;

public:
    // explicit用来防止非意愿的隐式转化
    explicit ListNode(const NODETYPE &info)
        : data(info), nextPtr(nullptr)
    {
    }

    NODETYPE getData() const
    {
        return data;
    }

private:
    NODETYPE data;
    ListNode<NODETYPE> *nextPtr;
};

template <typename NODETYPE>
class List
{
public:
    List() : firstPtr(nullptr), lastPtr(nullptr) {}
    // 列表析构时需要确保所有节点已经删除
    ~List()
    {
        if (!isEmpty())
        {
            cout << "Destroying nodes ...\n";

            ListNode<NODETYPE> *currentPtr = firstPtr;
            ListNode<NODETYPE> *tempPtr = nullptr;

            while (currentPtr != nullptr)
            {
                tempPtr = currentPtr;
                cout << tempPtr->data << '\n';
                currentPtr = currentPtr->nextPtr;
                delete tempPtr;
            }
        }

        cout << "All nodes destroyed\n\n";
    }

    void insertAtFront(const NODETYPE &value)
    {
        ListNode<NODETYPE> *newPtr = getNewNode(value);

        if (isEmpty())
            firstPtr = lastPtr = newPtr;
        else
        {
            newPtr->nextPtr = firstPtr;
            firstPtr = newPtr;
        }
    }

    void insertAtBack(const NODETYPE &value)
    {
        ListNode<NODETYPE> *newPtr = getNewNode(value);

        if (isEmpty())
            firstPtr = lastPtr = newPtr;
        else
        {
            lastPtr->nextPtr = newPtr;
            lastPtr = newPtr;
        }
    }

    bool removeFromFront(NODETYPE &value)
    {
        if (isEmpty())
            return false;
        else
        {
            ListNode<NODETYPE> *tempPtr = firstPtr;

            if (firstPtr == lastPtr)
                firstPtr = lastPtr = nullptr;
            else
                firstPtr = firstPtr->nextPtr;

            value = tempPtr->data;
            delete tempPtr;
            return true;
        }
    }

    bool removeFromBack(NODETYPE &value)
    {
        if (isEmpty())
            return false;
        else
        {
            ListNode<NODETYPE> *tempPtr = lastPtr;

            if (firstPtr == lastPtr)
                firstPtr = lastPtr = nullptr;
            else
            {
                ListNode<NODETYPE> *currentPtr = firstPtr;

                while (currentPtr->nextPtr != lastPtr)
                    currentPtr = currentPtr->nextPtr;
                lastPtr = currentPtr;
                currentPtr->nextPtr = nullptr;
            }

            value = tempPtr->data;
            delete tempPtr;
            return true;
        }
    }

    bool isEmpty() const
    {
        return firstPtr == nullptr;
    }

    void print() const
    {
        if (isEmpty())
        {
            cout << "\nThe list is empty\n\n";
            return;
        }

        ListNode<NODETYPE> *currentPtr = firstPtr;

        cout << "The list is: ";

        while (currentPtr != nullptr)
        {
            cout << currentPtr->data << " ";
            currentPtr = currentPtr->nextPtr;
        }

        cout << "\n\n";
    }

private:
    ListNode<NODETYPE> *firstPtr;
    ListNode<NODETYPE> *lastPtr;
    ListNode<NODETYPE> *getNewNode(const NODETYPE &value)
    {
        return new ListNode<NODETYPE>(value);
    }
};

// delegation委托的方式来分配任务
template <typename QUEUETYPE>
class Queue : private List<QUEUETYPE>
{
public:
    void enqueue(const QUEUETYPE &data)
    {
        this->insertAtBack(data);
    }

    bool dequeue(QUEUETYPE &data)
    {
        return this->removeFromFront(data);
    }

    bool isQueueEmpty() const
    {
        return this->isEmpty();
    }

    void printQueue() const
    {
        this->print();
    }
};

int main()
{
    Queue<int> intQueue;

    cout << "procession an integer Queue" << endl;

    for (int i = 0; i < 3; ++i)
    {
        intQueue.enqueue(i);
        intQueue.printQueue();
    }

    int dequeueInteger;

    while (!intQueue.isQueueEmpty())
    {
        intQueue.dequeue(dequeueInteger);
        cout << dequeueInteger << " dequeued" << endl;
        intQueue.printQueue();
    }

    Queue<double> doubleQueue;
    double value = 1.1;

    cout << "procession a double Queue" << endl;

    for (int j = 0; j < 3; ++j)
    {
        doubleQueue.enqueue(value);
        doubleQueue.printQueue();
        value += 1.1;
    }

    double dequeueDouble;

    while (!doubleQueue.isQueueEmpty())
    {
        doubleQueue.dequeue(dequeueDouble);
        cout << dequeueDouble << " dequeued" << endl;
        doubleQueue.printQueue();
    }
}
// 类中成员函数访问级别默认为private