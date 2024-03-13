// 用类实现链表
class Node
{
public:
    explicit Node(int);
    void setData(int);
    int getData() const;
    void setNextPtr(Node *);
    Node *getNextPtr() const;

private:
    int data;
    Node *nextPtr;
};
