#include <iostream>

using namespace std;

#define MAX_SIZE 100
//������� 
struct Queue
{
	int items[MAX_SIZE];
	int front, rear;
};
//��ʼ�� 
void initQueue(Queue& q)
{
	q.front = -1;
	q.rear = -1;
}
//�ж϶����Ƿ�Ϊ��     ѭ������ 
bool isEmpty(Queue q)
{
	return q.front == -1; 
}
//�ж��Ƿ����� 
bool isFull(Queue q)
{
	return (q.rear + 1) % MAX_SIZE == q.front;
}
//��Ӳ��� 
void enqueue(Queue& q, int value)
{
	if (isFull(q))
		cout << "Queue is full. Cannot enqueue." << endl;
	else
	{
		if (isEmpty(q))
		{
			q.front = q.rear = 0;
		}
		else
		{
			q.rear = (q.rear + 1) % MAX_SIZE;
		}
		q.items[q.rear] = value;
		cout << value << " enqueued into queue." << endl;
	}
	 
}
//���Ӳ��� 
void dequeue(Queue& q)
{
	if (isEmpty(q))
		cout << "Queue is empty. Cannot dequeue" << endl;
	else
	{
		int dequeuedValue =  q.items[q.front];
		if (q.front == q.rear)
			q.front = q.rear = -1;
		else
			q.front = (q.front + 1) % MAX_SIZE;
		cout << dequeuedValue << " dequeue from queue." << endl;
	}
}

void printQueue(Queue q)
{
	if (isEmpty(q))
	{
		cout << "Queue is empty." << endl;
		return;
	}
	else
	{
		cout << "Front of queue is: " << q.items[q.front] << endl;
		cout << "Rear of queue is: " << q.items[q.rear] << endl;
		int i = q.front;
		while (i != q.rear)
		{
			cout << q.items[i] << " ";
			i = (i + 1) % MAX_SIZE;
		}
		cout << q.items[q.rear] << endl;
	}
}

int main() {
    Queue q;
    initQueue(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);

    dequeue(q);
    printQueue(q);

    dequeue(q);
    dequeue(q);
    printQueue(q);

    dequeue(q);

    return 0;
}

