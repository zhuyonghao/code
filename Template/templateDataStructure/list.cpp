#include <iostream>
#include <string>
using namespace std;

// List声明过才可以被友元函数使用
template <typename NODETYPE>
class List;

template <typename NODETYPE>
class ListNode
{
    friend class List<NODETYPE>;

public:
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
/*
void instructions()
{
    cout << "Enter onr of following:\n"
         << " 1 to insert at beginning of list\n"
         << " 2 to insert at end of list\n"
         << " 3 to delete from beginning of list\n"
         << " 4 to delete from end of list\n"
         << " 5 to end list processing\n";
}

template <typename T>
void testList(List<T> &listObject, const string &typeName)
{
    cout << "Testing a list of " << typeName << " values\n";
    instructions();

    int choice;
    T value;

    do
    {
        cout << "? ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtFront(value);
            listObject.print();
            break;
        case 2:
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtBack(value);
            listObject.print();
            break;
        case 3:
            if (listObject.removeFromFront(value))
                cout << value << " remove from list\n";

            listObject.print();
            break;
        case 4:
            if (listObject.removeFromBack(value))
                cout << value << " remove from list\n";

            listObject.print();
            break;
        }
    } while (choice < 5);
    cout << "End list test\n\n";
}

int main()
{
    List<int> integerList;
    testList(integerList, "integer");

    List<double> doubleList;
    testList(doubleList, "double");
}
*/

// 基于List继承实现模板类Stack
template <typename STACKTYPE>
class Stack : private List<STACKTYPE>
{
public:
    // 需要指明作用域
    void push(const STACKTYPE &data)
    {
        List<STACKTYPE>::insertAtFront(data);
    }

    bool pop(STACKTYPE &data)
    {
        return List<STACKTYPE>::removeFromFront(data);
    }

    bool isStackEmpty() const
    {
        return this->isEmpty();
    }

    void printStack() const
    {
        this->print();
    }
};

int main()
{
    Stack<int> intStack;

    cout << "processing an integer Stack" << endl;

    for (int i = 0; i < 3; ++i)
    {
        intStack.push(i);
        intStack.printStack();
    }

    int popInteger;

    while (!intStack.isStackEmpty())
    {
        intStack.pop(popInteger);
        cout << popInteger << " popped from stack" << endl;
        intStack.printStack();
    }

    Stack<double> doubleStack;
    double value = 1.1;

    cout << "processing a double Stack" << endl;

    for (int j = 0; j < 3; ++j)
    {
        doubleStack.push(value);
        doubleStack.printStack();
        value += 1.1;
    }

    double popDouble;

    while (!doubleStack.isStackEmpty())
    {
        doubleStack.pop(popDouble);
        cout << popDouble << " popped from stack" << endl;
        doubleStack.printStack();
    }
}