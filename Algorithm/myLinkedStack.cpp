#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}	
};

class Stack
{
private:
	Node* top;
	
public:
	//��ջ��ָ���ʼ��Ϊ�� 
	Stack() : top(nullptr) {}
	//�ж�ջ�Ƿ�Ϊ�� 
	bool isEmpty()
	{
		return top == nullptr;
	}
	//ѹջ 
	void push(int val)
	{
		Node* newNode = new Node(val);
		newNode->next = top;
		top = newNode;
	}
	//��ջ 
	int pop()
	{
		if (isEmpty())
		{
			cerr << "Error: Stack is empty." << endl;
			return -1;
		}
		else
		{
			Node* temp = top;
			int popedValue = temp->data;
			top = top->next;
			delete	temp;
			return popedValue;
		}	
	}
	//��ȡջ��Ԫ�� 
	int peek()
	{
		if (isEmpty())
		{
			cerr << "Stack is empty." << endl;
			return -1;	
		}	
		else
		{
			return top->data;
		}
	} 
	//��ӡջ��Ԫ�� 
	void printStack()
	{
		Node* curr = top;
		while (curr != nullptr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
	//���ջ 
	void clear()
	{
		while (!isEmpty())
		{
			pop();
		}
	}
	//ջ��Ԫ�ظ��� 
	int size()
	{
		Node* curr = top;
		int count = 0;//Ҫ���г�ʼ�� 
		while (curr != nullptr)
		{
			count++;
			curr = curr->next;
		}
		return count;
	} 
	
};




int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Stack elements: ";
    stack.printStack();

    std::cout << "Stack size: " << stack.size() << std::endl;

    std::cout << "Top element: " << stack.peek() << std::endl;

    std::cout << "Popped element: " << stack.pop() << std::endl;

    std::cout << "Stack elements after popping: ";
    stack.printStack();

    stack.clear();

    std::cout << "Stack size after clearing: " << stack.size() << std::endl;

    return 0;
}

