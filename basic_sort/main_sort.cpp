#include <iostream>
#include <vector>
#include<sstream>

#include "bubble_sort.h"
#include "selection_sort.h"
#include "insert_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"

template<typename T>
void PrintArray(const std::vector<T>& array) {
    std::ostringstream oss;
    for (auto elem : array) {
        oss << elem;
        oss << " ";
    }
    printf("%s\n\n", oss.str().c_str());
}

int main () {
    std::vector<int> arr_int = {1, 6, 2, 8, 3, 0, 100, 65, 123, 99, 32, 8};
    base_sort::BubbleSort(arr_int);
    PrintArray<int>(arr_int);

    std::vector<char> arr_char = {'b', 'd', 's', 'c', 'x', 'z', 'n', 'k', 'h', 'f', 'a', 'k', 'g'};
    base_sort::BubbleSortWithTemplate<char>(arr_char);
    PrintArray<char>(arr_char);
    std::vector<int> arr_int_2 = {1, 6, 2, 8, 3, 0, 100, 65, 123, 99, 32, 8};
    base_sort::BubbleSortUseFlag(arr_int_2);
    PrintArray<int>(arr_int_2);

    std::vector<int> arr_int_3 = {1, 6, 2, 8, 3, 0, 100, 65, 123, 99, 32, 8};
    base_sort::SelectionSort(arr_int_3);
    PrintArray<int>(arr_int_3);

    std::vector<int> arr_int_4 = {1, 6, 2, 8, 3, 0, 100, 65, 123, 99, 32, 8};
    base_sort::InsertSort(arr_int_4);
    PrintArray<int>(arr_int_4);
    
    std::vector<int> arr_int_5 = {1, 6, 2, 8, 3, 0, 100, 65, 123, 99, 32, 8};
    base_sort::ShellSort(arr_int_5);
    PrintArray<int>(arr_int_5);

    std::vector<int> arr_int_6 = {1, 6, 2, 8, 3, 0, 100, 65, 123, 99, 32, 8};
    base_sort::MergeSortWithRecursive(arr_int_6);
    PrintArray<int>(arr_int_6);
    std::vector<int> arr_int_7 = {1, 6, 2, 8, 3, 0, 100, 65, 123, 99, 32, 8};
    base_sort::MergeSortWithLoop(arr_int_7);
    PrintArray<int>(arr_int_7);

    std::vector<int> arr_int_8 = {1, 6, 2, 8, 3, 0, 100, 65, 123, 99, 32, 8};
    base_sort::QuickSortWithRecursive(arr_int_8);
    PrintArray<int>(arr_int_8);
    std::vector<int> arr_int_9 = {6, 1};
    base_sort::QuickSortWithLoop(arr_int_9);
    PrintArray<int>(arr_int_9);

    std::vector<int> arr_int_10 = {1, 6, 2, 8, 3, 0, 100, 65, 123, 99, 32, 8};
    base_sort::HeapSort(arr_int_10);
    PrintArray<int>(arr_int_10);
}