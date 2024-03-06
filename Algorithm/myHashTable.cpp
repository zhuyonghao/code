#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable
{
private:
	//存储整型的列表的向量 
	//用于存储哈希表中具有相同哈希值的键
	vector<list<int>> table;
	int size;
//通过某种哈希算法 hash() 计算得到哈希值。得到key
//将哈希值对桶数量（数组长度）capacity 取模
//映射：从而获取该 key对应的数组索引 index 。
	int hashFunction(int key)
	{
		return key % size;
	} 

public:
	HashTable(int tableSize) : size(tableSize), table(size) {}
	//插入 
	void insert(int key)
	{
		int index = hashFunction(key);
		table[index].push_back(key);
	}
	//查找
	bool search(int key)
	{
		//得到哈希值 
		int index = hashFunction(key);
		//哈希值所对应的表中查找
		for (int k : table[index])
		{
			if (k == key)
				return true;
		}
		return false;	
	} 
	//删除
	void remove(int key)
	{
		int index = hashFunction(key);
		table[index].remove(key);	
	} 
	

	
};







int main() {
    HashTable ht(10);

    ht.insert(5);
    ht.insert(15);
    ht.insert(25);

    std::cout << "Search 15: " << (ht.search(15) ? "Found" : "Not found") << std::endl;

    ht.remove(15);

    std::cout << "Search 15 after removal: " << (ht.search(15) ? "Found" : "Not found") << std::endl;

    return 0;
}

