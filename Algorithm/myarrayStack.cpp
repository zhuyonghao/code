#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct Stack
{
	int top;
	int items[MAX_SIZE];	
};

//初始化 
void initStack(Stack& s)
{
	s.top = -1;
}

//判断栈顶指针是否为空
bool isEmpty(Stack& s)
{
	return s.top == -1;	
} 

//判断栈顶指针是否超过了最大容量
bool isFull(Stack& s)
{
	return s.top == MAX_SIZE - 1;	
} 

void push(Stack& s, int value)
{
	if (isFull(s))
		cout << "Stack is full. Cannot push element." << endl;
	else
	{
		s.items[++s.top] = value;
		cout << value << " is pushed into the stack." << endl;
	}
}

void pop(Stack& s)
{
	if (isEmpty(s))
		cout << "Stack is empty. Cannnot pop element." << endl;
	else
	{
		cout << s.items[s.top--] << " poped from the stack" << endl;
	}
}

int peek(Stack& s)
{
	if (isEmpty(s))
	{
		cout << "Stack is empty." << endl;
		return -1;	
	}
	else
	{
		return s.items[s.top];
	}
}

int main() {
    Stack stack;
    initStack(stack);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    cout << "Top element of the stack: " << peek(stack) << endl;

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);

    return 0;
}
