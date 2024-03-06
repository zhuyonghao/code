#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	//��ʼ������ 
	ListNode(int x) : val(x), next(nullptr) {}	
};

void insertAtHead(ListNode*& head, int val)
{
	ListNode* newNode = new ListNode(val);
	//�½���е���һ������Ϊhead 
	newNode->next = head;
	//head��Ϊ�½���λ�� 
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
	//���ͷ����ǿ��򷵻� 
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
	//ͷ���Ϊ�� 
	if (head == nullptr)
	{
		return;	
	}
	//ֻʣ��һ�����
	if (head->next == nullptr)
	{
		ListNode* temp = head;
		head = nullptr;
		delete temp;
		return;
	}
	ListNode* curr = head;
	//��һ������һ����� 
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

    // �������
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtTail(head, 4);
    printList(head);

    // ɾ������
    deleteAtHead(head);
    deleteAtTail(head);
    printList(head);

    // ��ת����
    head = reverseList(head);
    printList(head);

    return 0;
}

