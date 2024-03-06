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
	//初始化 
	Queue() : front(nullptr), rear(nullptr) {}
	//入队 
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
	//出队 
	void dequeue()
	{
		//判断是否为空 
		if (isEmpty())
		{
			cout << "Queue is empty. Cannot dequeue." << endl;
			return;
		}
		//删除操作 
		Node* temp = front;
		front = front->next;
		delete temp;
		
		if (front == nullptr)
		{
			rear = nullptr;
		}
	}
	//获取队头元素 
	int peek()
	{
		if (isEmpty())
		{
			cout << "Queue is empty." << endl;
			return -1;
		}
		
		return front->data;
	} 
	//判断队列是否为空 
	bool isEmpty()
	{
		return front == nullptr;
	}
	//清空所有元素 
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

    // 入队
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // 出队
    queue.dequeue();

    // 获取队首元素
    std::cout << "Front element: " << queue.peek() << std::endl;

    // 判断队列是否为空
    std::cout << "Is queue empty: " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    // 清空队列
    queue.clear();

    return 0;
}

