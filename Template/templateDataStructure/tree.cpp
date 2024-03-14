#include <iostream>
#include <iomanip>
using namespace std;

// 类的前置说明

// 树的结点
template <typename NODETYPE>
class Tree;

template <typename NODETYPE>
class TreeNode
{
    friend class Tree<NODETYPE>;

public:
    TreeNode(const NODETYPE &d)
        : leftPtr(nullptr),
          data(d),
          rightPtr(nullptr)
    {
    }

    NODETYPE getData() const
    {
        return data;
    }

private:
    TreeNode<NODETYPE> *leftPtr;
    NODETYPE data;
    TreeNode<NODETYPE> *rightPtr;
};

// 树类模板
template <typename NODETYPE>
class Tree
{
public:
    Tree()
        : rootPtr(nullptr) {}

    void insertNode(const NODETYPE &value)
    {
        insertNodeHelper(&rootPtr, value);
    }

    void preOrderTraversal()
    {
        preOrderHelper(rootPtr);
    }

    void inOrderTraversal()
    {
        inOrderHelper(rootPtr);
    }

    void postOrderTraversal()
    {
        postOrderHelper(rootPtr);
    }

private:
    TreeNode<NODETYPE> *rootPtr;
    // 因为想要改变根节点的值，所以传递的是二级指针
    void insertNodeHelper(TreeNode<NODETYPE> **ptr, const NODETYPE &value)
    {
        if (*ptr == nullptr)
            *ptr = new TreeNode<NODETYPE>(value);
        else
        {
            if (value < (*ptr)->data)
                insertNodeHelper(&((*ptr)->leftPtr), value);
            else
            {
                if (value > (*ptr)->data)
                    insertNodeHelper(&(*ptr)->rightPtr, value);
                else
                    cout << value << " dup" << endl;
            }
        }
    }

    void preOrderHelper(TreeNode<NODETYPE> *ptr) const
    {
        if (ptr != nullptr)
        {
            cout << ptr->data << ' ';
            preOrderHelper(ptr->leftPtr);
            preOrderHelper(ptr->rightPtr);
        }
    }

    void inOrderHelper(TreeNode<NODETYPE> *ptr) const
    {
        if (ptr != nullptr)
        {
            inOrderHelper(ptr->leftPtr);
            cout << ptr->data << ' ';
            inOrderHelper(ptr->rightPtr);
        }
    }

    void postOrderHelper(TreeNode<NODETYPE> *ptr) const
    {
        if (ptr != nullptr)
        {
            postOrderHelper(ptr->leftPtr);
            postOrderHelper(ptr->rightPtr);
            cout << ptr->data << ' ';
        }
    }
};

int main()
{
    Tree<int> intTree;

    cout << "Enter 10 integers values:\n";

    for (int i = 0; i < 10; ++i)
    {
        int intValue = 0;
        cin >> intValue;
        intTree.insertNode(intValue);
    }

    cout << "\nPreorder traversal\n";
    intTree.preOrderTraversal();

    cout << "\nInorder traversal\n";
    intTree.inOrderTraversal();

    cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();

    Tree<double> doubleTree;

    cout << fixed << setprecision(1)
         << "\n\nEnter 10 double values:\n";

    for (int j = 0; j < 10; ++j)
    {
        double doubleValue = 0.0;
        cin >> doubleValue;
        doubleTree.insertNode(doubleValue);
    }

    cout << "\nPreorder traversal\n";
    doubleTree.preOrderTraversal();

    cout << "\nInorder traversal\n";
    doubleTree.inOrderTraversal();

    cout << "\nPostorder traversal\n";
    doubleTree.postOrderTraversal();
    cout << endl;
}