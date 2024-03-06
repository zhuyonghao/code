#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
}; 

class Queue
{
private:
	Node* front;
	Node* rear;

public:
	//��ʼ�� 
	Queue() : front(nullptr), rear(nullptr) {}
	//��� 
	void enqueue(int value)
	{
		Node* newNode = new Node(value);
		if (isEmpty())
		{
			front = rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}
	//���� 
	void dequeue()
	{
		//�ж��Ƿ�Ϊ�� 
		if (isEmpty())
		{
			cout << "Queue is empty. Cannot dequeue." << endl;
			return;
		}
		//ɾ������ 
		Node* temp = front;
		front = front->next;
		delete temp;
		
		if (front == nullptr)
		{
			rear = nullptr;
		}
	}
	//��ȡ��ͷԪ�� 
	int peek()
	{
		if (isEmpty())
		{
			cout << "Queue is empty." << endl;
			return -1;
		}
		
		return front->data;
	} 
	//�ж϶����Ƿ�Ϊ�� 
	bool isEmpty()
	{
		return front == nullptr;
	}
	//�������Ԫ�� 
	void clear()
	{
		while (front != nullptr)
		{
			Node* temp = front;
			front = front->next;
			delete temp;
		}
		rear = nullptr;
	}
	
};

int main() {
    Queue queue;

    // ���
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // ����
    queue.dequeue();

    // ��ȡ����Ԫ��
    std::cout << "Front element: " << queue.peek() << std::endl;

    // �ж϶����Ƿ�Ϊ��
    std::cout << "Is queue empty: " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    // ��ն���
    queue.clear();

    return 0;
}

