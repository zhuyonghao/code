#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

template <typename T, size_t size>
void selectionSort(array<T, size> &items)
{
    // 最后一个元素不用选择
    for (size_t i = 0; i < items.size() - 1; ++i)
    {
        size_t indexOfSmallest = i;
        for (size_t index = i + 1; index < items.size(); ++index)
        {
            if (items[index] < items[indexOfSmallest])
                indexOfSmallest = index;
        }

        T hold = items[i];
        items[i] = items[indexOfSmallest];
        items[indexOfSmallest] = hold;
    }
}

int main()
{
    const size_t arraySize = 10;
    array<size_t, arraySize> data =
        {34, 56, 4, 10, 77, 51, 93, 30, 5, 52};
    cout << "Unsorted array:\n";
    for (size_t i = 0; i < data.size(); ++i)
        cout << setw(4) << data[i];

    selectionSort(data);
    cout << "\nSorted array:\n";
    for (size_t i = 0; i < data.size(); ++i)
        cout << setw(4) << data[i];
    cout << endl;
}