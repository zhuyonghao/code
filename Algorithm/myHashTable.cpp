#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable
{
private:
	//�洢���͵��б������ 
	//���ڴ洢��ϣ���о�����ͬ��ϣֵ�ļ�
	vector<list<int>> table;
	int size;
//ͨ��ĳ�ֹ�ϣ�㷨 hash() ����õ���ϣֵ���õ�key
//����ϣֵ��Ͱ���������鳤�ȣ�capacity ȡģ
//ӳ�䣺�Ӷ���ȡ�� key��Ӧ���������� index ��
	int hashFunction(int key)
	{
		return key % size;
	} 

public:
	HashTable(int tableSize) : size(tableSize), table(size) {}
	//���� 
	void insert(int key)
	{
		int index = hashFunction(key);
		table[index].push_back(key);
	}
	//����
	bool search(int key)
	{
		//�õ���ϣֵ 
		int index = hashFunction(key);
		//��ϣֵ����Ӧ�ı��в���
		for (int k : table[index])
		{
			if (k == key)
				return true;
		}
		return false;	
	} 
	//ɾ��
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

