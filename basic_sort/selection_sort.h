namespace base_sort {
    // basic version
    void SelectionSort(std::vector<int>& arr) {
        int arr_len = arr.size();

        for (int i = 0; i < arr_len - 1; ++i) {
            int min_pos = i;
            for (int j = i + 1; j < arr_len; ++j) {
                if (arr[min_pos] > arr[j]) {
                    min_pos = j;
                }
            }
            if (i != min_pos) {
                int tmp = arr[i];
                arr[i] = arr[min_pos];
                arr[min_pos] = tmp;
            }
        }
        printf("this is SelectionSort\n");
    }

}