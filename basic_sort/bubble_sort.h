namespace base_sort {
    // basic version
    void BubbleSort(std::vector<int>& arr) {
        int arr_len = arr.size();
        for (int i = 0; i < arr_len - 1; ++i) {
            for (int j = 0; j < arr_len - 1 - i; ++j) {
                if (arr[j] > arr[j + 1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
        printf("this is BubbleSort\n");
    }
    // template version
    template<typename T>
    void BubbleSortWithTemplate(std::vector<T>& arr) {
        int arr_len = arr.size();
        for (int i = 0; i < arr_len - 1; ++i) {
            for (int j = 0; j < arr_len - 1 - i; ++j) {
                if (arr[j] > arr[j + 1]) {
                    T tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
        printf("this is BubbleSortWithTemplate\n");
    }

    //use 'orderly' flag
    void BubbleSortUseFlag(std::vector<int>& arr) {
        int arr_len = arr.size();
        bool orderly = false;
        for (int i = 0; i < arr_len - 1 && !orderly; ++i) {
            orderly = true;
            for (int j = 0; j < arr_len - 1 - i; ++j) {
                if (arr[j] > arr[j + 1]) {
                    orderly = false;
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
        printf("this is BubbleSortUseFlag\n");
    }


}