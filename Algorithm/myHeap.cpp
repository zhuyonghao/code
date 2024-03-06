#include <iostream>
#include <vector>
using namespace std;

//大顶堆
//节点的值大于子节点的值 
class MaxHeap
{
private:
	vector<int> heap;
	
	
	//不断向上交换直到上面的是最大值 
	void heapifyUp(int index)
	{
		//无论是左右节点都相同 
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
		//将最大值变为最小值 
		heap[0] = heap.back();
		//移除最后一位元素 
		heap.pop_back();
		//从首位开始确保根节点比子节点的值大 
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

