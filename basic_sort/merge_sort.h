namespace base_sort {
    // basic loop version
    void MergeSortWithLoop(std::vector<int>& arr) {
        int arr_len = arr.size();
        int* temp_list_a = new int[arr_len];
        for (int i = 0; i < arr_len; ++i) {
            temp_list_a[i] = arr[i];
        }
        int* temp_list_b = new int[arr_len];
        for (int seg = 1; seg < arr_len; seg += seg) { //
            for (int start = 0; start < arr_len; start += (seg + seg)) { //
                int low = start;
                int mid = std::min(start + seg, arr_len); //
                int high = std::min(start + seg + seg, arr_len); //
                int left1 = low, right1 = mid;
                int left2 = mid, right2 = high;
                int cur_pos = low;
                while (left1 < right1 && left2 < right2) {
                    if (temp_list_a[left1] < temp_list_a[left2]) {
                        temp_list_b[cur_pos++] = temp_list_a[left1++];
                    } else {
                        temp_list_b[cur_pos++] = temp_list_a[left2++];
                    }
                }
                while (left1 < right1) {
                    temp_list_b[cur_pos++] = temp_list_a[left1++];
                }
                while (left2 < right2) {
                    temp_list_b[cur_pos++] = temp_list_a[left2++];
                }
            }
            int* temp_ptr = temp_list_a;
            temp_list_a = temp_list_b;
            temp_list_b = temp_ptr;
        }

        for (int i = 0; i < arr_len; ++i) {
            arr[i] = temp_list_a[i];
        }
        delete[] temp_list_a;
        delete[] temp_list_b;
        printf("this is MergeSortWithLoop\n");
    }

    // basic recursive version
    void MergeSortRecursiveCore(std::vector<int>& arr, int* temp_list, int begin, int end) {
        if (begin >= end) {
            return;
        }
        int mid = begin + (end - begin) / 2;
        MergeSortRecursiveCore(arr, temp_list, begin, mid);
        MergeSortRecursiveCore(arr, temp_list, mid + 1, end);
        int front_pos = begin;
        int back_pos = mid + 1;
        int cur_pos = begin;

        while (front_pos <= mid && back_pos <= end) {
            if (arr[front_pos] < arr[back_pos]) {
                temp_list[cur_pos++] = arr[front_pos++];
            } else {
                temp_list[cur_pos++] = arr[back_pos++];
            }
        }
        while (front_pos <= mid) {
            temp_list[cur_pos++] = arr[front_pos++];
        }
        while (back_pos <= end) {
            temp_list[cur_pos++] = arr[back_pos++];
        }
        for (int i = begin; i <= end; ++i) {
            arr[i] = temp_list[i];
        }
    }
    void MergeSortWithRecursive(std::vector<int>& arr) {
        int arr_len = arr.size();
        int temp_list[arr_len]; 
        MergeSortRecursiveCore(arr, temp_list, 0, arr_len - 1);
        printf("this is MergeSortWithRecursive\n");
    }
}