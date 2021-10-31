namespace base_sort {
    // basic version
    void ShellSort(std::vector<int>& arr) {
        int arr_len = arr.size();
        for (int gap = arr_len / 2; gap >= 1; gap /= 2) {
            for (int i = gap; i < arr_len; ++i) {
                int cur_val = arr[i];
                int pos = i - gap;
                while (pos >= 0 && arr[pos] > cur_val) {
                    arr[pos + gap] = arr[pos];
                    pos -= gap;
                }
                arr[pos + gap] = cur_val;
            }
        }
        printf("this is ShellSort\n");
    }
}