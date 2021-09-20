#include <iostream>
#include <algorithm>
#include <vector>

void ThreeSum(std::vector<int> nums, int key, std::vector<std::vector<int>>& result) {
    // sort
    std::sort(nums.begin(), nums.end());
    int nums_len = nums.size();
    if (nums_len == 0) return;
    int first_ptr = 0;
    while (first_ptr < nums_len - 2) {
        int cur_first = nums[first_ptr];
        // TwoSum
        int two_sum_value = key - cur_first;
        int second_ptr = first_ptr + 1;
        int third_ptr = nums_len - 1;
        while (second_ptr < third_ptr) {
            if (nums[second_ptr] + nums[third_ptr] == two_sum_value) {
                result.push_back({cur_first, nums[second_ptr], nums[third_ptr]});
                // de-duplication
                int temp = nums[second_ptr];
                while (temp == nums[second_ptr] && second_ptr < third_ptr) {
                    ++second_ptr;
                }
            } else if (nums[second_ptr] + nums[third_ptr] < two_sum_value) {
                ++second_ptr;
            } else {
                --third_ptr;
            }
        }
        //de-duplication
        while (first_ptr < nums_len && nums[first_ptr] == cur_first) {
            ++first_ptr;
        }
    }
}
int main () {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int key = 0;
    std::vector<std::vector<int>> result;
    ThreeSum(nums, key, result);
    for (auto triple : result) {
        for (auto elem : triple) {
            printf("%d ", elem);
        }
        printf("\n");
    }
}