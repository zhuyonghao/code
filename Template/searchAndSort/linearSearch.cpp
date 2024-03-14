#include <iostream>
#include <array>
using namespace std;

// 函数模板
template <typename T, size_t size>
int linearSearch(const array<T, size> &items, const T &key)
{
    for (size_t i = 0; i < items.size(); ++i)
        if (key == items[i])
            return i;
    return -1;
}

int main()
{
    const size_t arraySize = 100;
    array<int, arraySize> arrayToSearch;

    for (size_t i = 0; i < arrayToSearch.size(); ++i)
        arrayToSearch[i] = 2 * i;

    cout << "Enter integer search key: ";
    int searchKey;
    cin >> searchKey;

    int element = linearSearch(arrayToSearch, searchKey);

    if (element != -1)
        cout << "Found value in element " << element << endl;
    else
        cout << "Value not found" << endl;
}