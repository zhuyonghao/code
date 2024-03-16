// 归并排序 NlogN
#include <iostream>
#include <array>
#include <ctime>
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
void merge(array<T, size> &items,
           size_t left, size_t middle1, size_t middle2, size_t right)
{
    size_t leftIndex = left;
    size_t rightIndex = middle2;
    size_t combinedIndex = left;
    // 包含合并后的数组
    array<T, size> combined;

    cout << "merge:   ";
    displayElements(items, left, middle1);
    cout << "         ";
    displayElements(items, middle2, right);
    cout << endl;
    // 将较小的元素放入合并后的数组
    while (leftIndex <= middle1 && rightIndex <= right)
    {
        if (items[leftIndex] <= items[rightIndex])
            combined[combinedIndex++] = items[leftIndex++];
        else
            combined[combinedIndex++] = items[rightIndex++];
    }
    // 将右边的子数组中剩下的元素都复制到合并后的数组中
    if (leftIndex == middle2)
    {
        while (rightIndex <= right)
            combined[combinedIndex++] = items[rightIndex++];
    }
    // 将左边的子数组中剩下的元素都复制到合并后的数组中
    else
    {
        while (leftIndex <= middle1)
            combined[combinedIndex++] = items[leftIndex++];
    }

    // 将合并后的数组复制回原始数组
    for (size_t i = left; i <= right; ++i)
        items[i] = combined[i];

    cout << "      ";
    displayElements(items, left, right);
    cout << endl;
}

template <typename T, size_t size>
void mergeSort(array<T, size> &items, size_t low, size_t high)
{
    // 至少有两个元素
    if ((high - low) >= 1)
    {
        // 从中间分开
        int middle1 = (low + high) / 2;
        int middle2 = middle1 + 1;
        // 显示分割的数组
        cout << "split:   ";
        displayElements(items, low, high);
        cout << "         ";
        displayElements(items, low, middle1);
        cout << "         ";
        displayElements(items, middle2, high);
        cout << endl;
        // 递归调用进行分割
        mergeSort(items, low, middle1);
        mergeSort(items, middle2, high);
        // 合并
        merge(items, low, middle1, middle2, high);
    }
}

int main()
{
    default_random_engine engine(
        static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<unsigned int> randomInt(10, 99);

    const size_t arraySize = 10;
    array<int, arraySize> data;

    for (int &item : data)
        item = randomInt(engine);

    cout << "Unsorted array:" << endl;
    displayElements(data, 0, data.size() - 1);
    cout << endl;

    mergeSort(data, 0, data.size() - 1);

    cout << "Sorted array:" << endl;
    displayElements(data, 0, data.size() - 1);
}