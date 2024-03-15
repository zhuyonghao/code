#include <iostream>
#include <array>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

template <typename T, size_t size>
void displayElements(const array<T, size> &items,
                     size_t low, size_t high)
{
    for (size_t i = 0; i < items.size() && i < low; ++i)
        cout << "   ";
    for (size_t i = low; i < items.size() && i <= high; ++i)
        cout << items[i] << " ";

    cout << endl;
}

template <typename T, size_t size>
int binarySearch(const array<T, size> &items, const T &key)
{
    int low = 0;
    int high = items.size() - 1;
    // 在某些情况下，为总和加1可以确保中间值偏向于较高的一方
    int middle = (low + high + 1) / 2;
    int location = -1;

    do
    {
        displayElements(items, low, high);

        for (int i = 0; i < middle; ++i)
            cout << "   ";

        cout << " * " << endl;

        if (key == items[middle])
            location = middle;
        else if (key < items[middle])
            high = middle - 1;
        else
            low = middle + 1;
        middle = (low + high + 1) / 2;
    } while ((low <= high) && location == -1);

    return location;
}

int main()
{

    default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<unsigned int> randomInt(10, 99);

    const size_t arraySize = 15;
    array<int, arraySize> arrayToSearch;

    for (int &items : arrayToSearch)
        items = randomInt(engine);

    sort(arrayToSearch.begin(), arrayToSearch.end());

    displayElements(arrayToSearch, 0, arrayToSearch.size() - 1);

    cout << "\n Please enter an integer value (-1 to quit): ";
    int searchKey;
    cin >> searchKey;
    cout << endl;

    while (searchKey != -1)
    {
        int position = binarySearch(arrayToSearch, searchKey);

        if (position == -1)
            cout << "The integer " << searchKey << "was not found.\n";
        else
            cout << "The integer " << searchKey
                 << " was found in position " << position << endl;

        cout << "\n\nPlease enter an integer value(-1 to quit): ";
        cin >> searchKey;
        cout << endl;
    }
}