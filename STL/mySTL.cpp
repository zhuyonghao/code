/*
//迭代器

#include <iostream>
#include <vector>

using namespace std;
//vector类型的引用
template <typename T> void printVector(const vector<T>& integers2);



int main()
{
	const size_t SIZE = 6;
	int values[SIZE] = {1, 2, 3, 4, 5, 6};

	vector<int> integers;

	cout << "The initial size of integers is: " << integers.size()
		<< "\nThe initial capacity of integers is: " << integers.capacity();

	integers.push_back(2);
	integers.push_back(3);
	integers.push_back(4);

	cout << "The initial size of integers is: " << integers.size()
		<< "\nThe initial capacity of integers is: " << integers.capacity();

	for (const int* ptr = begin(values); ptr != end(values); ++ptr)
	{
		cout << *ptr << ' ';
	}

	cout << "\nOutput vecotr using iterator notation: ";
	printVector(integers);

	for (auto reverseIterator = integers.crbegin();
		reverseIterator != integers.crend(); ++reverseIterator)
		cout << *reverseIterator << ' ';

	return 0;
}


template <typename T> void printVector(const vector<T>& integers2)
{
	for (auto constIterator = integers2.cbegin();
		constIterator != integers2.cend(); ++constIterator)
	{
		cout << *constIterator << " ";
	}
}



//Vector

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

using namespace std;

int main()
{
	const size_t SIZE = 6;
	array<int, SIZE> values = {1, 2, 3, 4, 5, 6};
	//用数组来初始化
	vector<int> integers(values.cbegin(), values.cend());
	ostream_iterator<int> output(cout, " ");
	cout << "Vector integers contains: ";
	copy(integers.cbegin(), integers.cend(), output);
	cout << "\nFirst element of integers: " << integers.front()
		<< "\nLast element of integers: " << integers.back();

	integers[0] = 7;
	integers.at(2) = 10;
	integers.insert(integers.cbegin() + 1, 22);
	cout << "\n\nContents of vector integers after changes: ";
	copy(integers.cbegin(), integers.cend(), output);


	try
	{
		integers.at(100) = 777;
	}

	catch(out_of_range& outOfRange)
	{
		cout << "\n\nException: " << outOfRange.what();
	}


	integers.erase(integers.cbegin());
	cout << "\n\nVector integers after erasing first element: ";
	copy(integers.cbegin(), integers.cend(), output);

	integers.erase(integers.cbegin(), integers.cend());
	cout << "\nAfter erasing all elements, vector integers "
		<< (integers.empty() ? "is" : "is not") << "empty";

	integers.insert(integers.cbegin(), values.cbegin(), values.cend());
	cout << "\n\nContents of Vector integers before clear: ";
	copy(integers.cbegin(), integers.cend(), output);

	integers.clear();
	cout << "\nAfter clear, vector integers "
		<< (integers.empty() ? "is" : "is not") << "empty";

}




//List

#include <iostream>
#include <list>
#include <array>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T> void printList(const list<T>& listRef);


int main()
{
	const size_t SIZE = 4;
	array<int, SIZE> ints = {2, 6, 4, 8};
	list<int> values;
	list<int> otherValues;
	values.push_front(1);
	values.push_front(2);
	values.push_back(4);
	values.push_back(3);

	cout << "\nvalues contains: ";
	printList(values);

	values.sort();
	printList(values);

	otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
	cout << "\nAfter insert, other values contains: ";
	printList(otherValues);
	//将otherValues的值转移至values后面
	values.splice(values.cend(), otherValues);
	cout << "\nAfter splice, values contains: ";
	printList(values);



	values.sort();
	printList(values);

	otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
	otherValues.sort();
	cout << "\nAfter insert and sort, otherValues contains: ";
	printList(otherValues);

	values.merge(otherValues);
	cout << "\nAfter merge:\nvalues contains: ";
	printList(values);
	cout << "\notherValues contains: ";
	printList(otherValues);

	values.pop_front();
	values.pop_back();
	cout << "\nAfter pop_front and pop_back:\n   values contains: ";
	printList(values);

	values.unique();
	cout << "After unique, values contains: ";
	printList(values);

	values.swap(otherValues);
	cout << "\nAfter swap, \nvalues contains: ";
	printList(values);
	cout << "\notherValues contains: ";
	printList(otherValues);
	values.assign(otherValues.cbegin(), otherValues.cend());
	cout << "\nAfter assign, values contains: ";
	printList(values);

	values.merge(otherValues);
	cout << "\nAfter merge, values contains: ";
	printList(values);


	cout << "\nAfter remove(4), values contains: ";
	printList(values);
	cout << endl;

}


template<typename T> void printList(const list<T>& listRef)
{
	if (listRef.empty())
	{
		cout << "List is empty";
	}
	else
	{
		ostream_iterator<T> output(cout, " ");
		copy(listRef.cbegin(), listRef.cend(), output);
	}
}




//deque

#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	deque<double> values;
	ostream_iterator<double> output(cout, " ");

	values.push_front(2.2);
	values.push_front(3.5);
	values.push_back(1.1);

	cout << "values contains: ";

	for (size_t i = 0; i < values.size(); i++)
	{
		cout << values[i] << " ";
	}

	values.pop_front();
	cout << "\nAfter pop_front, values contains: ";
	copy(values.cbegin(), values.cend(), output);
	cout << endl;

	values[1] = 5.4;
	copy(values.cbegin(), values.cend(), output);
}




//multiset

#include <array>
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	const size_t SIZE = 10;
	array<int, SIZE> a = {7, 22, 9, 1, 18, 30, 100, 22, 85, 13};
	// multiset 内的元素。也就是说，multiset 中的元素将始终按升序排列
	multiset<int, less<int>> intMultiset;
	ostream_iterator<int> output(cout, " ");

	cout << "There are currently " << intMultiset.count(15)
		 << "values of 15 in the multiset\n";
	// Multiset 的 count 方法返回特定键出现的次数。
	intMultiset.insert(15);
	intMultiset.insert(15);
	cout << "After inserts, there are " << intMultiset.count(15)
		 << " values of 15 in the multiset\n\n";
	// 作用是在multiset中查找值为15的元素。如果找到，
	// 则返回指向该元素的迭代器。如果multiset中不存在值为15的元素，
	// 函数会返回指向multiset末尾的迭代器。
	auto result = intMultiset.find(15);

	if (result != intMultiset.end())
	{
		cout << "Found value 15\n";
	}

	result = intMultiset.find(20);

	if (result == intMultiset.end())
	{
		cout << "did not find value 20\n";
	}
	// 按照顺序的方式插入
	intMultiset.insert(a.cbegin(), a.cend());
	cout << "\nAfter insert, intmultiset contains: \n";
	// 用copy来输出
	copy(intMultiset.cbegin(), intMultiset.cend(), output);

	// 返回一个迭代器，指向第一个不小于22的元素，然后通过解引用操作 * 获取该元素的值。
	// 返回一个迭代器，指向第一个大于22的元素，然后通过解引用操作 * 获取该元素的值。
	cout << "\n\n lower bound of 22: " << *(intMultiset.lower_bound(22));
	cout << "\nupper bound of 22: " << *(intMultiset.upper_bound(22));
	// equal_range函数返回一个由两个迭代器组成的pair类，
	// 它们分别代表了在multiset中值等于22的元素的起始位置和结束位置。
	auto p = intMultiset.equal_range(22);
	// p.first 是第一个不小于22的元素的迭代器。
	// p.second 是第一个大于22的元素的迭代器
	cout << "\n\nequal range of 22:"
		 << "\n   lower bound: "
		 << *(p.first) << "\n    upper bound: " << *(p.second);
	cout << endl;
}





// Set

#include <iostream>
#include <array>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	const size_t SIZE = 5;
	array<double, SIZE> a = {2.1, 4.2, 9.5, 2.1, 3.7};
	// less是按照递增顺序的
	set<double, less<double>> doubleSet(a.begin(), a.end());
	ostream_iterator<double> output(cout, " ");

	cout << "doubleSet contains: ";
	// 需要修改所以不是cbegin()
	copy(doubleSet.begin(), doubleSet.end(), output);

	// 这个insert操作返回一个包含两个元素的pair：
	// p.first是一个迭代器，指向set中值为13.8的元素的位置。
	// p.second是一个bool值，如果成功插入了元素，则为true；
	// 如果set中已经存在值为13.8的元素，就不会进行插入操作，此时为false。
	auto p = doubleSet.insert(13.8);
	cout << "\n\n"
		 << *(p.first)
		 << (p.second ? "was" : "was not") << " inserrted";
	cout << "\ndoubleSet contains: 	";
	copy(doubleSet.begin(), doubleSet.end(), output);

	p = doubleSet.insert(9.5);
	cout << "\n\n"
		 << *(p.first)
		 << (p.second ? "was" : "was not") << " inserted";
	cout << "doubleSet coontains: ";
	copy(doubleSet.begin(), doubleSet.end(), output);
	cout << endl;
}





// multimap

#include <iostream>
#include <map>

using namespace std;

int main()
{
	// 按照key排序
	multimap<int, double, less<int>> pairs;

	cout << "There are currently " << pairs.count(15)
		 << " pairs with key 15 in the multimap\n";
	// 同一个键对应多个值
	pairs.insert(make_pair(15, 2.7));
	pairs.insert(make_pair(15, 99.3));
	// 统计Key = 15的次数
	cout << "After inserts, there are " << pairs.count(15)
		 << " pairs with key 15\n\n";

	pairs.insert(make_pair(30, 111.11));
	pairs.insert(make_pair(10, 22.22));
	pairs.insert(make_pair(25, 33.333));
	pairs.insert(make_pair(20, 9.345));
	pairs.insert(make_pair(5, 77.54));

	cout << "Multimap pairs contains: \nkey\tvalue\n";

	for (auto mapItem : pairs)
	{
		cout << mapItem.first << "\t" << mapItem.second << "\n";
	}

	cout << endl;
}
*/

// Map关联数组

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, double, less<int>> pairs;

	pairs.insert(make_pair(15, 2.7));
	pairs.insert(make_pair(30, 111.11));
	pairs.insert(make_pair(5, 1010.1));
	pairs.insert(make_pair(10, 22.22));
	pairs.insert(make_pair(25, 33.333));
	// 一个key对应一个value,所以此时无效
	pairs.insert(make_pair(20, 9.345));
	pairs.insert(make_pair(5, 77.54));
	pairs.insert(make_pair(15, 99.3));

	cout << "pairs contains:\nkey\tvalue\n";

	for (auto mapItem : pairs)
	{
		cout << mapItem.first << "\t" << mapItem.second << "\n";
	}
	cout << endl;

	pairs[25] = 9999.99; // 存在就修改
	pairs[40] = 8765.43; // 不存在则插入

	for (auto mapItem : pairs)
	{
		cout << mapItem.first << "\t" << mapItem.second << "\n";
	}

	cout << endl;
}
