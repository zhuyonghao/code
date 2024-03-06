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
	//将栈顶指针初始化为空 
	Stack() : top(nullptr) {}
	//判断栈是否为空 
	bool isEmpty()
	{
		return top == nullptr;
	}
	//压栈 
	void push(int val)
	{
		Node* newNode = new Node(val);
		newNode->next = top;
		top = newNode;
	}
	//出栈 
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
	//获取栈顶元素 
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
	//打印栈的元素 
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
	//清空栈 
	void clear()
	{
		while (!isEmpty())
		{
			pop();
		}
	}
	//栈的元素个数 
	int size()
	{
		Node* curr = top;
		int count = 0;//要进行初始化 
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

