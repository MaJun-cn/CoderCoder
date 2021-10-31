namespace base_sort {
    // basic loop version
    struct Range {
        int start, end;
        Range(int s = 0, int e = 0) {
            start = s, end = e;
        }
    };
    void QuickSortWithLoop(std::vector<int>& arr) {
        int arr_len = arr.size();
        int top_ptr = 0;
        Range stack[arr_len];
        stack[top_ptr] = Range(0, arr_len - 1);
        while (top_ptr >= 0) {
            Range cur_range = stack[top_ptr--];
            int low = cur_range.start;
            int high = cur_range.end;
            if (low >= high) {
                continue;
            }
            int key = arr[low];
            while (low < high) {
                while (low < high && arr[high] > key) {
                    --high;
                }
                if (low < high) {
                    arr[low++] = arr[high];
                }
                while (low < high && arr[low] <= key) {
                    ++low;
                }
                if (low < high) {
                    arr[high--] = arr[low];
                }
            }
            arr[low] = key;
            stack[++top_ptr] = Range(cur_range.start, low - 1);
            stack[++top_ptr] = Range(low + 1, cur_range.end);
        }
        printf("this is QuickSortWithLoop\n");
    }
    
    // basic recursive version
    void QuickSortRecursiveCore(std::vector<int>& arr, int begin, int end) {
        if (begin >= end) {
            return;
        }
        int low = begin;
        int high = end;
        int key = arr[low];
        while (low < high) {
            while (low < high && arr[high] > key) {
                --high;
            }
            if (low < high) {
                arr[low++] = arr[high];
            }
            while (low < high && arr[low] <= key) {
                ++low;
            }
            if (low < high) {
                arr[high--] = arr[low];
            }
        }
        arr[low] = key;
        QuickSortRecursiveCore(arr, begin, low - 1);
        QuickSortRecursiveCore(arr, low + 1, end);
    }
    void QuickSortWithRecursive(std::vector<int>& arr) {
        int arr_len = arr.size();
        QuickSortRecursiveCore(arr, 0, arr_len - 1);
        printf("this is QuickSortWithRecursive\n");
    }
}