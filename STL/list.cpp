// list基于双向链表
#include <iostream>

template <typename T>
struct ListNode
{
    T data;
    ListNode *prev;
    ListNode *next;
    ListNode(const T &value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class list
{
public:
    list() : head(nullptr), tail(nullptr), size(0) {}
    ~list()
    {
        // 不断删除头结点直至头结点为空
        while (head)
        {
            ListNode<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    size_t getSize() const { return size; }

    void push_back(T value)
    {
        ListNode<T> *newNode = new ListNode<T>(value);
        if (tail)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode; // 更新tail
        }
        else
        {
            head = tail = newNode;
        }
        ++size;
    }

    void insert(ListNode<T> *pos, T value)
    {
        ListNode<T> *newNode = new ListNode<T>(value);
        if (pos)
        {
            newNode->next = pos;
            newNode->prev = pos->prev;
            if (pos->prev)
                pos->prev->next = newNode;
            else
                head = newNode;
            pos->prev = newNode;
        }
        else
            push_back(value);
        ++size;
    }

    void erase(ListNode<T> *pos)
    {
        if (!pos)
            return;

        if (pos->prev)
        {
            pos->prev->next = pos->next;
        }
        else
        {
            // 删除首元素
            head = pos->next;
        }
        if (pos->next)
        {
            pos->next->prev = pos->prev;
        }
        else
        {
            // 删除尾元素
            tail = pos->prev;
        }
        delete pos;
        --size;
    }

    void printList() const
    {
        ListNode<T> *current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ListNode<T> *getHead() const { return head; }

    ListNode<T> *getTail() const { return tail; }

private:
    ListNode<T> *head;
    ListNode<T> *tail;
    size_t size;
};

int main()
{
    list<int> myList;

    // 在链表末尾添加元素
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);

    // 打印链表
    std::cout << "List after push_back: ";
    myList.printList();

    // 在第二个元素位置插入元素
    ListNode<int> *secondNode = myList.getHead()->next;
    myList.insert(secondNode, 5);

    std::cout << "List after inserting 5 before the second element: ";
    myList.printList();

    // 删除第三个元素
    ListNode<int> *thirdNode = myList.getHead()->next->next;
    myList.erase(thirdNode);

    std::cout << "List after deleting the third element: ";
    myList.printList();

    return 0;
}
