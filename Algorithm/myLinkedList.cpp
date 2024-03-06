#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	//初始化操作 
	ListNode(int x) : val(x), next(nullptr) {}	
};

void insertAtHead(ListNode*& head, int val)
{
	ListNode* newNode = new ListNode(val);
	//新结点中的下一个结点变为head 
	newNode->next = head;
	//head变为新结点的位置 
	head = newNode;
}

void insertAtTail(ListNode*& head, int val)
{
	ListNode* newNode = new ListNode(val);
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		ListNode* curr = head;
		while (curr->next != nullptr)
		{
			curr = curr->next;	
		}
		curr->next = newNode;
	}
}

void deleteAtHead(ListNode*& head)
{
	//如果头结点是空则返回 
	if (head == nullptr)
	{
		return;
	}
	ListNode* temp = head;
	head = head->next;
	delete temp;
}

void deleteAtTail(ListNode*& head)
{
	//头结点为空 
	if (head == nullptr)
	{
		return;	
	}
	//只剩下一个结点
	if (head->next == nullptr)
	{
		ListNode* temp = head;
		head = nullptr;
		delete temp;
		return;
	}
	ListNode* curr = head;
	//下一个的下一个结点 
	while (curr->next->next != nullptr)
	{
		curr = curr->next;	
	}
	delete curr->next;	
	curr->next = nullptr;
} 

ListNode* reverseList(ListNode* head)
{
	ListNode* prev = nullptr;
	ListNode* curr = head;
	while (curr != nullptr)
	{
		ListNode* nextTemp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextTemp;
	}
	return prev;
}

void printList(ListNode* head)
{
	ListNode* curr = head;
	while(curr != nullptr)
	{
		cout << curr->val;
		curr = curr->next;
	}	
	cout << endl;
} 

int main() {
    ListNode* head = nullptr;

    // 插入操作
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtTail(head, 4);
    printList(head);

    // 删除操作
    deleteAtHead(head);
    deleteAtTail(head);
    printList(head);

    // 反转操作
    head = reverseList(head);
    printList(head);

    return 0;
}

