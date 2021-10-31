namespace base_sort {
    // basic version
    void max_heapify(std::vector<int>& arr, int start, int end) {
        int dad = start;
        int son = start * 2 + 1;
        while (son <= end) {
            if (son + 1 <= end && arr[son] < arr[son + 1]) {
               ++son;
            }
            if (arr[son] <= arr[dad]) {
                break;
            }
            std::swap(arr[son], arr[dad]);
            dad = son;
            son = dad * 2 + 1;
        }
        return;
    }
    void HeapSort(std::vector<int>& arr) {
        int arr_len = arr.size();
        // adjust from the last parent node
        for (int i = arr_len / 2 - 1; i >= 0; --i) {
            max_heapify(arr, i, arr_len - 1);
        }
        for (int i = arr_len - 1; i > 0; --i) {
            std::swap(arr[0], arr[i]);
            max_heapify(arr, 0, i - 1);
        }
        printf("this is HeapSort\n");
    }

}