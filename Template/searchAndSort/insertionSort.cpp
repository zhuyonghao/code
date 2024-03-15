#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

template <typename T, size_t size>
void insertionSort(array<T, size> &items)
{
    for (size_t next = 1; next < items.size(); ++next)
    {
        T insert = items[next];
        size_t moveIndex = next;

        while ((moveIndex > 0) && (items[moveIndex - 1] > insert))
        {
            items[moveIndex] = items[moveIndex - 1];
            --moveIndex;
        }

        items[moveIndex] = insert;
    }
}

int main()
{
    const size_t arraySIZE = 10;
    array<int, arraySIZE> data =
        {34, 56, 4, 10, 77, 51, 93, 30, 5, 52};
    cout << "Unsorted array:\n";
    for (size_t i = 0; i < arraySIZE; ++i)
        cout << setw(4) << data[i];
    insertionSort(data);
    cout << "\nSorted array:\n";
    for (size_t i = 0; i < arraySIZE; ++i)
        cout << setw(4) << data[i];
    cout << endl;
}