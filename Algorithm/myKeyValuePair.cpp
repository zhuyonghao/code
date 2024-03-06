#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

struct KeyValuePair
{
	string key;
	int value;
	KeyValuePair(const string& k, int v) : key(k), value(v) {}
};

class HashMap
{
private:
	vector<list<KeyValuePair>> table;
	int size;
	
	int hashFunction(const string& key)
	{
		int hash = 0;
		//遍历每一个字符串，不断更新哈希值 
		for (char c : key)
		{
			hash = (hash * 31 + c) % size;
		}
		return hash;
	}

public:
	//让哈希表的数量和数组长度相等 
	HashMap(int tableSize) : size(tableSize), table(tableSize) {}
	
	//插入
	void insert(const string& key, int value)
	{
		int index = hashFunction(key);
		//列表直接把一个结构体放入 
		table[index].push_back(KeyValuePair(key, value)); 
	} 
	
	//获得value
	int get(const string& key)
	{
		int index = hashFunction(key);
		
		for (const KeyValuePair& pair : table[index])
		{
			if (pair.key == key)
			{
				return pair.value;
			}	
		}
		return -1; 
	} 
	
	//删除键值对
	void remove(const string& key)
	{
		int index = hashFunction(key);
		table[index].remove_if([&](const KeyValuePair& pair) { return pair.key == key; });	
	} 
	
	
};


int main() {
    HashMap hashMap(10);

    hashMap.insert("apple", 5);
    hashMap.insert("banana", 10);
    hashMap.insert("orange", 15);

    std::cout << "Value for key 'banana': " << hashMap.get("banana") << std::endl;
    std::cout << "Value for key 'grape': " << hashMap.get("grape") << std::endl;

    hashMap.remove("banana");

    std::cout << "Value for key 'banana' after removal: " << hashMap.get("banana") << std::endl;

    return 0;
}

