namespace base_sort {
    // basic version
    void InsertSort(std::vector<int>& arr) {
        int arr_len = arr.size();

        for (int i = 1; i < arr_len; ++i) {
            int cur_val = arr[i];
            int pos = i - 1;
            while (pos >=0 && arr[pos] > cur_val) {
                arr[pos + 1] = arr[pos];
                --pos;
            }
            arr[pos + 1] = cur_val;
        }
        printf("this is InsertSort\n");
    }

}