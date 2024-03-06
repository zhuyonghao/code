#include <iostream>
#include <vector>
using namespace std;

//�󶥶�
//�ڵ��ֵ�����ӽڵ��ֵ 
class MaxHeap
{
private:
	vector<int> heap;
	
	
	//�������Ͻ���ֱ������������ֵ 
	void heapifyUp(int index)
	{
		//���������ҽڵ㶼��ͬ 
		int parent = (index - 1) / 2;
		
		if (index > 0 && heap[index] > heap[parent])
		{
			swap(heap[index], heap[parent]);
			heapifyUp(parent);
		}
	} 
	
	
	void heapifyDown(int index)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		
		int largest = index;
		
		if (left < heap.size() && heap[left] > heap[largest])
			largest = left;
		
		if (right < heap.size() && heap[right] > heap[largest])
			largest = right;
			
		if (largest != index)
		{
			swap(heap[largest], heap[index]);
			heapifyDown(largest);	
		} 
	} 
	
public:
	void insert(int value)
	{
		heap.push_back(value);
		heapifyUp(heap.size() - 1);
	}
	
	void removeMax()
	{
		//�����ֵ��Ϊ��Сֵ 
		heap[0] = heap.back();
		//�Ƴ����һλԪ�� 
		heap.pop_back();
		//����λ��ʼȷ�����ڵ���ӽڵ��ֵ�� 
		heapifyDown(0);
	}
	
	void printHeap()
	{
		for (const auto& element : heap)
		{
			cout << element << " ";
		}
		cout << endl;
	} 
	
}; 

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(4);
    maxHeap.insert(10);
    maxHeap.insert(3);
    maxHeap.insert(5);
    maxHeap.insert(1);

    std::cout << "Max heap: ";
    maxHeap.printHeap();

    maxHeap.removeMax();
    std::cout << "Max heap after removing top element: ";
    maxHeap.printHeap();

    return 0;
}

