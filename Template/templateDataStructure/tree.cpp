#include <iostream>

using namespace std;

// 类的前置说明

// 树的结点
template <typename NODETYPE>
class Tree;

template <typename NODETYPE>
class TreeNode
{
    friend class Tree<TYPENAME>;

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